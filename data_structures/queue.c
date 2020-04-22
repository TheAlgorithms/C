////////////////////////////////////////////////////////////////////////////////
//INCLUDES
#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////
//MACROS: CONSTANTS

////////////////////////////////////////////////////////////////////////////////
//DATA STRUCTURES
struct node {
    int data;
    struct node* next;
    struct node* pre;
} *head, *tail, *tmp;

////////////////////////////////////////////////////////////////////////////////
//GLOBAL VARIABLES
int count;

////////////////////////////////////////////////////////////////////////////////
//FORWARD DECLARATIONS
void create();
void enque(int x);
int deque();
int peek();
int size();
int isEmpty();

////////////////////////////////////////////////////////////////////////////////
//MAIN ENTRY POINT

int main(int argc, char const *argv[]) {

    create();
    enque(5);


	return 0;
}


void create() {
    head = NULL;
    tail = NULL;
}

/**
 * Puts an item into the Queue.
 */
void enque(int x) {
    if(head == NULL) {
        head = (struct node *)malloc(1 * sizeof(struct node));
        head->data = x;
        head->pre = NULL;
        tail = head;
    } else {
        tmp = (struct node *)malloc(1 * sizeof(struct node));
        tmp->data = x;
        tmp->next = tail;
        tail = tmp;
    }
}

/**
 * Takes the next item from the Queue.
 */
int deque() {
    int returnData = 0;
    if(head == NULL) {
        printf("ERROR: Deque from empty queue.\n");
        exit(1);
    } else {
        returnData = head->data;
        if(head->pre == NULL)
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
int size() {
    return count;
}