#include <stdio.h>

// Euclid's algorithm
int GCD(int x, int y) {
    if (x == y || y == 0)
        return x;
    if (x == 0)
        return y;
    if (x > y)
        return GCD(x-y, y);
    else
        return GCD(x, y-x);
}

int main() {
    int a, b;
    printf("Input two numbers:\n");
    scanf("%d %d", &a, &b);
    printf("Greatest common divisor: %d\n", GCD(a, b));
}
