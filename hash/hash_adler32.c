/**
 * @addtogroup hash Hash algorithms
 * @{
 * @file hash_adler32.c
 * @author [Christian Bender](https://github.com/christianbender)
 * @brief 32-bit [Adler hash](https://en.wikipedia.org/wiki/Adler-32) algorithm
 */
#include <assert.h>
#include <inttypes.h>
#include <stdio.h>

/**
 * @brief 32-bit Adler algorithm implementation
 *
 * @param s NULL terminated ASCII string to hash
 * @return 32-bit hash result
 */
uint32_t adler32(const char* s)
{
    uint32_t a = 1;
    uint32_t b = 0;
    const uint32_t MODADLER = 65521;

    size_t i = 0;
    while (s[i] != '\0')
    {
        a = (a + s[i]) % MODADLER;
        b = (b + a) % MODADLER;
        i++;
    }
    return (b << 16) | a;
}

/**
 * @brief Test function for ::adler32
 */
void test_adler32()
{
    const uint32_t test1 = 403375133;
    assert(adler32("Hello World") == test1);
    const uint32_t test2 = 474547262;
    assert(adler32("Hello World!") == test2);
    const uint32_t test3 = 413860925;
    assert(adler32("Hello world") == test3);
    const uint32_t test4 = 487130206;
    assert(adler32("Hello world!") == test4);
    printf("Tests passed\n");
}

/** @} */

/** Main function */
int main()
{
    test_adler32();
    return 0;
}
