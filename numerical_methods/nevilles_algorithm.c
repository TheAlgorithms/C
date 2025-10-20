/**
 * @file
 * @brief Implementation of Neville's Algorithm for polynomial interpolation.
 * @details Neville's algorithm is an iterative method to find the value of a
 * polynomial that passes through a given set of n+1 points.
 * https://en.wikipedia.org/wiki/Neville%27s_algorithm
 * @author [Mitrajit Ghorui](https://github.com/KeyKyrios)
 */
#include <assert.h>    /// for assert
#include <math.h>      /// for fabs
#include <stdio.h>     /// for IO operations
#include <stdlib.h>    /// for malloc, free
#include <string.h>    /// for memcpy

/**
 * @brief Evaluates the interpolating polynomial at a specific point.
 * @param x_coords Array of x-coordinates of the given points.
 * @param y_coords Array of y-coordinates of the given points.
 * @param n The number of points (size of the arrays).
 * @param target The x-coordinate at which to evaluate the polynomial.
 * @returns The interpolated y-value at the target x-coordinate. Returns NaN if
 * inputs are invalid.
 */
double interpolate(const double *x_coords, const double *y_coords, size_t n,
                   double target) {
    if (n == 0) {
        return NAN;  // Not a Number, indicates error
    }

    double *p = (double *)malloc(n * sizeof(double));
    if (p == NULL) {
        return NAN; // Memory allocation failed
    }
    memcpy(p, y_coords, n * sizeof(double));

    for (size_t k = 1; k < n; ++k) {
        for (size_t i = 0; i < n - k; ++i) {
            p[i] = ((target - x_coords[i + k]) * p[i] +
                    (x_coords[i] - target) * p[i + 1]) /
                   (x_coords[i] - x_coords[i + k]);
        }
    }

    double result = p[0];
    free(p);
    return result;
}

/**
 * @brief Self-test implementations
 * @returns void
 */
static void tests() {
    // Test 1: Linear interpolation y = 2x + 1
    double x1[] = {0, 2};
    double y1[] = {1, 5};
    double expected1 = 3.0;
    assert(fabs(interpolate(x1, y1, 2, 1.0) - expected1) < 1e-9);
    printf("Linear test passed.\n");

    // Test 2: Quadratic interpolation y = x^2
    double x2[] = {0, 1, 3};
    double y2[] = {0, 1, 9};
    double expected2 = 4.0;
    assert(fabs(interpolate(x2, y2, 3, 2.0) - expected2) < 1e-9);
    printf("Quadratic test passed.\n");

    // Test 3: Negative numbers y = x^2 - 2x + 1
    double x3[] = {-1, 0, 2};
    double y3[] = {4, 1, 1};
    double expected3 = 0.0;
    assert(fabs(interpolate(x3, y3, 3, 1.0) - expected3) < 1e-9);
    printf("Negative numbers test passed.\n");

    printf("All tests have successfully passed!\n");
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
    tests();  // run self-test implementations
    return 0;
}