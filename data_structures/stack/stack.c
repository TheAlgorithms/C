/*
    author: Christian Bender

    This is the implementation of the (generic) stack.
    The implementation uses the dynamic memory management and the principle
    of data hiding.
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

/*
   actual stack data structure
   This pointer will pointing at the actual field (of void * pointers)
   that represents the stack.
 */
void **array;

/* the current capacity of the stack */
int max = 10;

/* counter variable for counting the elements of the stack. */
int counter = 0;

/*
    offset address
    points at the top element of the stack.
*/
int offset = -1;

void initStack()
{
    array = malloc(sizeof(void *) * max);
    assert(array); /* tests whether pointer is assigned to memory. */
}

/*
    grow: increases the stack by 10 elements.
          This utility function isn't part of the public interface
*/
void grow()
{
    max += 10; /* increases the capacity */

    int i;  // for the loop
    void **tmp = malloc(sizeof(void *) * max);

    /* copies the elements from the origin array in the new one. */
    for (i = 0; i < max - 10; i++)
    {
        *(tmp + i) = *(array + i);
    }
    /*free the memory */
    free(array);
    array = tmp;
}

/* push: pushs the argument onto the stack */
void push(void *object)
{
    assert(object); /* tests whether pointer isn't null */

    if (counter < max)
    {
        offset++; /* increases the element-pointer */

        /*
            moves pointer by the offset address
            pushs the object onto stack
         */
        *(array + offset) = object;

        /* increases the inner counter */
        counter++;
    }
    else /* stack is full */
    {
        grow();       /* lets grow stack */
        push(object); /* recursive call */
    }
}

/*
    pop: pops the top element of the stack from the stack.
*/
void *pop()
{
    void *top = *(array + offset);

    /* check pointers */
    assert(top);

    /* if use the pop-function, stack must not empty. */
    assert(!isEmpty());

    /* decreases the offset address for pointing of
        the new top element */
    offset--;

    /* decreases the inner counter */
    counter--;

    return top;
}

/*
    size: gets the number of elements of the stack.
*/
int size() { return counter; }

/*
    isEmpty(): returns 1 if stack is empty otherwise 0.
*/
int isEmpty() { return counter == 0; }

/*
    top: returns the top element from the stack without removing it.
*/
void *top()
{
    /* offset address points to the top element */
    return array[offset];
}
