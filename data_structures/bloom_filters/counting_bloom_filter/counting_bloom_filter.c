#include <math.h>

#include "./counting_bloom_filter.h"
#include "../EBdefs.h"

static inline int murmur_32_scramble(int k) {
    k *= 0xcc9e2d51;
    k = (k << 15) | (k >> 17);
    k *= 0x1b873593;
    return k;
}
int murmur3_32(const uint8_t *key, size_t len, int seed) {
    seed = murmur_32_scramble((seed + pow(seed,3)) * pow(2,seed));
    int h = seed;
    int k;
    /* Read in groups of 4. */
    for (size_t i = len >> 2; i; i--) {
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
    for (unsigned long i = len & 3; i; i--) {
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

struct CountingBloomFilter {
    int hashFuncs;
    int numSlots;
    int maxElems;
    union Nibbler internal[]; 
};

void countingBloom_printStats(struct CountingBloomFilter *this) {
    int numOnes = 0;
    for(int i = 0; i < this->numSlots; ++i) {
        float slot = ((float) i)/ 2.0;
        if(slot == (int)slot) {
            if(this->internal[(int)slot].nibbles.first > 0) {
                ++numOnes;
            }
        } else {
            if(this->internal[(int)slot].nibbles.second > 0) {
                ++numOnes;
            }
        }
    }

    float nStar = -((float)this->numSlots/(float)this->hashFuncs) * log(1.0-((float)numOnes/(float)this->numSlots));

    printf("Max Elements (n): %d \nHash Functions (k): %d \nSlots (m): %d\nEstimated Elements Inserted (n*): %f (estimate deteriorates as inserted elements approaches n)\n",
            this->maxElems,
            this->hashFuncs,
            this->numSlots,
            nStar);
}

int countingBloom_insert(struct CountingBloomFilter *this, void *elem, size_t size) {
    for (int i = 0; i < this->hashFuncs; ++i) {
        int spot = murmur3_32((uint8_t *)elem, size, i) % this->numSlots;
        float slot = ((float) spot)/ 2.0;
        if(slot == (int)slot) {
            if(this->internal[(int)slot].nibbles.first++ == 15) {
                return 1;
            };
        } else {
            if(this->internal[(int)slot].nibbles.second++ == 15) {
                return 1;
            };
        }
    }
    return 0;
}
int countingBloom_remove(struct CountingBloomFilter *this, void *elem, size_t size) {
    for (int i = 0; i < this->hashFuncs; ++i) {
        int spot = murmur3_32((uint8_t *)elem, size, i) % this->numSlots;
        float slot = ((float) spot)/ 2.0;
        if(slot == (int)slot) {
            if(this->internal[(int)slot].nibbles.first-- == 0) {
                return 1;
            };
        } else {
            if(this->internal[(int)slot].nibbles.second-- == 0) {
                return 1;
            };
        }
    }
    return 0;
}
enum bloomResponse countingBloom_contains(struct CountingBloomFilter *this, void *elem, size_t size) {
    for (int i = 0; i < this->hashFuncs; ++i) {
        int spot = murmur3_32((uint8_t *)elem, size, i) % this->numSlots;
        float slot = ((float) spot)/ 2.0;
        if(slot == (int)slot) {
            if(this->internal[(int)slot].nibbles.first == 0) {
                return DEFINITELY_NOT_PRESENT;
            }
        } else {
            if(this->internal[(int)slot].nibbles.second == 0) {
                return DEFINITELY_NOT_PRESENT;
            }
        }
    }
    return PROBABLY_PRESENT;
}

void delete_CountingBloomFilter(struct CountingBloomFilter *this) {
    free(this);
}

struct CountingBloomFilter *construct_CountingBloomFilter(int expectedElems, float falsePositveProb) {
    int m = -floor((expectedElems * log(falsePositveProb)) / pow(log(2),2));
    int k = ceil((m / expectedElems) * log(2));

    struct CountingBloomFilter * new = calloc(1, sizeof(struct CountingBloomFilter) + sizeof(union Nibbler)*((m+1)/2));
    if(!new) {
        fprintf(stderr, "construct_CountingBloomFilter no memory");
        return NULL;
    }
    new->hashFuncs = k;
    new->maxElems = expectedElems;
    new->numSlots = m;

    return new;
}