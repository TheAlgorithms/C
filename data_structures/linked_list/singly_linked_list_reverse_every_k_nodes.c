/* Singly Linked List- Program to reverse every k nodes of singly linked list */

#include <stdio.h>
#include <stdlib.h>

/* Includes structure for a node which can be use to make new nodes of the Linked
  List. It is assumed that the data in nodes will be an integer, though function
  can be modified according to the data type, easily.
*/
struct Node
{
	int data;
	struct Node* next;
};

/* This function is responsible for printing the data value of each node of the singly Linked. */
void printlist(struct Node* head)
{
	struct Node* ptr = head;
	while (ptr)
	{
		printf("%d -> ", ptr->data);
		ptr = ptr->next;
	}

	printf("NULL\n");
}

/* This function is responsible for inserting the data in the singly Linked List. */
void push(struct Node** head, int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = *head;

	*head = newNode;
}

/* This function is responsible for reversing every k nodes in singly Linked List. */
struct Node *reverseingroups(struct Node *head, int k)
{
      struct Node* p=head;
      struct Node* q=NULL;
      struct Node* r=NULL;
    int count=0;
     while(p!=NULL && count<k)
      {
        r=p->next;
        p->next=q;
        q=p;
        p=r;
        count++;
       }
       if(r!=NULL)
        head->next=reverseingroups(r,k);
        return q;
}

/* This is main method returning 0 on exit. */
int main(void)
{
	int keys[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int n = sizeof(keys)/sizeof(keys[0]);

	struct Node *head = NULL;
	for (int i = n - 1; i >=0; i--)
		push(&head, keys[i]);

	head = reverseingroups(head, 3);

	printlist(head);

	return 0;
}
