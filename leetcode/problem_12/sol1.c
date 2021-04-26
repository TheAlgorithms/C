/**
 * \file
 * \brief [12. Integer to
 * roman](https://leetcode.com/problems/integer-to-roman/) solution \details
 * Given an integer, convert it to a roman numeral.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Get the Roman numeral for units place
 *
 * @param c character digit to convert
 * @return null terminated string
 */
char *getOne(char c)
{
    switch (c)
    {
    case '9':
        return "IX";

    case '8':
        return "VIII";

    case '7':
        return "VII";

    case '6':
        return "VI";

    case '5':
        return "V";

    case '4':
        return "IV";

    case '3':
        return "III";

    case '2':
        return "II";

    case '1':
        return "I";

    case '0':
        return "";

    default:
        return NULL;
    }
}

/**
 * @brief Get the Roman numeral for tens place
 *
 * @param c character digit to convert
 * @return null terminated string
 */
char *getTen(char c)
{
    switch (c)
    {
    case '9':
        return "XC";

    case '8':
        return "LXXX";

    case '7':
        return "LXX";

    case '6':
        return "LX";

    case '5':
        return "L";

    case '4':
        return "XL";

    case '3':
        return "XXX";

    case '2':
        return "XX";

    case '1':
        return "X";

    case '0':
        return "";

    default:
        return NULL;
    }
}

/**
 * @brief Get the Roman numeral for hundreds place
 *
 * @param c character digit to convert
 * @return null terminated string
 */
char *getHundred(char c)
{
    switch (c)
    {
    case '9':
        return "CM";

    case '8':
        return "DCCC";

    case '7':
        return "DCC";

    case '6':
        return "DC";

    case '5':
        return "D";

    case '4':
        return "CD";

    case '3':
        return "CCC";

    case '2':
        return "CC";

    case '1':
        return "C";

    case '0':
        return "";

    default:
        return NULL;
    }
}

/**
 * @brief Get the Roman numeral for thousandths place
 *
 * @param c character digit to convert
 * @return null terminated string
 */
char *getThousand(char c)
{
    switch (c)
    {
    case '3':
        return "MMM";

    case '2':
        return "MM";

    case '1':
        return "M";

    default:
        return "";
    }
}

/**
 * @brief Convert Roman numeral for units place
 *
 * @param num number to convert
 * @return null terminated string
 */
const char *intToRoman(int num)
{
    char number[5];
    static char s[16];

    sprintf(number, "%04i", num);

    sprintf(s, "%s%s%s%s", getThousand(number[0]), getHundred(number[1]),
            getTen(number[2]), getOne(number[3]));

    return s;
}

/**
 * @brief Main function
 * @return 0
 */
int main()
{
    assert(strcmp(intToRoman(3), "III") == 0);
    printf("Test 1 passed\n");
    assert(strcmp(intToRoman(4), "IV") == 0);
    printf("Test 2 passed\n");
    assert(strcmp(intToRoman(9), "IX") == 0);
    printf("Test 3 passed\n");
    assert(strcmp(intToRoman(58), "LVIII") == 0);
    printf("Test 4 passed\n");
    assert(strcmp(intToRoman(1994), "MCMXCIV") == 0);
    printf("Test 5 passed\n");

    return 0;
}
