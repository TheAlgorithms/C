// C program to reverse a linked list
// For Test cases and their outputs see at end of this file

#include <stdio.h>
#include <stdlib.h>
 
/* Link list node */
struct Node {
    int data;
    struct Node* next;
};
 
/* Function to reverse the linked list */
void reverse(struct Node** head_ref)
{
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next = NULL;
    while (current != NULL) {
        // Store next
        next = current->next;
 
        // Assign's current node's next as Previous node
        current->next = prev;
 
        // Move pointers ahead
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
 
/* Function to push a node at the begining of list*/
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;

}
 
/* Function to print linked list */
void printList(struct Node* head)
{
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}
 
/* Driver code*/
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
 
    push(&head, 2);
    push(&head, 4);
    push(&head, 105);
    push(&head, 8);
 
    printf("Given linked list\n");
    printList(head);
    reverse(&head);
    printf("\nReversed Linked list \n");
    printList(head);
    
}

/* Tests 
************************************************
Input-1 : Push (2, 4, 105, 8)
Linked list : 8 105 4 2 (As we are pushing at front every time)
Output-1 : 2 4 105 8

*************************************************
Input-2 : Push(1, 3, 5, 7)
Linked list : 7 5 3 1 (As we are pushing at front every time)
Output-2 : 1 3 5 7

**************************************************