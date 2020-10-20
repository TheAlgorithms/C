/**
 * @file
 * @brief Octal to hexadecimal conversion by scanning user input
 * @details
 * The octalToHexadecimal function take the octal number as long
 * return a string hexadecimal value after conversion
 * @author [Rachit Bhalla](https://github.com/rachitbhalla)
 */
#include <assert.h> // for assert
#include <math.h> // for pow function
#include <stdio.h> // for scanf and printf functions
#include <stdlib.h> // for malloc and free functions
#include <string.h> // for strcmp function

/**
 * @brief Convert octal number to decimal number
 * @param octalValue is the octal number that needs to be converted
 * @returns a decimal number after conversion
 */
long octalToDecimal(long octalValue){
    long decimalValue = 0;
    int i = 0;
    while (octalValue) {
        // Extracts right-most digit, multiplies it with 8^i, and increment i by 1
        decimalValue += (long)(octalValue % 10) * pow(8, i++);
        // Shift right in base 10
        octalValue /= 10;
    }
    return decimalValue;
}

/**
 * @brief Convert octal number to hexadecimal number
 * dynamically allocated memory needs to be freed by the calling the function free
 * @param octalValue is the octal number that needs to be converted
 * @returns a hexadecimal value as a string after conversion
 */
char *octalToHexadecimal(long octalValue){
    char *hexadecimalValue = malloc(256 * sizeof(char));
    sprintf(hexadecimalValue, "%lX", octalToDecimal(octalValue));
    return hexadecimalValue;
}

/**
 * @brief Test function
 * @returns void
 */
static void test() {
    /* test that hexadecimal value of octal number 213 is 8B */
    assert(strcmp(octalToHexadecimal(213), "8B") == 0);

    /* test that hexadecimal value of octal number 174 is 7C */
    assert(strcmp(octalToHexadecimal(174), "7C") == 0);
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main()
{
    // execute the tests
    test();

    // get the value of octal number as input
    int octalValue;
    printf("Enter an octal number: ");
    scanf("%d", &octalValue);

    // call the function octalToHexadecimal and print the hexadecimal value
    char *hexadecimalValue = octalToHexadecimal(octalValue);
    printf("Equivalent hexadecimal number is: %s", hexadecimalValue);

    // free the memory allocated dynamically in function octalToHexadecimal
    free(hexadecimalValue);

    // return 0 and exit
    return 0;
}
