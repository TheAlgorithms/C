/**
 * @file
 * @brief Implementation of [Floyd's Cycle
 * Detection](https://en.wikipedia.org/wiki/Cycle_detection) algorithm
 * @details
 * Given an array of integers containing 'n + 1' integers, where each
 * integer is in the range [1, n] inclusive. If there is only one duplicate
 * number in the input array, this algorithm returns the duplicate number in
 * O(1) space and the time complexity is less than O(n^2) without modifying the
 * original array, otherwise, it returns -1.
 * @author [Swastika Gupta](https://github.com/Swastyy)
 */
#include <assert.h>
#include <math.h>
#include <stdio.h>

/**
 * @brief The main function implements search algorithm
 * @tparam T type of array
 * @param in_arr the input array
 * @param n size of array
 * @returns the duplicate number
 */
int duplicateNumber(const int *in_arr, size_t n)
{
    if (n == 0 || n == 1) {  // to find duplicate in an array its size should be atleast 2
        return -1;
    }
    int tortoise = in_arr[0];  // variable tortoise is used for the longer
                                    // jumps in the array
    int hare = in_arr[0];  // variable hare is used for shorter jumps in the array
    do {
        tortoise = in_arr[tortoise];
        hare = in_arr[in_arr[hare]];
    } while (tortoise != hare);
    tortoise = in_arr[0];
    while (tortoise != hare) {
        tortoise = in_arr[tortoise];
        hare = in_arr[hare];
    }
    return tortoise;
}

/**
 * @brief Test implementation of the function
 *
 */
void test()
{
    int arr[] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
    size_t n = sizeof(arr) / sizeof(int);

    printf("Test 1.... ");
    int index = duplicateNumber(arr, n);
    assert(index == 1);
    printf("passed\n");
}

/**
 * @brief Main function
 */
int main()
{
    test();
    return 0;
}
