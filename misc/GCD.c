#include <stdio.h>

// Euclid's algorithm
int GCD(int x, int y) {
    if (y == 0)
        return x;
    return GCD(y, x%y);
}

int main() {
    int a, b;
    printf("Input two numbers:\n");
    scanf("%d %d", &a, &b);
    printf("Greatest common divisor: %d\n", GCD(a, b));
}
