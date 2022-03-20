/*------------------Trie Data Structure----------------------------------*/
/*-------------Implimented for search a word in dictionary---------------*/

/*-----character - 97 used for get the character from the ASCII value-----*/

// needed for strnlen
#define _POSIX_C_SOURCE 200809L

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

/*--Node in the Trie--*/
struct trie {
    struct trie *children[ALPHABET_SIZE];
    bool end_of_word;
};


/*--Create new trie node--*/
int trie_new (
    struct trie ** trie
)
{
    *trie = calloc(1, sizeof(struct trie));
    if (NULL == *trie) {
        // memory allocation failed
        return -1;
    }
    return 0;
}


/*--Insert new word to Trie--*/
int trie_insert (
    struct trie * trie,
    char *word,
    unsigned word_len
)
{
    int ret = 0;

    // this is the end of this word; add an end-of-word marker here and we're
    // done.
    if (0 == word_len) {
        trie->end_of_word = true;
        return 0;
    }

    // if you have some more complex mapping, you could introduce one here. In
    // this easy example, we just subtract 'a' (97) from it, meaning that 'a' is 0,
    // 'b' is 1, and so on.
    const unsigned int index = word[0] - 'a';

    // this index is outside the alphabet size; indexing this would mean an
    // out-of-bound memory access (bad!). If you introduce a separate map
    // function for indexing, then you could move the out-of-bounds index in
    // there.
    if (ALPHABET_SIZE <= index) {
        return -1;
    }

    // The index does not exist yet, allocate it.
    if (NULL == trie->children[index]) {
        ret = trie_new(&trie->children[index]);
        if (-1 == ret) {
            // creating new trie node failed
            return -1;
        }
    }
    
    // recurse into the child node
    return trie_insert(
        /* trie = */ trie->children[index],
        /* word = */ word + 1,
        /* word_len = */ word_len - 1
    );
}


/*--Search a word in the Trie--*/
int trie_search(
    struct trie * trie,
    char *word,
    unsigned word_len,
    struct trie ** result
)
{
    // we found a match
    if (0 == word_len) {
        *result = trie;
        return 0;
    }

    // same here as in trie_insert, if you have a separate index mapping, add
    // it here. In this example, we just subtract 'a'.
    const unsigned int index = word[0] - 'a';

    // This word contains letters outside the alphabet length; it's invalid.
    // Remember to do this to prevent buffer overflows.
    if (ALPHABET_SIZE <= index) {
        return -1;
    }

    // No match
    if (NULL == trie->children[index]) {
        return -1;
    }

    // traverse the trie
    return trie_search(
        /* trie = */ trie->children[index],
        /* word = */ word + 1,
        /* word_len = */ word_len - 1,
        /* result = */ result
    );
}

/*---Return all the related words------*/
void trie_print (
    struct trie * trie,
    char prefix[],
    unsigned prefix_len
)
{

    // An end-of-word marker means that this is a complete word, print it.
    if (true == trie->end_of_word) {
        printf("%.*s\n", prefix_len, prefix);
    }

    // However, there can be longer words with the same prefix; traverse into
    // those as well.
    for (int i = 0; i < ALPHABET_SIZE; i++) {

        // No words on this character
        if (NULL == trie->children[i]) {
            continue;
        }

        // If you have a separate index mapping, then you'd need the inverse of
        // the map here. Since we subtracted 'a' for the index, we can just add
        // 'a' to get the inverse map function.
        prefix[prefix_len] = i + 'a';

        // traverse the print into the child
        trie_print(trie->children[i], prefix, prefix_len + 1);
    }
}


/*------Demonstrate purposes uses text file called dictionary -------*/

int main() {
    int ret = 0;
    struct trie * root = NULL;
    struct trie * trie = NULL;
    char word[100] = {0};

    // Create a root trie
    ret = trie_new(&root);
    if (-1 == ret) {
        fprintf(stderr, "Could not create trie\n");
        exit(1);
    }

    // open the dictionary file
    FILE *fp = fopen("dictionary.txt", "r");
    if (NULL == fp) {
        fprintf(stderr, "Error while opening dictionary file");
        exit(1);
    }

    // insert all the words from the dictionary
    while (1 == fscanf(fp, "%100s\n", word)) {
        ret = trie_insert(root, word, strnlen(word, 100));
        if (-1 == ret) {
            fprintf(stderr, "Could not insert word into trie\n");
            exit(1);
        }
    }

    while (1) {
        printf("Enter keyword: ");
        if (1 != scanf("%100s", word)) {
            break;
        }

        printf(
            "\n==========================================================\n");
        printf("\n********************* Possible Words ********************\n");

        ret = trie_search(root, word, strnlen(word, 100), &trie);
        if (-1 == ret) {
            printf("No results\n");
            continue;
        }

        trie_print(trie, word, strnlen(word, 100));

        printf("\n==========================================================\n");
    }
}
