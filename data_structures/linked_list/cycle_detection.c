#include <stdio.h>
#include <stdlib.h>
  
/* Linked list node structure */
struct node {
  int data;
  struct node *next;
} *head;
 
void initialize(){
    head = NULL;
}
 
/* 
Given a Inserts a node in front of a singly linked list. 
*/
void add(int data) {
   
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->data  = data;
    temp->next = head;
    head = temp;
}
 
void loopdetection(struct node *head) {
    struct node *slow, *fast;
    slow = fast = head;
   
    while(slow && fast && fast->next) {
        slow = slow->next;
        fast  = fast->next->next;
        if (slow == fast) {
           printf("Loop exists\n");
           return;
        }
    }
    printf("No loop\n");
}
/*
 Printing the linked list
*/
void printLinkedList(struct node *nodePtr) {
  while (nodePtr != NULL) {
     printf("%d", nodePtr->data);
     nodePtr = nodePtr->next;
     if(nodePtr != NULL)
         printf("-->");
  }
}
  
int main() {
    initialize();
    add(5);  
    add(4); 
    add(6); 
    add(1);
    add(10);
     
    /* Creating loop in list */
    head->next->next->next->next->next = head->next;
 
    loopdetection(head);
    return 0;
}
