/**
 * \file
 * \brief [1. Twos Sum](https://leetcode.com/problems/two-sum/) solution
 * \details
 * Given an array of integers `nums` and an integer `target`, return **indices
 * of the two numbers such that they add up to `target`**.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Solution implementation
 *
 * @param [in] nums array of integers
 * @param [in] numsSize number of integers in the array
 * @param [in] target target integer
 * @param [out] returnSize size of output array (always = 2)
 * @return int* array
 * @note the output array must be **freed** by the calling function.
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int i, j;
    int *ret = calloc(2, sizeof(int));
    for (i = 0; i < numsSize; i++)
    {
        int key = target - nums[i];
        for (j = i + 1; j < numsSize; j++)
            if (nums[j] == key)
            {
                ret[0] = i;
                ret[1] = j;
            }
    }
    *returnSize = 2;
    return ret;
}

/** Main function
 * @returns 0
 */
int main()
{
    int in1[] = {2, 7, 11, 15};
    int target1 = 9;
    int tmp;
    int *test1 = twoSum(in1, 4, target1, &tmp);
    assert(in1[test1[0]] + in1[test1[1]] == target1);
    printf("Test 1 passed.\n");
    free(test1);

    int in2[] = {3, 2, 4};
    int target2 = 6;
    int *test2 = twoSum(in2, 3, target2, &tmp);
    assert(in2[test2[0]] + in2[test2[1]] == target2);
    printf("Test 2 passed.\n");
    free(test2);

    int in3[] = {3, 3};
    int target3 = 6;
    int *test3 = twoSum(in3, 2, target3, &tmp);
    assert(in3[test3[0]] + in3[test3[1]] == target3);
    printf("Test 3 passed.\n");
    free(test3);

    return 0;
}
