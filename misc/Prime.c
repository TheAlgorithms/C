#include <stdio.h>
#include <math.h>

int isPrime(int x) {
    if (x == 2) {
        return 1;
    }
    if (x < 2 || x % 2 == 0) {
        return 0;
    }
    
    double squareRoot = sqrt(x);
    
    for (int i = 3; i <= squareRoot; i += 2) {
        if (x % i == 0)
            return 0;
    }
    return 1;

}

int main() {
    int a;
    printf("Input a number to see if it is a prime number:\n");
    scanf("%d", &a);
    if (isPrime(a))
        printf("%d is a prime number.\n", a);
    else
        printf("%d is not a prime number.\n", a);
    return 0;
}
