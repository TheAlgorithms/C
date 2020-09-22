/**
 * @file
 * @brief Program to calculate
 * [exponentiation](https://en.wikipedia.org/wiki/Exponentiation) using
 * recursion algorithm.
 *
 * @author [Du Yuanchao](https://github.com/shellhub)
 */
#include <assert.h>

/**
 * @brief Returns the value of the first argument raised to the power of the
 * second argument using recursion.
 * @param a the base.
 * @param b the exponent.
 * @returns the value {@code a}<sup>{@code b}</sup>.
 */
long power(int a, int b) { return b == 0 ? 1 : a * power(a, b - 1); }

/**
 * @brief Test function
 * @return void
 */
static void test()
{
    assert(power(0, 2) == 0);
    assert(power(2, 3) == 8);
    assert(power(2, 10) == 1024);
    assert(power(3, 3) == 27);
}

/**
 * @brief Driver Code
 * @returns 0 on exit
 */
int main()
{
    test();
    return 0;
}
