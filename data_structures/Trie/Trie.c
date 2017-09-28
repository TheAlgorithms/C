/*------------------Trie Data Structure----------------------------------*/
/*-------------Implimented for search a word in dictionary---------------*/

/*-----character - 97 used for get the character from the ASCII value-----*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

/*--Node in the Trie--*/
typedef struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    char character;
    bool isEndOfWord;
    
} TrieNode;

/*--Create new node--*/
TrieNode *createTrieNode() 
{	
	TrieNode *node;
    node = malloc(sizeof(TrieNode));
	node->isEndOfWord = false;
    int i = 0;
    while(i<ALPHABET_SIZE){
        node->children[i] = NULL;
        i++;
    }
    return node; 
}

/*--Insert new word to Trie--*/
void insert(TrieNode *root,char *word) 
{
	/*----Addition of the word done by recurcively----*/
	
	//Check wheather word character pointer is NULL  
	if((strlen(word)-1) != 0)	
	{
		char character = *word;
		if(root->children[character-97] == NULL)
		{
			TrieNode *node = NULL;
			node = createTrieNode();
			node->character = character;
			root->children[character-97] = node;
		}
            word++;
            insert(root->children[character-97],word);
	}
	else
	{
		root->isEndOfWord = true;
	}
	return;
}

/*--Search a word in the Trie--*/
TrieNode *search( TrieNode *root, char *word)
{
	TrieNode *temp;
	while(*word != '\0')
	{
		char character = *word;
		if(root->children[character - 97] != NULL)
		{
			temp = root->children[character-97];
			word++;
			root = temp;
		}
		else
		{
			printf("No possible words!!\n");
			return NULL;
		}
	}
	return root;
}

/*---Print a word in the array--*/
void printArray(char chars[], int len) 
{
	  int i;
	  for (i=0; i<len; i++) 
	  {
		printf("%c", chars[i]);
	  }
	  printf("\n");
}

/*---Return all the related words------*/
void printPathsRecur(TrieNode* node, char prefix[], int filledLen) 
{
	  if (node==NULL) return;

	  prefix[filledLen] = node->character;
	  filledLen++;

	  if (node->isEndOfWord) 
	  {
		printArray(prefix, filledLen);
	  }

	  int i ;
	  for(i=0;i<ALPHABET_SIZE;i++)
	  {
		printPathsRecur(node->children[i], prefix, filledLen);
	  }
}

/*--Travel through the Trie and return words from it--*/
void traverse(char prefix[], TrieNode *root) 
{
    TrieNode *temp = NULL;
    temp = search(root,prefix);
    int j=0;
    while(prefix[j]!='\0')
    {
        j++;
    }
	printPathsRecur(temp,prefix,j-1);
}

/*------Demonstrate purposes uses text file called dictionary -------*/

#define NUMBER_OF_WORDS (354935)
#define INPUT_WORD_SIZE (100)

/*----Get input from the user------*/
char *receiveInput(char *s)
{
    scanf("%99s", s);
    return s;
}

int main() 
{
	//Read the file dictionary
    int word_count = 0;
    char* words[NUMBER_OF_WORDS];
    FILE *fp = fopen("dictionary.txt", "r");
    
    if (fp == 0)
    {
        fprintf(stderr, "Error while opening dictionary file");
        exit(1);
    }
    
    words[word_count] = malloc(INPUT_WORD_SIZE);
    
    while (fgets(words[word_count], INPUT_WORD_SIZE, fp)) 
    {
        word_count++;
        words[word_count] = malloc(INPUT_WORD_SIZE);
    }


    //Push the words in to Trie 
    TrieNode *root = NULL;
    root = createTrieNode();
    int i;
    for(i=0;i<NUMBER_OF_WORDS;i++)
    {
      insert(root,words[i]);
    }

    while (1) 
    {
        printf("Enter keyword: ");
        char str[100];
        receiveInput(str);
        printf("\n==========================================================\n");
        printf("\n********************* Possible Words ********************\n");
 
       //Find the word through the Trie
        traverse(str,root);

        printf("\n==========================================================\n");
    }
}
