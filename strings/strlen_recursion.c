/**
 * @file
 * @brief Program to calculate length of string using recursion.
 *
 * @author [Du Yuanchao](https://github.com/shellhub)
 */
#include <assert.h>
#include <string.h>

/**
 * @brief Returns the length of string using recursion
 * @param str the pointer of string.
 * @return the length of string.
 */
int length(const char *str) { return *str == '\0' ? 0 : 1 + length(++str); }

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
