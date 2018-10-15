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
int x,y,z;
    create();

do{printf("1.enque 2.deque 3.Exit\n");
printf("Enter the option\n"); 
scanf("%d",&z);
switch(z)
{

case 1:printf("Enter the item to enque\n");
	 scanf("%d",&x);
	 enque(x);
	 printf("item %d enqued\n",x);
	  break;
case 2:y=deque();
	 printf("item %d dequed\n",y);
         break;
case 3:printf("Exited");
       exit(0);
default:printf("Entered incorrect option\n");
}}while(1);
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
    int returnData;
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
}

/**
 * Returns the size of the Queue.
 */
int size() {
    return count;
}





































