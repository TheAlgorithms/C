/**
 * \file
 * \brief [Problem 7](https://projecteuler.net/problem=7) solution
 */
#include <stdio.h>
#include <stdlib.h>

/** Main function */
int main(void)
{
    char *sieve;
    size_t i;
    unsigned count = 0;
    size_t n = 1000000;
    const unsigned target = 10001;

    sieve = (char *)calloc(n, sizeof(char));
    for (i = 2; i < n; i++)
    {
        if (!sieve[i])
        {
            size_t j;
            count++;
            if (count == target)
            {
                printf("%lu\n", i);
                break;
            }
            for (j = i * 2; j < n; j += i)
            {
                sieve[j] = 1;
            }
        }
    }
    free(sieve);
    return 0;
}
