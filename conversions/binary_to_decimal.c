/**
* A C code to convert a binary number to a decimal one.
* Modified 07/12/2017, Kyler Smith
* Modified 2021 lazy-dude
*/

#include <assert.h>
#include <stdbool.h>
#include <stdint.h> 
#include <stdio.h>
#include <stdlib.h>

/**
* function prototypes
*/
bool is_binary(intmax_t num);
int num_len(intmax_t num);
intmax_t binary_decimal(intmax_t num);
void test(void);

int main(void)
{
    test();
    printf("All tests passed.\n");
    return 0;
}

/**
* is_binary checks whether num is a binary one
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
* num_len finds length of an intmax_t num
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
* binary_decimal function does the actual job of conversion
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
* some tests using assert
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

