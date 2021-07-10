int findNumbers(int* nums, int numsSize)
{
    int ans = 0;
    for (int i = 0; i < numsSize; i++)
    {
        int c = nums[i];
        int count = 0;
        while (c > 0)
        {
            count++;
            c = c / 10;
        }
        if (count % 2 == 0)
        {
            ans++;
        }
    }
    return ans;
}
