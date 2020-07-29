/**
 * @addtogroup hash Hash algorithms
 * @{
 * @file hash_xor8.c
 * @author [Christian Bender](https://github.com/christianbender)
 * @brief 8-bit [XOR hash](https://en.wikipedia.org/wiki/XOR_cipher) algorithm
 * for ASCII characters
 */
#include <assert.h>
#include <inttypes.h>
#include <stdio.h>

/**
 * @brief 8-bit XOR algorithm implementation
 *
 * @param s NULL terminated ASCII string to hash
 * @return 8-bit hash result
 */
uint8_t xor8(const char* s)
{
    uint8_t hash = 0;
    size_t i = 0;
    while (s[i] != '\0')
    {
        hash = (hash + s[i]) & 0xff;
        i++;
    }
    return (((hash ^ 0xff) + 1) & 0xff);
}

/**
 * @brief Test function for ::xor8
 * \returns None
 */
void test_xor8()
{
    assert(xor8("Hello World") == 228);
    assert(xor8("Hello World!") == 195);
    assert(xor8("Hello world") == 196);
    assert(xor8("Hello world!") == 163);
    printf("Tests passed\n");
}

/** @} */

/** Main function */
int main()
{
    test_xor8();
    return 0;
}
