#include <stdio.h>

/**
 * Calculates the factorial of a non-negative integer using recursion.
 *
 * @param n The non-negative integer for which to calculate the factorial.
 * @return The factorial of n.
 */
unsigned long long factorial(int n) {
    // Base case: If n is 0 or 1, the factorial is 1.
    if (n == 0 || n == 1) {
        return 1;
    }
    // Recursive case: Multiply n by the factorial of (n-1).
    else {
        return n * factorial(n - 1);
    }
}

int main() {
    int num;
    
    printf("Enter a non-negative integer: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        unsigned long long result = factorial(num);
        printf("Factorial of %d is %llu\n", num, result);
    }

    return 0;
}
