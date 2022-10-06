//C program to find out the roots of a quadratic equation
#include <math.h>
#include <stdio.h>
int main()
{
    float a, b, c, d, root1, root2, real, imag;
    printf("Enter coefficients a, b and c for the quadratic equation of the form 'ax^2+bx+c' (separated by spaces): ");
    scanf("%f %f %f", &a, &b, &c);
     d = b * b - 4 * a * c;

    // condition for real and different roots
    if (d > 0)
    {
        root1 = (-b + sqrt(d)) / (2 * a);
        root2 = (-b - sqrt(d)) / (2 * a);
        printf("root1 = %.2f and root2 = %.2f", root1, root2);
    }
    // condition for real and equal roots
    else if (d == 0)
    {
        root1 = root2 = -b / (2 * a);
        printf("root1 = root2 = %.2f", root1);
    }
    // if roots are not real
    else
    {
        real = -b / (2 * a);
        imag = sqrt(-d) / (2 * a);
        printf("root1 = %.2f +%.2fi and root2 = %.2f -%.2fi", real, imag, real, imag);
    }

    return 0;
}