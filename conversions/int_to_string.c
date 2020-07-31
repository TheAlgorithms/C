/**
 * @file
 * @brief Convert a positive integer to string (non-standard function)
 * representation.
 */
#include <assert.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * Converts an integer value to a null-terminated string using the specified
 * base and stores the result in the array given by str parameter.
 * @param value Value to be converted to a string.
 * @param dest pointer to array in memory to store the resulting null-terminated
 * string.
 * @param base Numerical base used to represent the value as a string, between 2
 * and 16, where 10 means decimal base, 16 hexadecimal, 8 octal, and 2 binary.
 * @returns A pointer to the resulting null-terminated string, same as parameter
 * str.
 * @note The destination array must be pre-allocated by the calling function.
 */
char *int_to_string(uint16_t value, char *dest, int base)
{
    const char hex_table[] = {'0', '1', '2', '3', '4', '5', '6', '7',
                              '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

    int len = 0;
    do
    {
        dest[len++] = hex_table[value % base];
        value /= base;
    } while (value != 0);

    /* reverse characters */
    for (int i = 0, limit = len / 2; i < limit; ++i)
    {
        char t = dest[i];
        dest[i] = dest[len - 1 - i];
        dest[len - 1 - i] = t;
    }
    dest[len] = '\0';
    return dest;
}

/** Test function
 * @returns `void`
 */
static void test()
{
    const int MAX_SIZE = 100;
    char *str1 = (char *)calloc(sizeof(char), MAX_SIZE);
    char *str2 = (char *)calloc(sizeof(char), MAX_SIZE);

    for (int i = 1; i <= 100; ++i) /* test 100 random numbers */
    {
        /* Generate value from 0 to 100 */
        int value = rand() % 100;

        // assert(strcmp(itoa(value, str1, 2), int_to_string(value, str2, 2)) ==
        //        0);
        snprintf(str1, MAX_SIZE, "%o", value);  //* standard C - to octal */
        assert(strcmp(str1, int_to_string(value, str2, 8)) == 0);
        snprintf(str1, MAX_SIZE, "%d", value); /* standard C - to decimal */
        assert(strcmp(str1, int_to_string(value, str2, 10)) == 0);
        snprintf(str1, MAX_SIZE, "%x", value); /* standard C - to hexadecimal */
        assert(strcmp(str1, int_to_string(value, str2, 16)) == 0);
    }

    free(str1);
    free(str2);
}

/** Driver Code */
int main()
{
    /* Intializes random number generator */
    srand(time(NULL));
    test();
    return 0;
}
