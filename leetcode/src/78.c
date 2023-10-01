/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int numSubsets = (int)pow(2, numsSize);

    // Allocate memory for the result array
    int** result = (int**)malloc(numSubsets * sizeof(int*));
    *returnColumnSizes = (int*)malloc(numSubsets * sizeof(int));

    // Initialize the sizes of individual subsets
    for (int i = 0; i < numSubsets; i++)
    {
        int subsetSize = 0;
        for (int j = 0; j < numsSize; j++)
        {
            if ((i >> j) & 1)
            {
                subsetSize++;
            }
        }
        (*returnColumnSizes)[i] = subsetSize;
    }

    // Generate all subsets
    for (int i = 0; i < numSubsets; i++)
    {
        result[i] = (int*)malloc((*returnColumnSizes)[i] * sizeof(int));
        int index = 0;
        for (int j = 0; j < numsSize; j++)
        {
            if ((i >> j) & 1)
            {
                result[i][index++] = nums[j];
            }
        }
    }

    *returnSize = numSubsets;
    return result;
}
