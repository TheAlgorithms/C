/**
 * @file
 * @brief [Hamming distance](https://en.wikipedia.org/wiki/Hamming_distance)
 * algorithm implementation.
 * @details
 * In information theory, the Hamming distance between two strings of
 * equal length is the number of positions at which the corresponding symbols
 * are different.
 * @author [Aybars Nazlica](https://github.com/aybarsnazlica)
 */

#include <assert.h>  /// for assert
#include <stdio.h>   /// for IO operations

/**
 * @brief Function to calculate the Hamming distance between two strings
 * @param param1 string 1
 * @param param2 string 2
 * @returns Hamming distance
 */
int hamming_distance(char* str1, char* str2)
{
    int i = 0, distance = 0;

    while (str1[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            distance++;
        }
        i++;
    }

    return distance;
}

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test()
{
    char str1[] = "karolin";
    char str2[] = "kathrin";

    assert(hamming_distance(str1, str2) == 3);

    char str3[] = "00000";
    char str4[] = "11111";

    assert(hamming_distance(str3, str4) == 5);
    printf("All tests have successfully passed!\n");
}
/**
 * @brief Main function
 * @returns 0 on exit
 */
int main()
{
    test();  // run self-test implementations
    return 0;
}
