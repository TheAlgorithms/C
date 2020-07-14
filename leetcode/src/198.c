// House Robber

#define max(x, y) ((x) > (y) ? (x) : (y))

int rob(int* nums, int numsSize)
{
    if (!numsSize)
        return 0;
    if (numsSize == 1)
        return nums[0];
    if (numsSize == 2)
        return max(nums[0], nums[1]);

    int day1 = max(nums[0], nums[1]);
    int day2 = nums[0];
    int cur;

    for (int i = 2; i < numsSize; i++)
    {
        cur = max(day2 + nums[i], day1);
        day2 = day1;
        day1 = cur;
    }

    return max(day1, day2);
}
