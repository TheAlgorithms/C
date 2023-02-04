#include "./counting_bloom_filter.h"
#include <sys/resource.h>

int main(void) {
    struct CountingBloomFilter * bf = construct_CountingBloomFilter(1000, .001);
    int aP;
    for(int i = 0; i < 100; ++i) {
        
        int * p = malloc(sizeof *p);
        *p = rand();
        aP = *p;
        countingBloom_insert(bf, p, sizeof *p);
        free(p);
    }
    countingBloom_printStats(bf);
    printf("\nContains %d: %d\n", aP, countingBloom_contains(bf, &aP, sizeof aP));
    countingBloom_remove(bf, &aP, sizeof aP);
    printf("\nContains %d: %d\n", aP, countingBloom_contains(bf, &aP, sizeof aP));
    --aP;
    printf("Contains %d: %d\n", aP, countingBloom_contains(bf, &aP, sizeof aP));
    delete_CountingBloomFilter(bf);
    return 0;
}