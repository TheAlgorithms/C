
/* Double Linked List (Basic Operations) - Program to create a memory efficient version of Doubly Linked List by storing XOR of next and previous nodes addresses  */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

/* Assume that the data portion of each node consists of ONLY an integer.*/

struct Node
{
	int data;
	struct Node* next_XOR_Prev; /* XOR of next and previous node */
};

/* returns XORed value of the node addresses */
struct Node* XOR (struct Node *a, struct Node *b)
{
	return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}

/* Insert a node at the beginning of the 
XORed linked list and makes the newly
inserted node as head */
void insert(struct Node **head_ref, int data)
{
	/* Allocate memory for new node */
	struct Node *new_node = (struct Node *) malloc (sizeof (struct Node) );
	new_node->data = data;

	/* Since new node is being inserted at the 
	beginning, next_XOR_Prev of new node will always be
	XOR of current head and NULL */
	new_node->next_XOR_Prev = *head_ref;

	/* If linked list is not empty, then next_XOR_Prev of 
	current head node will be XOR of new node
	and node next to current head */
	if (*head_ref != NULL)
	{
		/* *(head_ref)->next_XOR_Prev is XOR of NULL and next. 
		 So if we do XOR of it with NULL, we get next */
		(*head_ref)->next_XOR_Prev = XOR(new_node, (*head_ref)->next_XOR_Prev);
	}

	*head_ref = new_node;
}

void printList (struct Node *head)
{
	struct Node *curr = head;
	struct Node *prev = NULL;
	struct Node *next;

	printf ("\n Following are the nodes of Linked List: \n");

	while (curr != NULL)
	{
		// print current node
		printf ("%d ", curr->data);

		/* get address of next node: curr->next_XOR_Prev is 
		   next^prev, so curr->next_XOR_Prev^prev will be
		   next^prev^prev which is next*/
		next = XOR (prev, curr->next_XOR_Prev);

		prev = curr;
		curr = next;
	}
}

int main ()
{
	/* Create following Doubly Linked List
    head-->40<-->30<-->20<-->10 */
    struct Node *test1_head = NULL;
    insert(&test1_head, 10);
    insert(&test1_head, 20);
    insert(&test1_head, 30);
    insert(&test1_head, 40);
 
    printList (test1_head);
	
	/* Create following Doubly Linked List
    head-->22<-->10 */
    struct Node *test2_head = NULL;
    insert(&test2_head, 10);
    insert(&test2_head, 22);
 
    printList (test2_head);
	return 0;
}
