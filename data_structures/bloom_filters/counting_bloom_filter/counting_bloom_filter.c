/**
 * @file counting_bloom_filter.c
 * @brief Implementation of a counting bloom filter
 * https://en.wikipedia.org/wiki/Counting_Bloom_filter
 * @author [Eric Breyer](https://github.com/ericbreyer)
 * @see counting_bloom_filter.h, main.c
 */

#include "counting_bloom_filter.h"  // interface

#include <math.h>    // log
#include <stdint.h>  // extended integer types

/**
 * @brief Helper function for hash
 *
 * @param[in] k the number to scramble
 * @return int the scrambled number
 */
static inline int murmur_32_scramble(int k)
{
    k *= 0xcc9e2d51;
    k = (k << 15) | (k >> 17);
    k *= 0x1b873593;
    return k;
}
/**
 * @brief The hash function used to hash the values. Can simulate indefinite
 * uniform independent hash functions by seeding this with a different number
 * each time.
 * Algorithm credit: https://en.wikipedia.org/wiki/MurmurHash#Algorithm
 *
 * @param[in] key the thing to hash
 * @param[in] len the size of said key
 * @param[in] seed the seed
 * @return int the hashed key
 */
int murmur3_32(const uint8_t *key, size_t len, int seed)
{
    seed = murmur_32_scramble((seed + pow(seed, 3)) * pow(2, seed));
    int h = seed;
    int k;
    /* Read in groups of 4. */
    for (size_t i = len >> 2; i; i--)
    {
        // Here is a source of differing results across endiannesses.
        // A swap here has no effects on hash properties though.
        memcpy(&k, key, sizeof(int));
        key += sizeof(int);
        h ^= murmur_32_scramble(k);
        h = (h << 13) | (h >> 19);
        h = h * 5 + 0xe6546b64;
    }
    /* Read the rest. */
    k = 0;
    for (unsigned long i = len & 3; i; i--)
    {
        k <<= 8;
        k |= key[i - 1];
    }
    // A swap is *not* necessary here because the preceding loop already
    // places the low bytes in the low places according to whatever endianness
    // we use. Swaps only apply when the memory is copied in a chunk.
    h ^= murmur_32_scramble(k);
    /* Finalize. */
    h ^= len;
    h ^= h >> 16;
    h *= 0x85ebca6b;
    h ^= h >> 13;
    h *= 0xc2b2ae35;
    h ^= h >> 16;
    return h;
}

// A union to store the counts as 4-bit buckets instead of 8.
// Allows for the counting filter to be more space efficient.
union Nibbler
{
    struct
    {
        unsigned int first : 4;
        unsigned int second : 4;
    } nibbles;
    unsigned char byte_value;
};

struct CountingBloomFilter
{
    /**
     * @brief The number of hash functions this bloom filter will use.
     */
    int hashFuncs;
    /**
     * @brief The number of buckets in the underlying array.
     */
    int numSlots;
    /**
     * @brief The expected max number of elements to be inserted
     */
    int maxElems;
    /**
     * @brief The underlying array structure of the filter
     */
    union Nibbler buckets[];
};

void countingBloom_printStats(struct CountingBloomFilter *this)
{
    int numOnes = 0;
    for (int i = 0; i < this->numSlots; ++i)
    {
        float slot = ((float)i) / 2.0;
        if (slot == (int)slot)
        {
            if (this->buckets[(int)slot].nibbles.first > 0)
            {
                ++numOnes;
            }
        }
        else
        {
            if (this->buckets[(int)slot].nibbles.second > 0)
            {
                ++numOnes;
            }
        }
    }

    float nStar = -((float)this->numSlots / (float)this->hashFuncs) *
                  log(1.0 - ((float)numOnes / (float)this->numSlots));

    printf(
        "Max Elements (n): %d \nHash Functions (k): %d \nSlots (m): "
        "%d\nEstimated Elements Inserted (n*): %f (estimate deteriorates as "
        "inserted elements approaches n)\n",
        this->maxElems, this->hashFuncs, this->numSlots, nStar);
}

int countingBloom_insert(struct CountingBloomFilter *this, void *elem,
                         size_t size)
{
    for (int i = 0; i < this->hashFuncs; ++i)
    {
        int spot = murmur3_32((uint8_t *)elem, size, i) % this->numSlots;
        float slot = ((float)spot) / 2.0;
        if (slot == (int)slot)
        {
            if (this->buckets[(int)slot].nibbles.first++ == 15)
            {
                return 1;
            };
        }
        else
        {
            if (this->buckets[(int)slot].nibbles.second++ == 15)
            {
                return 1;
            };
        }
    }
    return 0;
}
int countingBloom_remove(struct CountingBloomFilter *this, void *elem,
                         size_t size)
{
    for (int i = 0; i < this->hashFuncs; ++i)
    {
        int spot = murmur3_32((uint8_t *)elem, size, i) % this->numSlots;
        float slot = ((float)spot) / 2.0;
        if (slot == (int)slot)
        {
            if (this->buckets[(int)slot].nibbles.first-- == 0)
            {
                return 1;
            };
        }
        else
        {
            if (this->buckets[(int)slot].nibbles.second-- == 0)
            {
                return 1;
            };
        }
    }
    return 0;
}
enum bloomResponse countingBloom_contains(struct CountingBloomFilter *this,
                                          void *elem, size_t size)
{
    for (int i = 0; i < this->hashFuncs; ++i)
    {
        int spot = murmur3_32((uint8_t *)elem, size, i) % this->numSlots;
        float slot = ((float)spot) / 2.0;
        if (slot == (int)slot)
        {
            if (this->buckets[(int)slot].nibbles.first == 0)
            {
                return DEFINITELY_NOT_PRESENT;
            }
        }
        else
        {
            if (this->buckets[(int)slot].nibbles.second == 0)
            {
                return DEFINITELY_NOT_PRESENT;
            }
        }
    }
    return PROBABLY_PRESENT;
}

void delete_CountingBloomFilter(struct CountingBloomFilter *this)
{
    free(this);
}

struct CountingBloomFilter *construct_CountingBloomFilter(
    int expectedElems, float falsePositiveProb)
{
    int m = -floor((expectedElems * log(falsePositiveProb)) / pow(log(2), 2));
    int k = ceil((m / expectedElems) * log(2));

    struct CountingBloomFilter *new =
        calloc(1, sizeof(struct CountingBloomFilter) +
                      sizeof(union Nibbler) * ((m + 1) / 2));
    if (!new)
    {
        fprintf(stderr, "construct_CountingBloomFilter no memory");
        return NULL;
    }
    new->hashFuncs = k;
    new->maxElems = expectedElems;
    new->numSlots = m;

    return new;
}
