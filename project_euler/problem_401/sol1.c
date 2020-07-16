/**
 * \file
 * \brief [Problem 401](https://projecteuler.net/problem=401) solution -
 * Sum of squares of divisors
 * \author [Krishna Vedala](https://github.com/kvedala)
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define __STDC_FORMAT_MACROS
#include <inttypes.h>
#ifdef _OPENMP
#include <omp.h>
#endif

#define MOD_LIMIT (uint64_t)1e9 /**< modulo limit */
#define MAX_LENGTH 5000         /**< chunk size of array allocation */

/**
 * Check if a number is present in given array
 * \param[in] N number to check
 * \param[in] D array to check
 * \param[in] L length of array
 * \returns 1 if present
 * \returns 0 if absent
 */
char is_in(uint64_t N, uint64_t *D, uint64_t L)
{
    uint64_t i;
    for (i = 0; i < L; i++)
    {
        if (D[i] == N)
        {
            return 1;
        }
    }
    return 0;
}

/**
 * Get all integer divisors of a number
 * \param[in] N number to find divisors for
 * \param[out] D array to store divisors in
 * \returns number of divisors found
 */
uint64_t get_divisors(uint64_t N, uint64_t *D)
{
    uint64_t q, r;
    int64_t i, num = 0;

    if (N == 1)
    {
        D[0] = 1;
        return 1;
    }

    // search till sqrt(N)
    // because after this, the pair of divisors will repeat themselves
    for (i = 1; i * i <= N + 1; i++)
    {
        r = N % i;  // get reminder

        // reminder = 0 if 'i' is a divisor of 'N'
        if (r == 0)
        {
            q = N / i;
            if (!is_in(i, D, num))  // if divisor was already stored
            {
                D[num] = i;
                num++;
            }
            if (!is_in(q, D, num))  // if divisor was already stored
            {
                D[num] = q;
                num++;
            }
        }

        if (num == MAX_LENGTH)
        {  // limit of array reached, allocate more space
            D = (uint64_t *)realloc(D, MAX_LENGTH * sizeof(uint64_t) << 1);
        }
    }
    return num;
}

/**
 * compute sum of squares of all integer factors of a number
 * \param[in] N
 * \returns sum of squares
 */
uint64_t sigma2(uint64_t N)
{
    uint64_t sum = 0, L;
    int64_t i;
    uint64_t *D = (uint64_t *)malloc(MAX_LENGTH * sizeof(uint64_t));

    L = get_divisors(N, D);
    for (i = 1; i < L; i++)
    {
        uint64_t DD = (D[i] * D[i]) % MOD_LIMIT;
        sum += DD;
    }

    free(D);
    return sum % MOD_LIMIT;
}

/**
 * sum of squares of factors of numbers
 * from 1 thru N
 */
uint64_t sigma(uint64_t N)
{
    uint64_t s, sum = 0;
    int64_t i;

#ifdef _OPENMP
// parallelize on threads
#pragma omp parallel for reduction(+ : sum)
#endif
    for (i = 0; i <= N; i++)
    {
        s = sigma2(i);
        sum += s;
    }
    return sum % MOD_LIMIT;
}

/** Main function */
int main(int argc, char **argv)
{
    uint64_t N = 1000;

    if (argc == 2)
    {
        N = strtoll(argv[1], NULL, 10);
    }
    else if (argc > 2)
    {
        fprintf(stderr, "Wrong number of input arguments!\n");
        printf("Usage:\t ./sol1.c [N=1000]");
        return -1;
    }

    clock_t start_time = clock();
    uint64_t result = sigma(N);
    double dtime = clock() - start_time;

    printf("N = %" PRIu64 "\nSum: %" PRIu64 "\n", N, result);
    printf("Time taken: %.4gms\n", dtime * 1e3 / CLOCKS_PER_SEC);

    return 0;
}
