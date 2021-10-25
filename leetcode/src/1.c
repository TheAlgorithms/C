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
