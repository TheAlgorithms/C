#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma once


// Options for a set membership query.
enum bloomResponse {
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
 * @brief Querys the filter for item membership an item into the filter.
 * 
 * @param[in] this the bloomFilter to perform the query on
 * @param[in] elem the pointer to the element to test
 * @param[in] size the size of said elements in bytes
 * 
 * @return item is DEFINITELY_NOT_PRESENT or PROBABLY_PRESENT
 */
enum bloomResponse bloom_contains(struct BloomFilter *this, void *elem, size_t size);

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
 * NOTE: mallocs memory for the struct
 * 
 * @param[in] expectedElems the max number of elements expected 
 *                          to be placed in the filter
 * @param[in] falsePositveProb the desired false positive probability
 * @return the new struct bloomFilter* or NULL if the malloc failed
 */
struct BloomFilter *construct_bloomFilter(int expectedElems, float falsePositveProb);