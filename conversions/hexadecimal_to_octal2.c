/**
 * @file
 * @brief Convert hexadecimal number to octal number (with decimal intermediary)
 * @details
 * The input is valid from 0 to 0xFFFF_FFFF_FFFF_FFFF.
 *
 * At first, this program converts a hex string to an unsigned long long
 * decimal, and then to an octal string.
 *
 * When there is an invalid character in input string, this program stops
 * parsing and converts the string until that character.
 *
 * @see hexadecimal_to_octal.c
 */

#include <stdio.h>  /// for printf() and fgets()
#include <string.h> /// for memset()

/**
 * @brief Convert a hexadecimal number to octal number.
 * @param hex Hexadecimal number to convert.
 * @returns A pointer to the converted octal string.
 */
const char *hex_to_oct(const char *hex)
{
#define MAX_OCT_STR_LEN 23 /* 17_7777_7777_7777_7777_7777 */
    static char octal[MAX_OCT_STR_LEN];
    memset(octal, '\0', MAX_OCT_STR_LEN); // Initialize as NULL string

    unsigned long long decimal = 0;
    int i = 0;
    int len;

    if (hex == NULL)
    {
        // Return an empty string
        return octal;
    }

    /* Hexadecimal to decimal conversion */
    while (*hex != '\n' && *hex != '\0')
    {
        char ch = *hex;

        if (ch >= '0' && ch <= '9')
        {
            ch -= '0';
        }
        else if (ch >= 'a' && ch <= 'f')
        {
            ch = ch - 'a' + 10;
        }
        else if (ch >= 'A' && ch <= 'F')
        {
            ch = ch - 'A' + 10;
        }
        else
        {
            printf("Invalid hexadecimal input: %c\n", ch);
            break;
        }

        decimal *= 16;
        decimal += ch;
        hex++;
    }

    /* Decimal to octal conversion */
    if (decimal == 0)
    {
        octal[0] = '0';
        len = 1;
    }
    else
    {
        i = 0;
        while (decimal > 0)
        {
            octal[i] = '0' + decimal % 8;
            i++;
            decimal /= 8;
        }

        len = i;
    }

    octal[len] = '\0';

    /* Reverse the octal string */
    for (i = 0; i < len / 2; i++)
    {
        char tmp = octal[i];
        octal[i] = octal[len - i - 1];
        octal[len - i - 1] = tmp;
    }

    return octal;
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main()
{
#define MAX_HEX_STR_LEN 17 /* FFFF_FFFF_FFFF_FFFF */
    char hex[MAX_HEX_STR_LEN];

    /* Input hexadecimal number from user */
    printf("Enter any hexadecimal number: ");
    fgets(hex, MAX_HEX_STR_LEN, stdin);

    const char *octal = hex_to_oct(hex);

    printf("Hexadecimal number = %s\n", hex);
    printf("Octal number = %s\n", octal);

    return 0;
}
