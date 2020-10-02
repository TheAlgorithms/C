/**
 * @file
 * @brief Leetcode problem #5
 * @details
 * This is a working solution for the "Longest Palindromic Substring" problem.
 * Runtime: 8ms, memory: 7.2 MB, outperforms 90.45% of C submissions.
 * @author [Gabriele Bruno Franco](https://github.com/gbrunofranco)
 */

#include "assert.h"
#include "stdlib.h"

/**
 * Function documentation
 * @param inputString
 * @returns `NULL` if inputString is NULL
 * @returns `inputString' if inputString is one character long
 * @returns the longest palindrome sub-string if inputString is more than one
 * character long
 */
char* longestPalindrome(char* inputString)
{
    int stringSize;
    int subStringSize = 0, j, k;
    int max = 1;
    int head = 0;

    stringSize = strlen(inputString);

    if (inputString == NULL)
        return NULL;
    if (stringSize == 1)
        return inputString;

    for (subStringSize = 0;
         subStringSize < stringSize && (stringSize - subStringSize) > max / 2;)
    {
        j = subStringSize;
        k = subStringSize;

        while (k < stringSize - 1 && inputString[k] == inputString[k + 1])
        {
            k++;
        }
        subStringSize = k + 1;
        while (j > 0 && k < stringSize - 1 &&
               inputString[j - 1] == inputString[k + 1])
        {
            j--;
            k++;
        }

        if (max < (k - j + 1))
        {
            max = k - j + 1;
            head = j;
        }
    }
    char* res = (char*)malloc(sizeof(char) * (max + 1));
    if (res == NULL)
        return NULL;
    for (subStringSize = 0; subStringSize < max; ++subStringSize)
        res[subStringSize] = inputString[head + subStringSize];

    res[max] = '\0';

    return res;
}
