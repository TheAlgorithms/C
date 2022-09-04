#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX 50

int main()
{
    int n, i;
    float x[MAX], y[MAX], sumX = 0, sumPowX = 0, sumY = 0, sumXY = 0, m, c;

    /* to get the User Input */
    printf("How many data points > ");
    scanf("%d", &n);
    printf("Enter data:\n");
    printf("============\n");
    
    //saving user input into the array
    for (i = 1; i <= n; i++)
    {
        printf("\n(Point %d)\n",i);
        printf("x[%d]=", i);
        scanf("%f", &x[i]);
        printf("y[%d]=", i);
        scanf("%f", &y[i]);
    }

    /* Calculating Required Sum */
    for (i = 1; i <= n; i++)
    {
        sumX = sumX + x[i];
        sumPowX = sumPowX + pow(x[i],2);
        sumY = sumY + y[i];
        sumXY = sumXY + x[i] * y[i];
    }

    /* Calculating m and c */
    m = (n * sumXY - sumX * sumY) / (n * sumPowX - pow(sumX,2));
    c = (sumY - m * sumX) / n;


    /* Displaying value of m and c */
    printf("Values are: a=%0.2f and b = %0.2f", c, m);
    if (c < 0)
    {
        c = c*-1;
        printf("\nEquation of best fit is: y = %0.2fx - %0.2f", m, c);
    }else if (c>0)
    {
        printf("\nEquation of best fit is: y = %0.2fx + %0.2f", m, c);
    }else
    {
        printf("\nEquation of best fit is: y = %0.2fx", m);
    }   
    return (0);
}
