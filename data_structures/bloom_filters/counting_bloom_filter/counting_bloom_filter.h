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

// A union to store the counts as 4-bit buckets instead of 8.
// Allows for the counting filter to be more space efficient.
union Nibbler {
     struct { 
        unsigned int first:4;
        unsigned int second:4;
     } nibbles;
     unsigned char byte_value;
};

/**
 * @brief A probabilistic set data structure supporting insertion and removal
 * that can make time and space efficient membership queries at the expense of 
 * a small probability of false positives (but no false negatives). 
 * In other words, a contains query can return either DEFINITELY_NOT_PRESENT 
 * or PROBABLY_PRESENT.
 */
struct CountingBloomFilter;

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
 * @param this the CountingBloomFilter to print the stats of
 */
void countingBloom_printStats(struct CountingBloomFilter *this);

/**
 * @brief Inserts an item into the filter.
 * 
 * @param[in] this the CountingBloomFilter to insert an item into
 * @param[in] elem the pointer to the element to insert
 * @param[in] size the size of said elements in bytes
 * 
 * @return 0 if the insert was successful
 * @return non-zero if the insert was unsuccessful (a counter overflowed)
 */
int countingBloom_insert(struct CountingBloomFilter *this, void *elem, size_t size);

/**
 * @brief Removes an item from the filter.
 * 
 * @param[in] this the CountingBloomFilter to remove an item from
 * @param[in] elem the pointer to the element to remove
 * @param[in] size the size of said elements in bytes
 * 
 * @return 0 if the remove was successful
 * @return non-zero if the remove was unsuccessful (a counter underflowed)
 */
int countingBloom_remove(struct CountingBloomFilter *this, void *elem, size_t size);

/**
 * @brief Querys the filter for item membership an item into the filter.
 * 
 * @param[in] this the CountingBloomFilter to perform the query on
 * @param[in] elem the pointer to the element to test
 * @param[in] size the size of said elements in bytes
 * 
 * @return item is DEFINITELY_NOT_PRESENT or PROBABLY_PRESENT
 */
enum bloomResponse countingBloom_contains(struct CountingBloomFilter *this, void *elem, size_t size);

/**
 * @brief Deletes an instance of a CountingBloomFilter
 * NOTE: Also frees the memory pointed to by this
 * 
 * @param[in] this the CountingBloomFilter to delete
 */
void delete_CountingBloomFilter(struct CountingBloomFilter *this);

/**
 * @brief Constructs an instance of a CountingBloomFilter. For a desired number
 *          of elements to insert and false positive probability.
 * NOTE: mallocs memory for the struct
 * 
 * @param[in] expectedElems the max number of elements expected 
 *                          to be placed in the filter
 * @param[in] falsePositveProb the desired false positive probability
 * @return the new struct CountingBloomFilter* or NULL if the malloc failed
 */
struct CountingBloomFilter *construct_CountingBloomFilter(int expectedElems, float falsePositveProb);