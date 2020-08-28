/**
 * \file
 * \brief [Problem 5](https://projecteuler.net/problem=5) solution - Naive
 * algorithm (slowest)
 *
 * \see Faster: problem_5/sol2.c
 * \see Fastest: problem_5/sol3.c
 */
#include <stdio.h>
#include <stdlib.h>

/** Pretty naive implementation. Just checks every number if it's devisable by 1
 * through 20
 * @param n number to check
 * @returns 0 if not divisible
 * @returns 1 if divisible
 */
static char check_number(unsigned long long n)
{
    for (unsigned long long i = 1; i <= 20; ++i)
    {
        if (n % i != 0)
        {
            return 0;
        }
    }

    return 1;
}

/**
 * @brief Main function
 *
 * @return 0 on exit
 */
int main(void)
{
    for (unsigned long long n = 1;; ++n)
    {
        if (check_number(n))
        {
            printf("Result: %llu\n", n);
            break;
        }
    }

    return 0;
}
