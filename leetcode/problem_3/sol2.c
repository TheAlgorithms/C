/**
 * \file
 * \brief [3. Longest
 * substring](https://leetcode.com/problems/longest-substring-without-repeating-characters/)
 *  brute force solution
 * \details Given a string `s`, find the length of the longest substring without
 * repeating characters.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Optimized Longest substring function.
 *
 * @param str NULL terminated alpha-numeric string to search
 * @return length of longest substring
 * @note no spaces or other non-alphanumeric characters
 */
int lengthOfLongestSubstring(const char *s)
{
    int cur_max = 0, max = 0;
    int counter[255];
    int end = 0;

    memset(counter, 0, sizeof(int) * 255);
    while (end < strlen(s))
    {
        if (counter[s[end]] == 0)
        {
            counter[s[end]]++;
            end++;
            cur_max++;
        }
        else
        {
            char c = s[end];
            memset(counter, 0, 255 * sizeof(int));
            if (cur_max >= max)
                max = cur_max;
            cur_max = 0;
            while (s[end - 1] != c) end--;
        }
    }
    if (cur_max >= max)
        max = cur_max;
    return max;
}

/**
 * @brief Main function
 * @return 0
 */
int main()
{
    int test1 = lengthOfLongestSubstring("abcabcbb");
    assert(test1 == 3);
    printf("Test 1 passed\n");
    int test2 = lengthOfLongestSubstring("bbbbb");
    assert(test2 == 1);
    printf("Test 2 passed\n");
    int test3 = lengthOfLongestSubstring("pwwkew");
    assert(test3 == 3);
    printf("Test 3 passed\n");
    int test4 = lengthOfLongestSubstring("");
    assert(test4 == 0);
    printf("Test 4 passed\n");

    return 0;
}
