
#include <stdio.h>

int main(void) {
    long long n;
    printf("Enter a non-negative integer: ");
    if (scanf("%lld", &n) != 1) {
        printf("Invalid input\n");
        return 1;
    }
    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return 1;
    }

    long long result = 1;
    for (long long i = 2; i <= n; ++i) {
        result *= i;
    }

    printf("%lld! = %lld\n", n, result);
    return 0;
}
