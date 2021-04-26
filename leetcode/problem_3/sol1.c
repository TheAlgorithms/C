/**
 * \file
 * \brief [3. Longest
 * substring](https://leetcode.com/problems/longest-substring-without-repeating-characters/)
 * optimized solution
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
int lengthOfLongestSubstring(const char *str)
{
    size_t n = strlen(str);

    if (!n)
        return 0;

    int L_len = 1;  // length of longest substring
    int C_len = 1;  // length of current substring

    int P_ind, i;      //  P_ind for previous index
    int visited[256];  //  visited will keep track of visiting char for the last
                       //  instance. since there are 256 ASCII char, its size is
                       //  limited to that value.
    memset(visited, -1, sizeof(int) * 256);
    visited[str[0]] =
        0;  //  the index of that char will tell us that when it was visited.
    for (i = 1; i < n; i++)
    {
        P_ind = visited[str[i]];
        if (P_ind == -1 || i - C_len > P_ind)
            C_len++;  //  if the current char was not visited earlier, or it is
                      //  not the part of current substring
        else
        {  //  otherwise, we need to change the current/longest substring length
            if (C_len > L_len)
                L_len = C_len;
            C_len = i - P_ind;
        }
        visited[str[i]] = i;
    }
    if (C_len > L_len)
        L_len = C_len;
    return L_len;
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
