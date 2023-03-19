/**
 * @file
 * @brief Program to print the nth term of the Fibonacci series.
 * @details
 * Fibonacci series generally starts from 0 and 1. Every next term in
 * the series is equal to the sum of the two preceding terms.
 */

#include <assert.h>  /// for assert()
#include <errno.h>  /// for errno - to determine whether there is an using strtol()
#include <stdio.h>   /// for input, output
#include <stdlib.h>  /// for exit() - to exit the program
/**
 * @brief Determines the nth Fibonacci term
 * @param number - n in "nth term" and it can't be negative as well as zero
 * @return nth term in unsigned type
 * @warning
 * Only till 47th and 48th fibonacci element can be stored in 'int' and
 * 'unsigned' respectively (takes more than 20 seconds to print)
 */
unsigned int fib(int number)
{
    // Check for negative integers
    if (number <= 0)
    {
        fprintf(stderr, "Illegal Argument Is Passed!\n");
        exit(EXIT_FAILURE);
    }

    // Base conditions
    if (number == 1)
        return 0;

    if (number == 2)
        return 1;

    // Recursive call to the function
    return fib(number - 1) + fib(number - 2);
}

/**
 * @brief Get the input from the user
 * @return valid argument to the fibonacci function
 */
int getInput(void)
{
    int num, excess_len;
    char buffer[3], *endPtr;

    while (1)
    {  // Repeat until a valid number is entered
        printf("Please enter a valid number:");
        fgets(buffer, 3, stdin);  // Inputs the value from user

        excess_len = 0;
        while (getchar() != '\n') excess_len++;

        num = strtol(buffer, &endPtr,
                     10);  // Attempts to convert the string to integer

        // Checking the input
        if (  // The number is too large
            (excess_len > 0 || num > 48) ||
            // Characters other than digits are included in the input
            (*endPtr != '\0' && *endPtr != '\n') ||
            // No characters are entered
            endPtr == buffer)
        {
            continue;
        }

        break;
    }

    printf("\nEntered digit: %d\n", num);
    return num;
}

/**
 * @brief self-test implementation
 * @return void
 */
static void test()
{
    assert(fib(5) == 3);
    assert(fib(2) == 1);
    assert(fib(9) == 21);
}

/**
 * @brief Main function
 * @return 0 on exit
 */
int main()
{
    // Performing the test
    test();
    printf("Tests passed...\n");

    // Getting n
    printf(
        "Enter n to find nth fibonacci element...\n"
        "Note: You would be asked to enter input until valid number ( less "
        "than or equal to 48 ) is entered.\n");

    int number = getInput();

    printf("Fibonacci element %d is %u\n", number, fib(number));
    return 0;
}
