/*
    authors: Christian Bender, ChatN0ir, vypxl
    This file contains a simple test program for each hash-function.
*/

#include <stdio.h>
#include "hash.h"

int main(void)
{
    char s[] = "name";

    /* actual tests */
    printf("sdbm: %s --> %lld\n", s, sdbm(s));
    printf("djb2: %s --> %lld\n", s, djb2(s));
    printf("xor8: %s --> %i\n", s, xor8(s)); /* 8 bit */
    printf("adler_32: %s --> %i\n", s, adler_32(s)); /* 32 bit */
    printf("crc32: %s --> %i\n", s, crc32(s));

    __uint128_t md5result = md5(s);
    printf("md5: %s --> ", s); for (int i = 0; i < 16; i++) printf("%02x", ((__uint8_t*)(&md5result))[i]); printf("\n");

    return 0;
}
