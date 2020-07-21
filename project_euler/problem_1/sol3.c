/**
 * \file
 * \brief [Problem 1](https://projecteuler.net/problem=1) solution.
 * This solution is based on the pattern that the successive numbers in the
 * series follow: 0+3,+2,+1,+3,+1,+2,+3.
 *
 * If we list all the natural numbers below 10 that are multiples of 3 or 5,
 * we get 3,5,6 and 9. The sum of these multiples is 23.
 * Find the sum of all the multiples of 3 or 5 below N.
 */
#include <stdio.h>

/** Main function */
int main()
{
    int n = 0;
    int sum = 0;
    int num = 0;
    scanf("%d", &n);

    while (1)
    {
        num += 3;
        if (num >= n)
            break;
        sum += num;
        num += 2;
        if (num >= n)
            break;
        sum += num;
        num += 1;
        if (num >= n)
            break;
        sum += num;
        num += 3;
        if (num >= n)
            break;
        sum += num;
        num += 1;
        if (num >= n)
            break;
        sum += num;
        num += 2;
        if (num >= n)
            break;
        sum += num;
        num += 3;
        if (num >= n)
            break;
        sum += num;
    }

    printf("%d\n", sum);
    return 0;
}