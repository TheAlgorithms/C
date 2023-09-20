/**
 * @file
 * @brief Calculates the nth power of a number in O(log(n)) time.
 * @details
 * Calculating the nth power of a number requires O(n) time using the naive
 * method. This algorithm optimizes it through exponentiation by squaring.
 * https://cp-algorithms.com/algebra/binary-exp.html
 * @author [Praneeth Jain](https://github.com/PraneethJain)
 */

#include <assert.h>  // for assert()
#include <stdio.h>   // for output
#include <stdlib.h>  // for exit()

/**
 * @brief Determines a raised to the nth power via binary exponentiation.
 * @param a - base
 * @param n - exponent
 * @return a raised to the nth power
 * @warning
 * `int` can overflow very quickly.
 */
int binary_exponentiation(int a, int n)
{
    // Check for negative exponent
    if (n < 0)
    {
        fprintf(stderr, "Illegal exponent passed! n should be non negative.\n");
        exit(EXIT_FAILURE);
    }

    int res = 1;
    while (n > 0)
    {
        if (n % 2 == 1)  // If the current bit is 1
        {
            res *= a;  // Then it must be multiplied to the result
        }

        a *= a;   // Square the base
        n >>= 1;  // Move to the next bit
    }

    return res;
}

/**
 * @brief self-test implementation
 * @return void
 */
static void tests()
{
    assert(binary_exponentiation(5, 3) == 125);
    assert(binary_exponentiation(-7, 3) == -343);
    assert(binary_exponentiation(9, 0) == 1);
    assert(binary_exponentiation(-123, 0) == 1);
    assert(binary_exponentiation(3, 5) == 243);
    assert(binary_exponentiation(-4, 5) == -1024);

    printf("All tests have successfully passed!\n");
}

/**
 * @brief Main function
 * @return 0 on exit
 */
int main()
{
    tests();  // run self-test implementations
    return 0;
}
