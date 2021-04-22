/**
 * @file
 * @author [Ankita Kulkarni](https://github.com/ankitakul)
 * @brief Detect a cycle/loop in a [Singly Linked List](https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/)
 * @descpriton This Algorithm uses two pointers (fast and slow), fast pointer moves 2 nodes at a time and the slow pointer moves 1 node at a time. If at any time if the fast pointer and slow pointer are pointing at the same node, we can say that loop exists. If pointers do not meet, then the linked list does not have a loop.
*/

#include <stdio.h>   /// for IO operations (`printf`)
#include <stdlib.h>  /// for the `malloc` operation
#include <assert.h>  /// for assert
 
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
    struct node* newNode = (struct node*) malloc(sizeof(struct node)); // an object that stores data and a pointer to next object.
    
    // assign value(num)
    newNode->data  = num;
    
    // next pointer of new node will point to head node of linked list
    newNode->next = head;
    
    // head of the list is the new node
    head = newNode;
    
    printf("Inserted Element : %d\n", num);
}
 
/**
 * @brief Checks if a loop exists in the linked list
 * @param head pointer to the first node in the linked list
 * @returns 1 if a loop is detected
 * @returns 0 if loop not detected
*/
int findLoop(struct node *head) {

    // creating slow and fast pointers.
    struct node *slow, *fast;
    slow = fast = head;
   
    while(slow && fast && fast->next) {
        // slow pointer will move one node per iteration  
        // fast pointer will move two nodes per iteration
        // loop exist if slow and fast pointers are pointing to same node
        slow = slow->next;
        fast  = fast->next->next;
        
        // check if the list contains a loop
        if (slow == fast) {
           printf("Linked List contains a loop\n");
           return 1;
        }
    }
    
    printf("No Loop in Linked List\n");
    return 0;
}

/**
 * @brief Test function 
 * @returns void
*/
static void test() {
              
    // this creates a loop in the linked list
    // `head->next->next->next->next->next = head->next;`

    // check if a loop exists
    assert(findLoop(head) ==0);
    
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
     
    test(head);  // run self-test implementations
    return 0;
}
