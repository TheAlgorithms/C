/**
 * \file
 * \brief [Problem 23](https://projecteuler.net/problem=23) solution -
 * optimization using look-up array
 * \author [Krishna Vedala](https://github.com/kvedala)
 *
 * Optimization applied - compute & store abundant numbers once
 * into a look-up array.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef _OPENMP
#include <omp.h>
#endif

/**
 * This is the global array to be used to store a flag to identify
 * if a particular number is abundant (1) or not (0).
 * Using a whole byte to store a binary info would be redundant.
 * We will use each byte to represent 8 numbers by relying on bits.
 * This saves memory required by 1/8
 */
char *abundant_flags = NULL;

/**
 * \returns -1 if N is deficient
 * \returns 1 if N is abundant
 * \returns 0 if N is perfect
 */
char get_perfect_number(unsigned long N)
{
    unsigned long sum = 1;
    char ret = 0;

    for (unsigned long i = 2; i * i <= N; i++)
    {
        if (N % i == 0)
        {
            sum += i;
            unsigned long tmp = N / i;
            if (tmp != i)
            {
                sum += tmp;
            }
        }
    }

    ret = sum == N ? 0 : (sum > N ? 1 : -1);
#ifdef DEBUG
    printf("%5lu: %5lu : %d\n", N, sum, ret);
#endif
    return ret;
}

/**
 * Is the given number an abundant number (1) or not (0)
 */
char is_abundant(unsigned long N)
{
    // return abundant_flags[N >> 3] & (1 << N % 8) ? 1 : 0;
    return abundant_flags[N >> 3] & (1 << (N & 7))
               ? 1
               : 0; /* optimized modulo operation */
}

/**
 * Find the next abundant number after N and not including N
 */
unsigned long get_next_abundant(unsigned long N)
{
    unsigned long i;
    /* keep checking successive numbers till an abundant number is found */
    for (i = N + 1; !is_abundant(i); ++i)
    {
        ;
    }
    return i;
}

/**
 * check if a given number can be represented as a sum
 * of two abundant numbers.
 * \returns 1 - if yes
 * \returns 0 - if not
 */
char is_sum_of_abundant(unsigned long N)
{
    /* optimized logic:
     * i + j = N   where both i and j should be abundant
     * hence we can simply check for j = N - i as we loop through i
     */
    for (unsigned long i = get_next_abundant(1); i <= (N >> 1);
         i = get_next_abundant(i))
    {
        if (is_abundant(N - i))
        {
#ifdef DEBUG
            printf("\t%4lu + %4lu = %4lu\n", i, N - i, N);
#endif
            return 1;
        }
    }
    return 0;
}

/** Main function */
int main(int argc, char **argv)
{
    long MAX_N = 28123; /* Limit of numbers to check */

    unsigned long sum = 0;
    if (argc == 2)
    {
        MAX_N = strtoul(argv[1], NULL, 10);
    }

    /* byte array to store flags to identify abundant numbers
     * the flags are identified by bits
     */
    abundant_flags = (char *)calloc(MAX_N >> 3, 1);
    if (!abundant_flags)
    {
        perror("Unable to allocate memoey!");
        return -1;
    }

#ifdef _OPENMP
    printf("Using OpenMP parallleization with %d threads\n",
           omp_get_max_threads());
#else
    printf("Not using parallleization!\n");
#endif

    clock_t start_time = clock();

    /* Loop to set abundant flags */
    long N;
#ifdef _OPENMP
#pragma omp for schedule(runtime)
#endif
    for (N = 1; N <= MAX_N; N++)
    {
        char ret = get_perfect_number(N);
        if (ret == 1)
        {
            // int byte_offset = N % 8, index = N >> 3;
            int byte_offset = N & 7, index = N >> 3;
#ifdef _OPENMP
#pragma omp critical
#endif
            abundant_flags[index] |= ret << byte_offset;
        }
        // if (i % 100 == 0)
        //     printf("... %5lu: %8lu\r", i, sum);
    }

    clock_t end_time = clock();
    double t1 = 1e3 * (end_time - start_time) / CLOCKS_PER_SEC;
    printf("Time taken to get abundant numbers: %.4g ms\n", t1);

    clock_t t2 = 0;
    long i;
#ifdef _OPENMP
#pragma omp parallel for schedule(runtime) reduction(+ : sum)
#endif
    for (i = 1; i < MAX_N; i++)
    {
        clock_t start_time1 = clock();
        if (!is_sum_of_abundant(i))
        {
            // #ifdef _OPENMP
            // #pragma omp critical
            // #endif
            sum += i;
        }
        clock_t end_time1 = clock();
#ifdef _OPENMP
#pragma omp critical
#endif
        t2 += end_time1 - start_time1;

        printf("... %5lu: %8lu\r", i, sum);
        if (i % 100 == 0)
        {
            fflush(stdout);
        }
    }

#ifdef DEBUG
    putchar('\n');
#endif
    double t22 = 1e3 * t2 / CLOCKS_PER_SEC;
    printf("Time taken for final sum: %.4g ms\nTotal Time taken: %.4g ms\n",
           t22, t1 + t22);
    printf("Memory used: %lu bytes\n", MAX_N >> 3);
    printf(
        "Sum of numbers that cannot be represented as sum of two abundant "
        "numbers : %lu\n",
        sum);

    free(abundant_flags);

    return 0;
}
