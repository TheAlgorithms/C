/**
 * @file
 * @author [Ankita Kulkarni](https://github.com/ankitakul)
 * @brief This Algorithm detects a loop in a singly linked list 
*/

#include <stdio.h>  /// for IO operations (`printf`)
#include <stdlib.h> /// for the `malloc` operation
 
/**
* @brief Linked list node structure
*/
struct node {
  int data; //data assigned to the data part of the node
  struct node *next; //pointer to next node in linked list
} *head;
 
 
/**
 * @brief Creates a new node and inserts it in front of a singly linked list
 * @param num data that is assigned to the node
 * @returns void
*/

void insert(int num) {
    // create a new node
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    
    // assign value(num)
    newNode->data  = num;
    
    // next pointer of new node will point to head node of linked list
    newNode->next = head;
    
    //head of the list is the new node
    head = newNode;
    
    //printf("Inserted Element : %d\n", num);
}
 
/**
 * Function findLoop
 * @brief This function checks if a loop exists in the linked list
 * @param head pointer to the first node in linked list
 * @returns void
*/
void findLoop(struct node *head) {

    // creating slow and fast pointers.
    struct node *slow, *fast;
    slow = fast = head;
   
    while(slow && fast && fast->next) {
        //Slow pointer will move one node per iteration  
        //Fast pointer will move two nodes per iteration
        // loop exist if slow and fast pointers are pointing to same node
        slow = slow->next;
        fast  = fast->next->next;
        
        // check if the list contains a loop
        if (slow == fast) {
           printf("Linked List contains a loop\n");
           return;
        }
    }
    
    printf("No Loop in Linked List\n");
}

/**
 * @brief Main function
 * @returns 0 on exit
*/
int main() {
    
    head=NULL; // head is pointing to NULL
    
    // creating a singly linked List
    insert(8);  
    insert(3);
    insert(2);
    insert(7);
    insert(9);
     
    // this creates a loop in the linked list
    // @test comment/uncomment the line below to check if a loop exists or not
    
    head->next->next->next->next->next = head->next;
   
    // check if loop exists
    findLoop(head);
    return 0;
    }
