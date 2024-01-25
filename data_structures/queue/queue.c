////////////////////////////////////////////////////////////////////////////////
// INCLUDES
#include <stdio.h>
#include<stdlib.h>
////////////////////////////////////////////////////////////////////////////////
// Defination of the node
struct node{
    int data;
    struct node *next;
    struct node *pre;
};
////////////////////////////////////////////////////////////////////////////////
// Declaring head, tail
struct node* head=NULL;
struct node* tail =NULL;
////////////////////////////////////////////////////////////////////////////////
// GLOBAL VARIABLES
int count;

void create()
{
    head = NULL;
    tail = NULL;
}

/**
 * Puts an item into the Queue.
 */
void enque(int x)
{
    if (head == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        head->data = x;
        head->pre = NULL;
        tail = head;
    }
    else
    {   
        struct node* tmp;
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->data = x;
        tmp->next = tail;
        tail = tmp;
    }
}

/**
 * Takes the next item from the Queue.
 */
int deque()
{
    int returnData = 0;
    if (head == NULL)
    {
        printf("ERROR: Deque from empty queue.\n");
        return 0;
    }
    else
    {
        returnData = head->data;
        if (head->pre == NULL)
            head = NULL;
        else
            head = head->pre;
        head->next = NULL;
    }
    return returnData;
}

/**
 * Returns the size of the Queue.
 */
int size() { return count; }


////////////////////////////////////////////////////////////////////////////////
// MAIN ENTRY POINT

int main(int argc, char const *argv[])
{
    create();
    enque(5);

    return 0;
}
