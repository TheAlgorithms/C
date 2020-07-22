/**
 * @addtogroup hash Hash algorithms
 * @{
 * @file hash_djb2.c
 * @author [Christian Bender](https://github.com/christianbender)
 * @brief [DJB2 hash algorithm](http://www.cse.yorku.ca/~oz/hash.html)
 */
#include <assert.h>
#include <inttypes.h>
#include <stdio.h>

/**
 * @brief DJB2 algorithm implementation
 *
 * @param s NULL terminated string to hash
 * @return 64-bit hash result
 */
uint64_t djb2(const char* s)
{
    uint64_t hash = 5381; /* init value */
    size_t i = 0;
    while (s[i] != '\0')
    {
        hash = ((hash << 5) + hash) + s[i];
        i++;
    }
    return hash;
}

/**
 * @brief Test function for ::djb2
 */
void test_djb2()
{
    const uint64_t test1 = 13827776004929097857;
    assert(djb2("Hello World") == test1);
    const uint64_t test2 = 13594750393630990530;
    assert(djb2("Hello World!") == test2);
    const uint64_t test3 = 13827776004967047329;
    assert(djb2("Hello world") == test3);
    const uint64_t test4 = 13594750394883323106;
    assert(djb2("Hello world!") == test4);
    printf("Tests passed\n");
}

/** @} */

/** Main function */
int main()
{
    test_djb2();
    return 0;
}
