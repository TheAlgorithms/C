/**
 * @file hangman.c
 * @brief Hangman: A classic word game(https://en.wikipedia.org/wiki/Hangman_(game))
 * @details Hangman is word guessing game where the program will randomly pick a word 
 * from a word pool and represent it's letter in dashes"_ _ _". The user has to guess 
 * the right word within a particular number of chances.
 * @author [Anindya Sen](https://github.com/anindyasen)
 */
#include "hangman.h"


/**
 * @brief Generate a random index
 *
 * @param low Floor of index
 * @param high Ceiling of index
 * @return Randomly generated index
 */
int gen_index(int low, int high) { 
    srand(time(0));
    
    return ((rand() % (high - low + 1)) + low); 
} 

/**
 * @brief Display hangman game
 *
 * @param wg_cnt No. of wrong guess
 * @param len Length of word
 */
void display(uint8_t wg_cnt, int len){
    int i = 0;
    printf("\033[H\033[J \n");
    printf("GAME START\n");
    printf(" ┏━━━┓\n");
    printf(" ┃   │\n");
    printf(" ┃   %c\n",   wg_cnt<1?' ':'O');
    printf(" ┃  %c%s%c\n",wg_cnt<3?' ':'/', wg_cnt<2?" ":"│", wg_cnt<4?' ':'\\');
    printf(" ┃  %c %c\n", wg_cnt<5?' ':'/',               wg_cnt<6?' ':'\\');
    printf(" ┃\n");
    printf("┏┻━━━━━━━┓\n┃   %d    ┗━┓\n┗━━━━━━━━━━┛\n",(WRONG_GUESS_CNT-wg_cnt));

    for(i=0; i<len;i++) {
        if(final_word[i] == 0){
            printf("_ ");
        }else {
            printf("%c ",final_word[i]);
        }
    }
    printf("\n");
}

/*
 * Hash Table: Implemented as a array of linklist of size 21 (total no. of 
 * alphabet). Each location of the array consists of linklist denoting the 
 * index of that alphabet in the selected word.
 * Eg. if at location 0 of the array there is a linked list like
 * 1-->5-->8. It means that, in the selected word 'a'(idx 0 of array) is
 * present in location 1 5 8 in the selected word
 * */

/**
 * @brief Add node in the beginning of linklist 
 * @param head Address of start of linklist 
 * @param data Data to be stored in linklist
 * @returns `-1` if failure
 * @returns `0` if success
 */
int list_add_start(index_list_t** head, int data){
    index_list_t *newnode = malloc(sizeof(index_list_t));
    
    if (NULL == newnode) {
        return -1;
    }
    newnode->idx = data;
    newnode->next = *head;
    *head = newnode;
    return 0;
}

/**
 * @brief Delete node from the beginnig of linklist 
 * @param head Address of start of linklist 
 * @returns `-1` if ailure
 * @returns `deleted_val` if success, Deleted value
 */
int32_t list_delete_start(index_list_t **head) {
    index_list_t *tmp = NULL;
    if(NULL == *head){
        return -1;
    }
    uint32_t deleted_val = 0;
    tmp = *head;
    *head = tmp->next;
    deleted_val = tmp->idx;
    free (tmp);
    return deleted_val;
}

/**
 * @brief Adding in the hash table
 * @data Hash table key(alphabets)
 * @idx  Hash table vakue(position of alphabet in word)
 */
void hash_insert(char data, int idx){
    data = tolower(data);
    if(-1 == list_add_start(&(ht->tbl[data-97].head), idx)) {
        printf("Insertion in list failed\n");
    }
}

/**
 * @brief Deletion in the hash table
 * @data Hash table key(alphabets)
 * @return if success, deleted value
 * @return -1 if failure
 */
int32_t hash_del(char data){
    data = tolower(data);
    if(!is_empty(data)){
        return (list_delete_start(&ht->tbl[data-97].head));
    }
    return -1;
}

/**
 * @brief Lookup in the hash table
 * @data Hash table key(alphabets)
 * @return 1 if success
 * @return 0 if failure
 */
uint8_t hash_search(char data){
    data = tolower(data);
    if(NULL != ht->tbl[data-97].head){
        return TRUE;
    }
    return FALSE;
}

/**
 * @brief Check hash table location is free
 *
 * @param data Hash table key
 * @return true if empty
 * @return false if non-empty
 */
uint8_t is_empty(char data) {
    data = tolower(data);
    if(NULL == ht->tbl[data-97].head){
        return TRUE;
    }
    return FALSE;
}

/**
 * @brief Main funtion
 * @return 0 on exit
 */
int main(){
    uint8_t c, wrg_guess_cnt = 0;
    uint32_t i=0, len = 0, idx = 0, gidx = 0;

    //Initialization
    //hash table
    ht = malloc(sizeof(hashtable_t));
    if (!ht){
        printf ("failed to malloc hash table\n");
        return 0;
    }
    for(idx=0;idx<26;idx++){
        ht->tbl[idx].head = NULL;
    }
    //initialized with 0
    memset(guessed_letter, 0, (sizeof(uint8_t)*26));
    memset(final_word, 0, (sizeof(uint8_t)*26));
    
    //randomly generating index to select word
    gidx = gen_index(0/*low*/,MAX_WORD_COUNT-1/*high*/);
    printf("%s\n", words[gidx].string);
    len = strlen(words[gidx].string);

    for(i=0; i<len; i++) {
        hash_insert(words[gidx].string[i], i);
    }

    wrg_guess_cnt = WRONG_GUESS_CNT;

    display(0, strlen(words[gidx].string));
    while(len != 0){
        printf("Guess the word\n");
        scanf(" %c",&c);
        c = tolower(c);
        if (c < 'a' || c > 'z'){
            printf("Type letters...\n");
            continue;
        } 
        if(guessed_letter[c-97] == TRUE){
            printf("Letter Already guessed\n");
            continue;
        } else {
            guessed_letter[c-97] = TRUE;
        }

        //check wheather letter present in hash table
        if(TRUE == hash_search(c)){
            while(!is_empty(c)){
              idx = hash_del(c);
              final_word[idx] = c;
              len--;
            }
        }
        else {
            printf("WRONG GUESS...\n");
            if (wrg_guess_cnt != 0) {
                wrg_guess_cnt--;
            }
            else {
                printf("GAME OVER\n");
                return 0;
            }
        }
        display((WRONG_GUESS_CNT - wrg_guess_cnt),strlen(words[gidx].string));
    }
    return 0;
}
