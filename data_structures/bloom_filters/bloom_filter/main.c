/**
 * @file main.c
 * @brief Test and example code for bloom filter
 * https://en.wikipedia.org/wiki/Bloom_filter
 * @author [Eric Breyer](https://github.com/ericbreyer)
 * @see bloom_filter.c, bloom_filter.h
 */

#include <assert.h>  // assertions
#include <stdio.h>   // printing

#include "bloom_filter.h"  // include the structure

int main(void)
{
    struct BloomFilter* bf = construct_bloomFilter(100, .001);
    int aNum;
    for (int i = 0; i < 10; ++i)
    {
        aNum = i;
        bloom_insert(bf, &aNum, sizeof aNum);
    }
    bloom_printStats(bf);
    printf("\nContains %d: %d\n", aNum, bloom_contains(bf, &aNum, sizeof aNum));
    assert(bloom_contains(bf, &aNum, sizeof aNum) == PROBABLY_PRESENT);
    aNum = 1000;
    printf("Contains %d: %d\n", aNum, bloom_contains(bf, &aNum, sizeof aNum));
    assert(bloom_contains(bf, &aNum, sizeof aNum) == DEFINITELY_NOT_PRESENT);
    delete_bloomFilter(bf);
    return 0;
}
