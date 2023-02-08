/**
 * @file main.c
 * @brief Test and example code for counting bloom filter
 * [counting bloom
 * filter](https://en.wikipedia.org/wiki/Counting_countingBloom_filter)
 * @details A Bloom filter is a space-efficient probabilistic data structure,
 * that is used to test whether an element is a member of a set. False positive
 * matches are possible, but false negatives are not – in other words, a query
 * returns either "possibly in set" or "definitely not in set". Elements can be
 * added to the set, and in this counting variant they can also can also be
 * removed because the buckets use counters instead of bits. Thus an element can
 * be removed simply by decrementing all its corresponding buckets. (description
 * of bloom filter from wikipedia)
 * @author [Eric Breyer](https://github.com/ericbreyer)
 * @see counting_countingcountingBloom_filter.c,
 * counting_countingcountingBloom_filter.h
 */
#include <assert.h>  /// assertions
#include <stdio.h>   /// printing
#include <stdlib.h>  /// rand

#include "counting_bloom_filter.h"  /// include the structure

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test()
{
    int err;
    printf("Constructing a new filter.\n");
    struct CountingBloomFilter* bf = construct_CountingBloomFilter(100, .001);
    if (bf == NULL)
    {
        fprintf(stderr, "Not enough memory to create filter");
    }
    assert(bf);

    int testNum;
    printf("Inserting elements into the filter: ");
    for (int i = 0; i < 100; ++i)
    {
        testNum = i;
        printf("%d, ", i);
        err = countingBloom_insert(bf, &testNum, sizeof testNum);
        if (err)
        {
            fprintf(stderr, "Insert caused a counter to overflow\n");
        }
        assert(!err);
    }
    printf("\n\nPrinting Stats:\n");
    countingBloom_printStats(bf);
    printf("\n");
    testNum = 5;
    printf("Checking %d's membership:\n", testNum);
    enum bloomResponse res =
        countingBloom_contains(bf, &testNum, sizeof testNum);
    assert(res == PROBABLY_PRESENT);
    printf("%d is %s.\n\n", testNum,
           res == PROBABLY_PRESENT ? "probably present"
                                   : "definitely not present");
    printf("Removing %d from the filter\n", testNum);
    err = countingBloom_remove(bf, &testNum, sizeof testNum);
    if (err)
    {
        fprintf(stderr, "Remove caused a counter to underflow\n");
    }
    assert(!err);
    printf("Checking %d's membership:\n", testNum);
    res = countingBloom_contains(bf, &testNum, sizeof testNum);
    assert(res == DEFINITELY_NOT_PRESENT);
    printf("%d is %s.\n\n", testNum,
           res == PROBABLY_PRESENT ? "probably present"
                                   : "definitely not present");
    testNum = 1000;
    printf("Checking %d's membership:\n", testNum);
    res = countingBloom_contains(bf, &testNum, sizeof testNum);
    assert(res == DEFINITELY_NOT_PRESENT);
    printf("%d is %s.\n\n", testNum,
           res == PROBABLY_PRESENT ? "probably present"
                                   : "definitely not present");
    printf("Deleting the filter.\n");
    delete_CountingBloomFilter(bf);
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
