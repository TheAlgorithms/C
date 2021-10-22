/**
 * @file
 * @brief [Problem 1](https://projecteuler.net/problem=1) solution
 *
 * If we list all the natural numbers below 10 that are multiples of 3 or 5,
 * we get 3,5,6 and 9. The sum of these multiples is 23.
 * Find the sum of all the multiples of 3 or 5 below N.
 *
 * This solution is based on the pattern that the successive numbers in the
 * series follow: 0+3,+2,+1,+3,+1,+2,+3.
 */
#include <getopt.h>  /// For CLI arg parsing (getopt, optind)
#include <unistd.h>  /// For miscellaneous symbolic constants, types and functions
#include <stdio.h>   /// For I/O operations (printf, fprintf, EXIT_... macros)
#include <stdlib.h>  /// For type casting (atol)

int solution(long limit);
int sum_multiples(int a, long limit);
int sum_of_ap(int a, int n, int d);

/**
 * @brief CLI driver of program
 * @param -h Get help message
 * @param limit Named arg to set limit
 */
int main(int argc, char *argv[])
{
    int opt;
    char usage_msg[] = "Usage: %s limit\n";
    while ((opt = getopt(argc, argv, "h")) != -1) {
        switch (opt) {
            case 'h':
                printf(usage_msg, argv[0]);
                exit(EXIT_SUCCESS);
            default: /* '?' */
                fprintf(stderr, usage_msg, argv[0]);
                exit(EXIT_FAILURE);
        }
    }
    if (optind >= argc) {
        fprintf(stderr, "Expected argument '%s'\n", "limit");
        exit(EXIT_FAILURE);
    }

    long limit = atol(argv[optind]);

    int ans = solution(limit);
    printf("%d\n", ans);
}

/**
 * @brief Solution to problem
 * @param limit Number upto which sum is to be calculated
 */
int solution(long limit)
{
    return sum_multiples(3, limit) + sum_multiples(5, limit) -
           sum_multiples(15, limit);
}

/**
 * @brief Compute multiples of `a` upto `limit`
 * @param a number
 * @param limit ceiling upto which to calculate
 * @return Sum of multiples of `a` till `limit`
 */
int sum_multiples(int a, long limit)
{
    int n = (limit - 1) / a;
    return sum_of_ap(a, n, a);
}

/**
 * @brief Implement formula for sum of n terms of Arithmetic progression (A.P)
 * @details Formula: S = n / 2 (2a + (n-1)d)
 * @param a First term
 * @param n Number of terms
 * @param d Interval between terms
 * @return Sum of AP
 */
int sum_of_ap(int a, int n, int d)
{
    return (n / 2.0) * (2 * a + (n - 1) * d);
}
