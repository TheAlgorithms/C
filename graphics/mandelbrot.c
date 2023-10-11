/**
@file mandelbrot.c
@brief Implementation of the
    [Mandelbrot set](https://en.wikipedia.org/wiki/Mandelbrot_set).

@details
This will only focus on the formula, the graphic part can be done by
    any person who wants to do it. ;)
So the formula is:

Z0 = 0;
Zn+1 = Zn^2 + C;

`Z` refers to the complex number of the mandelbrot set.
`C` refers to the constant of the point in the cartesian plane,
    that point is X + Yi, where X is the real part and Y is the
    imaginary part.
The number with Z represents the iteration.
A complex number is considered part of the mandelbrot set if he doesn't
    diverge to infinity, basically a number is considered infinite if
    it's absolute value is greater than 2, as we gonna see in the code.
@author [andreyvdl](https://github.com/andreyvdl)
 */

#include <assert.h>        /// for assert
#include <math.h>          /// for math functions
#include <stdbool.h>       /// for boolean
#include <unistd.h>        /// for size_t
#include <stdio.h>         /// for printf

#define MAX_ITERATIONS 100 /// the maximum iterations to be made

bool point_is_part_of_mandelbrot(double real, double imaginary);

/**
@brief The function that makes all the tests

@return void
 */
void test(void)
{
    // tests that resulted in true
    assert(point_is_part_of_mandelbrot(0.0, 0.0) == true);
    assert(point_is_part_of_mandelbrot(-1.123, 0.0) == true);
    assert(point_is_part_of_mandelbrot(0.25, 0.0) == true);
    assert(point_is_part_of_mandelbrot(-1.3, 0.0) == true);
    assert(point_is_part_of_mandelbrot(-0.1, -0.7) == true);

    // tests that resulted in false
    assert(point_is_part_of_mandelbrot(42.0, 0.0) == false);
    assert(point_is_part_of_mandelbrot(0.0, -42.0) == false);
    assert(point_is_part_of_mandelbrot(-1.123, 2.0) == false);
    assert(point_is_part_of_mandelbrot(-1.123, -2.0) == false);
    assert(point_is_part_of_mandelbrot(1.0, -1.0) == false);

    printf("Passed in all tests :)\n");
}

/**
@brief The main function

@return 0 on exit
 */
int main(void)
{
    test();
    return 0;
}

/**
@brief Mandelbrot formula function

@param real The X real point
@param imaginary  The Y imaginary point
@return true If the point is part of the mandelbrot set
@return false If the point is not part of the mandelbrot set
 */
bool point_is_part_of_mandelbrot(double real, double imaginary)
{
    double complex_imaginary;
    double complex_real;
    double temp_real;
    size_t iterator;

    complex_imaginary = 0;
    complex_real = 0;
    temp_real = 0;
    iterator = 0;

    // the sum of the squares represents the absolute value
    // (hipotenuse) of the complex number.
    while (MAX_ITERATIONS > iterator &&
            2 >= pow(complex_real, 2) + pow(complex_imaginary, 2))
    {
        temp_real = pow(complex_real, 2) -
                    pow(complex_imaginary, 2) + real;
        complex_imaginary = 2 * complex_real * complex_imaginary +
                            imaginary;
        complex_real = temp_real;
        iterator = iterator + 1;
    }
    if (MAX_ITERATIONS == iterator) { return true; }
    return false;
}
