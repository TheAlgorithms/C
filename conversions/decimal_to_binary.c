#include <stdio.h>
#include <stdlib.h>

#define MAXBITS 100

int main()
{
    // input of the user
    int inputNumber;

    // for the remainder
    int re;

    // contains the bits 0/1
    int bits[MAXBITS];

    // for the loops
    int j;
    int i = 0;

    printf("\t\tConverter Decimal --> Binary\n\n");

    // reads a decimal number from the user.
    printf("\nEnter a positive integer number: ");
    scanf("%d", &inputNumber);

    // make sure the input number is a positive integer.
    if (inputNumber < 0)
    {
        printf("Only positive integers >= 0\n");
        return 1;
    }

    // actual processing
    while (inputNumber > 0)
    {
        // computes the remainder by modulo 2
        re = inputNumber % 2;

        // computes the quotient of division by 2
        inputNumber = inputNumber / 2;

        bits[i] = re;
        i++;
    }

    printf("\nThe number in binary is: ");

    // iterates backwards over all bits
    for (j = i - 1; j >= 0; j--)
    {
        printf("%d", bits[j]);
    }

    // for the case the input number is 0
    if (i == 0)
    {
        printf("0");
    }
    printf("\n");
    return 0;
}
