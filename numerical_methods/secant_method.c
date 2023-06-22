/**
 * @file
 * @brief [Secant Method](https://en.wikipedia.org/wiki/Secant_method) implementation. Find a
 * continuous function's root by using a succession of roots of secant lines to
 * approximate it, starting from the given points' secant line.
 * @author [Samuel Pires](https://github.com/disnoca)
 */

#include <assert.h>  /// for assert
#include <math.h>    /// for fabs
#include <stdio.h>   /// for io operations

#define TOLERANCE 0.0001  // root approximation result tolerance
#define NMAX 100          // maximum number of iterations

/**
 * @brief Continuous function for which we want to find the root
 * @param x Real input variable
 * @returns The evaluation result of the function using the input value
 */
double func(double x)
{
    return x * x - 3.;  // x^2 = 3 - solution is sqrt(3)
}

/**
 * @brief Root-finding method for a continuous function given two points
 * @param x0 One of the starting secant points
 * @param x1 One of the starting secant points
 * @param tolerance Determines how accurate the returned value is. The returned
 * value will be within `tolerance` of the actual root
 * @returns `root of the function` if secant method succeed within the
 * maximum number of iterations
 * @returns `-1` if secant method fails
 */
double secant_method(double x0, double x1, double tolerance)
{
    int n = 1;  // step counter

    while (n++ < NMAX)
    {
        // calculate secant line root
        double x2 = x1 - func(x1) * (x1 - x0) / (func(x1) - func(x0));

        // update values
        x0 = x1;
        x1 = x2;

        // return value if it meets tolerance
        if (fabs(x1 - x0) < tolerance)
            return x2;
    }

    return -1;  // method failed (maximum number of steps exceeded)
}

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test()
{
    // compares root values found by the secant method within the tolerance
    assert(secant_method(0.2, 0.5, TOLERANCE) - sqrt(3) < TOLERANCE);
    assert(fabs(secant_method(-2, -5, TOLERANCE)) - sqrt(3) < TOLERANCE);
    assert(secant_method(-3, 2, TOLERANCE) - sqrt(3) < TOLERANCE);
    assert(fabs(secant_method(1, -1.5, TOLERANCE)) - sqrt(3) < TOLERANCE);

    printf("All tests have successfully passed!\n");
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main()
{
    test();  // run self-test implementations
    return 0;
}
