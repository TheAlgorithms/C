#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHAR_SENSITIVE   //
// #define CHAR_INSENSITIVE    //

#ifdef CHAR_SENSITIVE
#define CHARACTER_NO 52
#endif
#ifdef CHAR_INSENSITIVE
#define CHARACTER_NO 26
#endif

struct trie {
    char data;
    struct trie* next[CHARACTER_NO];
    int isEnd;
    int childs;
};
typedef struct trie Trie;

int GetIndex(char ch) {
#ifdef CHAR_INSENSITIVE
    return toupper(ch) - 65;
#elif #defined (CHAR_SENSITIVE)
    if (isupper(ch)) {
        return (ch - 65) + 26;
    } else {
        return (ch - 97);
    }
#else
    return 0;
#endif
}

Trie* CreateNewNode(char ch) {
    Trie* newNode = (void*)malloc(sizeof(Trie));
#ifdef CHAR_INSENSITIVE
    newNode->data = toupper(ch);
#elif #defined (CHAR_SENSITIVE)
    newNode->data = ch;
#endif
    newNode->childs = 0;
    newNode->isEnd = 0;
    for (int i = 0; i < CHARACTER_NO; i++) {
        newNode->next[i] = NULL;
    }
}

Trie* InsertWord(Trie* myTrie, char* word) {
    Trie* current = myTrie;
    while (*word != '\0') {
        int index = GetIndex(*word);
        if (current->next[index] == NULL) {
            current->childs++;
            current->next[index] = CreateNewNode(*word);
        }
        if (*(word + 1) == '\0') {
            current->next[index]->isEnd = 1;
        }
        current = current->next[index];
        word++;
    }
    return myTrie;
}

Trie* DeleteWord(Trie* myTrie, char* word) {
    if (myTrie == NULL) {  // Word Not Found
        return NULL;
    } else {
        char ch = *word;  // Finding by Characters
        if (myTrie->next[GetIndex(ch)] != NULL) {
            myTrie->next[GetIndex(ch)] = DeleteWord(myTrie->next[GetIndex(ch)], word + 1);
            // If Character was Found and was Deleted
            if (myTrie->next[GetIndex(ch)] == NULL) {
                myTrie->childs--;
            }
        }
    }
    // Reached the end of the word and checking
    if (*word == '\0' && myTrie->data != '\0') {
        if (myTrie->isEnd) {
            // Deleting End node
            if (myTrie->childs == 0) {
                free(myTrie);
                return NULL;
            } else {
                myTrie->isEnd = 0;
            }
        }
    }
    // Deleting the Path
    else {
        if (myTrie->childs == 0 && myTrie->isEnd == 0) {
            free(myTrie);
            return NULL;
        }
    }
    return myTrie;
}

int SearchWord(Trie* myTrie, char* word) {
    if (myTrie == NULL) {
        return 0;
    } else {
        if (*word == '\0') {
            return myTrie->isEnd;
        } else {
            return SearchWord(myTrie->next[GetIndex(*word)], word + 1);
        }
    }
}

void AutoComplete(Trie* Root, char* word) {
    int length = strlen(word);
    Trie* Node = Root;
    int i = 0;
    while (*(word + i) != 0) {
        if (Node->next[GetIndex(*(word + i))] != NULL) {
            Node = Node->next[GetIndex(*(word + i))];
        } else {
            return;
        }
        i++;
    }
    // GET TO THE END POINT OF PREFIX STRING AND PRINT ALL
    PrintAll(Node, word - 1, length);
}

void PrintAll(Trie* myTrie, char* word, int length) {
    word[length] = myTrie->data;
    for (int i = 0; i < CHARACTER_NO; i++) {
        if (myTrie->next[i] != NULL) {
            PrintAll(myTrie->next[i], word, length + 1);
        }
    }
    if (myTrie->isEnd) {
        for (int i = 1; i <= length; i++) {
            printf("%c", word[i]);
        }
        printf("\n");
    }
}

void Suggestion(Trie* myTrie, char* buffer, char* word, int length, int misspelled) {
    if (myTrie == NULL || misspelled > 1) {
        return;
    } else {
        buffer[length] = myTrie->data;
        // For printing
        if (*word == '\0') {
            for (int i = 1; i <= length; i++) {
                printf("%c", buffer[i]);
            }
            printf("\n");
        } else {
            // Wrong Charaacters
            if (misspelled == 0) {
                for (int i = 0; i < 26; i++) {
                    if (i != GetIndex(*word)) {
                        Suggestion(myTrie->next[i], buffer, word + 1, length + 1, misspelled + 1);
                    }
                }
            }
            // Correct Character
            Suggestion(myTrie->next[GetIndex(*word)], buffer, word + 1, length + 1, misspelled);
        }
    }
}
