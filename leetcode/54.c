
#include <stdio.h>
#include <stdlib.h>

// Function to return spiral order of matrix
int* spiralOrder(int** matrix, int n, int m, int* returnSize)
{
    // Allocate space for result
    int* ans = (int*)malloc(n * m * sizeof(int));
    *returnSize = 0;  // keeps track of how many elements are stored

    // Define boundaries
    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;
    int traversedCount = 0;
    int total = n * m;

    // Traverse while we haven't covered all elements
    while (traversedCount < total)
    {
        // Traverse from left to right (top row)
        for (int j = left; j <= right && traversedCount < total; j++)
        {
            ans[(*returnSize)++] = matrix[top][j];
            traversedCount++;
        }
        top++;

        // Traverse from top to bottom (right column)
        for (int i = top; i <= bottom && traversedCount < total; i++)
        {
            ans[(*returnSize)++] = matrix[i][right];
            traversedCount++;
        }
        right--;

        // Traverse from right to left (bottom row)
        for (int j = right; j >= left && traversedCount < total; j--)
        {
            ans[(*returnSize)++] = matrix[bottom][j];
            traversedCount++;
        }
        bottom--;

        // Traverse from bottom to top (left column)
        for (int i = bottom; i >= top && traversedCount < total; i--)
        {
            ans[(*returnSize)++] = matrix[i][left];
            traversedCount++;
        }
        left++;
    }

    return ans;
}
