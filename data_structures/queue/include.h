//////////////////////////////////////////////////////////////////////////////////////
/// INCLUDES

#include <stdio.h>
#include <stdlib.h>
////////////////////////////////////////////////////////////////////////////////
// DATA STRUCTURES
/**
 * Defining the structure of the node which contains 'data' (type : integer),
 * two pointers 'next' and 'pre' (type : struct node).
 */

struct node
{
    int data;
    struct node *next;
    struct node *pre;
} * head, *tail, *tmp;

////////////////////////////////////////////////////////////////////////////////
// FORWARD DECLARATIONS

void create();
void enque(int x);
int deque();
int peek();
int size();
int isEmpty();
