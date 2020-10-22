#include <stdio.h>

int factorial(int fj);
float power(float fx, int fj);
int main()
{
    float x, x1, sum = 0.0f;
    int i, lim, j;
    printf("\n\t Cos X series: ");
    printf("\n\t Enter X (deg): ");
    scanf("%f", &x);
    printf("Enter the limit upto which you want to expand the series: ");
    scanf("%d", &lim);
    x1 = x;
    x = x * (3.1415 / 180);
    for (i = 0; i < lim; i++)
    {
        j = 2 * i;
        if (i % 2 == 0)
        {
            sum = sum + power(x, j) / factorial(j);
        }
        else
            sum = sum - power(x, j) / factorial(j);
    }
    printf("Cos(%0.1f) = %f", x1, sum);
    return 0;
}
int factorial(int fj)
{
    int i, fac = 1;
    for (i = 1; i <= fj; i++)
    {
        fac = fac * i;
    }
    return fac;
}
float power(float fx, int fj)
{
    float pow = 1.0;
    int i = 0;
    for (i = 0; i < fj; i++)
    {
        pow = fx * pow;
    }
    return pow;
}
