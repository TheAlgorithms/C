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
#include <stdlib.h>
#include <string.h>

/**
 * @brief Function to remove duplicates in an array.
 *
 * @param [in,out] nums sorted input array
 * @param numsSize length of input array
 * @return modified length of the array
 */
int removeDuplicates(int *nums, int numsSize)
{
    int count = 0, i;
    for (i = 1; i < numsSize; i++)
    {
        if (nums[i] == nums[i - 1])
            count++;
        else
            nums[i - count] = nums[i];
    }
    return numsSize - count;
}

/**
 * @brief Main function
 * @return 0
 */
int main()
{
    int nums1[] = {1, 1, 2}, l1 = 3;
    int out1 = removeDuplicates(nums1, l1);
    assert(out1 == 2 && nums1[0] == 1 && nums1[1] == 2);

    int nums2[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4}, l2 = 10;
    int out2 = removeDuplicates(nums2, l2);
    assert(out2 == 5);
    for (int i = 0; i < out2 - 1; i++) assert(nums2[i] != nums2[i + 1]);

    return 0;
}
