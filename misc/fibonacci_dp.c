// Fibonacci Series using Dynamic Programming

/* Author: Moinak Banerjee(moinak878)
   Date : 1 October ,2019
*/

#include <stdio.h>
#include <stdlib.h>

int fib(int n)
{
    // Out of Range checking
    if (n < 0)
    {
        printf("\nNo Such term !\n");
        exit(0);
    }
    // declaring array to store fibonacci numbers -- memoization
    int *f = (int *)malloc(
        (n + 2) * sizeof(int));  //  one extra to handle edge case, n = 0
    int i;

    /* let 0th and 1st number of the series be 0 and 1*/
    f[0] = 0;
    f[1] = 1;

    for (i = 2; i <= n; i++)
    {
        // Adding the previous 2 terms to make the 3rd term
        f[i] = f[i - 1] + f[i - 2];
    }

    int out = f[n];
    free(f);
    return out;
}

int main(int argc, char *argv[])
{
    int number;

    // Asks for the number/position of term in Fibonnacci sequence
    if (argc == 2)
        number = atoi(argv[1]);
    else
    {
        printf("Enter the value of n(n starts from 0 ): ");
        scanf("%d", &number);
    }

    printf("The nth term is : %d \n", fib(number));

    return 0;
}