/**
 * @file
 * @brief Algorithm to calculate the Riemann Zeta function for a given real number.
 * @details https://en.wikipedia.org/wiki/Riemann_zeta_function
 * @author ["Nunito (https://github.com/nunniii) <mateusnss@protonmail.ch>"]
 */

#include <math.h>
#include <complex.h>
#include <stdio.h>

/**
 * @brief Calculate the Riemann Zeta function for a given real number s.
 * @param real_part - Real part of the complex number s
 * @param num_terms - Number of terms in the series to sum
 * @return The value of the Riemann Zeta function at s
 * @warning This implementation is a simple approximation,
 * see the purpose of the num_terms_to_sum variable in the scope of main().
 *
 * @b Algorithm Complexity:
 *      - Time: O(num_terms)
 *      - Space: O(1)
 */
double complex riemann_zeta(double real_part, int num_terms)
{
    double complex result = 0.0 + 0.0 * I; // as a complex number

    for (int n = 1; n <= num_terms; ++n)
    {
        result += 1.0 / (cpow(n, real_part));
    }
    return result;
}

int main() {
    // Example of use:
    double real_part = 7.0;  // Real of "s"
    int num_terms_to_sum = 100;  // Number of terms that will be added to the series, (the greater  the quantity, the greater the precision)

    // zeta_value(double real_part, int num_terms) return double
    double complex zeta_value = riemann_zeta(real_part, num_terms_to_sum);

    printf("Zeta(%lf) = %.10lf + %.10lfi\n", real_part, creal(zeta_value), cimag(zeta_value));

    return 0;
}
