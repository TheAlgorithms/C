/**
 * @file main.c
 * @brief Test and example code for counting bloom filter
 * https://en.wikipedia.org/wiki/Counting_Bloom_filter
 * @author [Eric Breyer](https://github.com/ericbreyer)
 * @see counting_bloom_filter.c, counting_bloom_filter.h
 */
#include <assert.h>  // assertions
#include <stdio.h>   // printing
#include <stdlib.h>  //rand

#include "counting_bloom_filter.h"  // include the structure

int main(void)
{
    struct CountingBloomFilter* bf = construct_CountingBloomFilter(1000, .001);
    int aNum;
    for (int i = 0; i < 100; ++i)
    {
        aNum = rand();
        countingBloom_insert(bf, &aNum, sizeof aNum);
    }
    countingBloom_printStats(bf);
    printf("Contains %d: %d\n", aNum,
           countingBloom_contains(bf, &aNum, sizeof aNum));

    assert(countingBloom_contains(bf, &aNum, sizeof aNum) == PROBABLY_PRESENT);

    countingBloom_remove(bf, &aNum, sizeof aNum);
    printf("Contains %d: %d\n", aNum,
           countingBloom_contains(bf, &aNum, sizeof aNum));

    assert(countingBloom_contains(bf, &aNum, sizeof aNum) ==
           DEFINITELY_NOT_PRESENT);
    --aNum;
    printf("Contains %d: %d\n", aNum,
           countingBloom_contains(bf, &aNum, sizeof aNum));

    assert(countingBloom_contains(bf, &aNum, sizeof aNum) ==
           DEFINITELY_NOT_PRESENT);
    delete_CountingBloomFilter(bf);
    return 0;
}
