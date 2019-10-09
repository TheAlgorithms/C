#include <stdio.h>

unsigned long gcd(unsigned long a, unsigned long b) {
    unsigned long r;
    if (a > b) {
        unsigned long t = a;
        a = b;
        b = t;
    }
    while (r = a % b) {
        a = b;
        b = r;
    }
    return b;
}

unsigned long lcm(unsigned long a, unsigned long b) {
    unsigned long long p = (unsigned long long)a * b;
    return p / gcd(a, b);
}

int main(void) {
    unsigned long ans = 1;
    unsigned long i;
    for (i = 1; i <= 20; i++) {
        ans = lcm(ans, i);
    }
    printf("%lu\n", ans);
    return 0;
}
