/**
 * @file
 * @brief Function to convert a Cartesian co-ordinate to polar form.
 */
#define _USE_MATH_DEFINES /**< required for MS Visual C */
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Function to convert cartesian coordinates to polar.
 *\f{eqnarray*}{
 r &=& \sqrt{x^2+y^2}\\
 \theta &=& \atan\frac{y}{x}
 \f}
 * @param [in] x absicca value
 * @param [in] y ordinate value
 * @param [out] r pointer to store polar radius
 * @param [out] theta pointer to store polar angle (in radian)
 */
void to_polar(double x, double y, double *r, double *theta)
{
    double thetaFinal = 0.f;

    *r = sqrt(x * x + y * y);

    if (x != 0)
    {
        if (y != 0)
        {
            *theta = atan(y / x);
            if ((x > 0 && y > 0) || (x == -y))
            {  // Q1
                thetaFinal = *theta;
            }
            else if (x < 0 && y > 0)
            {  // Q2
                thetaFinal = *theta + M_PI;
            }
            else if (x < 0 && y < 0)
            {  // Q3
                thetaFinal = *theta - M_PI;
            }
            else if (x > 0 && y < 0)
            {  // Q4
                thetaFinal = 2 * M_PI - *theta;
            }
            else
            {
                fprintf(stderr, "Should not reach here!\n");
            }
        }
    }
    else
    {  // exceptions when no actual angle is present
        if (y > 0)
        {
            thetaFinal = M_PI / 2;
        }
        else
        {
            thetaFinal = -(M_PI / 2);
        }
    }
    if (y == 0)
    {
        if (x > 0)
        {
            thetaFinal = 0;
        }
        else
        {
            thetaFinal = -M_PI;
        }
    }

    *theta = thetaFinal;
}

/**
 * @brief Generate a random number in the given limits
 *
 * @param lim1 lower limit
 * @param lim2 upper limit
 * @return random number in the given range
 */
double get_rand(double lim1, double lim2)
{
    double r = (double)rand() / RAND_MAX;  // value in [0,1)
    return (lim2 - lim1) * r + lim1;       // scale to range
}

/**
 * @brief Test implementation
 *
 */
void test()
{
    srand(10);
    int NUM_TESTS = 5;

    for (int i = 0; i < NUM_TESTS; i++)
    {
        double r, theta;
        printf("Test %d.... ", i);
        double x = get_rand(-5, 5);
        double y = get_rand(-5, 5);
        printf("(%.2g, %.2g).... ", x, y);
        to_polar(x, y, &r, &theta);
        assert(fabs(r - hypot(x, y)) < 0.01);
        assert(fabs(theta - atan2(y, x)) < 0.01);
        printf("passed\n");
    }
}

/** Main function */
int main()
{
    test();

    return 0;
}
