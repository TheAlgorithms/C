// ThreeSum code in C

int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

int** threeSum(int* nums, int numsSize, int* returnSize,
               int** returnColumnSizes)
{
    // Sort the input array
    qsort(nums, numsSize, sizeof(int), compare);

    int** result = (int**)malloc(sizeof(int*) * numsSize);
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * numsSize);

    for (int i = 0; i < numsSize - 2; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;  // Skip duplicates
        }

        int left = i + 1;
        int right = numsSize - 1;

        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0)
            {
                result[*returnSize] = (int*)malloc(sizeof(int) * 3);
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;
                left++;
                right--;
            }
            else if (sum < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    return result;
}
