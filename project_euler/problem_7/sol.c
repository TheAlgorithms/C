#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *sieve;
    size_t i;
    unsigned count = 0;
    size_t n = 1000000;
    const unsigned target = 10001;

    sieve = calloc(n, sizeof *sieve);
    for (i = 2; i < n; i++) {
        if (!sieve[i]) {
            size_t j; 
            count++;
            if (count == target) {
                printf("%lu\n", i);
                break;
            }
            for (j = i * 2; j < n; j += i) {
                sieve[j] = 1;
            }
        }
    }
    free(sieve);
    return 0;
}
