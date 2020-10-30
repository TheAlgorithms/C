/**
 * \file
 * \brief [7. Reverse integer](https://leetcode.com/problems/reverse-integer/)
 * solution
 * \details Given a 32-bit signed integer, reverse digits of an integer.
 */

#include <assert.h>
#include <inttypes.h>
#include <limits.h>
#include <stdio.h>

/**
 * @brief Reverse the digits of a signed number
 *
 * @param x input signed number
 * @return number with reversed digits
 */
int32_t reverse(int32_t x)
{
    int rev = 0;
    while (x != 0)
    {
        int pop = x % 10;
        x /= 10;
        if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7))
            return 0;
        if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8))
            return 0;
        rev = rev * 10 + pop;
    }
    return rev;
}

/** Main function
 * @returns 0
 */
int main()
{
    assert(reverse(123) == 321);
    printf("Test 1 passed.\n");

    assert(reverse(-123) == -321);
    printf("Test 2 passed.\n");

    assert(reverse(120) == 21);
    printf("Test 3 passed.\n");

    return 0;
}
