/** 
 * @file
 * @brief Converts a binary number to a decimal one.
 * @details
 * A binary number is an input, it is checked to be binary
 * then, the number is converted to a decimal number.
 * @author Kyler Smith
 * @author [lazy-dude] (https://github.com/lazy-dude)
 */

// includes
#include <assert.h> /// for assert
#include <stdbool.h> /// for bool
#include <stdint.h> /// for uintmax_t
#include <stdio.h> /// for IO operations

/**
 * @brief is_binary checks whether num is a binary one
 * @param num to be checked if it has binary representation
 * @return boolean true if num is binary false if not
 */
bool is_binary(uintmax_t num)
{
    unsigned remainder = 0;

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
 * @brief num_len finds length of an uintmax_t num
 * @param num whose length to be computed
 * @return the length of the number
 */
int num_len(uintmax_t num)
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
uintmax_t binary_decimal(uintmax_t number)
{
	unsigned remainder;
	uintmax_t decimal_number = 0, temp = 1;

    int length = num_len(UINTMAX_MAX) - 1;
    
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
 * @brief Self-test implementations
 * @returns void
 */
static void test()
{
	assert(binary_decimal(0)==0);
	assert(binary_decimal(1)==1);
	assert(binary_decimal(1110001)==113);
	assert(binary_decimal(11111111)==255);
	assert(binary_decimal(10000000000)==1024);
	assert(binary_decimal(1001110100000100)==40196);
}

/**
 * @brief main function
 * @param void
 * @returns 0 on exit
 */
int main()
{
    test();  // run self-test implementations
    printf("All tests passed.\n");
    return 0;
}

