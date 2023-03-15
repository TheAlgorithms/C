/**
 * @file
 * @brief In mathematics, the bisection method is a root-finding method that
 * applies to any continuous function for which one knows two values with
 * opposite signs. https://en.wikipedia.org/wiki/Bisection_method
 * @details
 * The method consists of repeatedly bisecting the interval
 * defined by these values and then selecting the subinterval in which the
 * function changes sign, and therefore must contain a root. It is a very
 * simple and robust method, but it is also relatively slow. Because of this,
 * it is often used to obtain a rough approximation to a solution which is
 * then used as a starting point for more rapidly converging methods.
 * @author [Aybars Nazlica](https://github.com/aybarsnazlica)
 */

#include <assert.h>  /// for assert
#include <math.h>    /// for pow and fabs

#define EPSILON 0.0001  // a small positive infinitesimal quantity
#define NMAX 50         // maximum number of iterations

/**
 * @brief Function documentation
 * @param a First value
 * @param b Second value
 * @returns `sign`
 */
float sign(float a, float b) { return a * b; }

/**
 * @brief Polynomial function for root finding
 * @param x
 * @returns `function evaluation result`
 */
float func(float x)
{
    return pow(x, 3.0) + 2.0 * x - 10.0;  // f(x) = x**3 + 2x - 10
}

/**
 * @brief Function documentation
 * @param x_left Lower interval value
 * @param x_right Upper interval value
 * @param tolerance error threshold
 * @returns `root of the function` if bisection method succeed within the
 * maximum number of iterations
 * @returns `-1` if bisection method fails
 */
float bisection(float x_left, float x_right, float tolerance)
{
    int n = 1;     // step counter
    float middle;  // midpoint

    while (n <= NMAX)
    {
        middle = (x_left + x_right) / 2;  // bisect the interval
        float error = fabs(x_left - x_right) / 2;

        if (func(middle) == 0.0 || error < tolerance)
        {
            return middle;
        }

        if (sign(func(middle), func(x_left)) >= 0.0)
        {
            x_left = middle;  // new lower interval
        }
        else
        {
            x_right = middle;  // new upper interval
        }

        n++;  // increase step counter
    }
    return -1.0;  // method failed (maximum number of steps exceeded)
}

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test()
{
    /* Compares root value that is found by the bisection method within a given
     * floating point error*/
    assert(fabs(bisection(1.0, 2.0, 0.0001) - 1.847473) <=
           EPSILON);  // the algorithm works as expected
    assert(fabs(bisection(100.0, 250.0, 0.0001) - 249.999928) <=
           EPSILON);  // the algorithm works as expected
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
