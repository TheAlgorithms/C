/**
 * @file
 * \brief Find approximate solution for \f$f(x) = 0\f$ using
 * Newton-Raphson interpolation algorithm.
 *
 * \author [Krishna Vedala](https://github.com/kvedala)
 */

#include <complex.h> /* requires minimum of C99 */
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ACCURACY 1e-10 /**< solution accuracy */

/**
 * Return value of the function to find the root for.
 * \f$f(x)\f$
 */
double complex func(double complex x)
{
    return x * x - 3.; /* x^2 = 3 - solution is sqrt(3) */
    // return x * x - 2.; /* x^2 = 2 - solution is sqrt(2) */
}

/**
 * Return first order derivative of the function.
 * \f$f'(x)\f$
 */
double complex d_func(double complex x) { return 2. * x; }

/**
 * main function
 */
int main(int argc, char **argv)
{
    double delta = 1;
    double complex cdelta = 1;

    /* initialize random seed: */
    srand(time(NULL));

    /* random initial approximation */
    double complex root = (rand() % 100 - 50) + (rand() % 100 - 50) * I;

    unsigned long counter = 0;
    /* iterate till a convergence is reached */
    while (delta > ACCURACY && counter < ULONG_MAX)
    {
        cdelta = func(root) / d_func(root);
        root += -cdelta;
        counter++;
        delta = fabs(cabs(cdelta));

#if defined(DEBUG) || !defined(NDEBUG)
        if (counter % 50 == 0)
        {
            double r = creal(root);
            double c = cimag(root);

            printf("Iter %5lu: Root: %4.4g%c%4.4gi\t\tdelta: %.4g\n", counter,
                   r, c >= 0 ? '+' : '-', c >= 0 ? c : -c, delta);
        }
#endif
    }

    double r = creal(root);
    double c = fabs(cimag(root)) < ACCURACY ? 0 : cimag(root);

    printf("Iter %5lu: Root: %4.4g%c%4.4gi\t\tdelta: %.4g\n", counter, r,
           c >= 0 ? '+' : '-', c >= 0 ? c : -c, delta);

    return 0;
}
