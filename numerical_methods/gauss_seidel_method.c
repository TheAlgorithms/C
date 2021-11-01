#include <math.h>
#include <stdio.h>

int main()
{
    float a, b, c, a1, a2, a3, b1, b2, b3, c1, c2, c3, d1, d2, d3, x1, x2, x3;

    printf("Enter values of eq1:");
    scanf("%f%f%f%f", &a1, &a2, &a3, &d1);
    printf("Enter values of eq2:");
    scanf("%f%f%f%f", &b1, &b2, &b3, &d2);
    printf("Enter values of eq3:");
    scanf("%f%f%f%f", &c1, &c2, &c3, &d3);
    x1 = x2 = x3 = 0.0;
    do
    {
        a = x1;
        b = x2;
        c = x3;
        x1 = (1 / a1) * (d1 - (a2 * x2) - (a3 * x3));
        x2 = (1 / b2) * (d2 - (b1 * x1) - (b3 * x3));
        x3 = (1 / c3) * (d3 - (c1 * x1) - (c2 * x2));
    } while (fabs(x1 - a) > 0.0001 && fabs(x2 - b) > 0.0001 &&
             fabs(x3 - c) > 0.0001);
    printf("x1=%f\nx2=%f\nx3=%f", x1, x2, x3);

    return 0;
}