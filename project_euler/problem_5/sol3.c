/**
 * \file
 * \brief [Problem 5](https://projecteuler.net/problem=5) solution
 */
#include <stdio.h>

/** Compute [Greatest Common Divisor
 * (GCD)](https://en.wikipedia.org/wiki/Greatest_common_divisor) of two numbers
 * using Euclids algorithm
 */
unsigned long gcd(unsigned long a, unsigned long b)
{
    unsigned long r;
    if (a > b)
    {
        unsigned long t = a;
        a = b;
        b = t;
    }
    while ((r = (a % b)))
    {
        a = b;
        b = r;
    }
    return b;
}

/** Compute [Least Common Multiple
 * (LCM)](https://en.wikipedia.org/wiki/Least_common_multiple) of two numbers
 */
unsigned long lcm(unsigned long a, unsigned long b)
{
    unsigned long long p = (unsigned long long)a * b;
    return p / gcd(a, b);
}

/** Main function */
int main(void)
{
    unsigned long ans = 1;
    unsigned long i;
    for (i = 1; i <= 20; i++)
    {
        ans = lcm(ans, i);
    }
    printf("%lu\n", ans);
    return 0;
}
