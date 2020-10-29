int missingNumber(int *nums, int numsSize)
{
    int i, actual_sum = 0, sum = 0;
    for (i = 0; i < numsSize; i++)
    {
        sum = sum + nums[i];
        actual_sum = actual_sum + i;
    }
    return actual_sum + numsSize - sum;
}
