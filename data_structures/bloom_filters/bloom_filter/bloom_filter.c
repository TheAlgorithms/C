#include <math.h>

#include "./bloom_filter.h"
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

// A union to store the counts as 4-bit buckets instead of 8.
// Allows for the counting filter to be more space efficient.
union Bits {
     struct { 
        unsigned int b1:1;
        unsigned int b2:1;
        unsigned int b3:1;
        unsigned int b4:1;
        unsigned int b5:1;
        unsigned int b6:1;
        unsigned int b7:1;
        unsigned int b8:1;
     } nibbles;
     unsigned char byte_value;
};

struct BloomFilter {
    int hashFuncs;
    int numSlots;
    int maxElems;
    union Bits internal[]; 
};

void bloom_printStats(struct BloomFilter *this) {
    int numOnes = 0;
    for(int i = 0; i < this->numSlots; ++i) {
        int slot = i / 8;
        int bit = i % 8;
        if((this->internal[(int)slot].byte_value >> bit) == 1) {
            ++numOnes;
        }
    }

    float nStar = -((float)this->numSlots/(float)this->hashFuncs) * log(1.0-((float)numOnes/(float)this->numSlots));

    printf("Max Elements (n): %d \nHash Functions (k): %d \nSlots (m): %d\nEstimated Elements Inserted (n*): %f (estimate deteriorates as inserted elements approaches n)\n",
            this->maxElems,
            this->hashFuncs,
            this->numSlots,
            nStar);
}

void bloom_insert(struct BloomFilter *this, void *elem, size_t size) {
    for (int i = 0; i < this->hashFuncs; ++i) {
        int spot = murmur3_32((uint8_t *)elem, size, i) % this->numSlots;
        int slot = spot / 8;
        int bit = spot % 8;
        this->internal[(int)slot].byte_value |= (1 << bit);
    }
    return;
}

enum bloomResponse bloom_contains(struct BloomFilter *this, void *elem, size_t size) {
    for (int i = 0; i < this->hashFuncs; ++i) {
        int spot = murmur3_32((uint8_t *)elem, size, i) % this->numSlots;
        int slot = spot / 8;
        int bit = spot % 8;
        if((this->internal[(int)slot].byte_value >> bit) == 0) {
            return DEFINITELY_NOT_PRESENT;
        }
    }
    return PROBABLY_PRESENT;
}

void delete_bloomFilter(struct BloomFilter *this) {
    free(this);
}

struct BloomFilter *construct_bloomFilter(int expectedElems, float falsePositveProb) {
    int m = -floor((expectedElems * log(falsePositveProb)) / pow(log(2),2));
    int k = ceil((m / expectedElems) * log(2));

    struct BloomFilter * new = calloc(1, sizeof(struct BloomFilter) + sizeof(union Bits)*((m+1)/8));
    if(!new) {
        fprintf(stderr, "construct_bloomFilter no memory");
        return NULL;
    }
    new->hashFuncs = k;
    new->maxElems = expectedElems;
    new->numSlots = m;

    return new;
}