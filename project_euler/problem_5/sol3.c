/**
 * \file
 * \brief [Problem 5](https://projecteuler.net/problem=5) solution (Fastest).
 * @details Solution is the LCM of all numbers between 1 and 20.
 *
 * \see Slowest: problem_5/sol1.c
 * \see Slower: problem_5/sol2.c
 */
#include <stdio.h>

/** Compute [Greatest Common Divisor
 * (GCD)](https://en.wikipedia.org/wiki/Greatest_common_divisor) of two numbers
 * using Euclids algorithm
 * @param a first number
 * @param b second number
 * @return GCD of `a` and `b`
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
 * @param a first number
 * @param b second number
 * @return LCM of `a` and `b`
 */
unsigned long lcm(unsigned long a, unsigned long b)
{
    unsigned long long p = (unsigned long long)a * b;
    return p / gcd(a, b);
}

/** Main function
 * @returns 0 on exit
 */
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
