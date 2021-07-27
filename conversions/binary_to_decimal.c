/** 
 * @file
 * @brief Converts a [binary number to a decimal](https://byjus.com/binary-to-decimal-formula/) number.
 * @details
 * A binary number is an input that is checked to be binary
 * then, the number is converted to a decimal number.
 * @author [Kyler Smith](https://github.com/KylerSmith)
 * @author [lazy-dude](https://github.com/lazy-dude)
 */

#include <assert.h>     /// for assert
#include <stdbool.h>   /// for bool
#include <stdint.h>   /// for uintmax_t
#include <stdio.h>   /// for IO operations

/**
 * @brief checks whether the number is binary
 * @param num the number to be checked if it has binary representation
 * @returns `true` if the number IS binary
 * @returns `false` if the number is NOT binary
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
 * @brief finds the length of an `uintmax_t` number
 * @param num whose length to be computed
 * @returns the length of the number
 */
uint16_t num_len(uintmax_t num)
{
    uint16_t len = 0;
    for (len = 0; num > 0; len++) {
        num /= 10;
    }
    return len;
}

/**
 * @brief The `binary_decimal` function does the actual job of conversion
 * @param number the number binary to be converted
 * @returns decimal_number decimal representation of a binary number
 */
uintmax_t binary_decimal(uintmax_t number)
{
	uint8_t remainder;
	uintmax_t decimal_number = 0;
	uint32_t temp = 1;

	uint16_t length = num_len(UINTMAX_MAX) - 1;
    
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

        printf("All tests have passed!\n");
}

/**
 * @brief main function
 * @param void
 * @returns 0 on exit
 */
int main()
{
    test();  // run self-test implementations
    return 0;
}
