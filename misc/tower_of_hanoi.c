#include <stdio.h>

// Function for Tower of Hanoi algorithm

void TOH(int n, int A, int B, int C)   // Taking n discs named A, B and C as the parameters of the function
{
    if(n > 0)    // only when n is greater than 0
    {
        TOH(n-1, A, C, B);      // n-1 disks in the tower
        printf("Moving disc from rod %d to %d\n",A,C);    // printing statements for the discs when it moves from one position to other
        TOH(n-1, B, A, C);      // recursive call of the tower and hanoi function
    }
}

int main()
{
    TOH(3,1,2,3);
}
