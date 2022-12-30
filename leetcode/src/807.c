#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

// Collect maxes on each row and each column.
// Runtime: O(n * n)
// Space: O(n)
int maxIncreaseKeepingSkyline(int** grid, int gridSize, int* gridColSize){
    int* rowsMaxs = calloc(gridSize, sizeof(int));
    int* colsMaxs = calloc(gridSize, sizeof(int));

    // Find max of each row and column
    for(int i = 0; i < gridSize; i++){
        for (int j = 0; j < gridSize; j++){
            rowsMaxs[i] = max(rowsMaxs[i], grid[i][j]);
            colsMaxs[j] = max(colsMaxs[j], grid[i][j]);
        }
    }

    int result = 0;
    for(int i = 0; i < gridSize; i++){
        for (int j = 0; j < gridSize; j++){
            int rowMax = rowsMaxs[i];
            int colMax = colsMaxs[j];
            result += min(rowMax - grid[i][j], colMax - grid[i][j]);
        }
    }

    free(rowsMaxs);
    free(colsMaxs);

    return result;
}
