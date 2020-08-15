/**
 * @file
 * @brief Strong number is a number whose sum of all digits’ factorial is equal
 * to the number n For example: 145 = 1!(1) + 4!(24) + 5!(120)
 */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

/**
 * Check if given number is strong number or not
 * @param number
 * @return `true` if given number is strong number, otherwise `false`
 */
bool isStrong(int number)
{
    if (number < 0)
    {
        return false;
    }
    int sum = 0;
    int originalNumber = number;
    while (originalNumber != 0)
    {
        int remainder = originalNumber % 10;
        int factorial = remainder == 0 ? 0 : 1; /* 0! == 1 */

        /* calculate factorial of n */
        for (int i = 1; i <= remainder; factorial *= i, i++)
        {
            ;
        }
        sum += factorial;
        originalNumber /= 10;
    }
    return number == sum;
}

/**
 * Test function
 * @return void
 */
void test()
{
    assert(isStrong(145));  /* 145 = 1! + 4! + 5! */
    assert(!isStrong(543)); /* 543 != 5!+ 4! + 3! */
}

/**
 * Driver Code
 * @return None
 */
int main()
{
    test();
    return 0;
}
