#include <stdio.h>

/*
gcc 64 bit int size is 4 bytes

compliment operator table (1's compliment)
~1 = 0 
~0 = 1
*/

int main()
{
    int a = 15; /* 15 = 0000 0000 0000 0000 0000 0000 0000 1111 */

    int c = -1; /* -1 = 1111 1111 1111 1111 1111 1111 1111 1111*/

    /* Negative numbers are represented in 2's compliment form.*/

    printf("Value of ~a is %d\n", ~a); /* -16 = 1111 1111 1111 1111 1111 1111 1111 0000 */
    printf("Value of ~c is %d\n", ~c); /* 0 = 0000 0000 0000 0000 0000 0000 0000 0000*/
    return 0;
}