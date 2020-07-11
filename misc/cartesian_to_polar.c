/**
 * @file
 * @brief Function to convert a Cartesian co-ordinate to polar form.
 */
#define _USE_MATH_DEFINES /**< required for MS Visual C */
#include <math.h>
#include <stdio.h>

/**
give as arguments to the executable two x and y coordinates
outputs a polar coordinate
*/
int main()
{
    double x, y;
    double r, theta, thetaFinal;
    scanf("%lf %lf", &x, &y);
    r = hypot(x, y);
    if (x != 0)
    {
        if (y != 0)
        {
            theta = atan(y / x);
            if ((x > 0 && y > 0) || (x == -y))
            {  // Q1
                thetaFinal = theta;
            }
            else if (x < 0 && y > 0)
            {  // Q2
                thetaFinal = theta + M_PI;
            }
            else if (x < 0 && y < 0)
            {  // Q3
                thetaFinal = theta - M_PI;
            }
            else if (x > 0 && y < 0)
            {  // Q4
                thetaFinal = 2 * M_PI - theta;
            }
        }
    }
    if (x == 0)
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
    printf("%.2f %.2f\n", r, atan2(y, x));
}
