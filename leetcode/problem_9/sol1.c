/**
 * \file
 * \brief [9. Palindrome
 * number](https://leetcode.com/problems/palindrome-number/)
 * solution
 * \details Determine whether an integer is a palindrome. An integer is
 * a palindrome when it reads the same backward as forward.
 */

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Function to check if a given number is palindrome.
 *
 * @param x number to check
 * @return `true` if number if palindrome
 * @return `false` if number is not a palindrome
 */
bool isPalindrome(int x)
{
    if (x < 0 || (x % 10 == 0 && x != 0))
    {
        return false;
    }

    int revertedNumber = 0;
    while (x > revertedNumber)
    {
        revertedNumber = revertedNumber * 10 + x % 10;
        x /= 10;
    }

    return x == revertedNumber || x == revertedNumber / 10;
}

/**
 * @brief Main function
 * @return 0
 */
int main()
{
    assert(isPalindrome(121) == true);
    printf("Test 1 passed\n");
    assert(isPalindrome(-121) == false);
    printf("Test 2 passed\n");
    assert(isPalindrome(10) == false);
    printf("Test 3 passed\n");
    assert(isPalindrome(101) == true);
    printf("Test 4 passed\n");

    return 0;
}
