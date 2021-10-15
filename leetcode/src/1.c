/**
 * @file
 * @brief Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * @param [in,out] nums array of integers to be searched.
 * @param [in] nums_size nums array size.
 * @param [in] target target num.
 * @param [in,out] return_size size of returned array.
 * @return a pointer to the resulting array with the indices of the two numbers such that they add up to target.
 */
int *twoSum(int *nums, int nums_size, int target, int *return_size) {
    int i, j;
    int *ret = calloc(2, sizeof(int));
    for (i = 0; i < nums_size; i++)    {
        for (j = i + 1; j < nums_size; j++)
            if (nums[i] + nums[j] == target) {
                ret[0] = i;
                ret[1] = j;
            }
    }
    
    *return_size = 2;
    return ret;
}
