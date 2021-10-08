int *twoSum(int *nums, int nums_size, int target, int *return_size)
{
    int i, j;
    int *ret = calloc(2, sizeof(int));
    for (i = 0; i < nums_size; i++)
    {
        int key = target - nums[i];
        for (j = i + 1; j < nums_size; j++)
            if (nums[j] == key)
            {
                ret[0] = i;
                ret[1] = j;
            }
    }
    *return_size = 2;
    return ret;
}
