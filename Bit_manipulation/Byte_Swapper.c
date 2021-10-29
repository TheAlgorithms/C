/* C program to swap bytes/words of integer number.*/

#include <stdio.h>

int main()
{
    unsigned int data = 0x1234;
    printf("\ndata before swapping : %04X", data);

    data = ((data << 8) & 0xff00) | ((data >> 8) & 0x00ff);

    printf("\ndata after swapping  : %04X \n", data);

    return 0;
}
