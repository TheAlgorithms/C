#include <stdio.h>
int value(double arr[], double m, double *e, int n)
{
    int b = n + 1;
    int a = 0;
    int c = 0;
    double sum = 0;
    double d = 1;
    int i = n;
    while (i >= 0)
    {
        while (c < a)
        {
            d = d * m;
            c++;
        }
        sum = arr[i] * d + sum;
        a++;
        i--;
    }
    *e = sum;
}
int diff(double arr[], double m, double *c, int n)
{
    int a = n;
    int i = 0;
    double arr1[n];
    while (i < n)
    {
        arr1[i] = arr[i + 1] * (a);
        a--;
        i++;
    }
    value(arr1, m, c, n);
}
int main()
{
    int n;
    double p, q;
    scanf("%d", &n);
    int b = n + 1;
    double arr[b];
    double c, d, x, y;
    double h;
    int count = 0;
    p = -100000;
    for (int i = 0; i < b; i++)
    {
        scanf("%lf", &arr[i]);
    }
go:
    if (count < n)
    {
        for (q = p + 1; q < 1000000; q++)
        {
            value(arr, p, &c, n);
            value(arr, q, &d, n);
            if (c * d <= 0)
            {
                p = q - 1;
                value(arr, p, &c, n);
                if (c == 0 && d == 0)
                {
                    printf("%lf\n", p);
                    count++;
                    p = q;
                    goto go;
                }
                else if (c == 0)
                {
                    printf("%lf\n", p);
                    count++;
                    p = q;
                    goto go;
                }
                else if (d == 0)
                {
                    p = q;
                    goto go;
                }
                while (c * d < 0)
                {
                    h = (p + q) / 2;
                    double e;
                    value(arr, h, &e, n);
                    if (e < 0.005 && e > -0.005)
                    {
                        printf("%lf\n", h);
                        count++;
                        p = q;
                        goto go;
                    }
                    else if (e < -0.005)
                    {
                        if (c < 0)
                        {
                            p = h;
                        }
                        else
                        {
                            q = h;
                        }
                    }
                    else if (e > 0.005)
                    {
                        if (c > 0)
                        {
                            p = h;
                        }
                        else
                        {
                            q = h;
                        }
                    }
                }
            }
            else
            {
                diff(arr, p, &x, n);
                diff(arr, q, &y, n);
                if (x * y < 0)
                {
                    for (int t = 0; t < 10000000; t++)
                    {
                        h = (p + q) / 2;
                        double e;
                        value(arr, h, &e, n);
                        if (e < 0.005 && e > -0.005)
                        {
                            printf("%lf\n", h);
                            count++;
                            p = q;
                            goto go;
                        }
                        else if (e < -0.005)
                        {
                            if (c < 0)
                            {
                                p = h;
                            }
                            else
                            {
                                q = h;
                            }
                        }
                        else if (e > 0.005)
                        {
                            if (c > 0)
                            {
                                p = h;
                            }
                            else
                            {
                                q = h;
                            }
                        }
                    }
                }
            }
        }
    }
    else
    {
        return 0;
    }
}
