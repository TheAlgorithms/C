/**
 * \file
 * \brief [3. Longest
 * substring](https://leetcode.com/problems/longest-substring-without-repeating-characters/)
 * brute force solution
 * \details Given a string `s`, find the length of the longest substring without
 * repeating characters.
 */

#include <assert.h>
#include <stdio.h>

/**
 * @brief Remove a value from a given array.
 *
 * @param [in,out] nums array of numbers that gets modified in place
 * @param numsSize length of input array
 * @param val value to remove from the array
 * @return length of the new array
 */
int removeElement(int *nums, int numsSize, int val)
{
    int i, start = 0;
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] != val)
            nums[start++] = nums[i];
    }
    return start;
}

/**
 * @brief Main function
 * @return 0
 */
int main()
{
    int nums1[] = {3, 2, 2, 3}, l1 = 4;
    int out1 = removeElement(nums1, l1, 3);
    assert(out1 == 2);
    for (int i = 0; i < out1; i++) printf("%d ", nums1[i]);
    putchar('\n');

    int nums2[] = {0, 1, 2, 2, 3, 0, 4, 2}, l2 = 8;
    int out2 = removeElement(nums2, l2, 2);
    assert(out2 == 5);
    for (int i = 0; i < out2; i++) printf("%d ", nums2[i]);
    putchar('\n');

    return 0;
}
