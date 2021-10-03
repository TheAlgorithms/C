/**
 * @file
 * @author [sunzhenliang](https://github.com/HiSunzhenliang)
 * @brief A-law algorithm for encoding and decoding (16bit pcm <=> a-law).
 * This is the implementation of [G.711](https://en.wikipedia.org/wiki/G.711)
 * in C.
 **/

/**
 * Linear input code | Compressed code | Linear output code
 * ------------------+-----------------+-------------------
 * s0000000abcdx     | s000abcd        | s0000000abcd1
 * s0000001abcdx     | s001abcd        | s0000001abcd1
 * s000001abcdxx     | s010abcd        | s000001abcd10
 * s00001abcdxxx     | s011abcd        | s00001abcd100
 * s0001abcdxxxx     | s100abcd        | s0001abcd1000
 * s001abcdxxxxx     | s101abcd        | s001abcd10000
 * s01abcdxxxxxx     | s110abcd        | s01abcd100000
 * s1abcdxxxxxxx     | s111abcd        | s1abcd1000000
 *
 * Compressed code: (s | eee | abcd)
 **/
#include <assert.h>    /// for assert
#include <inttypes.h>  /// for appropriate size int types
#include <stdio.h>     /// for IO operations

/* length of test inputs */
#define LEN ((size_t)8)

/* input pcm for test */
int16_t pcm[LEN] = {1000, -1000, 1234, 3200, -1314, 0, 32767, -32768};

/* result coded alaw for test */
uint8_t r_coded[LEN] = {250, 122, 230, 156, 97, 213, 170, 42};

/* result decoded for test */
int16_t r_decoded[LEN] = {1008, -1008, 1248, 3264, -1312, 8, 32256, -32256};

/**
 * @brief 16bit pcm to 8bit alaw
 * @param out unsigned 8bit alaw array
 * @param in  signed 16bit pcm array
 * @param len length of pcm array
 * @returns void
 */
void encode(uint8_t *out, int16_t *in, size_t len)
{
    uint8_t alaw = 0;
    int16_t pcm = 0;
    int32_t sign = 0;
    int32_t abcd = 0;
    int32_t eee = 0;
    int32_t mask = 0;
    for (size_t i = 0; i < len; i++)
    {
        pcm = *in++;
        /* 0-7 kinds of quantization level from the table above */
        eee = 7;
        mask = 0x4000; /* 0x4000: '0b0100 0000 0000 0000' */

        /* Get sign bit */
        sign = (pcm & 0x8000) >> 8;

        /* Turn negative pcm to positive */
        /* The absolute value of a negative number may be larger than the size
         * of the corresponding positive number, so here needs `-pcm -1` after
         * taking the opposite number. */
        pcm = sign ? (-pcm - 1) : pcm;

        /* Get eee and abcd bit */
        /* Use mask to locate the first `1` bit and quantization level at the
         * same time */
        while ((pcm & mask) == 0 && eee > 0)
        {
            eee--;
            mask >>= 1;
        }

        /* The location of abcd bits is related with quantization level. Check
         * the table above to determine how many bits to `>>` to get abcd */
        abcd = (pcm >> (eee ? (eee + 3) : 4)) & 0x0f;

        /* Put the quantization level number at right bit location to get eee
         * bits */
        eee <<= 4;

        /* Splice results */
        alaw = (sign | eee | abcd);

        /* The standard specifies that all resulting even bits (LSB
         * is even) are inverted before the octet is transmitted. This is to
         * provide plenty of 0/1 transitions to facilitate the clock recovery
         * process in the PCM receivers. Thus, a silent A-law encoded PCM
         * channel has the 8 bit samples coded 0xD5 instead of 0x80 in the
         * octets. (Reference from wiki above) */
        *out++ = alaw ^ 0xD5;
    }
}

/**
 * @brief 8bit alaw to 16bit pcm
 * @param out signed 16bit pcm array
 * @param in  unsigned 8bit alaw array
 * @param len length of alaw array
 * @returns void
 */
void decode(int16_t *out, uint8_t *in, size_t len)
{
    uint8_t alaw = 0;
    int32_t pcm = 0;
    int32_t sign = 0;
    int32_t eee = 0;
    for (size_t i = 0; i < len; i++)
    {
        alaw = *in++;

        /* Re-toggle toggled bits */
        alaw ^= 0xD5;

        /* Get sign bit */
        sign = alaw & 0x80;

        /* Get eee bits */
        eee = (alaw & 0x70) >> 4;

        /* Get abcd bits and add 1/2 quantization step */
        pcm = (alaw & 0x0f) << 4 | 8;

        /* If quantization level > 0, there need `1` bit before abcd bits */
        pcm += eee ? 0x100 : 0x0;

        /* Left shift according quantization level */
        pcm <<= eee > 1 ? (eee - 1) : 0;

        /* Use the right sign */
        *out++ = sign ? -pcm : pcm;
    }
}

/**
 * @brief Self-test implementations
 * @param pcm signed 16bit pcm array
 * @param coded unsigned 8bit alaw array
 * @param decoded signed 16bit pcm array
 * @param len length of test array
 * @returns void
 */
static void test(int16_t *pcm, uint8_t *coded, int16_t *decoded, size_t len)
{
    /* run encode */
    encode(coded, pcm, len);

    /* check encode result */
    for (size_t i = 0; i < len; i++)
    {
        assert(coded[i] == r_coded[i]);
    }

    /* run decode */
    decode(decoded, coded, len);

    /* check decode result */
    for (size_t i = 0; i < len; i++)
    {
        assert(decoded[i] == r_decoded[i]);
    }
}

/**
 * @brief Main function
 * @param argc commandline argument count (ignored)
 * @param argv commandline array of arguments (ignored)
 * @returns 0 on exit
 */
int main(int argc, char *argv[])
{
    /* output alaw encoded by encode() */
    uint8_t coded[LEN];

    /* output pcm decoded by decode() from coded[LEN] */
    int16_t decoded[LEN];

    test(pcm, coded, decoded, LEN);  // run self-test implementations

    /* print test pcm inputs */
    printf("inputs: ");
    for (size_t i = 0; i < LEN; i++)
    {
        printf("%d ", pcm[i]);
    }
    printf("\n");

    /* print encoded alaw */
    printf("encode: ");
    for (size_t i = 0; i < LEN; i++)
    {
        printf("%u ", coded[i]);
    }
    printf("\n");

    /* print decoded pcm */
    printf("decode: ");
    for (size_t i = 0; i < LEN; i++)
    {
        printf("%d ", decoded[i]);
    }
    printf("\n");

    /* It can be seen that the encoded alaw is smaller than the input PCM, so
     * the purpose of compression is achieved. And the decoded PCM is almost the
     * same as the original input PCM, which verifies the correctness of the
     * decoding. The reason why it is not exactly the same is that there is
     * precision loss during encode / decode.  */

    return 0;
}
