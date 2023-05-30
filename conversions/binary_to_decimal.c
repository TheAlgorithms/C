/**
 * @brief Converts a number from [Binary to Decimal](https://en.wikipedia.org/wiki/Binary-coded_decimal).
 * @details
 *
 * Binary to decimal conversion is a process to convert a number
 * having a binary representation to its equivalent decimal representation.
 *
 * The base of both number systems is different.
 * Binary number system is base 2 number system while decimal number system is base 10 number system.
 * The numbers used in binary number system are 0 and 1 while decimal number system has numbers from 0 to 9.
 * The conversion of binary number to decimal number is done by multiplying
 * each digit of the binary number, starting from the rightmost digit, with the power of 2 and adding the result.
 *
 * @author [Anup Kumar Pawar](https://github.com/AnupKumarPanwar)
 * @author [David Leal](https://github.com/Panquesito7)
*/

#include <stdio.h>      /// for IO operations
#include <assert.h>     /// for assert
#include <math.h>       /// for pow
#include <inttypes.h>   /// for uint64_t

/**
 * @brief Converts the given binary number
 * to its equivalent decimal number/value.
 * @param number The binary number to be converted
 * @returns The decimal equivalent of the binary number
*/
int convert_to_decimal(uint64_t number) {
    int decimal_number = 0, i = 0;

    while (number > 0) {
        decimal_number += (number % 10) * pow(2, i);
        number = number / 10;
        i++;
    }

    return decimal_number;
}

/**
 * @brief Self-test implementations
 * @returns void
*/
static void tests() {
    assert(convert_to_decimal(111) == 7);
    assert(convert_to_decimal(101) == 5);
    assert(convert_to_decimal(1010) == 10);
    assert(convert_to_decimal(1101) == 13);
    assert(convert_to_decimal(100001) == 33);
    assert(convert_to_decimal(10101001) == 169);
    assert(convert_to_decimal(111010) == 58);
    assert(convert_to_decimal(100000000) == 256);
    assert(convert_to_decimal(10000000000) == 1024);
    assert(convert_to_decimal(101110111) == 375);

    printf("All tests have successfully passed!\n");
}

/**
 * @brief Main function
 * @returns 0 on exit
*/
int main()
{
    tests();  // run self-test implementations
    return 0;
}
