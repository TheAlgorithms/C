//C program to find out the roots of a quadratic equation
#include <math.h>
#include <stdio.h>
int main()
{
    float a, b, c, d, root1, root2, real, imag;
    printf("Enter coefficients a, b and c for the quadratic equation of the form 'ax^2+bx+c=0' (separated by spaces): ");
    scanf("%f %f %f", &a, &b, &c);
     d = b * b - 4 * a * c;

    // condition for real and different roots
    if (d > 0)
    {
        root1 = (-b + sqrt(d)) / (2 * a);
        root2 = (-b - sqrt(d)) / (2 * a);
        printf("Real and distinct roots \nRoot1 = %.2f and Root2 = %.2f", root1, root2);
    }
    // condition for real and equal roots
    else if (d == 0)
    {
        root1 = root2 = -b / (2 * a);
        printf("Real and equal roots \nRoot1 = Root2 = %.2f", root1);
    }
    // if roots are not real
    else
    {
        real = -b / (2 * a);
        imag = sqrt(-d) / (2 * a);
        printf("Imaginary roots \nRoot1 = %.2f +%.2fi and Root2 = %.2f -%.2fi", real, imag, real, imag);
    }

    return 0;
}
/*
Test case 1 :
Enter coefficients a, b and c for the quadratic equation of the form 'ax^2+bx+c' (separated by spaces): 2 8 10
Imaginary roots
Root1 = -2.00 +1.00i and Root2 = -2.00 -1.00i

Test case 2 :
Enter coefficients a, b and c for the quadratic equation of the form 'ax^2+bx+c' (separated by spaces): 4 16 16
root1 = root2 = -2.00
*/