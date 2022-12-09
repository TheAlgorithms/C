/**
    @file
    @author [Krishna Vedala](https://github.com/kvedala)
    @date 2 October, 2019
    @brief Compute \f$m^{mth}\f$ Fibonacci number using the formulae:
    \f{eqnarray*}{
        F_{2n-1} &=& F_n^2 + F_{n-1}^2 \\
        F_{2n}   &=& F_n\left(2F_{n-1} + F_n\right)
   \f}
*/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Get the \f$n^{th}\f$ and \f$n+1^{th}\f$ Fibonacci number using recursive
 * half-interval decimation.
 * \param [in] n index of Fibonacci number to get
 * \param [out] C left half interval value - end result here. Cannot be NULL
 * \param [out] D right half interval can be discarded at end and can be NULL
 */
void fib(unsigned long n, unsigned long *C, unsigned long *D)
{
    // Out of Range checking
    // commented out since `n` is unsigned integer
    // if (n < 0)
    // {
    //     printf("\nNo Such term !\n");
    //     exit(0);
    // }

    unsigned long a, b, c, d;

    if (n == 0)
    {
        C[0] = 0;
        if (D) /* if D is not NULL */
            D[0] = 1;
        return;
    }

    fib(n >> 1, &c, &d); /* Compute F(n/2) */

    a = c * ((d << 1) - c);
    b = c * c + d * d;
    if (n % 2 == 0) /* If n is even */
    {
        C[0] = a;
        if (D)
            D[0] = b;
        return;
    }

    /**< If n is odd */
    C[0] = b;
    if (D) /* if D is not NULL */
        D[0] = a + b;
    return;
}

/**
 * main function
 */
int main(int argc, char *argv[])
{
    unsigned long number, result;

    setlocale(LC_NUMERIC, "");  // format the printf output

    // Asks for the number/position of term in Fibonnacci sequence
    if (argc == 2)
        number = atoi(argv[1]);
    else
    {
        printf("Enter the value of n(n starts from 0 ): ");
        scanf("%lu", &number);
    }

    fib(number, &result, NULL);

    printf("The nth term is : %'lu \n", result);

    return 0;
}
