/**
 * \file
 * \brief [13. Roman to
 * Integer](https://leetcode.com/problems/roman-to-integer/)
 * solution
 * \details Given a roman numeral, convert it to an integer.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Convert a given roman numeral string to integer.
 *
 * @param s roman numeral string
 * @return converted integer
 */
int romanToInt(char *s)
{
    int romanToInt = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        switch (s[i])
        {
        case 'I':
            if (i + 1 < strlen(s))
            {
                if (s[i + 1] == 'V' || s[i + 1] == 'X')
                {
                    romanToInt -= 1;
                    break;
                }
            }
            romanToInt += 1;
            break;
        case 'V':
            romanToInt += 5;
            break;
        case 'X':
            if (i + 1 < strlen(s))
            {
                if (s[i + 1] == 'L' || s[i + 1] == 'C')
                {
                    romanToInt -= 10;
                    break;
                }
            }
            romanToInt += 10;
            break;
        case 'L':
            romanToInt += 50;
            break;
        case 'C':
            if (i + 1 < strlen(s))
            {
                if (s[i + 1] == 'D' || s[i + 1] == 'M')
                {
                    romanToInt -= 100;
                    break;
                }
            }
            romanToInt += 100;
            break;
        case 'D':
            romanToInt += 500;
            break;
        case 'M':
            romanToInt += 1000;
            break;
        default:
            break;
        }
    }
    return romanToInt;
}

/**
 * @brief Main function
 * @return 0
 */
int main()
{
    assert(romanToInt("III") == 3);
    printf("Test 1 passed\n");
    assert(romanToInt("IV") == 4);
    printf("Test 2 passed\n");
    assert(romanToInt("IX") == 9);
    printf("Test 3 passed\n");
    assert(romanToInt("LVIII") == 58);
    printf("Test 4 passed\n");
    assert(romanToInt("MCMXCIV") == 1994);
    printf("Test 5 passed\n");

    return 0;
}
