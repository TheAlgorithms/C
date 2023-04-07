/**
 * @addtogroup hash Hash algorithms
 * @{
 * @file
 * @author [Daniel Murrow](https://github.com/dsmurrow)
 * @brief [Blake2b cryptographic hash
 * function](https://www.rfc-editor.org/rfc/rfc7693)
 *
 * The Blake2b cryptographic hash function provides
 * hashes for data that are secure enough to be used in
 * cryptographic applications. It is designed to perform
 * optimally on 64-bit platforms. The algorithm can output
 * digests between 1 and 64 bytes long, for messages up to
 * 128 bits in length. Keyed hashing is also supported for
 * keys up to 64 bytes in length.
 */
#include <assert.h>    /// for asserts
#include <inttypes.h>  /// for fixed-width integer types e.g. uint64_t and uint8_t
#include <stdio.h>     /// for IO
#include <stdlib.h>    /// for malloc, calloc, and free. As well as size_t

/* Warning suppressed is in blake2b() function, more
 * details are over there */
#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wshift-count-overflow"
#elif _MSC_VER
#pragma warning(disable : 4293)
#endif

/**
 * @brief the size of a data block in bytes
 */
#define bb 128

/**
 * @brief max key length for BLAKE2b
 */
#define KK_MAX 64

/**
 * @brief max length of BLAKE2b digest in bytes
 */
#define NN_MAX 64

/**
 * @brief ceiling division macro without floats
 *
 * @param a dividend
 * @param b divisor
 */
#define CEIL(a, b) (((a) / (b)) + ((a) % (b) != 0))

/**
 * @brief returns minimum value
 */
#define MIN(a, b) ((a) < (b) ? (a) : (b))

/**
 * @brief returns maximum value
 */
#define MAX(a, b) ((a) > (b) ? (a) : (b))

/**
 * @brief macro to rotate 64-bit ints to the right
 * Ripped from RFC 7693
 */
#define ROTR64(n, offset) (((n) >> (offset)) ^ ((n) << (64 - (offset))))

/**
 * @brief zero-value initializer for u128 type
 */
#define U128_ZERO \
    {             \
        0, 0      \
    }

/** 128-bit number represented as two uint64's */
typedef uint64_t u128[2];

/** Padded input block containing bb bytes */
typedef uint64_t block_t[bb / sizeof(uint64_t)];

static const uint8_t R1 = 32;  ///< Rotation constant 1 for mixing function G
static const uint8_t R2 = 24;  ///< Rotation constant 2 for mixing function G
static const uint8_t R3 = 16;  ///< Rotation constant 3 for mixing function G
static const uint8_t R4 = 63;  ///< Rotation constant 4 for mixing function G

static const uint64_t blake2b_iv[8] = {
    0x6A09E667F3BCC908, 0xBB67AE8584CAA73B, 0x3C6EF372FE94F82B,
    0xA54FF53A5F1D36F1, 0x510E527FADE682D1, 0x9B05688C2B3E6C1F,
    0x1F83D9ABFB41BD6B, 0x5BE0CD19137E2179};  ///< BLAKE2b Initialization vector
                                              ///< blake2b_iv[i] = floor(2**64 *
                                              ///< frac(sqrt(prime(i+1)))),
                                              ///< where prime(i) is the i:th
                                              ///< prime number

static const uint8_t blake2b_sigma[12][16] = {
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
    {14, 10, 4, 8, 9, 15, 13, 6, 1, 12, 0, 2, 11, 7, 5, 3},
    {11, 8, 12, 0, 5, 2, 15, 13, 10, 14, 3, 6, 7, 1, 9, 4},
    {7, 9, 3, 1, 13, 12, 11, 14, 2, 6, 5, 10, 4, 0, 15, 8},
    {9, 0, 5, 7, 2, 4, 10, 15, 14, 1, 11, 12, 6, 8, 3, 13},
    {2, 12, 6, 10, 0, 11, 8, 3, 4, 13, 7, 5, 15, 14, 1, 9},
    {12, 5, 1, 15, 14, 13, 4, 10, 0, 7, 6, 3, 9, 2, 8, 11},
    {13, 11, 7, 14, 12, 1, 3, 9, 5, 0, 15, 4, 8, 6, 2, 10},
    {6, 15, 14, 9, 11, 3, 0, 8, 12, 2, 13, 7, 1, 4, 10, 5},
    {10, 2, 8, 4, 7, 6, 1, 5, 15, 11, 9, 14, 3, 12, 13, 0},
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
    {14, 10, 4, 8, 9, 15, 13, 6, 1, 12, 0, 2, 11, 7, 5,
     3}};  ///< word schedule permutations for each round of the algorithm

/**
 * @brief put value of n into dest
 *
 * @param dest 128-bit number to get copied from n
 * @param n value put into dest
 *
 * @returns void
 */
static inline void u128_fill(u128 dest, size_t n)
{
    dest[0] = n & UINT64_MAX;

    if (sizeof(n) > 8)
    {
        /* The C standard does not specify a maximum length for size_t,
         * although most machines implement it to be the same length as
         * uint64_t. On machines where size_t is 8 bytes long this will issue a
         * compiler warning, which is why it is suppressed. But on a machine
         * where size_t is greater than 8 bytes, this will work as normal. */
        dest[1] = n >> 64;
    }
    else
    {
        dest[1] = 0;
    }
}

/**
 * @brief increment an 128-bit number by a given amount
 *
 * @param dest the value being incremented
 * @param n what dest is being increased by
 *
 * @returns void
 */
static inline void u128_increment(u128 dest, uint64_t n)
{
    /* Check for overflow */
    if (UINT64_MAX - dest[0] <= n)
    {
        dest[1]++;
    }

    dest[0] += n;
}

/**
 * @brief blake2b mixing function G
 *
 * Shuffles values in block v depending on
 * provided indeces a, b, c, and d. x and y
 * are also mixed into the block.
 *
 * @param v array of words to be mixed
 * @param a first index
 * @param b second index
 * @param c third index
 * @param d fourth index
 * @param x first word being mixed into v
 * @param y second word being mixed into y
 *
 * @returns void
 */
static void G(block_t v, uint8_t a, uint8_t b, uint8_t c, uint8_t d, uint64_t x,
              uint64_t y)
{
    v[a] += v[b] + x;
    v[d] = ROTR64(v[d] ^ v[a], R1);
    v[c] += v[d];
    v[b] = ROTR64(v[b] ^ v[c], R2);
    v[a] += v[b] + y;
    v[d] = ROTR64(v[d] ^ v[a], R3);
    v[c] += v[d];
    v[b] = ROTR64(v[b] ^ v[c], R4);
}

/**
 * @brief compression function F
 *
 * Securely mixes the values in block m into
 * the state vector h. Value at v[14] is also
 * inverted if this is the final block to be
 * compressed.
 *
 * @param h the state vector
 * @param m message vector to be compressed into h
 * @param t 128-bit offset counter
 * @param f flag to indicate whether this is the final block
 *
 * @returns void
 */
static void F(uint64_t h[8], block_t m, u128 t, int f)
{
    int i;
    block_t v;

    /* v[0..7] := h[0..7] */
    for (i = 0; i < 8; i++)
    {
        v[i] = h[i];
    }
    /* v[8..15] := IV[0..7] */
    for (; i < 16; i++)
    {
        v[i] = blake2b_iv[i - 8];
    }

    v[12] ^= t[0]; /* v[12] ^ (t mod 2**w) */
    v[13] ^= t[1]; /* v[13] ^ (t >> w) */

    if (f)
    {
        v[14] = ~v[14];
    }

    for (i = 0; i < 12; i++)
    {
        const uint8_t *s = blake2b_sigma[i];

        G(v, 0, 4, 8, 12, m[s[0]], m[s[1]]);
        G(v, 1, 5, 9, 13, m[s[2]], m[s[3]]);
        G(v, 2, 6, 10, 14, m[s[4]], m[s[5]]);
        G(v, 3, 7, 11, 15, m[s[6]], m[s[7]]);

        G(v, 0, 5, 10, 15, m[s[8]], m[s[9]]);
        G(v, 1, 6, 11, 12, m[s[10]], m[s[11]]);
        G(v, 2, 7, 8, 13, m[s[12]], m[s[13]]);
        G(v, 3, 4, 9, 14, m[s[14]], m[s[15]]);
    }

    for (i = 0; i < 8; i++)
    {
        h[i] ^= v[i] ^ v[i + 8];
    }
}

/**
 * @brief driver function to perform the hashing as described in specification
 *
 * pseudocode: (credit to authors of RFC 7693 listed above)
 * FUNCTION BLAKE2( d[0..dd-1], ll, kk, nn )
 * |
 * |     h[0..7] := IV[0..7]          // Initialization Vector.
 * |
 * |     // Parameter block p[0]
 * |     h[0] := h[0] ^ 0x01010000 ^ (kk << 8) ^ nn
 * |
 * |     // Process padded key and data blocks
 * |     IF dd > 1 THEN
 * |     |       FOR i = 0 TO dd - 2 DO
 * |     |       |       h := F( h, d[i], (i + 1) * bb, FALSE )
 * |     |       END FOR.
 * |     END IF.
 * |
 * |     // Final block.
 * |     IF kk = 0 THEN
 * |     |       h := F( h, d[dd - 1], ll, TRUE )
 * |     ELSE
 * |     |       h := F( h, d[dd - 1], ll + bb, TRUE )
 * |     END IF.
 * |
 * |     RETURN first "nn" bytes from little-endian word array h[].
 * |
 * END FUNCTION.
 *
 * @param dest destination of hashing digest
 * @param d message blocks
 * @param dd length of d
 * @param ll 128-bit length of message
 * @param kk length of secret key
 * @param nn length of hash digest
 *
 * @returns 0 upon successful hash
 */
static int BLAKE2B(uint8_t *dest, block_t *d, size_t dd, u128 ll, uint8_t kk,
                   uint8_t nn)
{
    uint8_t bytes[8];
    uint64_t i, j;
    uint64_t h[8];
    u128 t = U128_ZERO;

    /* h[0..7] = IV[0..7] */
    for (i = 0; i < 8; i++)
    {
        h[i] = blake2b_iv[i];
    }

    h[0] ^= 0x01010000 ^ (kk << 8) ^ nn;

    if (dd > 1)
    {
        for (i = 0; i < dd - 1; i++)
        {
            u128_increment(t, bb);
            F(h, d[i], t, 0);
        }
    }

    if (kk != 0)
    {
        u128_increment(ll, bb);
    }
    F(h, d[dd - 1], ll, 1);

    /* copy bytes from h to destination buffer */
    for (i = 0; i < nn; i++)
    {
        if (i % sizeof(uint64_t) == 0)
        {
            /* copy values from uint64 to 8 u8's */
            for (j = 0; j < sizeof(uint64_t); j++)
            {
                uint16_t offset = 8 * j;
                uint64_t mask = 0xFF;
                mask <<= offset;

                bytes[j] = (h[i / 8] & (mask)) >> offset;
            }
        }

        dest[i] = bytes[i % 8];
    }

    return 0;
}

/**
 * @brief blake2b hash function
 *
 * This is the front-end function that sets up the argument for BLAKE2B().
 *
 * @param message the message to be hashed
 * @param len length of message (0 <= len < 2**128) (depends on sizeof(size_t)
 * for this implementation)
 * @param key optional secret key
 * @param kk length of optional secret key (0 <= kk <= 64)
 * @param nn length of output digest (1 <= nn < 64)
 *
 * @returns NULL if heap memory couldn't be allocated. Otherwise heap allocated
 * memory nn bytes large
 */
uint8_t *blake2b(const uint8_t *message, size_t len, const uint8_t *key,
                 uint8_t kk, uint8_t nn)
{
    uint8_t *dest = NULL;
    uint64_t long_hold;
    size_t dd, has_key, i;
    size_t block_index, word_in_block;
    u128 ll;
    block_t *blocks;

    if (message == NULL)
    {
        len = 0;
    }
    if (key == NULL)
    {
        kk = 0;
    }

    kk = MIN(kk, KK_MAX);
    nn = MIN(nn, NN_MAX);

    dd = MAX(CEIL(kk, bb) + CEIL(len, bb), 1);

    blocks = calloc(dd, sizeof(block_t));
    if (blocks == NULL)
    {
        return NULL;
    }

    dest = malloc(nn * sizeof(uint8_t));
    if (dest == NULL)
    {
        free(blocks);
        return NULL;
    }

    /* If there is a secret key it occupies the first block */
    for (i = 0; i < kk; i++)
    {
        long_hold = key[i];
        long_hold <<= 8 * (i % 8);

        word_in_block = (i % bb) / 8;
        /* block_index will always be 0 because kk <= 64 and bb = 128*/
        blocks[0][word_in_block] |= long_hold;
    }

    has_key = kk > 0 ? 1 : 0;

    for (i = 0; i < len; i++)
    {
        /* long_hold exists because the bit-shifting will overflow if we don't
         * store the value */
        long_hold = message[i];
        long_hold <<= 8 * (i % 8);

        block_index = has_key + (i / bb);
        word_in_block = (i % bb) / 8;

        blocks[block_index][word_in_block] |= long_hold;
    }

    u128_fill(ll, len);

    BLAKE2B(dest, blocks, dd, ll, kk, nn);

    free(blocks);

    return dest;
}

/** @} */

/**
 * @brief Self-test implementations
 * @returns void
 */
static void assert_bytes(const uint8_t *expected, const uint8_t *actual,
                         uint8_t len)
{
    uint8_t i;

    assert(expected != NULL);
    assert(actual != NULL);
    assert(len > 0);

    for (i = 0; i < len; i++)
    {
        assert(expected[i] == actual[i]);
    }
}

/**
 * @brief testing function
 *
 * @returns void
 */
static void test()
{
    uint8_t *digest = NULL;

    /* "abc" example straight out of RFC-7693 */
    uint8_t abc[3] = {'a', 'b', 'c'};
    uint8_t abc_answer[64] = {
        0xBA, 0x80, 0xA5, 0x3F, 0x98, 0x1C, 0x4D, 0x0D, 0x6A, 0x27, 0x97,
        0xB6, 0x9F, 0x12, 0xF6, 0xE9, 0x4C, 0x21, 0x2F, 0x14, 0x68, 0x5A,
        0xC4, 0xB7, 0x4B, 0x12, 0xBB, 0x6F, 0xDB, 0xFF, 0xA2, 0xD1, 0x7D,
        0x87, 0xC5, 0x39, 0x2A, 0xAB, 0x79, 0x2D, 0xC2, 0x52, 0xD5, 0xDE,
        0x45, 0x33, 0xCC, 0x95, 0x18, 0xD3, 0x8A, 0xA8, 0xDB, 0xF1, 0x92,
        0x5A, 0xB9, 0x23, 0x86, 0xED, 0xD4, 0x00, 0x99, 0x23};

    digest = blake2b(abc, 3, NULL, 0, 64);
    assert_bytes(abc_answer, digest, 64);

    free(digest);

    uint8_t key[64] = {
        0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a,
        0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15,
        0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20,
        0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b,
        0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36,
        0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f};
    uint8_t key_answer[64] = {
        0x10, 0xeb, 0xb6, 0x77, 0x00, 0xb1, 0x86, 0x8e, 0xfb, 0x44, 0x17,
        0x98, 0x7a, 0xcf, 0x46, 0x90, 0xae, 0x9d, 0x97, 0x2f, 0xb7, 0xa5,
        0x90, 0xc2, 0xf0, 0x28, 0x71, 0x79, 0x9a, 0xaa, 0x47, 0x86, 0xb5,
        0xe9, 0x96, 0xe8, 0xf0, 0xf4, 0xeb, 0x98, 0x1f, 0xc2, 0x14, 0xb0,
        0x05, 0xf4, 0x2d, 0x2f, 0xf4, 0x23, 0x34, 0x99, 0x39, 0x16, 0x53,
        0xdf, 0x7a, 0xef, 0xcb, 0xc1, 0x3f, 0xc5, 0x15, 0x68};

    digest = blake2b(NULL, 0, key, 64, 64);
    assert_bytes(key_answer, digest, 64);

    free(digest);

    uint8_t zero[1] = {0};
    uint8_t zero_key[64] = {
        0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a,
        0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15,
        0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20,
        0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b,
        0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36,
        0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f};
    uint8_t zero_answer[64] = {
        0x96, 0x1f, 0x6d, 0xd1, 0xe4, 0xdd, 0x30, 0xf6, 0x39, 0x01, 0x69,
        0x0c, 0x51, 0x2e, 0x78, 0xe4, 0xb4, 0x5e, 0x47, 0x42, 0xed, 0x19,
        0x7c, 0x3c, 0x5e, 0x45, 0xc5, 0x49, 0xfd, 0x25, 0xf2, 0xe4, 0x18,
        0x7b, 0x0b, 0xc9, 0xfe, 0x30, 0x49, 0x2b, 0x16, 0xb0, 0xd0, 0xbc,
        0x4e, 0xf9, 0xb0, 0xf3, 0x4c, 0x70, 0x03, 0xfa, 0xc0, 0x9a, 0x5e,
        0xf1, 0x53, 0x2e, 0x69, 0x43, 0x02, 0x34, 0xce, 0xbd};

    digest = blake2b(zero, 1, zero_key, 64, 64);
    assert_bytes(zero_answer, digest, 64);

    free(digest);

    uint8_t filled[64] = {
        0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a,
        0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15,
        0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20,
        0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b,
        0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36,
        0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f};
    uint8_t filled_key[64] = {
        0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a,
        0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15,
        0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20,
        0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b,
        0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36,
        0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f};
    uint8_t filled_answer[64] = {
        0x65, 0x67, 0x6d, 0x80, 0x06, 0x17, 0x97, 0x2f, 0xbd, 0x87, 0xe4,
        0xb9, 0x51, 0x4e, 0x1c, 0x67, 0x40, 0x2b, 0x7a, 0x33, 0x10, 0x96,
        0xd3, 0xbf, 0xac, 0x22, 0xf1, 0xab, 0xb9, 0x53, 0x74, 0xab, 0xc9,
        0x42, 0xf1, 0x6e, 0x9a, 0xb0, 0xea, 0xd3, 0x3b, 0x87, 0xc9, 0x19,
        0x68, 0xa6, 0xe5, 0x09, 0xe1, 0x19, 0xff, 0x07, 0x78, 0x7b, 0x3e,
        0xf4, 0x83, 0xe1, 0xdc, 0xdc, 0xcf, 0x6e, 0x30, 0x22};

    digest = blake2b(filled, 64, filled_key, 64, 64);
    assert_bytes(filled_answer, digest, 64);

    free(digest);

    printf("All tests have successfully passed!\n");
}

/**
 * @brief main function
 *
 * @returns 0 on successful program exit
 */
int main()
{
    test();
    return 0;
}
