/**
 * @file main.c
 * @brief Test and example code for bloom filter
 * [bloom filter](https://en.wikipedia.org/wiki/Bloom_filter)
 * @details A Bloom filter is a space-efficient probabilistic data structure,
 * that is used to test whether an element is a member of a set. False positive
 * matches are possible, but false negatives are not – in other words, a query
 * returns either "possibly in set" or "definitely not in set". Elements can be
 * added to the set, but not removed (description of bloom filter from
 * wikipedia)
 * @author [Eric Breyer](https://github.com/ericbreyer)
 * @see bloom_filter.c, bloom_filter.h
 */

#include <assert.h>  /// assertions
#include <stdio.h>   /// printing

#include "bloom_filter.h"  /// include the structure

int test()
{
    struct BloomFilter* bf = construct_bloomFilter(100, .001);
    int testNum;
    for (int i = 0; i < 10; ++i)
    {
        testNum = i;
        bloom_insert(bf, &testNum, sizeof testNum);
    }
    bloom_printStats(bf);
    assert(bloom_contains(bf, &testNum, sizeof testNum) == PROBABLY_PRESENT);
    testNum = 1000;
    assert(bloom_contains(bf, &testNum, sizeof testNum) ==
           DEFINITELY_NOT_PRESENT);
    delete_bloomFilter(bf);
}

int main(void)
{
    test();
    struct BloomFilter* example = construct_bloomFilter(100, .001);
    int num = 5;
    bloom_insert(example, &num, sizeof num);  // insert an item
    enum bloomResponse res =
        bloom_contains(example, &num, sizeof num);  // check for membership
    if (res == DEFINITELY_NOT_PRESENT)
        printf("%d is DEFINITELY_NOT_PRESENT\n", num);
    else if (res == PROBABLY_PRESENT)
        printf("%d is PROBABLY_PRESENT\n", num);
    delete_bloomFilter(example);
    return 0;
}
