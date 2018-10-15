/**
 * Kyler Smith, 2017
 * Stack data structure implementation.
 */

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
} *head, *tmp;

////////////////////////////////////////////////////////////////////////////////
//GLOBAL VARIABLES
int count = 0;

////////////////////////////////////////////////////////////////////////////////
//FUNCTION PROTOTYPES
void create();
void push(int x);
int pop();
int peek();
int size();
int isEmpty();

////////////////////////////////////////////////////////////////////////////////
//MAIN ENTRY POINT

int main(int argc, char const *argv[]) {

    int x, y, z;

    create();
   
do{printf("1.Push item to stack 2.Pop item from stack 3.Exit\n");
printf("Enter the option\n"); 
scanf("%d",&z);
switch(z)
{

case 1:printf("Enter the item to push\n");
	 scanf("%d",&x);
	 push(x);
	 printf("Pushed %d to stack\n",x);
	  break;
case 2:y=pop();
	 printf("Poped %d from stack\n",y);
         break;
case 3:printf("Exited");
       exit(0);
default:printf("Entered incorrect option\n");
}}while(1);
	return 0;

}

/**
 * Initialize the stack to NULL.
 */
void create() {
    head = NULL;
}

/**
 * Push data onto the stack.
 */
void push(int x) {
    if(head == NULL) {
        head = (struct node *)malloc(1 * sizeof(struct node));
        head->next = NULL;
        head->pre = NULL;
        head->data = x;
    } else {
        tmp = (struct node *)malloc(1 * sizeof(struct node));
        tmp->data = x;
        tmp->next = NULL;
        tmp->pre = head;
        head = tmp;
    }
    ++count;
}

/**
 * Pop data from the stack
 */
int pop() {
    int returnData;
    if(head == NULL) {
        printf("ERROR: Pop from empty stack.\n");
        exit(1);
    } else {
        returnData = head->data;

        if(head->pre == NULL)
            head = NULL;
        else {
            head = head->pre;
            free(head->next);
        }
    }
    --count;
    return returnData;
}

/**
 * Returns the next value to be popped.
 */
int peek() {
    if(head != NULL)
        return head->data;
    else {
        printf("ERROR: Peeking from empty stack.");
        exit(1);
    }
}

/**
 * Returns the size of the stack.
 */
int size() {
    return count;
}

/**
 * Returns 1 if stack is empty, returns 0 if not empty.
 */
int isEmpty() {
    if(count == 0)
        return 1;
    return 0;
}
