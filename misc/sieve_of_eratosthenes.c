/**
 * @file
 * @brief Get list of prime numbers using [Sieve of
 * Eratosthenes](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes)
 * @details
 * Sieve of Eratosthenes is an algorithm that finds all the primes
 * between 2 and N.
 *
 * Time Complexity  : \f$O(N \cdot\log \log N)\f$
 * <br/>Space Complexity : \f$O(N)\f$
 *
 */

#include <assert.h> /// for 'assert' in 'test' function
#include <stdbool.h> /// for 'bool' type in 'sieve' and 'test' function
#include <stdlib.h> /// for 'memset' in 'sieve' function
#include <string.h> /// for 'calloc' in 'sieve' function

/**
 * Return all primes between 2 and the given number
 * @param N the largest number to be checked for primality
 * @return is_prime a dynamically allocated array of `N + 1` booleans identifying if `i`^th number is a prime or not
 */
bool* sieve(int N)
{
    bool* primep = calloc(N+1, 1);
    memset(primep, true, N+1); 
    primep[0] = false; //0 is not a prime number
    primep[1] = false; //1 is not a prime number
    
    int i, j;
    for (i=2; i!=N/2; ++i)// i!=N+1 also works
        for (j=2; j<=N/i; ++j)// i*j <= N also works
            primep[i*j] = false;

    return primep;
}

/**
 * @brief Test function
 * @return void
 */
static void test()
{
    /* all the prime numbers less than 100 */
    int primers[] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                     43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    bool* primep = sieve(100);
    for (size_t i = 0, size = sizeof(primers) / sizeof(primers[0]); i < size;
         ++i)
    {
        assert(primep[primers[i]]);
    }

    /* Example Non-prime numbers */
    int nonPrimers[] = {4, 6, 8, 9, 10, 12, 16, 51};
    for (size_t i = 0, size = sizeof(nonPrimers) / sizeof(nonPrimers[0]);
         i < size; ++i)
    {
        assert(!primep[nonPrimers[i]]);
    }
}

/**
 * @brief Driver Code
 * @return 0 on exit
 */
int main()
{
    test();
    return 0;
}
