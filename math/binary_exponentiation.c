/**
 * @file
 * @brief Calculates the nth power of a number in O(log(n)) time.
 * @details
 * Calculating the nth power of a number requires O(n) time using the naive
 * method. This algorithm optimizes it through exponentiation by squaring.
 * https://cp-algorithms.com/algebra/binary-exp.html
 * @author [Praneeth Jain](https://github.com/PraneethJain)
 */

#include <assert.h>  /// for assert()
#include <stdint.h>  /// for int64 types
#include <stdio.h>   /// for output
#include <stdlib.h>  /// for exit()

/**
 * @brief Determines base raised to an exponent via binary exponentiation.
 * @param base of the given number
 * @param exponent of the given number
 * @return a raised to the nth power
 * @warning
 * can overflow very quickly.
 */
int64_t binary_exponentiation(int64_t base, uint64_t exponent)
{
    int64_t result = 1;
    while (exponent > 0)
    {
        if (exponent & 1)  // If the current bit is 1
        {
            result *= base;  // Then it must be multiplied to the result
        }

        base *= base;   // Square the base
        exponent >>= 1;  // Move to the next bit
    }

    return result;
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
