#include <stdio.h>
#include <math.h>
#include <stdlib.h>

char is_prime(long n)
{
    for (long i = 2; i < sqrtl(n) + 1; i++)
        if ( n % i == 0)
            return 0;

    return 1;
}


long long sum_of_primes(long N)
{
    long long  sum = 2;

    for (long i = 3; i < N; i+=2)   /* skip even numbers */
        if (is_prime(i))
            sum += i;

    return sum;
}


int main(int argc, char* argv[])
{
    long n = 100;

    if (argc == 2)  /* if command line argument is provided */
        n = atol(argv[1]);  /* use that as the upper limit */

    printf("%ld: %lld\n", n, sum_of_primes(n));

    return 0;
}