#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x[20], y[20], a, sum, p;
    int n, i, j;

    printf("Enter the no of entry to insert->");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("enter the value of x%d->", i);
        scanf("%f", &x[i]);
        printf("enter the value of y%d->", i);
        scanf("%f", &y[i]);
    }
    printf("\n X \t\t Y \n");
    printf("----------------------------\n");
    for (i = 0; i < n; i++)
    {
        printf("%f\t", x[i]);
        printf("%f\n", y[i]);
    }
    printf("\nenter the value of x for interpolation:");
    scanf("%f", &a);
    sum = 0;
    for (i = 0; i < n; i++)
    {
        p = 1.0;
        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                p = p * (a - x[j]) / (x[i] - x[j]);
            }
            sum = sum + y[i] * p;
        }
        printf("ans is->%f", sum);

        return 0;
    }
}