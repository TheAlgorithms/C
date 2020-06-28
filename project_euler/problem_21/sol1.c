/**
 * \file
 * \brief [Problem 21](https://projecteuler.net/problem=21) solution
 * \author [Krishna Vedala](https://github.com/kvedala)
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * function to return the sum of proper divisors of N
 */
unsigned long sum_of_divisors(unsigned int N)
{
    unsigned long sum = 1 + N; /* 1 and itself are always a divisor */
    /* divisors are symmertically distributed about the square-root */
    for (unsigned int i = 2; i * i < N; i++)
    {
        if ((N % i) != 0)
            /* i is not a divisor of N */
            continue;

        // #ifdef DEBUG
        //         printf("%4d, %4d,", i, N / i);
        // #endif

        sum += i + (N / i);
    }
    // #ifdef DEBUG
    //     printf("\nSum of divisors of %4d: %4d\n", N, sum);
    // #endif
    return sum;
}

/** Main function */
int main(int argc, char **argv)
{
    unsigned long sum = 0;
    unsigned int MAX_N = 500;
    if (argc == 2)
        MAX_N = atoi(argv[1]);

    /*
     * We use an array of flags to check if a number at the index was:
     * not-processed = 0
     * is amicable = 1
     * not amicable = -1
     */
    char *flags = (char *)calloc(MAX_N, sizeof(char));

    clock_t start_time = clock();
    int i;
    /* there are no such numbers till 10. Lets search from there on */
    for (i = 10; i < MAX_N; i++)
    {
        if (flags[i] != 0)
            /* already processed, skip */
            continue;

        unsigned int b = sum_of_divisors(i);
        if (b >= MAX_N)
            flags[i] = -1;
        else if (flags[b] == -1)
            continue;

        unsigned int c = sum_of_divisors(b);
        if (c == i && b != i)
        {
            /* found amicable */
            flags[b] = 1;
            flags[i] = 1;
            sum += b + i;
#ifdef DEBUG
            printf("Amicable: %4d : %4d\n", i, b);
#endif
        }
        else
        {
            flags[i] = -1;
            if (b < MAX_N)
                flags[b] = -1;
        }
    }

    clock_t end_time = clock();

    printf("\nTime taken: %.4g millisecond\n",
           1e3 * (end_time - start_time) / CLOCKS_PER_SEC);
    printf("Sum of all numbers = %lu\n", sum);

    free(flags);
    return 0;
}
