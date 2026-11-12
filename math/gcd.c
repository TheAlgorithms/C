#include <stdio.h>

// Euclid's algorithm
// This function returns the greatest common divisor of x and y.
int GCD(int x, int y)
{
    if (y == 0)
        return x;
    return GCD(y, x % y);
}

int main()
{
    int a, b;
    printf("Input two numbers:\n");
    scanf("%d %d", &a, &b);
    printf("Greatest common divisor: %d\n", GCD(a, b));
}
