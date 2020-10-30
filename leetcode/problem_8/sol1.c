/**
 * \file
 * \brief [8. Convert string to
 * integer](https://leetcode.com/problems/string-to-integer-atoi/) solution
 * \details Implement atoi which converts a string to an integer.
 *
 * The function first discards as many whitespace characters as necessary until
 * the first non-whitespace character is found. Then, starting from this
 * character takes an optional initial plus or minus sign followed by as many
 * numerical digits as possible, and interprets them as a numerical value.
 *
 * The string can contain additional characters after those that form the
 * integral number, which are ignored and have no effect on the behavior of this
 * function.
 *
 * If the first sequence of non-whitespace characters in str is not a valid
 * integral number, or if no such sequence exists because either str is empty or
 * it contains only whitespace characters, no conversion is performed.
 *
 * If no valid conversion could be performed, a zero value is returned.
 */

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Function to convert string representation of an integer to integer.
 *
 * @param str input string to convert
 * @return integer form of the string text
 */
int myAtoi(char *str)
{
    int minusFlag = 0;
    size_t length = strlen(str);
    long int result = 0;
    char numberBuffer[11];
    int counter = 0;
    while (str[counter] == ' ')
    {
        counter++;
    }
    str = &str[counter];
    counter = 0;

    for (int i = 0; i < length; i++)
    {
        if (i == 0)
        {
            if (str[0] == '-')
            {
                minusFlag = 1;
                i++;
            }
            else if (str[0] == '+')
            {
                i++;
            }
        }
        if (counter > 10)
        {
            if (minusFlag)
            {
                return INT_MAX * -1 - 1;
            }
            else
            {
                return INT_MAX;
            }
        }

        if (str[i] < '0' || str[i] > '9')
        {
            break;
        }
        if (counter == 0 && str[i] == '0')
        {
            continue;
        }

        numberBuffer[counter] = str[i];
        counter++;
    }

    int i = 0;
    while (counter > 0)
    {
        if (minusFlag)
        {
            result -= (numberBuffer[i] - '0') * pow(10.0, counter - 1);
        }
        else
        {
            result += (numberBuffer[i] - '0') * pow(10.0, counter - 1);
        }
        i++;
        counter--;
    }

    if (result > INT_MAX)
    {
        return INT_MAX;
    }
    else if (result < INT_MAX * -1 - 1)
    {
        return INT_MAX * -1 - 1;
    }
    return result;
}

/** Main function
 * @returns 0
 */
int main()
{
    assert(myAtoi("43") == 43);
    printf("Test 1 passed.\n");

    assert(myAtoi("4193 wth words") == 4193);
    printf("Test 2 passed.\n");

    assert(myAtoi("words and 987") == 0);
    printf("Test 3 passed.\n");

    return 0;
}
