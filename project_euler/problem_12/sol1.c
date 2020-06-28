/**
 * \file
 * \brief [Problem 12](https://projecteuler.net/problem=12) solution
 * \author [Krishna Vedala](https://github.com/kvedala)
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Get number of divisors of a given number
 *
 * If \f$x = a \times b\f$, then both \f$a\f$ and \f$b\f$ are divisors of
 * \f$x\f$. Since multiplication is commutative, we only need to search till a
 * maximum of \f$a=b = a^2\f$ i.e., till \f$\sqrt{x}\f$. At every integer till
 * then, there are eaxctly 2 divisors and at \f$a=b\f$, there is only one
 * divisor.
 */
long count_divisors(long long n)
{
    long num_divisors = 0;

    for (long long i = 1; i < sqrtl(n) + 1; i++)
        if (n % i == 0)
            num_divisors += 2;
        else if (i * i == n)
            num_divisors += 1;

    return num_divisors;
}

/** Main function */
int main(int argc, char **argv)
{
    int MAX_DIVISORS = 500;
    long i = 1, num_divisors;
    long long triangle_number = 1;

    if (argc == 2)
        MAX_DIVISORS = atoi(argv[1]);

    while (1)
    {
        i++;
        triangle_number += i;
        num_divisors = count_divisors(triangle_number);
        if (num_divisors > MAX_DIVISORS)
            break;
    }

    printf("First Triangle number with more than %d divisors: %lld\n",
           MAX_DIVISORS, triangle_number);

    return 0;
}
