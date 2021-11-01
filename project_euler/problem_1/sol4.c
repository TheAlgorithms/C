/**
 * \file
 * \brief [Problem 1](https://projecteuler.net/problem=1) solution
 *
 * An Efficient code to print all the sum of all numbers that are multiples of 3
 * & 5 below N.
 */

#include <stdio.h>

/** Main function */
int main()
{
    int t;
    printf("Enter number of times you want to try");
    scanf("%d", &t);
    while (t--)
    {
        unsigned long long N, p = 0, sum = 0;
        printf("Enter the value of N ");

        scanf("%lld", &N);  // Take input of N from user
        for (int i = 0; i < N; i++)
        {
            if (i % 3 == 0 || i % 5 == 0)
            {
                sum = sum + i;
            }
        }
        printf("%lld\n", sum);  // print the sum of all numbers that are
                                // multiples of 3 & 5 below N
    }
    return 0;
}
