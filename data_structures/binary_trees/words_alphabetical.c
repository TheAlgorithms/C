/**
 * @file
 * @brief Printing the [words contained in a file](http://www.dailyfreecode.com/Code/word-list-reads-text-file-makes-2050.aspx) named `file.txt` in alphabetical
 * order and also their frequencies in to another file "wordcount.txt"
 * @details
 * Given a file (file.txt) containing words (like a publication or a novel),
 * where words are separated by a space, newline, hyphen or underscore.
 * This program prints (writes or outputs) to another file (wordcount.txt),
 * the individual words contained in 'file.txt' with their frequencies (number of occurences)
 * each on a newline and in alphabetical order.
 * This program uses the binary tree data structure to accomplish this task.
 * @author [Randy Kwalar](https://github.com/RandyKdev)
 */

#include <ctype.h>    /// for type checks
#include <stdbool.h>  /// for boolean data type
#include <stdio.h>    /// for IO operations
#include <stdlib.h>   /// for memory allocation
#include <string.h>   /// for string operations
#include <inttypes.h> /// for specific integer types

/**
 * @brief structure defining a node in the binary tree
 */
struct Node
{
    char *word;              ///< the word (value) of the node
    uint64_t frequency;      ///< number of occurences of the word
    struct Node *left;       ///< pointer to the left child node
    struct Node *right;      ///< pointer to the right child node
};

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
        (char *)malloc(46 * sizeof(char));  ///< pointer to input string

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
 * @brief Adds word (node) to the correct position in tree
 * @param word word to be inserted in to the tree
 * @param currentNode node which is being compared
 * @returns a pointer to the root node
 */
struct Node *addWordToTree(char *word, struct Node *currentNode)
{
    if (currentNode == NULL)
    {
        struct Node *currentNode = allocateMemoryForNode();
        currentNode->word = getPointerToWord(word);
        currentNode->frequency = 1;
        currentNode->left = NULL;
        currentNode->right = NULL;
        return currentNode;
    }
    int64_t compared = strcmp(word, currentNode->word);  ///< holds compare state

    if (compared > 0)
        currentNode->right = addWordToTree(word, currentNode->right);
    else if (compared < 0)
        currentNode->left = addWordToTree(word, currentNode->left);
    else
        currentNode->frequency++;

    return currentNode;
}

/**
 * @brief Writes contents of tree to another file alphabetically
 * @param node pointer to current node
 * @param file pointer to file
 * @returns void
 */
void writeContentOfTreeToFile(struct Node *node, FILE *file)
{
    static uint64_t i = 1;  ///< for line numbering in write file
    if (node != NULL)
    {
        writeContentOfTreeToFile(node->left, file);
        fprintf(file, "%-5u \t %-9u \t %s \n", i++, node->frequency,
                node->word);
        writeContentOfTreeToFile(node->right, file);
    }
}

/**
 * @brief Stores word in memory
 * @param word word to be stored in memory
 * @returns a pointer to the newly allocated word
 */
char *getPointerToWord(char *word)
{
    char *string = (char *)malloc((strlen(word) + 1) *
                                  sizeof(char));  ///< pointer to string
    // + 1 is for the '\0' character
    if (string != NULL)
    {
        strcpy(string, word);
        return string;
    }
    endProgramAbruptly(
        "\n A problem occurred while reserving memory for word \n");
    return NULL;
}

/**
 * @brief Reserves memory for new node
 * @returns a pointer to the newly allocated node
 */
struct Node *allocateMemoryForNode()
{
    struct Node *node =
        (struct Node *)malloc(sizeof(struct Node));  ///< pointer to node
    if (node != NULL)
        return node;
    endProgramAbruptly(
        "\n A problem occured while reserving memory for structure \n");
    return NULL;
}

/**
 * @brief Closes file after read or write
 * @param file pointer to file to be closed
 * @returns void
 */
void closeFile(FILE *file)
{
    if (fclose(file))
        endProgramAbruptly(" \n A Problem Occurred while closing a file \n");
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
        free(node->word);  ///< freeing node->word because memory was allocated
                           ///< using malloc
        free(node);  ///< freeing node because memory was allocated using malloc
    }
}

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
 * @brief Main function
 * @returns 0 on exit
 */
int main()
{
    struct Node *root = NULL;  ///< pointer to root node
    FILE *file = NULL;         ///< pointer to file

    file = fopen("file.txt", "r");
    if (file == NULL)
        endProgramAbruptly("file: 'file.txt' not found");

    root = readWordsInFileToTree(file, root);
    closeFile(file);

    file = fopen("wordcount.txt", "a");
    fprintf(file, "%-5s \t %9s \t %s \n", "S/N", "FREQUENCY", "WORD");
    writeContentOfTreeToFile(root, file);
    closeFile(file);

    freeTreeMemory(root);

    return 0;
}
