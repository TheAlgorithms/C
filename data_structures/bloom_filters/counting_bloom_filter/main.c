/**
 * @file main.c
 * @brief Test and example code for counting bloom filter
 * [bloom filter](https://en.wikipedia.org/wiki/Counting_Bloom_filter)
 * @details A Bloom filter is a space-efficient probabilistic data structure,
 * that is used to test whether an element is a member of a set. False positive
 * matches are possible, but false negatives are not – in other words, a query
 * returns either "possibly in set" or "definitely not in set". Elements can be
 * added to the set, and can also be removed in this counting variant.
 * (description of bloom filter from wikipedia)
 * @author [Eric Breyer](https://github.com/ericbreyer)
 * @see counting_countingBloom_filter.c, counting_countingBloom_filter.h
 */
#include <assert.h>  /// assertions
#include <stdio.h>   /// printing
#include <stdlib.h>  /// rand

#include "counting_bloom_filter.h"  /// include the structure

int test()
{
    struct BloomFilter* bf = construct_CountingBloomFilter(100, .001);
    int testNum;
    for (int i = 0; i < 10; ++i)
    {
        testNum = i;
        countingBloom_insert(bf, &testNum, sizeof testNum);
    }
    countingBloom_printStats(bf);
    assert(countingBloom_contains(bf, &testNum, sizeof testNum) ==
           PROBABLY_PRESENT);
    testNum = 1000;
    assert(countingBloom_contains(bf, &testNum, sizeof testNum) ==
           DEFINITELY_NOT_PRESENT);
    delete_CountingBloomFilter(bf);
}

int main(void)
{
    test();
    struct BloomFilter* example = construct_CountingBloomFilter(100, .001);
    int num = 5;
    countingBloom_insert(example, &num, sizeof num);  // insert an item
    enum bloomResponse res = countingBloom_contains(
        example, &num, sizeof num);  // check for membership
    if (res == DEFINITELY_NOT_PRESENT)
        printf("%d is DEFINITELY_NOT_PRESENT\n", num);
    else if (res == PROBABLY_PRESENT)
        printf("%d is PROBABLY_PRESENT\n", num);
    countingBloom_remove(example, &num, sizeof num);  // remove an item
    res = countingBloom_contains(example, &num,
                                 sizeof num);  // check for membership
    if (res == DEFINITELY_NOT_PRESENT)
        printf("%d is now DEFINITELY_NOT_PRESENT\n", num);
    else if (res == PROBABLY_PRESENT)
        printf("%d is now PROBABLY_PRESENT\n", num);
    delete_CountingBloomFilter(example);
    return 0;
}
