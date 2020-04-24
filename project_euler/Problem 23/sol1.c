#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef _OPENMP
#include <omp.h>
#endif
#include "function_timer.h"

unsigned long MAX_N = 28123;

/**
 * Returns:
 * -1 if N is deficient
 *  1 if N is abundant
 *  0 if N is perfect
 **/
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
                sum += tmp;
        }
    }

    ret = sum == N ? 0 : (sum > N ? 1 : -1);
    // #ifdef DEBUG
    //     printf("%5lu: %5lu : %d\n", N, sum, ret);
    // #endif
    return ret;
}

/**
 * Is the given number an abundant number (1) or not (0)
 **/
unsigned long is_abundant(unsigned long N)
{
    return get_perfect_number(N) == 1 ? 1 : 0;
}

/**
 * Find the next abundant number after N and not including N
 **/
unsigned long get_next_abundant(unsigned long N)
{
    unsigned long i;
    for (i = N + 1; !is_abundant(i); i++)
        ;
    return i;
}

/**
 * check if a given number can be represented as a sum
 * of two abundant numbers.
 * 1 - if yes
 * 0 - if not
 **/
char is_sum_of_abundant(unsigned long N)
{
    /** optimized logic:
     * i + j = N   where both i and j should be abundant
     * hence we can simply check for j = N - i as we loop through i
     **/
    for (unsigned long i = get_next_abundant(1); i <= (N >> 1); i = get_next_abundant(i))
        if (is_abundant(N - i))
        {
#ifdef DEBUG
            printf("\t%4lu + %4lu = %4lu\n", i, N - i, N);
#endif
            return 1;
        }
    return 0;
}

int main(int argc, char **argv)
{
    unsigned long sum = 0;
    if (argc == 2)
        MAX_N = strtoul(argv[1], NULL, 10);

#ifdef _OPENMP
    printf("Using OpenMP parallleization with %d threads\n", omp_get_max_threads());
#else
    printf("Not using parallleization!\n");
#endif

    double total_duration = 0;
    long i;
    function_timer *timer = new_timer();
#ifdef _OPENMP
#pragma omp parallel for reduction(+ \
                                   : sum) schedule(runtime)
#endif
    for (i = 1; i <= MAX_N; i++)
    {
        start_timer(timer);
        if (!is_sum_of_abundant(i))
            sum += i;
        clock_t end_time = clock();
        total_duration += end_timer(timer);

        printf("... %5lu: %8lu\r", i, sum);
        if (i % 100 == 0)
            fflush(stdout);
    }

    printf("Time taken: %.4g s\n", total_duration);
    printf("Sum of numbers that cannot be represented as sum of two abundant numbers : %lu\n", sum);

    delete_timer(timer);
    return 0;
}
