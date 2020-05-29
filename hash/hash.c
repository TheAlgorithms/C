/*
    authors: Christian Bender, ChatN0ir, vypxl
    This is the implementation unit of the hash-functions.

    Overview about hash-functions:

    - sdbm
    - djb2
    - xor8 (8 bits)
    - adler_32 (32 bits)
    - crc32
    - md5
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <inttypes.h>

long long sdbm(char s[])
{
    long long hash = 0;
    int i = 0;
    while (s[i] != '\0')
    {
        hash = s[i] + (hash << 6) + (hash << 16) - hash;
        i++;
    }
    return hash;
}

long long djb2(char s[])
{
    long long hash = 5381; /* init value */
    int i = 0;
    while (s[i] != '\0')
    {
        hash = ((hash << 5) + hash) + s[i];
        i++;
    }
    return hash;
}

char xor8(char s[])
{
    int hash = 0;
    int i = 0;
    while (s[i] != '\0')
    {
        hash = (hash + s[i]) & 0xff;
        i++;
    }
    return (((hash ^ 0xff) + 1) & 0xff);
}

int adler_32(char s[])
{
    int a = 1;
    int b = 0;
    const int MODADLER = 65521;

    int i = 0;
    while (s[i] != '\0')
    {
        a = (a + s[i]) % MODADLER;
        b = (b + a) % MODADLER;
        i++;
    }
    return (b << 16) | a;
}

/* crc32 Hash-Algorithm*/
uint32_t crc32(char* data){
    int i = 0;
    uint32_t crc = 0xffffffff;
    while(data[i] != '\0'){
        uint8_t byte = data[i];
        crc = crc ^ byte;
        for(int j = 8; j > 0; --j)
            crc = (crc >> 1) ^ (0xEDB88320 & ( -(crc & 1)));

        i++;
    }
    return crc ^ 0xffffffff;
}

__uint128_t md5(char str[]) {
    // initialize constants
    uint32_t s[64] = { 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21 };
    uint32_t K[64];
    for (int i = 0; i < 64; i++) K[i] = floor(0x100000000 * fabs(sin(i + 1)));

    uint32_t a0 = 0x67452301;
    uint32_t b0 = 0xefcdab89;
    uint32_t c0 = 0x98badcfe;
    uint32_t d0 = 0x10325476;

    // calculate padded length
    int len = strlen(str);
    int lenpadded = (len / 4) + (16 - (len / 4) % 16);
    uint32_t msg[lenpadded];

    // fill with zeros, copy message, append '1' bit, write bit length to the end
    for (int i = 0; i < lenpadded; i++) msg[i] = 0;
    memcpy(msg, str, strlen(str));
    ((uint8_t*)msg)[len] = 0x80;
    msg[lenpadded - 2] = (len * 8);

    // execute rounds for every 512 bits
    for (int offset = 0; offset < lenpadded; offset += 16) {
        uint32_t *M = msg + offset;

        uint32_t a = a0;
        uint32_t b = b0;
        uint32_t c = c0;
        uint32_t d = d0;

        for (int i = 0; i < 64; i++) {
            uint32_t f, g;

            if (i < 16) {
                f = (b & c) | ((~b) & d);
                g = i;
            } else if (i < 32) {
                f = (d & b) | (c & (~d));
                g = (5 * i + 1) % 16;
            } else if (i < 48) {
                f = b ^ c ^ d;
                g = (3 * i + 5) % 16;
            } else {
                f = c ^ (b | (~d));
                g = (7 * i) % 16;
            }

            f = f + a + K[i] + M[g];
            a = d;
            d = c;
            c = b;
            b = b + ((f << s[i]) | (f >> (32 - s[i]))); // ≙ leftrotate(f, s[i]);
        }
        a0 += a;
        b0 += b;
        c0 += c;
        d0 += d;
    }

    // return results
    __uint128_t result = 0;
    uint32_t* ptr = (uint32_t*)(&result);
    ptr[0] = a0;
    ptr[1] = b0;
    ptr[2] = c0;
    ptr[3] = d0;
    return result;
}
