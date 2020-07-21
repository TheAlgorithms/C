/*
code for computing nth catalan number
*/
#include <stdio.h>
long int factorial(int x)  // long int for more than 10 factorial
{
    int i;
    long int fac;  // fac stores x factorial
    fac = x;
    for (i = 1; i < x; i++)  // loop to calculate x factorial
    {
        fac = fac * (x - i);
    }
    return fac;  // returning x factorial
}
int main()
{
    long int f1, f2, f3;  // long int for more than 10 factorial
    int n;
    float C;  // C is catalan number for n;
    scanf("%d", &n);
    f1 = factorial(2 * n);
    f2 = factorial(n + 1);
    f3 = factorial(n);
    C = f1 / (f2 * f3);  // formula for catalan number for n
    printf("%0.2f", C);
    return 0;
}
