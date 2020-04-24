#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>
#ifdef _OPENMP
#include <omp.h>
#endif

#define MOD (uint64_t)1e9
#define MAX_L 5000

char is_in(uint64_t N, uint64_t *D, uint64_t L)
{
    uint64_t i;
    for (i = 0; i < L; i++)
        if (D[i] == N)
            return 1;
    return 0;
}

uint64_t get_divisors(uint64_t N, uint64_t *D)
{
    uint64_t q, r;
    int64_t i, num = 0;

    if (N == 1)
    {
        D[0] = 1;
        return 1;
    }

    for (i = 1; i * i <= N + 1; i++)
    {
        r = N % i;

        if (r == 0)
        {
            q = N / i;
            if (!is_in(i, D, num))
            {
                D[num] = i;
                num++;
            }
            if (!is_in(q, D, num))
            {
                D[num] = q;
                num++;
            }
        }
        if (num == MAX_L)
            D = (uint64_t *)realloc(D, MAX_L * sizeof(uint64_t) << 1);
    }
    return num;
}

/**
 * sum of squares of all integer factors
 **/
uint64_t sigma2(uint64_t N)
{
    uint64_t sum = 0, DD, L;
    int64_t i;
    uint64_t *D = (uint64_t *)malloc(MAX_L * sizeof(uint64_t));

    L = get_divisors(N, D);
    for (i = 1; i < L; i++)
    {
        DD = (D[i] * D[i]) % MOD;
        sum += DD;
    }

    free(D);
    return sum % MOD;
}

/**
 * sum of squares of factors of numbers
 * from 1 thru N
 **/
uint64_t sigma(uint64_t N)
{
    uint64_t s, sum = 0;
    int64_t i;

#ifdef _OPENMP
#pragma omp parallel for reduction(+ \
                                   : sum)
#endif
    for (i = 0; i <= N; i++)
    {
        s = sigma2(i);
        sum += s;
    }
    return sum % MOD;
}

int main(int argc, char **argv)
{
    uint64_t N = 1000;

    if (argc == 2)
        N = strtoll(argv[1], NULL, 10);
    else if (argc > 2)
    {
        fprintf(stderr, "Wrong number of input arguments!\n");
        return -1;
    }

    clock_t start_time = clock();
    uint64_t result = sigma(N);
    double dtime = clock() - start_time;

    printf("N = %llu\nSum: %llu\n", N, result);
    printf("Time taken: %.4gms\n", dtime * 1e3 / CLOCKS_PER_SEC);

    return 0;
}