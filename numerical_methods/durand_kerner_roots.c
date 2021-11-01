/**
 * @file
 * \brief Compute all possible approximate roots of any given polynomial using
 * [Durand Kerner
 * algorithm](https://en.wikipedia.org/wiki/Durand%E2%80%93Kerner_method)
 *
 * \author [Krishna Vedala](https://github.com/kvedala)
 *
 * Test the algorithm online:
 * https://gist.github.com/kvedala/27f1b0b6502af935f6917673ec43bcd7
 *
 * Try the highly unstable Wilkinson's polynomial:
 * ```
 * ./numerical_methods/durand_kerner_roots.c 1 -210 20615 -1256850 53327946
 * -1672280820 40171771630 -756111184500 11310276995381 -135585182899530
 * 1307535010540395 -10142299865511450 63030812099294896 -311333643161390640
 * 1206647803780373360 -3599979517947607200 8037811822645051776
 * -12870931245150988800 13803759753640704000 -8752948036761600000
 * 2432902008176640000
 * ```
 * Sample implementation results to compute approximate roots of the equation
 * \f$x^4-1=0\f$:\n
 * <img
 * src="https://raw.githubusercontent.com/TheAlgorithms/C/docs/images/numerical_methods/durand_kerner_error.svg"
 * width="400" alt="Error evolution during root approximations computed every
 * iteration."/> <img
 * src="https://raw.githubusercontent.com/TheAlgorithms/C/docs/images/numerical_methods/durand_kerner_roots.svg"
 * width="400" alt="Roots evolution - shows the initial approximation of the
 * roots and their convergence to a final approximation along with the iterative
 * approximations" />
 */

#include <complex.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ACCURACY 1e-10 /**< maximum accuracy limit */

/**
 * Evaluate the value of a polynomial with given coefficients
 * \param[in] coeffs coefficients of the polynomial
 * \param[in] degree degree of polynomial
 * \param[in] x point at which to evaluate the polynomial
 * \returns \f$f(x)\f$
 */
long double complex poly_function(long double *coeffs, unsigned int degree,
                                  long double complex x)
{
    long double complex out = 0.;
    unsigned int n;

    for (n = 0; n < degree; n++) out += coeffs[n] * cpow(x, degree - n - 1);

    return out;
}

/**
 * create a textual form of complex number
 * \param[in] x point at which to evaluate the polynomial
 * \returns pointer to converted string
 */
const char *complex_str(long double complex x)
{
    static char msg[50];
    double r = creal(x);
    double c = cimag(x);

    sprintf(msg, "% 7.04g%+7.04gj", r, c);

    return msg;
}

/**
 * check for termination condition
 * \param[in] delta point at which to evaluate the polynomial
 * \returns 0 if termination not reached
 * \returns 1 if termination reached
 */
char check_termination(long double delta)
{
    static long double past_delta = INFINITY;
    if (fabsl(past_delta - delta) <= ACCURACY || delta < ACCURACY)
        return 1;
    past_delta = delta;
    return 0;
}

/***
 * the comandline inputs are taken as coeffiecients of a polynomial
 */
int main(int argc, char **argv)
{
    long double *coeffs = NULL;
    long double complex *s0 = NULL;
    unsigned int degree = 0;
    unsigned int n, i;

    if (argc < 2)
    {
        printf(
            "Please pass the coefficients of the polynomial as commandline "
            "arguments.\n");
        return 0;
    }

    degree = argc - 1; /* detected polynomial degree */
    coeffs = (long double *)malloc(
        degree * sizeof(long double)); /* store all input coefficients */
    s0 = (long double complex *)malloc(
        (degree - 1) *
        sizeof(long double complex)); /* number of roots = degree-1 */

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
     */
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
            printf("(%Lg) x^%d + ", coeffs[n], degree - n - 1);
        else if (coeffs[n] != 0)
            printf("(%Lg) x^%d = 0\n", coeffs[n], degree - n - 1);

        double tmp;
        if (n > 0)
            coeffs[n] /= tmp; /* numerical errors less when the first
                                 coefficient is "1" */
        else
        {
            tmp = coeffs[0];
            coeffs[0] = 1;
        }

        /* initialize root approximations with random values */
        if (n < degree - 1)
        {
            s0[n] = (long double)rand() + (long double)rand() * I;
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

    clock_t end_time, start_time = clock();
    while (!check_termination(tol_condition) && iter < INT_MAX)
    {
        long double complex delta = 0;
        tol_condition = 0;
        iter++;

#if defined(DEBUG) || !defined(NDEBUG)
        fprintf(log_file, "\n%ld,", iter);
#endif

        for (n = 0; n < degree - 1; n++)
        {
            long double complex numerator =
                poly_function(coeffs, degree, s0[n]);
            long double complex denominator = 1.0;
            for (i = 0; i < degree - 1; i++)
                if (i != n)
                    denominator *= s0[n] - s0[i];

            delta = numerator / denominator;

            if (isnan(cabsl(delta)) || isinf(cabsl(delta)))
            {
                printf("\n\nOverflow/underrun error - got value = %Lg",
                       cabsl(delta));
                goto end;
            }

            s0[n] -= delta;

            tol_condition = fmaxl(tol_condition, fabsl(cabsl(delta)));

#if defined(DEBUG) || !defined(NDEBUG)
            fprintf(log_file, "%s,", complex_str(s0[n]));
#endif
        }
        // tol_condition /= (degree - 1);

#if defined(DEBUG) || !defined(NDEBUG)
        if (iter % 500 == 0)
        {
            printf("Iter: %lu\t", iter);
            for (n = 0; n < degree - 1; n++) printf("\t%s", complex_str(s0[n]));
            printf("\t\tabsolute average change: %.4g\n", tol_condition);
        }

        fprintf(log_file, "%.4g", tol_condition);
#endif
    }
end:

    end_time = clock();

#if defined(DEBUG) || !defined(NDEBUG)
    fclose(log_file);
#endif

    printf("\nIterations: %lu\n", iter);
    for (n = 0; n < degree - 1; n++) printf("\t%s\n", complex_str(s0[n]));
    printf("absolute average change: %.4g\n", tol_condition);
    printf("Time taken: %.4g sec\n",
           (end_time - start_time) / (double)CLOCKS_PER_SEC);

    free(coeffs);
    free(s0);

    return 0;
}
