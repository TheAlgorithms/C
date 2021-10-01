#include <stdio.h>

/*
gcc 64 bit short int size is 2 bytes

When shifting an unsigned value, the >> operator in C is a logical shift. 
When shifting a signed value, the >> operator is an arithmetic shift
*/

int main()
{
    unsigned short a=15;    /* 15 = 0000 1111 */
    unsigned short b=-1;    /* 65535 = 1111 1111 */
    short c=15; /* 15 = 0000 1111 */
    short d=-1; /* -1 = 1111 1111 */
    printf("Value of a is %hu\n",a); /* 15 = 0000 1111 */
    printf("Value of a>>1 is %hu\n", a>>1); /* 7 = 0000 0111 */
    printf("Value of a<<1 is %hu\n", a<<1); /* 30 = 0001 1110 */
    printf("Value of b is %hu\n",b); /* 65535 = 1111 1111 */
    printf("Value of b>>1 is %hu\n", b>>1); /* 32767 = 0111 1111 */
    printf("Value of b<<1 is %hu\n", b<<1); /* 65534 = 1111 1110 */
    printf("Value of c is %hi\n",c); /* 15 = 0000 1111 */
    printf("Value of c>>1 is %hi\n", c>>1); /* 7 = 0000 0111 */
    printf("Value of c<<1 is %hi\n", c<<1); /* 30 = 0001 1110 */
    printf("Value of d is %hi\n",d);    /* -1 = 1111 1111 */
    printf("Value of d>>1 is %hi\n", d>>1); /* -1 = 1111 1111 */
    printf("Value of d<<1 is %hi\n", d<<1); /* -2 = 1111 1110 */
    return 0;
}