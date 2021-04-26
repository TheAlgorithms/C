int searchInsert(int *nums, int numsSize, int target)
{
    int low = 0, high = numsSize - 1, mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (target > nums[mid])
            low = mid + 1;
        else if (target < nums[mid])
            high = mid - 1;
        else
            return mid;
    }
    return low;
}

/* Recursive version */
int searchInsert(int *nums, int numsSize, int target)
{
    int idx = numsSize - 1;
    if (numsSize > 0)
    {
        if (target > nums[idx])
        {
            return numsSize;
        }
        return searchInsert(nums, numsSize - 1, target);
    }
    return 0;
}
