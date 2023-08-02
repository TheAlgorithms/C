/*
Program to calculate the interest of a certain amount of
money, a defined number of periods and an interest rate
The parameters are defined as:
principal := The original amount of money, where we receive the
interest on, e.g. 1000$
number_of_periods := The number of periods the interest is
received, e.g. 3 years
interest_rate := The interest earned per period, e.g. 3% pa
*/

#include <stdio.h>
#include <math.h>
int calculate_interest(float principal, int number_of_periods, float interest_rate)
{
    if (number_of_periods < 0)
    {
        //The number of periods cannot be negative
        printf("The number of periods must be > 0\n");
        return 0;
    }
    else
    {
        printf("The result is:\n");
        float result = principal * pow((1+interest_rate),number_of_periods);
        printf("%f",result);
    }
        return 0;
}

int main() {
    calculate_interest(1000,2,0.03);
    return 0;
}
