/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int compare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

// Recursive function to generate subsets with duplicates
void generateSubsetsWithDup(int *nums, int numsSize, int startIndex,
                            int *currentSubset, int currentSize, int ***result,
                            int **columnSizes, int *returnSize)
{
    // Add the current subset to the result
    (*result) = (int **)realloc((*result), (*returnSize + 1) * sizeof(int *));
    (*columnSizes) =
        (int *)realloc((*columnSizes), (*returnSize + 1) * sizeof(int));

    (*result)[*returnSize] = (int *)malloc(currentSize * sizeof(int));
    memcpy((*result)[*returnSize], currentSubset, currentSize * sizeof(int));

    (*columnSizes)[*returnSize] = currentSize;

    (*returnSize)++;

    // Generate subsets by including the current element
    for (int i = startIndex; i < numsSize; i++)
    {
        // Skip duplicates
        if (i > startIndex && nums[i] == nums[i - 1])
        {
            continue;
        }

        // Add the current element to the current subset
        currentSubset[currentSize] = nums[i];
        generateSubsetsWithDup(nums, numsSize, i + 1, currentSubset,
                               currentSize + 1, result, columnSizes,
                               returnSize);
    }
}

int **subsetsWithDup(int *nums, int numsSize, int *returnSize,
                     int **returnColumnSizes)
{
    // Sort the input array to handle duplicates
    qsort(nums, numsSize, sizeof(int), compare);

    int **result = NULL;
    int *columnSizes = NULL;
    int *currentSubset = (int *)malloc(numsSize * sizeof(int));
    *returnSize = 0;

    generateSubsetsWithDup(nums, numsSize, 0, currentSubset, 0, &result,
                           &columnSizes, returnSize);

    free(currentSubset);

    *returnColumnSizes = columnSizes;
    return result;
}
