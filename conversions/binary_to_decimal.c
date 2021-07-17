/** 
 * @file
 * @brief Converts a binary number to a decimal one.
 * @details
 * A binary number is an input, it is checked to be binary
 * then, the number is converted to a decimal number.
 * Some tests are added too.
 * Modified 07/12/2017
 * Modified 2021
 * @author Kyler Smith
 * @author [lazy-dude] (https://github.com/lazy-dude)
 */

// includes
#include <assert.h>
#include <stdbool.h>
#include <stdint.h> 
#include <stdio.h>
#include <stdlib.h>

// function prototypes
bool is_binary(intmax_t num);
int num_len(intmax_t num);
intmax_t binary_decimal(intmax_t num);
void test(void);

/**
 * @brief main function
 * @param void
 * @returns 0 on exit
 */
int main(void)
{
    test();
    printf("All tests passed.\n");
    return 0;
}

/**
 * @brief is_binary checks whether num is a binary one
 * @param num to be checked if it has binary representation
 * @return boolean true if num is binary false if not
 */
bool is_binary(intmax_t num)
{
    int remainder = 0;

    while (num > 0) {
        remainder = num % 10;
        if (remainder == 0 || remainder == 1) {
            num /= 10;
            continue;
        } else
            return false;
    }
    return true;
}

/**
 * @brief num_len finds length of an intmax_t num
 * @param num whose length to be computed
 * @return i int length of num
 */
int num_len(intmax_t num)
{
    int i;
    for (i = 0; num > 0; i++) {
        num /= 10;
    }
    return i;
}

/**
 * @brief binary_decimal function does the actual job of conversion
 * @param number binary to be converted
 * @return decimal_number decimal representation of binary number
 */
intmax_t binary_decimal(intmax_t number)
{
	intmax_t remainder, decimal_number = 0, temp = 1;

    int length = num_len(INTMAX_MAX) - 1;
    
    assert(number>=0);
    assert(num_len(number) <= length);
    assert(is_binary(number));

    // Iterate over the number until the end.
    while (number > 0) {
        remainder = number % 10;
        number = number / 10;
        decimal_number += remainder * temp;
        temp = temp * 2; // used as power of 2
    }

    return decimal_number;
}

/**
 * @brief some tests using assert
 * @param void
 * @return void
 */
void test(void)
{
	assert(binary_decimal(0)==0);
	assert(binary_decimal(1)==1);
	assert(binary_decimal(1110001)==113);
	assert(binary_decimal(11111111)==255);
	assert(binary_decimal(10000000000)==1024);
	assert(binary_decimal(1001110100000100)==40196);
}
