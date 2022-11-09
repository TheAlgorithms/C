#ifndef __HANGMAN_H__
#define __HANGMAN_H__
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "hangman_word_pool.h"
#define TRUE 1
#define FALSE 0

#define WRONG_GUESS_CNT    6

#ifdef WORD_LIST_FILL
#undef WORD_LIST_FILL
#endif
#define WORD_LIST_FILL( str_ ) {\
    .string = str_, \
} \

word_t words[] = {
   WORD_LIST
};

#define MAX_WORD_COUNT  sizeof(words)/sizeof(words[0])

//Hash table related data structure
typedef struct index_list_{
    int idx;
    struct index_list_ *next;
}index_list_t;

typedef struct hashdata_ {
    index_list_t *head;    
}hashdata_t;

typedef struct hashtable_{
    hashdata_t tbl[26];
}hashtable_t;


//insert beginning of linklist
int list_add_start(index_list_t **head, int data);

//delete from begining of the linklist
int32_t list_delete_start(index_list_t **head);

//insert in hash table
void hash_insert(char data, int idx);

//delete in hash table
int32_t hash_del(char data);

//search in hash table
uint8_t hash_search(char data);

uint8_t is_empty(char data);


//Global Variables

//Hash Table
hashtable_t  *ht;
//Array to store words already guessed
uint8_t guessed_letter[26];
//Array to store the guessed word
uint8_t final_word[26];

#endif //__HANGMAN_H__
