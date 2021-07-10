/**
 * C program to implement sum of Taylor Series(e^x)
 * e^x (upto n-terms) = 1 + x^1/1! + x^2/2! + x^3/3! + ....... + x^n/n!
 */

#include <stdio.h>

// Function for Taylor Series(e^x)
double e(int x, int n)
{    
    static double power = 1, fact = 1;
    double sum;
    for (int i = 0; i <= n; i++)
    {
        if (i == 0)
            sum = 1;
        else
        {
            power = power * x;
            fact = fact * i;
            sum = sum + (power / fact);
        }
    }
    return sum;
}

/** Main function */
int main()
{
    int x, n;
    double total_sum;

    // Taking input for e^x

    printf("For e^x, enter x : ");
    scanf("%d", &x);

    printf("Enter the n-term for sum : ");
    scanf("%d", &n);

    total_sum = e(x, n);
    printf("The sum of e^%d upto %d-terms is %f", x, n, total_sum);

    return 0;
}

/*  Test Case:
 * Case 1:   x                 : 2
 *           n-terms           : 20
 *           e^x (for n-terms) : 7.389056
 *
 * 
 * Case 2:   x                 : -1
 *           n-terms           : 20
 *           e^x (for n-terms) : 0.367879
 */