#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Calculates the best-fit line (y = alpha*x + beta) for the function sqrt(x)
 * over the interval [1.0, 2.0] using Least Squares Linear Regression.
 */
int compute_alpha_beta()
{
    int N = 1000;  // Number of sample points for the regression
    float x_start = 1.0;
    float x_end = 2.0;  // The approximation is optimized for this range
    float x, y;

    // Summation variables for the Least Squares formula
    float sx = 0.0;   // Sum of x
    float sy = 0.0;   // Sum of y (sqrt(x))
    float sxx = 0.0;  // Sum of x squared
    float sxy = 0.0;  // Sum of x * y

    for (int i = 0; i < N; i++)
    {
        // Step through the range [1, 2]
        x = x_start + (x_end - x_start) * ((float)i / N);
        y = sqrt(x);  // Get the actual target value

        sx += x;
        sy += y;
        sxx += x * x;
        sxy += y * x;
    }

    // Standard Linear Regression formulas to find Slope (alpha) and Intercept
    // (beta)
    float alpha = ((N * sxy - sx * sy) / (N * sxx - sx * sx));
    float beta = ((sy - alpha * sx) / N);

    printf("--- Float Results ---\n");
    printf("Alpha normal = %f\n", alpha);
    printf("Beta normal = %f\n", beta);

    // Type-punning: Printing the raw IEEE-754 hex bits of the float values.
    // This allows us to see how these numbers are stored in memory/registers.
    printf("Alpha hex normal = 0x%X\n", *((int*)(&alpha)));
    printf("Beta hex normal  = 0x%X\n\n", *((int*)(&beta)));

    // --- Fixed Point Conversion (16.16 Format) ---
    // We scale the values by 2^16 (65536) to perform "decimal math" using
    // integers. This is vital for systems without a Floating Point Unit (FPU).
    int alpha_fixed = (int)(alpha * 65536);
    int beta_fixed = (int)(beta * 65536);

    printf("--- 16.16 Fixed Point Results ---\n");
    printf("Alpha fixed point = %d\n", alpha_fixed);
    printf("Beta fixed point  = %d\n", beta_fixed);
    printf("Alpha hex fixed   = 0x%X\n", alpha_fixed);
    printf("Beta hex fixed    = 0x%X\n", beta_fixed);

    return 0;
}

/**
 * Fast Square Root Approximation using the pre-computed alpha/beta
 * coefficients. This replaces a heavy sqrt() call with 1 multiply and 1
 * addition. Good for graphics, shaders, and real-time simulations.
 */
int alpha_beta_approximations(float x)
{
    // These constants are derived from the [1, 2] range regression above.
    float alpha = 0.411859f;
    float beta = 0.601160f;

    // Linear Approximation: y = mx + b
    // Note: This is highly accurate between 1.0 and 2.0, but error increases
    // outside that range.
    float result = (alpha * x) + beta;

    printf("Approximated result = %4f\n", result);
    return 0;
}

int main()
{
    float x;

    // 1. Show the math behind the coefficients
    compute_alpha_beta();

    // 2. Test the approximation
    printf(
        "\nNote: Approximation is optimized for inputs between 1.0 and 2.0\n");
    printf("Enter number to approximate sqrt: ");

    if (scanf("%f", &x) == 1)
    {
        alpha_beta_approximations(x);
        printf("Actual sqrt value   = %4f\n", sqrt(x));
    }

    return 0;
}
