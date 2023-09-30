/**
 * @file
 * @brief Algorithm to calculate the Riemann Zeta function for a given real number.
 * @details https://en.wikipedia.org/wiki/Riemann_zeta_function
 * @author ["Nunito (https://github.com/nunniii) <mateusnss@protonmail.ch>"]
 */

#include <math.h>
#include <complex.h>

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
 *
 * @example: zeta_value(double real_part, int num_terms) return double
 * <><><>
 * "Considering x as the return value of zeta_value(), note that creal(x)
 * returns the real part of x, and cimag() returns the imaginary part of x.
 * [...] <complex.h> is essential in your code. Please refer to the
 * documentation of this library:
 * (https://pubs.opengroup.org/onlinepubs/009695399/basedefs/complex.h.html)"
 *
 * @example: creal( zeta_value(7, 12) ) = 1.008349
 * @example: cimag( zeta_value(7, 12) ) = 0.000000
 *
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

void main() {


    // Feel free to implement your code by removing the lines below.

    {
        
    // Example of use:
    double complex zeta_value = riemann_zeta(7 /* The real part */ , 12 /* Number of terms that will be added to the series, (the greater  the quantity, the greater the precision) */ );
    double real_part = creal(zeta_value);
    double imag_part = creal(zeta_value);

    }


}
