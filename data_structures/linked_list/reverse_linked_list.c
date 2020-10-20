/*Program to reverse linked list without using extra space
To reverse the given linked list we will use three extra pointers that will be in the process. The pointers will be previous, next, current.
We will initialize previous and next to NULL initially and current to head of the linked list.
After this, we will iterate until we reach the NULL of the initial (non-reversed linked list). And do the following −
     Before changing next of current, 
	store next node 
	next = curr->next
     Now change next of current 
     This is where actual reversing happens 
 	curr->next = prev 
     Move prev and curr one step forward 
	prev = curr 
	curr = next 
 Example:- Given linked list
 	1->2->3->4->NULL
	current initialize to head and pre vand next to null
	we will iterate until current reach the NULL
	Now next equals to current.next and then change current next to prev and prev to current (NULL<-1->2->3->4->NULL)
	   	   prev  curr next
	     	    |      \  /
	  NULL <----1  ----> 2 ----> 3 ----> 4 ----> NULL
	  current not equal to null iterate again
	     	            prev  curr next
	     	             |      \  /
	  NULL <----1  <---- 2 ----> 3 ----> 4 ----> NULL
	  current not equal to null iterate again
	     	                    prev  curr next
	     	    		     |      \  /
	  NULL <----1  <---- 2 <---- 3 ----> 4 ----> NULL
	  current not equal to null iterate again
	     	                            prev  curr next
	     	    			     |      \  /
	  NULL <----1  <---- 2 ----> 3 <---- 4 ----> NULL
	  Now current equals to null.
	  Now we got our reversed linked list whear head equals to prev:
	  4->3->2->1->NULL 
	  
*/


#include <stdio.h> 
#include <stdlib.h> 

// Link list node
struct Node { 
	int data; 
	struct Node* next; 
}; 

// Function to reverse the linked list
static void reverse(struct Node** head_ref) 
{ 
	// using three pointer to point previous node, current node and next node.
	struct Node* prev = NULL; 
	struct Node* current = *head_ref; 
	struct Node* next = NULL; 
	while (current != NULL) { 
		// Store next 
		next = current->next; 

		// Reverse current node's pointer 
		current->next = prev; 

		// Move pointers one position ahead. 
		prev = current; 
		current = next; 
	} 
	*head_ref = prev; 
} 

// Function to push node in linkedlist
void push(struct Node** head_ref, int new_data) 
{ 
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
	new_node->data = new_data; 
	new_node->next = (*head_ref); 
	(*head_ref) = new_node; 
} 

//  Function to print linked list
void printList(struct Node* head) 
{ 
	struct Node* temp = head; 
	while (temp != NULL) { 
		printf("%d ", temp->data); 
		temp = temp->next; 
	} 
} 

int main() 
{
	// Linked List 1: 20->4->15->85
    	//  making lists
	struct Node* head = NULL; 
	
	//push data in linked list
	push(&head, 20); 
	push(&head, 4); 
	push(&head, 15); 
	push(&head, 85);
	
	//print linked list
	printf("Given Linked List: \n");
	printList(head);
	
	//reverse linked list
	reverse(&head);
	
	//print reversed linked list
	printf("\nReversed Linked List: \n");
	printList(head); 
	getchar(); 
}
