/**
 * @file
 * @brief Compute greatest common divisor using Binary GCD (Stein's algorithm)
 * https://en.wikipedia.org/wiki/Binary_GCD_algorithm
 * @author [Apostolos Pappas](https://github.com/tolis-0/)
 * @date 28 November, 2023
 */

#include <assert.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#ifdef _MSC_VER
#include <intrin.h>
#define trailing_zeros(x) _tzcnt_u64(x)
#else
#define trailing_zeros(x) __builtin_ctzll(x)
#endif

/**
 * @brief Get greatest common divisor of u and v without division
 * @param [in] u nonnegative integer
 * @param [in] v nonnegative integer
 * @return gcd(u,v) in unsigned long type
 */
unsigned long binary_gcd(unsigned long u, unsigned long v)
{
    int shift, u_tz, v_tz;
    unsigned long tmp;

    if (u == 0)
    {
        return v;
    }
    if (v == 0)
    {
        return u;
    }

    // get number of trailing zero bits
    // essentially powers of 2 in prime factorization
    u_tz = trailing_zeros(u);
    v_tz = trailing_zeros(v);

    // keep minimum of powers of 2 because gcd(2u, 2v) = 2·gcd(u, v)
    shift = (u_tz < v_tz) ? u_tz : v_tz;
    v >>= v_tz;
    u >>= u_tz;

    // maintain v and u odd for gcd(u, v) = gcd(|u − v|, min(u, v))
    do
    {
        tmp = (u > v) ? u - v : v - u;  // |u - v|
        v = (u > v) ? v : u;            // min(u, v)
        u_tz = trailing_zeros(tmp);
        u = tmp >> u_tz;
    } while (u != 0);

    return v << shift;
}

/**
 * @brief Self-test implementations
 * @returns void
 */
static void tests()
{
    unsigned i;

    assert(binary_gcd(7, 0) == 7);
    assert(binary_gcd(0, 11) == 11);
    assert(binary_gcd(13398, 4785) == 957);
    assert(binary_gcd(34017, 242420) == 391);
    assert(binary_gcd(16807, 13377) == 343);
    assert(binary_gcd(21504, 56320) == 1024);
    assert(binary_gcd(90, 60) == 30);
    assert(binary_gcd(43010, 36309) == 1);

    // consecutive numbers have gcd 1
    for (i = 1; i < 1000; i++)
    {
        assert(binary_gcd(i, i + 1) == 1);
    }

    for (i = 2; i < 1000; i++)
    {
        assert(binary_gcd(i, i) == i);
    }

    for (i = 1; i < 1000; i++)
    {
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
    if (argc == 3)
    {
        num1 = atoi(argv[1]);
        num2 = atoi(argv[1]);
    }
    else
    {
        printf("Enter the values of 2 nonnegative numbers: ");
        scanf("%lu %lu", &num1, &num2);
    }

    result = binary_gcd(num1, num2);

    printf("gcd(%lu, %lu) = %lu \n", num1, num2, result);

    return 0;
}
