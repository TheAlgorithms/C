/**
 * @file
 * @brief Program to print the nth term of the Fibonacci series.
 * @details
 * Fibonacci series generally starts from 0 and 1. Every next term in
 * the series is equal to the sum of the two preceding terms.
 */

#include <assert.h>  /// for assert()
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
    int number;
    char buffer[8];

    // Performing the test
    test();
    printf("Tests passed...\n");

    // Getting n
    printf("Enter n to find nth fibonacci element: ");
    scanf("%3[0-9]s", buffer);  // Inputting only the first two digits as this
                                // program can handle only till 48th element

    number = atoi(buffer);  // Converting the string to integer (atoi - argument
                            // to integer)

    // Exit if n is greater than 48
    if (number >= 48)
    {
        printf("Sorry, n can't be greater than 48.\n");
        exit(EXIT_FAILURE);
    }

    printf("Fibonacci element %d is %u\n", number, fib(number));
    return 0;
}
