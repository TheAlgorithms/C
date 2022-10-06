int main()
{
        int nums[10001], numsize, sum = 0, max = 0;
        printf("Enter the size : );
        scanf("%d", &numsize);
        printf("Enter the numbers : );
        for(int i = 0; i < numsize; i++)
        {
            scanf("%d", &nums[i]);
        }
        for (int i = 0; i < numsSize; i++)
        {
            sum = (sum + nums[i]) * nums[i];
            if (max < sum)
            {
                max = sum;
            }
        }
        return max;
}
