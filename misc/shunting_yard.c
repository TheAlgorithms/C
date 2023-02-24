/**
 * @file
 * @brief [Shunting Yard Algorithm](https://en.wikipedia.org/wiki/Shunting_yard_algorithm)
 * @details From Wikipedia: In computer science,
 * the shunting yard algorithm is a method for parsing arithmetical or logical expressions, or a combination of both, specified in infix notation.
 * It can produce either a postfix notation string, also known as Reverse Polish notation (RPN), or an abstract syntax tree (AST).
 * The algorithm was invented by Edsger Dijkstra and named the "shunting yard" algorithm because its operation resembles that of a railroad shunting yard.
 * @author [CascadingCascade](https://github.com/CascadingCascade)
 */

#include <assert.h>     /// for assertion
#include <stdio.h>      /// for IO operations
#include <stdlib.h>     /// for memory management
#include <string.h>     /// for string operations
#include <ctype.h>      /// for isdigit()

/**
 * @brief Helper function that returns each operator's precedence
 * @param operator the operator to be queried
 * @returns the operator's precedence
 */
int getPrecedence(char operator) {
    switch (operator) {
        case '+':
        case '-': {
            return 1;
        }
        case '*':
        case '/': {
            return 2;
        }
        case '^': {
            return 3;
        }
        default:{
            fprintf(stderr,"Error: Invalid operator\n");
            return -1;
        }
    }
}

/**
 * @brief Helper function that returns each operator's associativity
 * @param operator the operator to be queried
 * @returns '1' if the operator is left associative
 * @returns '0' if the operator is right associative
 */
int getAssociativity(char operator) {
    switch (operator) {
        case '^': {
            return 0;
        }
        case '+':
        case '-':
        case '*':
        case '/': {
            return 1;
        }
        default: {
            fprintf(stderr,"Error: Invalid operator\n");
            return -1;
        }
    }
}

/**
 * @brief An implementation of the shunting yard that converts infix notation to reversed polish notation
 * @param input pointer to input string
 * @param output pointer to output location
 * @returns `1` if a parentheses mismatch is detected
 * @returns `0` if no mismatches are detected
 */
int shuntingYard(const char *input, char *output) {
    const unsigned int inputLength = strlen(input);
    char* operatorStack = (char*) malloc(sizeof(char) * inputLength);

    // This pointer points at where we should insert the next element,
    // Hence stackPointer - 1 is used when accessing elements
    unsigned int stackPointer = 0;

    // We will parse the input with strtok(),
    // Since strtok() is destructive, we make a copy of the input to preserve the original string
    char* str = malloc(sizeof(char) * inputLength + 1);
    strcpy(str,input);
    char* token = strtok(str," ");

    // We will push to output with strcat() and strncat(),
    // This initializes output to be a string with a length of zero
    output[0] = '\0';

    while (token != NULL) {
        // If it's a number, push it to the output directly
        if (isdigit(token[0])) {
            strcat(output,token);
            strcat(output," ");

            token = strtok(NULL," ");
            continue;
        }

        switch (token[0]) {
            // If it's a left parenthesis, push it to the operator stack for later matching
            case '(': {
                operatorStack[stackPointer++] = token[0];
                break;
            }

            // If it's a right parenthesis, search for a left parenthesis to match it
            case ')': {
                // Guard statement against accessing an empty stack
                if(stackPointer < 1) {
                    fprintf(stderr,"Error: Mismatched parentheses\n");
                    free(operatorStack);
                    free(str);
                    return 1;
                }

                while (operatorStack[stackPointer - 1] != '(') {
                    // strncat() with a count of 1 is used to append characters to output
                    const unsigned int i = (stackPointer--) - 1;
                    strncat(output, &operatorStack[i], 1);
                    strcat(output," ");

                    // If the operator stack is exhausted before a match can be found,
                    // There must be a mismatch
                    if(stackPointer == 0) {
                        fprintf(stderr,"Error: Mismatched parentheses\n");
                        free(operatorStack);
                        free(str);
                        return 1;
                    }
                }

                // Discards the parentheses now the matching is complete,
                // Simply remove the left parenthesis from the stack is enough,
                // Since the right parenthesis didn't enter the stack in the first place
                stackPointer--;
                break;
            }

            // If it's an operator(o1), we compare it to whatever is at the top of the operator stack(o2)
            default: {
                // Places the operator into the stack directly if it's empty
                if(stackPointer < 1) {
                    operatorStack[stackPointer++] = token[0];
                    break;
                }

                // We need to check if there's actually a valid operator at the top of the stack
                if((stackPointer - 1 > 0) && operatorStack[stackPointer - 1] != '(') {
                    const int precedence1 = getPrecedence(token[0]);
                    const int precedence2 = getPrecedence(operatorStack[stackPointer - 1]);
                    const int associativity = getAssociativity(token[0]);

                    // We pop operators from the stack, if...
                    while ( // ... their precedences are equal, and o1 is left associative, ...
                            ((associativity && precedence1 == precedence2) ||
                             // ... or o2 simply have a higher precedence, ...
                             precedence2 > precedence1) &&
                            // ... and there are still operators available to be popped.
                            ((stackPointer - 1 > 0) && operatorStack[stackPointer - 1] != '(')) {

                        strncat(output,&operatorStack[(stackPointer--) - 1],1);
                        strcat(output," ");
                    }
                }

                // We'll save o1 for later
                operatorStack[stackPointer++] = token[0];
                break;
            }
        }

        token = strtok(NULL," ");
    }

    free(str);

    // Now all input has been exhausted,
    // Pop everything from the operator stack, then push them to the output
    while (stackPointer > 0) {
        // If there are still leftover left parentheses in the stack,
        // There must be a mismatch
        if(operatorStack[stackPointer - 1] == '(') {
            fprintf(stderr,"Error: Mismatched parentheses\n");
            free(operatorStack);
            return 1;
        }

        const unsigned int i = (stackPointer--) - 1;
        strncat(output, &operatorStack[i], 1);
        if (i != 0) {
            strcat(output," ");
        }
    }

    free(operatorStack);
    return 0;
}

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test() {
    char* in = malloc(sizeof(char) * 50);
    char* out = malloc(sizeof(char) * 50);
    int i;

    strcpy(in,"3 + 4 * ( 2 - 1 )");
    printf("Infix: %s\n",in);
    i = shuntingYard(in, out);
    printf("RPN: %s\n",out);
    printf("Return code: %d\n\n",i);
    assert(strcmp(out,"3 4 2 1 - * +") == 0);
    assert(i == 0);

    strcpy(in,"3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3");
    printf("Infix: %s\n",in);
    i = shuntingYard(in, out);
    printf("RPN: %s\n",out);
    printf("Return code: %d\n\n",i);
    assert(strcmp(out,"3 4 2 * 1 5 - 2 3 ^ ^ / +") == 0);
    assert(i == 0);

    printf("Testing successfully completed!\n");
    free(in);
    free(out);
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
    test(); // Run self-test implementations
    return 0;
}
