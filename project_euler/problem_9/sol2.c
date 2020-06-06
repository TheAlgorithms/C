/**
 * \file
 * \brief [Problem 9](https://projecteuler.net/problem=9) solution
 * \author [Krishna Vedala](https://github.com/kvedala)
 *
 Problem Statement:
    A Pythagorean triplet is a set of three natural numbers, \f$a < b < c\f$,
 for which, \f$a^2 + b^2 = c^2\f$. For example, \f$3^2 + 4^2 = 9 + 16 = 25 =
 5^2\f$. There exists exactly one Pythagorean triplet for which \f$a + b + c =
 1000\f$. Find the product abc.


    Given \f$a^2 + b^2 = c^2\f$ and \f$a+b+c = n\f$, we can write:
    \f{eqnarray*}{
        b &=& \frac{n^2 - 2an}{2n - 2a}\\
        c &=& n - a - b
    \f}
 */
#include <stdio.h>
#include <stdlib.h>

/** Main function */
int main(void)
{
    int N = 1000;

    for (int a = 1; a < 300; a++)
    {
        long tmp1 = N * N - 2 * a * N;
        long tmp2 = 2 * (N - a);
        div_t tmp3 = div(tmp1, tmp2);
        int b = tmp3.quot;
        int c = N - a - b;

        if (a * a + b * b == c * c)
        {
            printf("%d x %d x %d = %ld\n", a, b, c, (long int)a * b * c);
            return 0;
        }
    }

    return 0;
}