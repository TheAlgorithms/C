// A simple C program for traversal of a linked list 
#include <stdio.h> 
#include <stdlib.h> 
  
struct Node { 
    int data; 
    struct Node* next; 
}; 
  
// This function prints contents of linked list starting from 
// the given node 
void printList(struct Node* n) 
{ 
    while (n != NULL) { 
        printf(" %d ", n->data); 
        n = n->next; 
    } 
} 
  
void main() 
{ 
    struct Node *curr,*tmp;  
    curr->data = rand(); // assign data in first node 
    curr->ind = rand()%2; 
    curr->next= NULL;  
	tmp=curr;  
	for(i=2; i<=3; i++)
    {
            curr = (struct Node*)malloc(sizeof(struct Node)); 
   			if(curr == NULL)
            {
                printf(" Memory can not be allocated.");
                break;
            }
            else
            {    
				curr->data = rand(); 
    			curr->ind = rand()%2; 
    			curr->next= NULL;
                tmp->next =curr ;
                tmp = tmp->next; 
			}
	}
   
   
  
   
}
