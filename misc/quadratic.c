/*C program to find out the roots and their nature of a quadratic equation
Author - Ankush Roy - https://github.com/ankushroy25
*/

/*including the necessary header files
math.h- for mathematical operations
stdio.h - for input-output operations
*/
#include <math.h> 
#include <stdio.h>

//main function body
int main()
{
    //variable decalration
    float a, b, c, d, root1, root2, real, imag; 
    /*a,b,c - the 3 coefficient numbers
    root1,root2 - the final roots that will satisfy the equation
    real - the real part of the root in case of complex roots
    imag - the imaginary part of the root in case of complex roots    
    d - the discriminant for the input equation
    
    */
    
    printf("Enter coefficients a, b and c for the quadratic equation of the form 'ax^2+bx+c=0' (separated by spaces): ");
    scanf("%f %f %f", &a, &b, &c); //input of the coefficients of quadratic equation
    
    d = b * b - 4 * a * c; 

    // condition for real and different roots i.e. discriminant greater than 0
    if (d > 0)
    {
        root1 = (-b + sqrt(d)) / (2 * a);
        root2 = (-b - sqrt(d)) / (2 * a);
        printf("Real and distinct roots \nRoot1 = %.2f and Root2 = %.2f", root1, root2);
    }
    // condition for real and equal roots i.e. discriminant equal to 0
    else if (d == 0)
    {
        root1 = root2 = -b / (2 * a);
        printf("Real and equal roots \nRoot1 = Root2 = %.2f", root1);
    }
    // if roots are not real i.e. discriminant lesser than 0
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