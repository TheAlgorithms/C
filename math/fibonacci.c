/**
 * @file
 * @brief Program to print the nth term of the Fibonacci series.
 * @details 
 * Fibonacci series generally starts from 0 and 1. Every next term in
 * the series is equal to the sum of the two preceding terms.
 * For further info: https://en.wikipedia.org/wiki/Fibonacci_sequence
 *
 * @author [Luiz Carlos Aguiar C](https://github.com/IKuuhakuI)
 * @author [Niranjan](https://github.com/niranjank2022)
 */

#include <assert.h>  /// for assert()
#include <errno.h>  /// for errno - to determine whether there is an error while using strtol()
#include <stdio.h>   /// for input, output
#include <stdlib.h>  /// for exit() - to exit the program
#include <time.h>   /// to calculate time taken by fib()
/**
 * @brief Determines the nth Fibonacci term
 * @param number - n in "nth term" and it can't be negative as well as zero
 * @return nth term in unsigned type
 * @warning
 * Only till 47th and 48th fibonacci element can be stored in `int` and
 * `unsigned int` respectively (takes more than 20 seconds to print)
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
        if (!(buffer[0] == '\n' ||
            buffer[1] == '\n' ||
            buffer[2] == '\n')) {
            while (getchar() != '\n') excess_len++;
        }

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

    printf("\nEntered digit: %d (it might take sometime)\n", num);
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
    clock_t start, end;

    start = clock();
    printf("Fibonacci element %d is %u ", number, fib(number));
    end = clock();

    printf("in %.3f seconds.\n", ((double)(end - start)) / CLOCKS_PER_SEC );
    return 0;
}
