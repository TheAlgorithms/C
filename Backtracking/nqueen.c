/* C/C++ program to solve N Queen Problem using
backtracking */
#define N 4
#include<stdio.h>


/* A utility function to print solution */
void printSolution(int board[N][N])
{
	static int k = 1;
	printf("%d-\n",k++);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf(" %d ", board[i][j]);
		printf("\n");
	}
	printf("\n");
}


int isSafe(int board[N][N], int row, int col)
{
	int i, j;

	/* Check this row on left side */
	for (i = 0; i < col; i++)
		if (board[row][i])
			return 0;

	/* Check upper diagonal on left side */
	for (i=row, j=col; i>=0 && j>=0; i--, j--)
		if (board[i][j])
			return 0;

	/* Check lower diagonal on left side */
	for (i=row, j=col; j>=0 && i<N; i++, j--)
		if (board[i][j])
			return 0;

	return 1;
}

/* A recursive utility function to solve N
Queen problem */
int solveNQUtil(int board[N][N], int col)
{
	/* base case: If all queens are placed
	then return true */
	if (col == N )
	{
		printSolution(board);
		return 1;
	}

	/* Consider this column and try placing
	this queen in all rows one by one */
	for (int i = 0; i < N; i++)
	{
		
		if ( isSafe(board, i, col) )
		{
			/* Place this queen in board[i][col] */
			board[i][col] = 1;

			/* recur to place rest of the queens */
			solveNQUtil(board, col + 1) ;

			/* If placing queen in board[i][col]
			doesn't lead to a solution, then
			remove queen from board[i][col] */
			board[i][col] = 0; // BACKTRACK
		}
	}

	return 0;
}


void solveNQ()
{
	int board[N][N] = { {0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
	};

	if (solveNQUtil(board, 0))
	{
		printf("Solution does not exist");
		return ;
	}

	return ;
}

// driver program to test above function
int main()
{
	solveNQ();
	return 0;
}
