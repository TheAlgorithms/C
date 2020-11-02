/**
 * @file
 * @brief [Factorial](https://en.wikipedia.org/wiki/Factorial) with recursive function call
 * [definition](https://en.wikipedia.org/wiki/Factorial#Definition)
 * [recurrence relation](https://en.wikipedia.org/wiki/Recurrence_relation)
 * @details
 * This version of the factorial computation function obtains the result by
 * recursively calling the function
 * @author [Nicola Masarone](https://github.com/nicola-masarone)
 *
 */

#include <assert.h>  /// allows the use of the assert() macro for a diagnostic test of the function
#include <stdio.h>  /// allows the use of standard input output functions such as scanf() and printf()

/**
 * Function documentation
 * This function calculates the factorial of a number: n! = n*(n-1)*...*1 
 * From its definition we can calculate the factorial as: n! = n*(n-1)! 
 * that is, with recursive call of the function applied to the argument decreased by 1. 
 * The recursion must stop when it reaches 0! which by definition is equal to 1.
 * @param val input value to calculate the factorial of
 * @returns factorial of the input value
 */
long long factorial_recursive(int val)
{
    // function statements here
    if (val < 1)
    {
        // 0! is 1
        return 1;
    }
    else
    {
        // recursive code, with factorial evaluated as: val! = val*(val-1)!
        return val * factorial_recursive(val - 1);
    }
}

/**
 * @brief Test implementations
 * @returns void
 */
static void test()
{
    /* desciptions of the following test */
    assert(factorial_recursive(5) ==
           120);  // this ensures that the algorithm works as expected
    assert(factorial_recursive(1) ==
           1);  // this ensures that the algorithm works as expected
    assert(factorial_recursive(0) ==
           1);  // this ensures that the algorithm works as expected
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main()
{
    test();  // execute the tests

    // code here
    int N = 0;
    long long result = 0;
    printf(
        "Enter the value (between 0 and 20) to calculate the factorial of and "
        "press enter: ");
    scanf("%d", &N);

    if (N < 0)
    {
        printf("Cannot calculate factorial of a negative number");
    }
    else if (N > 20)
    {
        printf("The factorial of the number entered is too large for me");
    }
    else
    {
        result = factorial_recursive(N);
        printf("The factorial of %d is %lld", N, result);
    }

    return 0;
}
