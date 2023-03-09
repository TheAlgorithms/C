/**
 * @file fibonacci.c
 * @brief Program to print the nth term of the Fibonacci series.
 * @details Fibonacci series generally starts from 0 and 1. Every next term in
 *the series is equal to the sum of the two preceding terms.
 **/

#include <stdio.h>

unsigned fib(int);

/* Driver Code */
int main()
{
    int number;

    // Getting n
    printf("Enter n to find nth fibonacci element: ");
    scanf("%d", &number);

    printf("%u\n", fib(number));
    return 0;
}

/**
 * @brief Determines the nth Fibonacci term
 * @param number - n in "nth term" and it can't be negative
 * @return nth term in unsigned type
 * @warning Only till 46th and 47th fibonacci element can be stored in 'int' and
 * 'unsigned' respectively (takes more than 20 seconds to print)
 */
unsigned fib(int number)
{
    if (number == 1)
        return 0;
    else if (number == 2)
        return 1;
    else
        return fib(number - 1) + fib(number - 2);
}
