// fourSum implementation in C

// Comparison function for qsort
int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

int** fourSum(int* nums, int numsSize, int target, int* returnSize,
              int** returnColumnSizes)
{
    // Sort the input array
    qsort(nums, numsSize, sizeof(int), compare);

    int** result = (int**)malloc(sizeof(int*) * numsSize);
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * numsSize);

    for (int i = 0; i < numsSize - 3; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;  // Skip duplicates
        }

        for (int j = i + 1; j < numsSize - 2; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
            {
                continue;  // Skip duplicates
            }

            int left = j + 1;
            int right = numsSize - 1;

            while (left < right)
            {
                long sum = (long)nums[i] + (long)nums[j] + (long)nums[left] +
                           (long)nums[right];

                if (sum == target)
                {
                    result[*returnSize] = (int*)malloc(sizeof(int) * 4);
                    result[*returnSize][0] = nums[i];
                    result[*returnSize][1] = nums[j];
                    result[*returnSize][2] = nums[left];
                    result[*returnSize][3] = nums[right];
                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;

                    while (left < right && nums[left] == nums[left + 1])
                        left++;  // Skip duplicates
                    while (left < right && nums[right] == nums[right - 1])
                        right--;  // Skip duplicates

                    left++;
                    right--;
                }
                else if (sum < target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
    }

    return result;
}
