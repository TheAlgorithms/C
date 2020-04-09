/***
 * approximate solution for f(x) = 0
 * given f(x) and f'(x)
 **/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <complex.h> /* requires minimum of C99 */

/**
 * f(x)
 */
double complex function(double complex x)
{
    return x * x - 3.; /* x^2 = 3 - solution is sqrt(3) */
    // return x * x - 2.; /* x^2 = 2 - solution is sqrt(2) */
}

/**
 * f'(x)
 */
double complex d_function(double complex x)
{
    return 2. * x;
}

int main(int argc, char **argv)
{
    const double accuracy = 1e-10;
    double delta = 1;
    double complex cdelta = 1;

    /* initialize random seed: */
    srand(time(NULL));

    double complex root = (rand() % 100 - 50) + (rand() % 100 - 50) * I;

    unsigned long counter = 0;
    while (delta > accuracy && counter < ULONG_MAX)
    {
        cdelta = function(root) / d_function(root);
        root += -cdelta;
        counter++;
        delta = fabs(cabs(cdelta));

#if defined(DEBUG) || !defined(NDEBUG)
        if (counter % 50 == 0)
        {
            double r = creal(root);
            double c = cimag(root);

            printf("Iter %5lu: Root: %4.4g%c%4.4gi\t\tdelta: %.4g\n", counter, r,
                   c >= 0 ? '+' : '-', c >= 0 ? c : -c, delta);
        }
#endif
    }

    double r = creal(root);
    double c = fabs(cimag(root)) < accuracy ? 0 : cimag(root);

    printf("Iter %5lu: Root: %4.4g%c%4.4gi\t\tdelta: %.4g\n", counter, r,
           c >= 0 ? '+' : '-', c >= 0 ? c : -c, delta);

    return 0;
}