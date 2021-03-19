#include <stdio.h>
#include <stdlib.h>
  
// linked list node structure
struct node {
  int data;
  struct node *next;
} *head;
 
 
//function to inserts a node in front of a singly linked list 
void insert(int num) {
    //Create a new node
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    
    //assing value(num)
    newNode->data  = num;
    
    //Next pointer of new node will point to head node of linked list
    newNode->next = head;
    
    //head of the list is the new node
    head = newNode;
    
    //printf("Inserted Element : %d\n", num);
}
 
// funtion to check if loop exist
void findloop(struct node *head) {

    struct node *slow, *fast;
    slow = fast = head;
   
    while(slow && fast && fast->next) {
        //Slow pointer will move one node per iteration  
        //Fast pointer will move two nodes per iteration 
        // loop exist if slow and fast pointers are pointing to same node
        slow = slow->next;
        fast  = fast->next->next;
        
        // check for loop
        if (slow == fast) {
           printf("Linked List contains a loop\n");
           return;
        }
    }
    
    printf("No Loop in Linked List\n");
}

// fucntion to prints the linked list from head.
void printLinkedList(struct node *nodePtr) {
  while (nodePtr != NULL) {
     printf("%d", nodePtr->data);
     nodePtr = nodePtr->next;
     if(nodePtr != NULL)
         printf("-->");
  }
}
  
int main() {
    
    head=NULL;
    /* Creating a singly linked List*/
    insert(8);  
    insert(3); 
    insert(2); 
    insert(7);
    insert(9);
     
    //Create loop in linked list
    head->next->next->next->next->next = head->next;
   
 
    findloop(head);
    return 0;
    }
