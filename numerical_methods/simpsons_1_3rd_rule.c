#include <math.h>
#include <stdio.h>

float f(float x)
{
    return 1.0 +
           x * x * x;  // This is the expresion of the function to integrate?
}

int main()
{
    int i, n;
    float a, b, h, x, s2, s3, sum, integral;

    printf("enter the lower limit of the integration:");
    scanf("%f", &a);
    printf("enter the upper limit of the integration:");
    scanf("%f", &b);
    printf("enter the number of intervals:");
    scanf("%d", &n);

    h = (b - a) / n;
    sum = f(a) + f(b);
    s2 = s3 = 0.0;

    for (i = 1; i < n; i += 3)
    {
        x = a + i * h;
        s3 = s3 + f(x) + f(x + h);
    }

    for (i = 3; i < n; i += 3)
    {
        x = a + i * h;
        s2 = s2 + f(x);
    }

    integral = (h / 3.0) * (sum + 2 * s2 + 4 * s3);
    printf("\nValue of the integral = %9.4f\n", integral);

    return 0;
}