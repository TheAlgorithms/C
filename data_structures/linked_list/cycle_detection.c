/* Singly linked list--Program to check whether a loop exists or not in a singly linked list(Variable head is globally declared)*/

#include <stdio.h>
#include <stdlib.h>
  
/* Assume that the data portion of each node consists of ONLY an integer.*/
struct node 
{
  int data;
  struct node *next;
};

struct node *head=NULL;
/* head is global variable and need not be passed to any function. Any changes made to head variable by any of the functions in the program will be reflected in the entire program */

/*This function is responsible for inserting the data into each node of linked list*/
void add(int data) 
{
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->data  = data;
    temp->next = head;
    head = temp;
}

/*This function is responsible for detecting the loop in linked list*/ 
void loopdetection(struct node *head)
{
    struct node *slow, *fast;
    slow = fast = head;
   
    while(slow && fast && fast->next) 
    {
        slow = slow->next;
        fast  = fast->next->next;
        if (slow == fast)
        {
           printf("Loop exists\n");
           return;
        }
    }
    printf("No loop\n");
}

/*This function is responsible for printing the data value of each node in linked list*/
void printLinkedList(struct node *nodePtr) 
{
  while (nodePtr != NULL) 
  {
     printf("%d", nodePtr->data);
     nodePtr = nodePtr->next;
     if(nodePtr != NULL)
         printf("-->");
  }
}

/*Main function which returns 0 on exit*/ 
int main()
{
    add(5);  
    add(4); 
    add(6); 
    add(1);
    add(10);
     
    /* Creating loop in list for testing*/
    head->next->next->next->next->next = head->next;
 
    loopdetection(head);
    return 0;
}
