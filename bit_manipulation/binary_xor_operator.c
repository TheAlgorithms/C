#include <stdio.h>

/*
gcc 64 bit int size is 4 bytes

xor operator table
1^1 = 0 (carry of 1)
1^0 = 1
0^1 = 1
0^0 = 0
*/

int main()
{
    int a = 15; /* 60 = 0000 0000 0000 0000 0000 0000 0000 1111 */
    int b = 13; /* 13 = 0000 0000 0000 0000 0000 0000 0000 1101 */

    int c = -1; /* -1 = 1111 1111 1111 1111 1111 1111 1111 1111*/
    int d = -2; /* -2 = 1111 1111 1111 1111 1111 1111 1111 1110*/
    /* Negative numbers are represented in 2's compliment form.*/

    printf("Value of a ^ b is %d\n", a ^ b); /* 2 = 0000 0000 0000 0000 0000 0000 0000 0010 */
    printf("Value of b ^ c is %d\n", c ^ d); /* 1 = 0000 0000 0000 0000 0000 0000 0000 0001*/
    return 0;
}