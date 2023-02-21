/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// Calculating ones on each row and column.
// Runtime: O(n * m)
// Space: O(n + m)
int** onesMinusZeros(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes){
    int n = gridSize;
    int m = gridColSize[0];

    int** result = malloc(gridSize * sizeof(int*));
    for (int i = 0; i < n; i++){
        result[i] = malloc(m * sizeof(int));
    }

    int* onesRows = calloc(n, sizeof(int));
    int* onesCols = calloc(m, sizeof(int));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j] == 1){
                onesRows[i] += 1;
                onesCols[j] += 1;
            }
        }
    }

    for (int i = 0; i < gridSize; i++){
        for (int j = 0; j < gridColSize[i]; j++){
            result[i][j] = onesRows[i] + onesCols[j] - (m - onesRows[i]) - (n - onesCols[j]);
        }
    }

    free(onesRows);
    free(onesCols);

    *returnSize = gridSize;
    *returnColumnSizes = gridColSize;
    return result;
}
