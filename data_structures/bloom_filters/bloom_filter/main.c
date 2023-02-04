#include "./bloom_filter.h"
#include <sys/resource.h>

int main(void) {
    struct BloomFilter * bf = construct_bloomFilter(100, .001);
    int aP;
    for(int i = 0; i < 10; ++i) {
        
        int * p = malloc(sizeof *p);
        *p = i;
        aP = *p;
        bloom_insert(bf, p, sizeof *p);
        free(p);
    }
    bloom_printStats(bf);
    printf("\nContains %d: %d\n", aP, bloom_contains(bf, &aP, sizeof aP));
    aP = 1000;
    printf("Contains %d: %d\n", aP, bloom_contains(bf, &aP, sizeof aP));
    delete_bloomFilter(bf);
    return 0;
}