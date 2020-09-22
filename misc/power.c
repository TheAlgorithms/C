/**
 * @file
 * @brief Program to calculate
 * [exponentiation](https://en.wikipedia.org/wiki/Exponentiation)
 *
 * @author [Du Yuanchao](https://github.com/shellhub)
 */
#include <assert.h>

/**
 * @brief Returns the value of the first argument raised to the power of the
 * second argument.
 * @param a the base.
 * @param b the exponent.
 * @returns the value {@code a}<sup>{@code b}</sup>.
 */
long power(int a, int b)
{
    long result = 1;
    for (int i = 1; i <= b; ++i)
    {
        result *= a;
    }
    return result;
}

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
