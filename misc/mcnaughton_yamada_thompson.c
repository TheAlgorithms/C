/**
 * @file
 * @brief [McNaughton–Yamada–Thompson algorithm](https://en.wikipedia.org/wiki/Thompson%27s_construction)
 * @details
 * From Wikipedia:
 * In computer science, Thompson's construction algorithm,
 * also called the McNaughton–Yamada–Thompson algorithm,
 * is a method of transforming a regular expression into
 * an equivalent nondeterministic finite automaton (NFA).
 * This implementation implements the all three operations
 * (implicit concatenation, '|' for union, '*' for Kleene star)
 * required by the formal definition of regular expressions.
 * @author [Sharon Cassidy](https://github.com/CascadingCascade)
 */

#include <assert.h> /// for assert()
#include <stdio.h>  /// for IO operations
#include <string.h> /// for string operations
#include <stdlib.h> /// for memory management

/* Begin declarations, I opted to place various helper / utility functions
 * close to their usages and didn't split their declaration / definition */

/**
 * @brief Definition for a binary abstract syntax tree (AST) node
 */
struct ASTNode {
    char content;          ///< the content of this node
    struct ASTNode* left;  ///< left child
    struct ASTNode* right; ///< right child
};

struct ASTNode* createNode(char content);
void destroyNode(struct ASTNode* node);
char* preProcessing(const char* input);
struct ASTNode* buildAST(const char* input);

/**
 * @brief Definition for a NFA state transition rule
 */
struct transRule {
    struct NFAState* target; ///< pointer to the state to transit to
    char cond;               ///< the input required to activate this transition
};

struct transRule* createRule(struct NFAState* state, char c);
void destroyRule(struct transRule* rule);

/**
 * @brief Definition for a NFA state. Each NFAState object is initialized
 *        to have a capacity of three rules, since there will only be at most two
 *        outgoing rules and one empty character circular rule in this algorithm
 */
struct NFAState {
    int ruleCount;            ///< number of transition rules this state have
    struct transRule** rules; ///< the transition rules
};

struct NFAState* createState(void);
void destroyState(struct NFAState* state);

/**
 * @brief Definition for the NFA itself.
 *        statePool[0] is defined to be its starting state,
 *        and statePool[1] is defined to be its accepting state.
 *        for simplicity's sake all NFAs are initialized to have
 *        a small fixed capacity, although due to the recursive nature
 *        of this algorithm this capacity is believed to be sufficient
 */
struct NFA {
    int stateCount;                  ///< the total number of states this NFA have
    struct NFAState** statePool;     ///< the pool of all available states
    int ruleCount;                   ///< the total number of transition rules in this NFA
    struct transRule** rulePool;     ///< the pool of all transition rules
    int CSCount;                     ///< the number of currently active states
    struct NFAState** currentStates; ///< the pool of all active states
    int subCount;                    ///< the number of sub NFAs
    struct NFA** subs;               ///< the pool of all sub NFAs
    int wrapperFlag;                 ///< whether this NFA is a concatenation wrapper
};

struct NFA* createNFA(void);
void destroyNFA(struct NFA* nfa);
void addState(struct NFA* nfa, struct NFAState* state);
void addRule(struct NFA* nfa, struct transRule* rule, int loc);
void postProcessing(struct NFA* nfa);
void transit(struct NFA* nfa, char input);
int isAccepting(const struct NFA* nfa);

/* End definitions, begin abstract syntax tree construction */

/**
 * @brief helper function to determine whether a character should be
 *        considered a character literal
 * @param ch the character to be tested
 * @returns `1` if it is a character literal
 * @returns `0` otherwise
 */
int isLiteral(const char ch) {
    return !(ch == '(' || ch == ')' || ch == '*' || ch == '\n' || ch == '|');
}

/**
 * @brief performs preprocessing on a regex string,
 *        making all implicit concatenations explicit
 * @param input target regex string
 * @returns pointer to the processing result
 */
char* preProcessing(const char* input) {
    const size_t len = strlen(input);
    if(len == 0) {
        char* str = malloc(1);
        str[0] = '\0';
        return str;
    }

    char* str = malloc(len * 2);
    size_t op = 0;

    for (size_t i = 0; i < len - 1; ++i) {
        char c = input[i];
        str[op++] = c;
        // one character lookahead
        char c1 = input[i + 1];

        if( (isLiteral(c) && isLiteral(c1)) ||
            (isLiteral(c) && c1 == '(') ||
            (c == ')' && c1 == '(') ||
            (c == ')' && isLiteral(c1)) ||
            (c == '*' && isLiteral(c1)) ||
            (c == '*' && c1 == '(')
                ) {
            // '\n' is used to represent concatenation
            // in this implementation
            str[op++] = '\n';
        }
    }

    str[op++] = input[len - 1];
    str[op] = '\0';
    return str;
}

/**
 * @brief utility function to locate the first occurrence
 *        of a character in a string while respecting parentheses
 * @param str target string
 * @param key the character to be located
 * @returns the index of its first occurrence, `0` if it could not be found
 */
size_t indexOf(const char* str, char key) {
    int depth = 0;

    for (size_t i = 0; i < strlen(str); ++i) {
        const char c = str[i];

        if(depth == 0 && c == key) {
            return i;
        }
        if(c == '(') depth++;
        if(c == ')') depth--;
    }
    // Due to the way this function is intended to be used,
    // it's safe to assume the character will not appear as
    // the string's first character
    // thus `0` is used as the `not found` value
    return 0;
}

/**
 * @brief utility function to create a subString
 * @param str target string
 * @param begin starting index, inclusive
 * @param end ending index, inclusive
 * @returns pointer to the newly created subString
 */
char* subString(const char* str, size_t begin, size_t end) {
    char* res = malloc(end - begin + 2);
    strncpy(res, str + begin, end - begin + 1);
    res[end - begin + 1] = '\0';
    return res;
}

/**
 * @brief recursively constructs a AST from a preprocessed regex string
 * @param input regex
 * @returns pointer to the resulting tree
 */
struct ASTNode* buildAST(const char* input) {

    struct ASTNode* node = createNode('\0');
    node->left = NULL;
    node->right = NULL;
    const size_t len = strlen(input);
    size_t index;

    // Empty input
    if(len == 0) return node;

    // Character literals
    if(len == 1) {
        node->content = input[0];
        return node;
    }

    // Discard parentheses
    if(input[0] == '(' && input[len - 1] == ')') {
        char* temp = subString(input, 1, len - 2);
        destroyNode(node);
        node = buildAST(temp);

        free(temp);
        return node;
    }

    // Union
    index = indexOf(input, '|');
    if(index) {
        node->content = '|';

        char* temp1 = subString(input, 0, index - 1);
        char* temp2 = subString(input, index + 1, len - 1);
        node->left = buildAST(temp1);
        node->right = buildAST(temp2);

        free(temp2);
        free(temp1);
        return node;
    }

    // Concatenation
    index = indexOf(input, '\n');
    if(index) {
        node->content = '\n';

        char* temp1 = subString(input, 0, index - 1);
        char* temp2 = subString(input, index + 1, len - 1);
        node->left = buildAST(temp1);
        node->right = buildAST(temp2);

        free(temp2);
        free(temp1);
        return node;
    }

    // Kleene star
    // Testing with indexOf() is unnecessary here,
    // Since all other possibilities have been exhausted
    node->content = '*';
    char* temp = subString(input, 0, len - 2);
    node->left = buildAST(temp);
    node->right = NULL;

    free(temp);
    return node;
}

/* End AST construction, begins the actual algorithm itself */

/**
 * @brief helper function to recursively redirect transition rule targets
 * @param nfa target NFA
 * @param src the state to redirect away from
 * @param dest the state to redirect to
 * @returns void
 */
void redirect(struct NFA* nfa, struct NFAState* src, struct NFAState* dest) {
    for (int i = 0; i < nfa->subCount; ++i) {
        redirect(nfa->subs[i], src, dest);
    }
    for (int i = 0; i < nfa->ruleCount; ++i) {
        struct transRule* rule = nfa->rulePool[i];
        if (rule->target == src) {
            rule->target = dest;
        }
    }
}

struct NFA* compileFromAST(struct ASTNode* root) {

    struct NFA* nfa = createNFA();

    // Empty input
    if (root->content == '\0') {
        addRule(nfa, createRule(nfa->statePool[1], '\0'), 0);
        return nfa;
    }

    // Character literals
    if (isLiteral(root->content)) {
        addRule(nfa, createRule(nfa->statePool[1], root->content), 0);
        return nfa;
    }

    switch (root->content) {

        case '\n': {
            struct NFA* ln = compileFromAST(root->left);
            struct NFA* rn = compileFromAST(root->right);

            // Redirects all rules targeting ln's accepting state to
            // target rn's starting state
            redirect(ln, ln->statePool[1], rn->statePool[0]);

            // Manually creates and initializes a special
            // "wrapper" NFA
            destroyNFA(nfa);
            struct NFA* wrapper = malloc(sizeof(struct NFA));
            wrapper->stateCount = 2;
            wrapper->statePool = malloc(sizeof(struct NFAState*) * 2);
            wrapper->subCount = 0;
            wrapper->subs = malloc(sizeof(struct NFA*) * 2);
            wrapper->ruleCount = 0;
            wrapper->rulePool = malloc(sizeof(struct transRule*) * 3);
            wrapper->CSCount = 0;
            wrapper->currentStates = malloc(sizeof(struct NFAState*) * 2);
            wrapper->wrapperFlag = 1;
            wrapper->subs[wrapper->subCount++] = ln;
            wrapper->subs[wrapper->subCount++] = rn;

            // Maps the wrapper NFA's starting and ending states
            // to its sub NFAs
            wrapper->statePool[0] = ln->statePool[0];
            wrapper->statePool[1] = rn->statePool[1];

            return wrapper;
        }
        case '|': {

            struct NFA* ln = compileFromAST(root->left);
            struct NFA* rn = compileFromAST(root->right);
            nfa->subs[nfa->subCount++] = ln;
            nfa->subs[nfa->subCount++] = rn;

            // Adds empty character transition rules
            addRule(nfa, createRule(ln->statePool[0], '\0'), 0);
            addRule(ln, createRule(nfa->statePool[1], '\0'), 1);
            addRule(nfa, createRule(rn->statePool[0], '\0'), 0);
            addRule(rn, createRule(nfa->statePool[1], '\0'), 1);

            return nfa;
        }
        case '*': {
            struct NFA* ln = compileFromAST(root->left);
            nfa->subs[nfa->subCount++] = ln;

            addRule(ln, createRule(ln->statePool[0], '\0'), 1);
            addRule(nfa, createRule(ln->statePool[0], '\0'), 0);
            addRule(ln, createRule(nfa->statePool[1], '\0'), 1);
            addRule(nfa, createRule(nfa->statePool[1], '\0'), 0);

            return nfa;
        }
    }

    // Fallback, shouldn't happen in normal operation
    destroyNFA(nfa);
    return NULL;
}

/* Ends the algorithm, begins NFA utility functions*/

/**
 * @brief adds a state to a NFA
 * @param nfa target NFA
 * @param state the NFA state to be added
 * @returns void
 */
void addState(struct NFA* nfa, struct NFAState* state) {
    nfa->statePool[nfa->stateCount++] = state;
}

/**
 * @brief adds a transition rule to a NFA
 * @param nfa target NFA
 * @param rule the rule to be added
 * @param loc which state this rule should be added to
 * @returns void
 */
void addRule(struct NFA* nfa, struct transRule* rule, int loc) {
    nfa->rulePool[nfa->ruleCount++] = rule;
    struct NFAState* state = nfa->statePool[loc];
    state->rules[state->ruleCount++] = rule;
}

/**
 * @brief performs postprocessing on a compiled NFA,
 *        add circular empty character transition rules where
 *        it's needed for the NFA to function correctly
 * @param nfa target NFA
 * @returns void
 */
void postProcessing(struct NFA* nfa) {
    // Since the sub NFA's states and rules are managed
    // through their own pools, recursion is necessary
    for (int i = 0; i < nfa->subCount; ++i) {
        postProcessing(nfa->subs[i]);
    }

    // If a state does not have any empty character accepting rule,
    // we add a rule that circles back to itself
    // So this state will be preserved when
    // empty characters are inputted
    for (int i = 0; i < nfa->stateCount; ++i) {

        struct NFAState* pState = nfa->statePool[i];
        int f = 0;
        for (int j = 0; j < pState->ruleCount; ++j) {
            if(pState->rules[j]->cond == '\0') {
                f = 1;
                break;
            }
        }

        if (!f) {
            addRule(nfa, createRule(pState, '\0'), i);
        }
    }
}

/**
 * @brief helper function to determine an element's presence in an array
 * @param states target array
 * @param len length of the target array
 * @param state the element to search for
 * @returns `1` if the element is present, `0` otherwise
 */
int contains(struct NFAState** states, int len, struct NFAState* state) {
    int f = 0;
    for (int i = 0; i < len; ++i) {
        if(states[i] == state) {
            f = 1;
            break;
        }
    }
    return f;
}

/**
 * @brief helper function to manage empty character transitions
 * @param target target NFA
 * @param states pointer to results storage location
 * @param sc pointer to results count storage location
 * @returns void
 */
void findEmpty(struct NFAState* target, struct NFAState** states, int *sc) {
    for (int i = 0; i < target->ruleCount; ++i) {
        const struct transRule *pRule = target->rules[i];

        if (pRule->cond == '\0' && !contains(states, *sc, pRule->target)) {
            states[(*sc)++] = pRule->target;
            // the use of `states` and `sc` is necessary
            // to sync data across recursion levels
            findEmpty(pRule->target, states, sc);
        }
    }
}

/**
 * @brief moves a NFA forward
 * @param nfa target NFA
 * @param input the character to be fed into the NFA
 * @returns void
 */
void transit(struct NFA* nfa, char input) {
    struct NFAState** newStates = malloc(sizeof(struct NFAState*) * 10);
    int NSCount = 0;

    if (input == '\0') {
        // In case of empty character input, it's possible for
        // a state to transit to another state that's more than
        // one rule away, we need to take that into account
        for (int i = nfa->CSCount - 1; i > -1; --i) {
            struct NFAState *pState = nfa->currentStates[i];
            nfa->CSCount--;

            struct NFAState** states = malloc(sizeof(struct NFAState*) * 10);
            int sc = 0;
            findEmpty(pState, states, &sc);

            for (int j = 0; j < sc; ++j) {
                if(!contains(newStates,NSCount, states[j])) {
                    newStates[NSCount++] = states[j];
                }
            }
            free(states);
        }
    } else {
        // Iterates through all current states
        for (int i = nfa->CSCount - 1; i > -1; --i) {
            struct NFAState *pState = nfa->currentStates[i];
            // Gradually empties the current states pool, so
            // it can be refilled
            nfa->CSCount--;

            // Iterates through rules of this state
            for (int j = 0; j < pState->ruleCount; ++j) {
                const struct transRule *pRule = pState->rules[j];

                if(pRule->cond == input) {
                    if(!contains(newStates, NSCount, pRule->target)) {
                        newStates[NSCount++] = pRule->target;
                    }
                }
            }
        }
    }

    nfa->CSCount = NSCount;
    for (int i = 0; i < NSCount; ++i) {
        nfa->currentStates[i] = newStates[i];
    }
    free(newStates);
}

/**
 * @brief determines whether the NFA is currently in its accepting state
 * @param nfa target NFA
 * @returns `1` if the NFA is in its accepting state
 * @returns `0` otherwise
 */
int isAccepting(const struct NFA* nfa) {
    for (int i = 0; i < nfa->CSCount; ++i) {
        if(nfa->currentStates[i] == nfa->statePool[1]) {
            return 1;
        }
    }
    return 0;
}

/* Ends NFA utilities, begins testing function*/

/**
 * @brief Testing helper function
 * @param regex the regular expression to be used
 * @param string the string to match against
 * @param expected expected results
 * @returns void
 */
void testHelper(const char* regex, const char* string, const int expected) {
    char* temp = preProcessing(regex);
    struct ASTNode* node = buildAST(temp);

    struct NFA* nfa = compileFromAST(node);
    postProcessing(nfa);

    // reallocates the outermost NFA's current states pool
    // because it will actually be used to store all the states
    nfa->currentStates = realloc(nfa->currentStates, sizeof(struct NFAState*) * 100);
    // Starts the NFA by adding its starting state to the pool
    nfa->currentStates[nfa->CSCount++] = nfa->statePool[0];

    // feeds empty characters into the NFA before and after
    // every normal character
    for (size_t i = 0; i < strlen(string); ++i) {
        transit(nfa, '\0');
        transit(nfa, string[i]);
    }
    transit(nfa, '\0');

    assert(isAccepting(nfa) == expected);

    destroyNFA(nfa);
    destroyNode(node);
    free(temp);
}

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test(void) {
    testHelper("(c|a*b)", "c", 1);
    testHelper("(c|a*b)", "aab", 1);
    testHelper("(c|a*b)", "ca", 0);
    testHelper("(c|a*b)*", "caaab", 1);
    testHelper("(c|a*b)*", "caba", 0);
    testHelper("", "", 1);
    testHelper("", "1", 0);
    testHelper("(0|(1(01*(00)*0)*1)*)*","11",1);
    testHelper("(0|(1(01*(00)*0)*1)*)*","110",1);
    testHelper("(0|(1(01*(00)*0)*1)*)*","1100",1);
    testHelper("(0|(1(01*(00)*0)*1)*)*","10000",0);
    testHelper("(0|(1(01*(00)*0)*1)*)*","00000",1);

    printf("All tests have successfully passed!\n");
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main(void) {
    test(); // run self-test implementations
    return 0;
}

/* I opted to place these more-or-less boilerplate code and their docs
 * at the end of file for better readability */

/**
 * @brief creates and initializes a AST node
 * @param content data to initializes the node with
 * @returns pointer to the newly created node
 */
struct ASTNode* createNode(const char content) {
    struct ASTNode* node = malloc(sizeof(struct ASTNode));
    node->content = content;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/**
 * @brief recursively destroys a AST
 * @param node the root node of the tree to be deleted
 * @returns void
 */
void destroyNode(struct ASTNode* node) {
    if(node->left != NULL) {
        destroyNode(node->left);
    }

    if(node->right != NULL) {
        destroyNode(node->right);
    }

    free(node);
}

/**
 * @brief creates and initializes a transition rule
 * @param state transition target
 * @param c transition condition
 * @returns pointer to the newly created rule
 */
struct transRule* createRule(struct NFAState* state, char c) {
    struct transRule* rule = malloc(sizeof(struct transRule));
    rule->target = state;
    rule->cond = c;
    return rule;
}

/**
 * @brief destroys a transition rule object
 * @param rule pointer to the object to be deleted
 * @returns void
 */
void destroyRule(struct transRule* rule) {
    free(rule);
}

/**
 * @brief creates and initializes a NFA state
 * @returns pointer to the newly created NFA state
 */
struct NFAState* createState(void) {
    struct NFAState* state = malloc(sizeof(struct NFAState));
    state->ruleCount = 0;
    state->rules = malloc(sizeof(struct transRule*) * 3);
    return state;
}

/**
 * @brief destroys a NFA state
 * @param state pointer to the object to be deleted
 * @returns void
 */
void destroyState(struct NFAState* state) {
    free(state->rules);
    free(state);
}

/**
 * @brief creates and initializes a NFA
 * @returns pointer to the newly created NFA
 */
struct NFA* createNFA(void) {
    struct NFA* nfa = malloc(sizeof(struct NFA));

    nfa->stateCount = 0;
    nfa->statePool = malloc(sizeof(struct NFAState*) * 5);
    nfa->ruleCount = 0;
    nfa->rulePool = malloc(sizeof(struct transRule*) * 10);
    nfa->CSCount = 0;
    nfa->currentStates = malloc(sizeof(struct NFAState*) * 5);
    nfa->subCount = 0;
    nfa->subs = malloc(sizeof(struct NFA*) * 5);
    nfa->wrapperFlag = 0;

    addState(nfa, createState());
    addState(nfa, createState());
    return nfa;
}

/**
 * @brief recursively destroys a NFA
 * @param nfa pointer to the object to be deleted
 * @returns void
 */
void destroyNFA(struct NFA* nfa) {
    for (int i = 0; i < nfa->subCount; ++i) {
        destroyNFA(nfa->subs[i]);
    }

    // In case of a wrapper NFA, do not free its states
    // because it doesn't really have any states of its own
    if (!nfa->wrapperFlag) {
        for (int i = 0; i < nfa->stateCount; ++i) {
            destroyState(nfa->statePool[i]);
        }
    }
    for (int i = 0; i < nfa->ruleCount; ++i) {
        destroyRule(nfa->rulePool[i]);
    }
    free(nfa->statePool);
    free(nfa->currentStates);
    free(nfa->rulePool);
    free(nfa->subs);
    free(nfa);
}
