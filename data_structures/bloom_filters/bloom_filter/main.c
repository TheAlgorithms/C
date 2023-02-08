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

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test()
{
    printf("Constructing a new filter.\n");
    struct BloomFilter* bf = construct_bloomFilter(100, .001);
    if (bf == NULL)
    {
        printf("Not enough memory to create filter");
    }
    assert(bf);
    int testNum;
    printf("Inserting elements into the filter: ");
    for (int i = 0; i < 10; ++i)
    {
        testNum = i;
        printf("%d, ", i);
        bloom_insert(bf, &testNum, sizeof testNum);
    }
    printf("\n\nPrinting Stats:\n");
    bloom_printStats(bf);
    printf("\n");
    testNum = 5;
    printf("Checking %d's membership:\n", testNum);
    enum bloomResponse res = bloom_contains(bf, &testNum, sizeof testNum);
    assert(res == PROBABLY_PRESENT);
    printf("%d is %s.\n\n", testNum,
           res == PROBABLY_PRESENT ? "probably present"
                                   : "definitely not present");
    testNum = 1000;
    printf("Checking %d's membership:\n", testNum);
    res = bloom_contains(bf, &testNum, sizeof testNum);
    assert(res == DEFINITELY_NOT_PRESENT);
    printf("%d is %s.\n\n", testNum,
           res == PROBABLY_PRESENT ? "probably present"
                                   : "definitely not present");
    printf("Deleting the filter.\n");
    delete_bloomFilter(bf);
    printf("Testing successfully completed!\n");
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main(void)
{
    test();
    return 0;
}
