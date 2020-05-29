/*
    author: Christian Bender

    This header represents the public stack-interface.
    The stack is generic and self growing.
*/

#ifndef __STACK__
#define __STACK__

/*
    initStack: initializes the stack with a capacity of 10 elements.
*/
void initStack();

/*
    push: pushs the argument onto the stack
*/
void push(void *object);

/*
    pop: pops the top element of the stack from the stack.
    assumes: stack not empty.
*/
void *pop();

/*
    size: gets the number of elements of the stack.
*/
int size();

/*
    isEmpty(): returns 1 if stack is empty otherwise 0.
*/
int isEmpty();

/*
    top: returns the top element from the stack without removing it.
*/
void *top();

#endif