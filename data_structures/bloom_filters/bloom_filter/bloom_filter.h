/**
 * @file bloom_filter.h
 * @brief Declaration of a bloom filter
 * [bloom filter](https://en.wikipedia.org/wiki/Bloom_filter)
 * @details A Bloom filter is a space-efficient probabilistic data structure,
 * that is used to test whether an element is a member of a set. False positive
 * matches are possible, but false negatives are not – in other words, a query
 * returns either "possibly in set" or "definitely not in set". Elements can be
 * added to the set, but not removed (description of bloom filter from
 * wikipedia)
 * @author [Eric Breyer](https://github.com/ericbreyer)
 * @see bloom_filter.c, main.c
 */

#include <stdio.h>   /// logging
#include <stdlib.h>  /// free and calloc
#include <string.h>  /// memcpy
#pragma once

// Options for a set membership query.
enum bloomResponse
{
    DEFINITELY_NOT_PRESENT = 0,
    PROBABLY_PRESENT = 1
};

/**
 * @brief A probabilistic set data structure supporting insertion
 * that can make time and space efficient membership queries at the expense of
 * a small probability of false positives (but no false negatives).
 * In other words, a contains query can return either DEFINITELY_NOT_PRESENT
 * or PROBABLY_PRESENT.
 */
struct BloomFilter;

/**
 * @brief Prints some stats about the filter.
 * - Max Elements (n)
 * - Hash Functions (k)
 * - Slots (m)
 * - Estimated Elements Inserted (n*)
 * By nature of the filter we can not retrieve what elements were
 * previously inserted, so this is the best version of a "to string" we
 * can do
 *
 * @param this the bloomFilter to print the stats of
 */
void bloom_printStats(struct BloomFilter *this);

/**
 * @brief Inserts an item into the filter.
 *
 * @param[in] this the bloomFilter to insert an item into
 * @param[in] elem the pointer to the element to insert
 * @param[in] size the size of said elements in bytes
 */
void bloom_insert(struct BloomFilter *this, void *elem, size_t size);

/**
 * @brief Querys the filter for an item's membership in the filter.
 *
 * @param[in] this the bloomFilter to perform the query on
 * @param[in] elem the pointer to the element to test
 * @param[in] size the size of said elements in bytes
 *
 * @return item is DEFINITELY_NOT_PRESENT or PROBABLY_PRESENT
 */
enum bloomResponse bloom_contains(struct BloomFilter *this, void *elem,
                                  size_t size);

/**
 * @brief Deletes an instance of a bloomFilter
 * NOTE: Also frees the memory pointed to by this
 *
 * @param[in] this the bloomFilter to delete
 */
void delete_bloomFilter(struct BloomFilter *this);

/**
 * @brief Constructs an instance of a bloomFilter. For a desired number
 *          of elements to insert and false positive probability.
 * NOTE: allocates memory for the struct
 *
 * @param[in] expectedElems the max number of elements expected
 *                          to be placed in the filter
 * @param[in] falsePositiveProb the desired false positive probability
 * @return the new struct bloomFilter* or NULL if the memory allocation failed
 */
struct BloomFilter *construct_bloomFilter(int expectedElems,
                                          float falsePositiveProb);
