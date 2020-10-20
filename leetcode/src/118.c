int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
	*returnSize = 0;
	*returnColumnSizes = NULL;
	
	if(numRows == 0)
		return NULL;
	
	int **ret = NULL;
	
	*returnSize = numRows;
	
	ret = malloc (sizeof(int *) * numRows);
	for (int row = 0; row < numRows; row++) {
		ret[row] = malloc (sizeof(int) * (row + 1));
		ret[row][0] = 1;   // First col is 1
		ret[row][row] = 1; // Last col is 1
	}
		
	*returnColumnSizes = malloc(sizeof(int) * numRows);
	for (int row = 0; row < numRows; row++) 
		(*returnColumnSizes)[row] = row + 1;

   /* Middle col calculation */
	for (int row = 2; row < numRows; row++) {
		for (int col = 1; col < row; col++){
			ret[row][col] = ret[row - 1][col - 1] + ret[row - 1][col];
		}
	}
	return ret;
}
