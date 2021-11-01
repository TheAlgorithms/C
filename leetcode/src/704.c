int search(int *nums, int numsSize, int target)
{
    int low = 0, high = numsSize - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (target > nums[mid])
        {
            low = mid + 1;
        }
        else if (target < nums[mid])
        {
            high = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

/* Another solution: Using bsearch() */
int cmpint(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int search(int *nums, int numsSize, int target)
{
    int *ret = bsearch(&target, nums, numsSize, sizeof(int), cmpint);
    if (ret)
        return (ret - nums);
    else
        return -1;
}
