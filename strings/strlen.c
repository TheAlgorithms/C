/**
 * @file
 * @brief Program to calculate length of string.
 *
 * @author [Du Yuanchao](https://github.com/shellhub)
 */
#include <assert.h>
#include <string.h>

/**
 * Returns the length of string.
 * @param str the pointer of string.
 * @return the length of string.
 */
int length(const char *str)
{
    int count = 0;
    for (int i = 0; *(str + i) != '\0'; ++i)
    {
        count++;
    }
    return count;
}

/**
 * @brief Test function
 * @return void
 */
static void test()
{
    assert(length("") == strlen(""));
    assert(length(("a")) == strlen("a"));
    assert(length("abc") == strlen("abc"));
    assert(length("abc123def") == strlen("abc123def"));
    assert(length("abc\0def") == strlen("abc\0def"));
}

/**
 * @brief Driver Code
 * @returns 0 on exit
 */
int main()
{
    test();
    return 0;
}
