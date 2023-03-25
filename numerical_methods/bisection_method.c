/**
 * @file
 * @brief In mathematics, the [Bisection
 * Method](https://en.wikipedia.org/wiki/Bisection_method) is a root-finding
 * method that applies to any continuous function for which one knows two values
 * with opposite signs.
 * @details
 * The method consists of repeatedly bisecting the interval
 * defined by the two values and then selecting the subinterval in which the
 * function changes sign, and therefore must contain a root. It is a very
 * simple and robust method, but it is also relatively slow. Because of this,
 * it is often used to obtain a rough approximation to a solution which is
 * then used as a starting point for more rapidly converging methods.
 * @author [Aybars Nazlica](https://github.com/aybarsnazlica)
 */

#include <assert.h>  /// for assert
#include <math.h>    /// for fabs
#include <stdio.h>   /// for IO operations

#define EPSILON 0.0001  // a small positive infinitesimal quantity
#define NMAX 50         // maximum number of iterations

/**
 * @brief Function to check if two input values have the same sign (the property
 * of being positive or negative)
 * @param a Input value
 * @param b Input value
 * @returns 1.0 if the input values have the same sign,
 * @returns -1.0 if the input values have different signs
 */
double sign(double a, double b)
{
    return (a > 0 && b > 0) + (a < 0 && b < 0) - (a > 0 && b < 0) -
           (a < 0 && b > 0);
}

/**
 * @brief Continuous function for which we want to find the root
 * @param x Real input variable
 * @returns The evaluation result of the function using the input value
 */
double func(double x)
{
    return x * x * x + 2.0 * x - 10.0;  // f(x) = x**3 + 2x - 10
}

/**
 * @brief Root-finding method for a continuous function given two values with
 * opposite signs
 * @param x_left Lower endpoint value of the interval
 * @param x_right Upper endpoint value of the interval
 * @param tolerance Error threshold
 * @returns `root of the function` if bisection method succeed within the
 * maximum number of iterations
 * @returns `-1` if bisection method fails
 */
double bisection(double x_left, double x_right, double tolerance)
{
    int n = 1;      // step counter
    double middle;  // midpoint

    while (n <= NMAX)
    {
        middle = (x_left + x_right) / 2;  // bisect the interval
        double error = middle - x_left;

        if (fabs(func(middle)) < EPSILON || error < tolerance)
        {
            return middle;
        }

        if (sign(func(middle), func(x_left)) > 0.0)
        {
            x_left = middle;  // new lower endpoint
        }
        else
        {
            x_right = middle;  // new upper endpoint
        }

        n++;  // increase step counter
    }
    return -1;  // method failed (maximum number of steps exceeded)
}

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test()
{
    /* Compares root value that is found by the bisection method within a given
     * floating point error*/
    assert(fabs(bisection(1.0, 2.0, 0.0001) - 1.847473) <
           EPSILON);  // the algorithm works as expected
    assert(fabs(bisection(100.0, 250.0, 0.0001) - 249.999928) <
           EPSILON);  // the algorithm works as expected

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
