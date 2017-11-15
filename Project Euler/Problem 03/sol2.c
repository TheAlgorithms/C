/*
Problem Statement:
The prime factors of 13195 are 5,7,13 and 29. What is the largest prime factor of a given number N?
e.g. for 10, largest prime factor = 5. For 17, largest prime factor = 17.
*/
#include <stdio.h>
#include <math.h>

int main() {
    long long n,i;
    scanf("%lld", &n);
    long long p=1; //p= largest prime factor
    for (i=2; i*i<=n; i++) {
        while (n%i==0) {
            p = i;
            n /= i;
        }
    }
    if (n > 1) p = n;
        printf("%lld\n", p);
    return 0;
}
