#define min(x,y)(((x)<(y))?(x):(y))

// DP up -> down. We are going down from gridline to gridline
// and collect the minumum cost path.
// Runtime : O(gridSize*gridColSize*gridColSize)
// Space: O(gridColSize)
int minPathCost(int** grid, int gridSize, int* gridColSize, int** moveCost, int moveCostSize, int* moveCostColSize){
    int* dp = (int*)calloc(gridColSize[0], sizeof(int));
    int* newDp = (int*)calloc(gridColSize[0], sizeof(int));
    
    for(int i = 0; i < gridSize - 1; i++){
        int currGridColSize = gridColSize[i];
        for(int j = 0; j < currGridColSize; j++){
            newDp[j] = -1;
        }
        
        for(int j = 0; j < currGridColSize; j++){
            int currGridItem = grid[i][j];
            for(int z = 0; z < currGridColSize; z++){
                int currMoveCost = dp[j] + moveCost[currGridItem][z] + currGridItem;
                
                newDp[z] = (newDp[z] == -1) ? currMoveCost : min(newDp[z], currMoveCost);
            }
        }
        
        for(int j = 0; j < currGridColSize; j++){
            dp[j] = newDp[j];
        }
    }
    
    // Find minimum value.
    int minValue = dp[0] + grid[gridSize - 1][0];
    for(int j = 1; j < gridColSize[0]; j++){
        minValue = min(minValue, dp[j] + grid[gridSize - 1][j]);
    }
    
    // free resources
    free(dp);
    free(newDp);
    
    return minValue;
}
