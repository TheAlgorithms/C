/**
 * @file
 * @brief Compute greatest common divisor using Binary GCD (Stein's algorithm)
 * https://en.wikipedia.org/wiki/Binary_GCD_algorithm
 * @author [Apostolos Pappas](https://github.com/tolis-0/)
 * @date 28 November, 2023
 */

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
 * @brief Get greatest common divisor of u and v without division
 * @param [in] u nonnegative integer
 * @param [in] v nonnegative integer
 * @return gcd(u,v) in unsigned long type
 */
unsigned long binary_gcd (unsigned long u, unsigned long v)
{
    int shift, u_tz, v_tz;
    unsigned long tmp;

    if (u == 0) return v;
    if (v == 0) return u;

    // get number of trailing zero bits
    // essentially powers of 2 in prime factorization
    u_tz = __builtin_ctzll(u);
    v_tz = __builtin_ctzll(v);

    // keep minimum of powers of 2 because gcd(2u, 2v) = 2·gcd(u, v)
    shift = (u_tz < v_tz) ? u_tz : v_tz;
    v >>= v_tz;
    u >>= u_tz;

    // maintain v and u odd for gcd(u, v) = gcd(|u − v|, min(u, v))
    do {
        tmp = (u > v) ? u - v : v - u; // |u - v|
        v = (u > v) ? v : u; // min(u, v)
        u_tz = __builtin_ctzll(tmp);
        u = tmp >> u_tz;
    } while (u != 0);

    return v << shift;
}

/**
 * @brief Self-test implementations
 * @returns void
 */
static void tests() {
    unsigned i;

    assert(binary_gcd(7, 0) == 7);
    assert(binary_gcd(0, 11) == 11);
    assert(binary_gcd(2*3*7*11*29, 3*5*11*29) == 3*11*29);
    assert(binary_gcd(3*17*23*29, 2*2*5*17*23*31) == 17*23);
    assert(binary_gcd(7*7*7*7*7, 3*7*7*7*13) == 7*7*7);
    assert(binary_gcd(1024*3*7, 1024*11*5) == 1024);
    assert(binary_gcd(2*3*3*5, 2*2*3*5) == 2*3*5);
    assert(binary_gcd(2*5*11*17*23, 3*7*7*13*19) == 1);

    // consecutive numbers have gcd 1
    for (i = 1; i < 1000; i++) {
        assert(binary_gcd(i, i + 1) == 1);
    }

    for (i = 2; i < 1000; i++) {
        assert(binary_gcd(i, i) == i);
    }

    for (i = 1; i < 1000; i++) {
        assert(binary_gcd(1, i) == 1);
        assert(binary_gcd(i, 1) == 1);
    }

    printf("All tests have successfully passed!\n");
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main(int argc, char *argv[])
{
    unsigned long num1, num2, result;

    setlocale(LC_NUMERIC, "");  // format the printf output

    tests();

    // Asks for the input numbers
    if (argc == 3) {
        num1 = atoi(argv[1]);
        num2 = atoi(argv[1]);
    } else {
        printf("Enter the values of 2 nonnegative numbers: ");
        scanf("%lu %lu", &num1, &num2);
    }

    result = binary_gcd(num1, num2);

    printf("gcd(%lu, %lu) = %lu \n", num1, num2, result);

    return 0;
}