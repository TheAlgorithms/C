/**
 * \file
 * \brief [Problem 5](https://projecteuler.net/problem=5) solution - Naive
 * algorithm (Improved over problem_5/sol1.c)
 * @details Little bit improved version of the naive `problem_5/sol1.c`. Since
 * the number has to be divisable by 20, we can start at 20 and go in 20 steps.
 * Also we don't have to check against any number, since most of them are
 * implied by other divisions (i.e. if a number is divisable by 20, it's also
 * divisable by 2, 5, and 10). This all gives a 97% perfomance increase on my
 * machine (9.562 vs 0.257)
 *
 * \see Slower: problem_5/sol1.c
 * \see Faster: problem_5/sol3.c
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Hack to store divisors between 1 & 20
 */
static unsigned int divisors[] = {
    11, 13, 14, 16, 17, 18, 19, 20,
};

/** Checks if a given number is devisable by every number between 1 and 20
 * @param n number to check
 * @returns 0 if not divisible
 * @returns 1 if divisible
 */
static int check_number(unsigned long long n)
{
    for (size_t i = 0; i < 7; ++i)
    {
        if (n % divisors[i] != 0)
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
    for (unsigned long long n = 20;; n += 20)
    {
        if (check_number(n))
        {
            printf("Result: %llu\n", n);
            break;
        }
    }
    return 0;
}
