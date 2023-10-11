/*
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

#define MAX_ITERATIONS 100 /// the maximum iterations to be made

bool point_is_part_of_mandelbrot(double real, double imaginary);

int main(void)
{
    return 0;
}

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

    // the sum of the squares represents the absolute value of
    // the complex number
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
    return MAX_ITERATIONS == iterator; // if they are equal, it means
                                       // that the number is part of
                                       // the mandelbrot set
}
