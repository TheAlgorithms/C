/**
 * @file
 * @brief Algorithm to split linkedlist into even and odd linkedlist
 * @details
 * This algorithm traverse through the linked list elements
 * Find the elements divisible by 2 and store them into a different nodes
 * Seperate the other nodes not divisible by 2 into a different nodes
 * @author [Suman Raj](https://github.com/the-suman)
 * Time Complexity: O(N)
 */

#include <assert.h>  /// for assert
#include <stdio.h>   /// for IO operations
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *nxt;
} Node;

/**
 * @brief Utility function to Initialize a given node of linked
 * @details
 * This function takes a node of the linked list
 * Initialize the given node with NULL value
 * @param aa_head the node of the linked list to be initialized
 */
void initialisation(Node **aa_head) { *aa_head = NULL; }

/**
 * @brief Utility function to insert an element into the linked list in serial
 * order
 * @details
 * This function takes an element and insert into the linked list
 * if the node is  null, it creates a new node and return the new created node
 * If the node is not null, it traverse to the last node and add the element to
 * the last node of the linkedlist
 * @param aa_head this is the head node of the linked list
 * @param n the integer data to be inserted into the linked list
 */
void insertion_serial_order(Node **aa_head, int n)
{
    Node *t, *prv, *cur;
    t = (Node *)malloc(sizeof(Node *));
    t->data = n;
    t->nxt = NULL;

    for (cur = *aa_head, prv = NULL; cur; cur = cur->nxt)
    {
        prv = cur;
    }
    t->nxt = cur;
    if (prv != NULL)
    {
        prv->nxt = t;
    }
    else
    {
        *aa_head = t;
    }
}

/**
 * @brief function to split the given linked list into odd and even
 * @details
 * This function takes the head node of the linked list to split
 * Traverse through the linked list
 * Check if the item is divisible by 2 or not
 * Update the received even and odd linked list node
 * Add the even digits to the even list node
 * Add the odd digits to the odd linked list node in serial order
 * @param a_head this is the head node of the linked list to be splitted
 * @param aa_head_odd the head node to store the odd integers after split
 * @param aa_head_even the head node to store the even integers after split
 */
void split(Node *a_head, Node **aa_head_odd, Node **aa_head_even)
{
    Node *cur;
    initialisation(aa_head_even);
    initialisation(aa_head_odd);

    for (cur = a_head; cur; cur = cur->nxt)
    {
        if (cur->data % 2 == 0)
        {
            insertion_serial_order(aa_head_even, cur->data);
        }
        else
        {
            insertion_serial_order(aa_head_odd, cur->data);
        }
    }
}

/**
 * @brief Utility function to display the elements of the linked list
 * @details
 * This function takes the head node of the linked list
 * Traverse through the items of the linked list
 * Display the items with space seperated
 * @param a_head the head node of the linked list
 */
void display(Node *a_head)
{
    Node *temp;
    temp = a_head;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->nxt;
    }
    printf("\n");
}

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test()
{
    int i = 0;
    Node *head = NULL;
    Node *even = NULL;
    Node *odd = NULL;

    initialisation(&head);

    // Insert items into the head node
    for (i = 1; i < 10; i++)
    {
        insertion_serial_order(&head, i);
    }

    // split the linked list
    split(head, &odd, &even);

    // assert if the odd and even node is not null
    assert(odd != NULL);
    assert(even != NULL);

    // assert if the  received node in even list is correct
    Node *temp = even;
    for (i = 2; i < 10 && temp; i += 2)
    {
        assert(i == temp->data);
        temp = temp->nxt;
    }

    // assert if the received node in odd list is correct
    temp = odd;
    for (i = 1; i < 10 && temp; i += 2)
    {
        assert(i == temp->data);
        temp = temp->nxt;
    }

    printf("All test cases have successfully passed!\n");
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
void main()
{
    test();  // run self-test implementations
    return 0;
}
