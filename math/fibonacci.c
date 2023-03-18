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
#include <string.h>  /// for strlen()
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
    int num, success = 0;
    char buffer[4], *endPtr;

    do
    {
        fgets(buffer, 4, stdin);  // Inputs the value from user

        errno = 0;  // Reseting the errno value
        num = strtol(buffer, &endPtr,
                     10);  // Attempts to convert the string to integer

        if (strlen(buffer) > 3 || num > 48)
            success = 0;  // Three digit numbers are not allowed
        else if (errno == ERANGE)
            success = 0;  // ERANGE value is the error when arg. of strtol() is
                          // beyond long int limit
        else if (endPtr == buffer)
            success = 0;  // No character is entered
        else if (*endPtr != '\0' && *endPtr != '\n')
            success = 0;  // *endptr is neither end of string nor newline
        else
            success = 1;

    } while ((!success));  // Repeat until valid
                           // number is entered

    printf("Entered digit: %d\n", num);
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
