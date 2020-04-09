#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <complex.h>

#define ACCURACY 1e-10

/**
 * define polynomial function
 **/
double complex function(double *coeffs, unsigned int degree, double complex x)
{
    double complex out = 0.;
    unsigned int n;

    for (n = 0; n < degree; n++)
        out += coeffs[n] * cpow(x, degree - n - 1);

    return out;
}

const char *complex_str(double complex x)
{
    static char msg[50];
    double r = creal(x);
    double c = cimag(x);

    sprintf(msg, "%.04g%c%.04gi", r, c >= 0 ? '+' : '-', c >= 0 ? c : -c);

    return msg;
}

double get_rand()
{
    const double max = 10, min = -10;
    return (double)rand() / (double)RAND_MAX * (max - min + 1);
}

/***
 * the comandline inputs are taken as coeffiecients of a polynomial
 **/
int main(int argc, char **argv)
{
    double *coeffs = NULL;
    double complex *s0 = NULL;
    unsigned int degree = 0;
    unsigned int n, i;

    if (argc < 2)
    {
        printf("Please pass the coefficients of the polynomial as commandline arguments.\n");
        return 0;
    }

    degree = argc - 1;                                                    /*< detected polynomial degree */
    coeffs = (double *)malloc(degree * sizeof(double));                   /**< store all input coefficients */
    s0 = (double complex *)malloc((degree - 1) * sizeof(double complex)); /**< number of roots = degree-1 */

    /* initialize random seed: */
    srand(time(NULL));

    if (!coeffs || !s0)
    {
        perror("Unable to allocate memory!");
        if (coeffs)
            free(coeffs);
        if (s0)
            free(s0);
        return EXIT_FAILURE;
    }

#if defined(DEBUG) || !defined(NDEBUG)
    /**
     * store intermediate values to a CSV file
     **/
    FILE *log_file = fopen("durand_kerner.log.csv", "wt");
    if (!log_file)
    {
        perror("Unable to create a storage log file!");
        free(coeffs);
        free(s0);
        return EXIT_FAILURE;
    }
    fprintf(log_file, "iter#,");
#endif

    printf("Computing the roots for:\n\t");
    for (n = 0; n < degree; n++)
    {
        coeffs[n] = strtod(argv[n + 1], NULL);
        if (n < degree - 1 && coeffs[n] != 0)
            printf("(%g) x^%d + ", coeffs[n], degree - n - 1);
        else if (coeffs[n] != 0)
            printf("(%g) x^%d = 0\n", coeffs[n], degree - n - 1);

        /* initialize root approximations with random values */
        if (n < degree - 1)
        {
            s0[n] = get_rand() + get_rand() * I;
#if defined(DEBUG) || !defined(NDEBUG)
            fprintf(log_file, "root_%d,", n);
#endif
        }
    }

#if defined(DEBUG) || !defined(NDEBUG)
    fprintf(log_file, "avg. correction");
    fprintf(log_file, "\n0,");
    for (n = 0; n < degree - 1; n++)
        fprintf(log_file, "%s,", complex_str(s0[n]));
#endif

    double tol_condition = 1;
    unsigned long iter = 0;

    while (tol_condition > ACCURACY && iter < ULONG_MAX)
    {
        double complex delta = 0;
        tol_condition = 0;
        iter++;

#if defined(DEBUG) || !defined(NDEBUG)
        fprintf(log_file, "\n%ld,", iter);
#endif

        for (n = 0; n < degree - 1; n++)
        {
            double complex numerator = function(coeffs, degree, s0[n]);
            double complex denominator = 1.0;
            for (i = 0; i < degree - 1; i++)
                if (i != n)
                    denominator *= s0[n] - s0[i];

            if (cabs(denominator) == 0)
            {
                printf("denominatpr = 0\n");
                goto end;
            }

            delta = numerator / denominator;

            s0[n] -= delta;

            tol_condition += fabs(cabs(delta));

#if defined(DEBUG) || !defined(NDEBUG)
            fprintf(log_file, "%s,", complex_str(s0[n]));
#endif
        }
        tol_condition /= (degree - 1);

#if defined(DEBUG) || !defined(NDEBUG)
        fprintf(log_file, "%.4g", tol_condition);
#endif
    }

end:

#if defined(DEBUG) || !defined(NDEBUG)
    fclose(log_file);
#endif

    printf("Iterations: %lu\n", iter);
    for (n = 0; n < degree - 1; n++)
        printf("\t%s\n", complex_str(s0[n]));
    printf("absolute average change: %.4g\n", tol_condition);

    free(coeffs);
    free(s0);

    return 0;
}