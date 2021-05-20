/**
 * @file
 * @brief Code to Reverse contents of a [Singly linked list](https://en.wikipedia.org/wiki/Linked_list)
 *
 * @details
 * A Singly linked list is a Data Structure, which is list/sequence
 * of components, that store data. Each component in the Linked list
 * consists of some Data (Here in this implementation we store only one
 * one variable and a pointer to next component but in general we can 
 * store more than one) in the form of variables.
 * 
 * Here in this program we primarily implement a code to reverse the contents of
 * a given singly linked list.Sample test cases are added at end of this file
 * 
 * In this implementation, the functions of pushing variables 
 * into the list,Reversing the given list, printing the list,
 * and an example showing what input is and how the outcome is!
 *  
 * @author    [Sai Akash Janapati](http://github.com/Sai-Akash2009Janapati)
 * 
 * */

#include <stdio.h>
#include <stdlib.h>
 
/**
 * @brief Struct of Link list node
 * */
struct Node {
    int data;
    struct Node* next;
};

/**
 * @brief           Given contents of linked list will be reversed
 * @param  head_ref a pointer to the pointer of head node/initial node
 *                  so that we can change the contents of it
 * @returns         This returns void
 * */
void reverse(struct Node** head_ref);

/**
 * @brief           Pushes the new data we want to push to the existing linked list
 * @param  head_ref Pointer to the pointer of Head node/initial node
 * @param  new_data The new data that should be pushed to the List
 * @returns         void
 * 
 * */
void push(struct Node** head_ref, int new_data);

/**
 * @brief       Prints the data present in a linked list
 * @param head  Pointer to the initial node/head node of linked list
 * @returns    void
 * 
 * */
void print_List(struct Node* head);

/**
 * @brief   Tests the functionalities implemented in this file
 * @param   void / No parameters
 * @returns void
 * */
void test();

/* Driver code*/
int main()
{
    test();

    return 0;
}


/**
 * @brief           Given contents of linked list will be reversed
 * @param  head_ref a pointer to the pointer of head node/initial node
 *                  so that we can change the contents of it
 * @returns         This returns void
 * */

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
 
/**
 * @brief           Pushes the new data we want to push to the existing linked list
 * @param  head_ref Pointer to the pointer of Head node/initial node
 * @param  new_data The new data that should be pushed to the List
 * @returns         void
 * 
 * */

void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;

}
 
/**
 * @brief       Prints the data present in a linked list
 * @param head  Pointer to the initial node/head node of linked list
 * @returns    void
 * 
 * */

void print_List(struct Node* head)
{
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}
 

/**
 * @brief   Tests the functionalities implemented in this file
 * @param   void / No parameters
 * @returns void
 * */
void test()
{
    int n;
    struct Node * head = NULL; //Initially starting from zero elements

    printf("Enter the number of elements you want to push into Linked list :");
    scanf("%d",&n);

    for(int i = 0;i < n;i++){
        int x;
        scanf("%d",&x);
        push(&head,x);
    }

    printf("Given Linked list is :\n");
    print_List(head);

    reverse(&head);
    printf("\nReversed Linked list is:\n");
    print_List(head);
}


/* Tests 
************************************************
Input-1 :
4
2 4 105 8
Linked list : 8 105 4 2 (As we are pushing at front every time)
Output-1 :
 2 4 105 8

*************************************************
Input-2 : 
5
1 3 5 7 10
Linked list :10 7 5 3 1 (As we are pushing at front every time)
Output-2 :
 1 3 5 7 10

**************************************************
