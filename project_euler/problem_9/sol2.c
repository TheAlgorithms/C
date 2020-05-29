#include <stdio.h>
#include <stdlib.h>

/**
 Problem Statement:
    A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
        a^2 + b^2 = c^2
    For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
    There exists exactly one Pythagorean triplet for which a + b + c = 1000.
    Find the product abc.


    Given a^2 + b^2 = c^2 and a+b+c = n, we can write:
        b = (n^2 - 2*a*n) / (2*n - 2*a)
        c = n - a - b
 **/

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
            printf("%d x %d x %d = %ld\n", a, b, c, (long int) a*b*c);
            return 0;
        }
    }

    return 0;
}