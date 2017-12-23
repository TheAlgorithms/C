/*
    author: Christian Bender

    This is the main-program for testing the stack.
*/

#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main()
{

    int MAX = 55;
    int field[MAX];
    int i; /* for the loop */
    int *pInt = NULL;

    initStack();

    /* pushs some elements onto stack */
    for (i = 0; i < MAX; i++)
    {
        field[i] = i;
        push((field + i));  // HERE
    }

    /* pops the elements from the stack and print that out.*/
    for (i = 0; i < MAX; i++)
    {
        pInt = pop();   /* fetch next integer */
       
        printf("%d\n", *pInt); /* print value */
    }

   

    return EXIT_SUCCESS;
}