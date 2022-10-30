/**
 * @file
 * @brief Conversion of [roman numerals](https://en.wikipedia.org/wiki/Roman_numerals) to decimal
 * @details Roman numerals are an ancient Roman numeral system consisting of the symbols I, V, X, L, C, D, and M
 * 
 * @author [Focusucof](https://github.com/Focusucof)
 */

#include <assert.h> /// for assert
#include <stdio.h>  /// for IO operations
#include <string.h> /// for strlen()

/**
 * @brief Convert roman numeral symbol to a decimal value helper function
 * @param symbol Roman numeral char
 * @returns Integer of decimal value for given symbol
 */
int symbol(char symbol) {
    int value = 0;
    switch(symbol) {
        case 'I':
            value = 1;
            break;
        case 'V':
            value = 5;
            break;
        case 'X':
            value = 10;
            break;
        case 'L':
            value = 50;
            break;
        case 'C':
            value = 100;
            break;
        case 'D':
            value = 500;
            break;
        case 'M':
            value = 1000;
            break;
    }
    return value;    
}

/**
 * @brief Converts roman numerals into a decimal number
 * @param input Input roman numeral as a C-string
 * @returns The converted number in decimal form
 */
int roman_to_decimal(char input[]) {
    int result = 0; // result in decimal

    for(int i = 0; i < strlen(input); i++) {
        if(strlen(input) > i + 1) {
            if(symbol(input[i]) >= symbol(input[i + 1])) {
                result += symbol(input[i]); // add value to sum
            } else {
                result += symbol(input[i + 1]) - symbol(input[i]); // if the current symbol is smaller than the next (ex. IV), subtract it from the next symbol
                i++; // skip over an extra symbol 
            }
        } else {
            result += symbol(input[i]); // add value to sum
        }
    }
    return result;
}

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test() {
    // 1st test
    char input[] = "MCMIV";
    int expected = 1904;
    
    int output = roman_to_decimal(input);

    printf("TEST 1\n");
    printf("Input: %s\n", input);
    printf("Expected Output: %d\n", expected);
    printf("Output: %d\n", output);
    assert(output == expected);
    printf("== TEST PASSED ==\n\n");

    // 2nd test
    char input2[] = "MMMDCCXXIV";
    expected = 3724;
    
    output = roman_to_decimal(input2);

    printf("TEST 2\n");
    printf("Input: %s\n", input2);
    printf("Expected Output: %d\n", expected);
    printf("Output: %d\n", output);
    assert(output == expected);
    printf("== TEST PASSED ==\n\n");

    // 3rd test
    char input3[] = "III";
    expected = 3;
    
    output = roman_to_decimal(input3);

    printf("TEST 3\n");
    printf("Input: %s\n", input3);
    printf("Expected Output: %d\n", expected);
    printf("Output: %d\n", output);
    assert(output == expected);
    printf("== TEST PASSED ==\n\n");
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
    test();  // run self-test implementations
    return 0;
}
