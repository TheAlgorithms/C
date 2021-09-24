/**
 * @file
 * @author [sunzhenliang](https://github.com/HiSunzhenliang)
 * @brief A-law algorithm for encoding and decoding (16bit pcm <=> a-law).
 * @see audio/alaw.c
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
 * https://en.wikipedia.org/wiki/G.711
 *
 * Compressed code: (s | eee | abcd)
 **/
#include <stdio.h>
#include <stdlib.h>

#define MAX 32635 /* short int max */

/**
 * @brief 16bit pcm to 8bit alaw
 * @param out 8bit alaw
 * @param int 16bit pcm
 * @param len length of pcm array
 * @returns void
 */
void encode(unsigned char *out, short *in, size_t len)
{
    unsigned char alaw;
    short pcm;
    int sign;
    int abcd;
    int eee;
    int mask;
    for (size_t i = 0; i < len; i++)
    {
        pcm = *in++;
        eee = 7;
        mask = 0x4000;

        sign = (pcm & 0x8000) >> 8;
        pcm = sign ? -pcm : pcm;
        pcm = pcm > MAX ? MAX : pcm;
        while ((pcm & mask) == 0 && eee > 0)
        {
            eee--;
            mask >>= 1;
        }
        abcd = (pcm >> (eee ? (eee + 3) : 4)) & 0x0f;
        eee <<= 4;

        alaw = (sign | eee | abcd);
        *out++ = alaw ^ 0xD5;
    }
}

/**
 * @brief  8bit alaw to 16bit pcm
 * @param out 16bit pcm
 * @param int 8bit alaw
 * @param len length of alaw array
 * @returns void
 */
void decode(short *out, unsigned char *in, size_t len)
{
    unsigned char alaw;
    int pcm;
    int sign;
    int eee;
    for (size_t i = 0; i < len; i++)
    {
        alaw = *in++;
        alaw ^= 0xD5;
        sign = alaw & 0x80;
        eee = (alaw & 0x70) >> 4;
        pcm = alaw & 0x0f;
        pcm <<= 4;
        pcm += 0x8;
        pcm += eee ? 0x100 : 0x0;
        pcm <<= eee > 1 ? (eee - 1) : 0;

        *out++ = sign ? -pcm : pcm;
    }
}

#define LEN 4
int main(int argc, char *argv[])
{
    short pcm[LEN] = {1000, 1234, 3200, -1314};
    unsigned char coded[LEN];
    short decoded[LEN];

    printf("inputs: ");
    for (int i = 0; i < LEN; i++)
    {
        printf("%d ", pcm[i]);
    }
    printf("\n");

    printf("encode: ");
    encode(coded, pcm, LEN);
    for (int i = 0; i < LEN; i++)
    {
        printf("%u ", coded[i]);
    }
    printf("\n");

    printf("decode: ");
    decode(decoded, coded, LEN);
    for (int i = 0; i < LEN; i++)
    {
        printf("%d ", decoded[i]);
    }
    printf("\n");

    return 0;
}
