/**
 * \file
 * \brief Recoding the original atoi function in stdlib.h
 * \author [Mohammed YMIK](https://github.com/medymik)W
 * The function convert a string passed to an integer
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * the function take a string and return an integer
 * \param[out] str pointer to a char address
 */
int c_atoi(const char *str)
{
    int i;
    int sign;
    long value;
    long prev;

    i = 0;
    sign = 1;
    value = 0;

    /* skipping the spaces */
    while (((str[i] <= 13 && str[i] >= 9) || str[i] == 32) && str[i] != '\0')
        i++;

    /* store the sign if it is negative sign */
    if (str[i] == '-')
	{
        sign = -1;
	i++;
	}
    else if (str[i] == '+')
	{
        sign = 1;
	i++;
	}

    /* converting char by char to a numeric value */
    while (str[i] >= 48 && str[i] <= 57 && str[i] != '\0')
    {
        prev = value;
        value = value * 10 + sign * (str[i] - '0');

        /* managing the overflow */
        if (sign == 1 && prev > value)
            return (-1);
        else if (sign == -1 && prev < value)
            return (0);
        i++;
    }
    return (value);
}

/**
 * test the function implementation
 */
void test_c_atoi()
{
    printf("<<<< TEST FUNCTION >>>>\n");
    assert(c_atoi("123") == atoi("123"));
    assert(c_atoi("-123") == atoi("-123"));
    assert(c_atoi("") == atoi(""));
    assert(c_atoi("-h23") == atoi("-h23"));
    assert(c_atoi("         23") == atoi("         23"));
    assert(c_atoi("999999999") == atoi("999999999"));
    printf("<<<< TEST DONE >>>>\n");
}

/**
 * the main function take one argument of type char*
 * example : ./program 123
 */
int main(int argc, char **argv)
{
    test_c_atoi();

    if (argc == 2)
    {
        printf("Your number + 5 is %d\n", c_atoi(argv[1]) + 5);
        return (0);
    }
    printf("wrong number of parmeters\n");
    return (1);
}
