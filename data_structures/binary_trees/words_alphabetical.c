/**
 * @file
 * @brief Printing the [words contained in a
 * file](http://www.dailyfreecode.com/Code/word-list-reads-text-file-makes-2050.aspx)
 * named `file.txt` in alphabetical order and also their frequencies in to
 * another file "wordcount.txt"
 * @details
 * Given a file (`file.txt`) containing words (like a publication or a novel),
 * where words are separated by a space, newline, or underscore.
 * This program prints (writes or outputs) to another file (`wordcount.txt`),
 * the individual words contained in 'file.txt' with their frequencies (number
 * of occurrences) each on a newline and in alphabetical order. This program uses
 * the binary tree data structure to accomplish this task.
 * @author [Randy Kwalar](https://github.com/RandyKdev)
 */

#include <assert.h>    /// for assert
#include <ctype.h>     /// for type checks
#include <inttypes.h>  /// for uint64_t based types, int64_t based types
#include <stdbool.h>   /// for boolean data type
#include <stdio.h>     /// for IO operations
#include <stdlib.h>    /// for memory allocation
#include <string.h>    /// for string operations

/**
 * @brief structure defining a node in the binary tree
 */
struct Node
{
    char *word;          ///< the word (value) of the node
    uint64_t frequency;  ///< number of occurrences of the word
    struct Node *left;   ///< pointer to the left child node
    struct Node *right;  ///< pointer to the right child node
};

/**
 * @brief Ends program due to an error
 * @param errorMessage the error message to be printed
 * @returns void
 */
void endProgramAbruptly(char *errorMessage)
{
    fprintf(stderr, "%s\n", errorMessage);
    exit(EXIT_FAILURE);
}

/**
 * @brief Frees memory when program is terminating
 * @param node pointer to current node
 * @returns void
 */
void freeTreeMemory(struct Node *node)
{
    if (node != NULL)
    {
        freeTreeMemory(node->left);
        freeTreeMemory(node->right);
        free(node->word);  // freeing node->word because memory was allocated
                           // using malloc
        free(node);  // freeing node because memory was allocated using malloc
    }
}

/**
 * @brief Stores word in memory
 * @param word word to be stored in memory
 * @returns a pointer to the newly allocated word if the word IS stored successfully
 * @returns `NULL` if the word is NOT stored
 */
char *getPointerToWord(char *word)
{
    char *string =
        (char *)malloc((strlen(word) + 1) * sizeof(char));  ///< pointer to string
    // + 1 is for the '\0' character
    if (string != NULL)
    {
        strcpy(string, word);
        return string;
    }
    endProgramAbruptly(
        "\nA problem occurred while reserving memory for the word\n");
    return NULL;
}

/**
 * @brief Closes the file after reading or writing
 * @param file pointer to the file to be closed
 * @returns void
 */
void closeFile(FILE *file)
{
    if (fclose(file)) {
        endProgramAbruptly("\nA Problem Occurred while closing a file\n");
     }
}

/**
 * @brief Reserves memory for new node
 * @returns a pointer to the newly allocated node if memory IS successfully reserved
 * @returns `NULL` if memory is NOT reserved
 */
struct Node *allocateMemoryForNode()
{
    struct Node *node =
        (struct Node *)malloc(sizeof(struct Node));  ///< pointer to the node
    if (node != NULL)
    {
        return node;
    }
    endProgramAbruptly(
        "\nA problem occurred while reserving memory for the structure\n");
    return NULL;
}

/**
 * @brief Writes contents of tree to another file alphabetically
 * @param node pointer to current node
 * @param file pointer to file
 * @returns void
 */
void writeContentOfTreeToFile(struct Node *node, FILE *file)
{
    static uint64_t i = 1;  ///< for word numbering in the write file
    if (node != NULL)       // checks if the node is valid
    {
        writeContentOfTreeToFile(
            node->left,
            file);  // calls `writeContentOfTreeToFile` for left sub tree
        fprintf(file, "%-5lu \t %-9lu \t %s \n", i++, node->frequency,
                node->word);  // prints the word number, word frequency and word
                              // in tabular format to the file
        writeContentOfTreeToFile(
            node->right,
            file);  // calls `writeContentOfTreeToFile` for right sub tree
    }
}

/**
 * @brief Adds word (node) to the correct position in tree
 * @param word word to be inserted in to the tree
 * @param currentNode node which is being compared
 * @returns a pointer to the root node
 */
struct Node *addWordToTree(char *word, struct Node *currentNode)
{
    if (currentNode == NULL)  // checks if `currentNode` is `NULL`
    {
        struct Node *currentNode =
            allocateMemoryForNode();  // allocates memory for new node
        currentNode->word = getPointerToWord(word);  // stores `word` in memory
        currentNode->frequency = 1;  // initializes the word frequency to 1
        currentNode->left = NULL;    // sets left node to `NULL`
        currentNode->right = NULL;   // sets right node to `NULL`
        return currentNode;          // returns pointer to newly created node
    }

    int64_t compared = strcmp(word, currentNode->word);  ///< holds compare state

    if (compared > 0) {
        currentNode->right = addWordToTree(word,
            currentNode->right);  // adds `word` to right sub tree if `word` is
                                  // alphabetically greater than `currentNode->word`
    }
    else if (compared < 0) {
        currentNode->left = addWordToTree(word,
            currentNode->left);  // adds `word` to left sub tree if `word` is
                                 // alphabetically less than `currentNode->word`
    }
    else {
        currentNode->frequency++; // increments `currentNode` frequency if `word` is the same as `currentNode->word`
    }

    return currentNode; // returns pointer to current node
}

/**
 * @brief Reads words from file to tree
 * @param file file to be read from
 * @param root root node of tree
 * @returns a pointer to the root node
 */
struct Node *readWordsInFileToTree(FILE *file, struct Node *root)
{
    // longest english word = 45 chars
    // +1 for '\0' = 46 chars
    char *inputString =
        (char *)malloc(46 * sizeof(char));  ///< pointer to the input string

    char inputChar;                ///< temp storage of characters
    bool isPrevCharAlpha = false;  ///< bool to mark the end of a word
    uint8_t pos = 0;  ///< position in inputString to place the inputChar

    while ((inputChar = fgetc(file)) != EOF)
    {
        if (pos > 0)
            isPrevCharAlpha = isalpha(inputString[pos - 1]);

        // checks if character is letter
        if (isalpha(inputChar))
        {
            inputString[pos++] = tolower(inputChar);
            continue;
        }

        // checks if character is ' or - and if it is preceded by a letter eg
        // yours-not, persons' (valid)
        if ((inputChar == '\'' || inputChar == '-') && isPrevCharAlpha)
        {
            inputString[pos++] = inputChar;
            continue;
        }

        // makes sure that there is something valid in inputString
        if (pos == 0)
            continue;

        // if last character is not letter and is not ' then replace by \0
        if (!isPrevCharAlpha && inputString[pos - 1] != '\'')
            pos--;
        inputString[pos] = '\0';
        pos = 0;
        isPrevCharAlpha = false;
        root = addWordToTree(inputString, root);
    }

    // this is to catch the case for the EOF being immediately after the last
    // letter or '
    if (pos > 0)
    {
        if (!isPrevCharAlpha && inputString[pos - 1] != '\'')
            pos--;
        inputString[pos] = '\0';
        root = addWordToTree(inputString, root);
    }

    free(inputString);
    return root;
}

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test()
{
    struct Node *root = NULL;  ///< pointer to the root node
    FILE *file = NULL;         ///< pointer to the file

    file = fopen("file.txt", "w");  // creates test file in write mode

    fprintf(file,
            "hey_this, is a. test input \n to a_file");  // writes test data to
                                                         // test file

    closeFile(file);                // closes test file
    file = fopen("file.txt", "r");  // reopens test file in read mode

    root = readWordsInFileToTree(file,
                                 root);  // reads words from test file to tree

    // Tests to check if words were added to correct position in tree and also
    // if their frequencies were added correctly
    assert(strcmp(root->word, "hey") == 0);
    assert(root->frequency == 1);
    assert(strcmp(root->left->word, "a") == 0);
    assert(root->left->frequency == 2);
    assert(strcmp(root->right->word, "this") == 0);
    assert(strcmp(root->left->right->word, "file") == 0);
    assert(strcmp(root->right->left->word, "is") == 0);

    closeFile(file);     // closes test file
    remove("file.txt");  // deletes test file from storage

    file = fopen("wordcount.txt", "a");  // creates write file
    fprintf(file, "%-5s \t %9s \t %s \n", "S/N", "FREQUENCY",
            "WORD");  // prints the heading to `wordcount.txt`
    writeContentOfTreeToFile(
        root, file);  // writes content of tree to file (`wordcount.txt`)

    // Here is how the output to `wordcount.txt` should look like
    char *correctString =
        "S/N   	 FREQUENCY 	 WORD \n"
        "1     	 2         	 a \n"
        "2     	 1         	 file \n"
        "3     	 1         	 hey \n"
        "4     	 1         	 input \n"
        "5     	 1         	 is \n"
        "6     	 1         	 n \n"
        "7     	 1         	 test \n"
        "8     	 1         	 this \n"
        "9     	 1         	 to \n";

    int16_t inputChar;  // holds the current character in `wordcount.txt`
    uint64_t i = 0;     // holds the current index in `correctString`

    // Checks if the content in `wordcount.txt` is as expected (the same as in
    // `correctString`)
    while ((inputChar = fgetc(file)) != EOF) {
        assert(inputChar == correctString[i++]);
    }

    closeFile(file);          // closes `wordcount.txt`
    remove("wordcount.txt");  // deletes `wordcount.txt`

    freeTreeMemory(root);  // frees memory taken up by the tree
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main()
{
    test();  // run self-test implementations
    return 0;
}
