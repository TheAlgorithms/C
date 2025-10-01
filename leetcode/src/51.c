/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
bool isSafe(char** board, int row, int col, int n)
{
    int r, c;

    // upper-left diagonal
    r = row;
    c = col;
    while (r >= 0 && c >= 0)
    {
        if (board[r][c] == 'Q')
            return false;
        r--;
        c--;
    }

    // left row
    c = col;
    while (c >= 0)
    {
        if (board[row][c] == 'Q')
            return false;
        c--;
    }

    // lower-left diagonal
    r = row;
    c = col;
    while (r < n && c >= 0)
    {
        if (board[r][c] == 'Q')
            return false;
        r++;
        c--;
    }

    return true;
}

void solve(int col, char** board, int n, char**** ans, int* ansCount,
           int** returnColumnSizes)
{
    if (col == n)
    {
        // save current solution
        (*ans)[*ansCount] = (char**)malloc(sizeof(char*) * n);
        for (int i = 0; i < n; i++)
        {
            (*ans)[*ansCount][i] = (char*)malloc((n + 1) * sizeof(char));
            strcpy((*ans)[*ansCount][i], board[i]);
        }
        (*returnColumnSizes)[*ansCount] = n;
        (*ansCount)++;
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(board, row, col, n))
        {
            board[row][col] = 'Q';
            solve(col + 1, board, n, ans, ansCount, returnColumnSizes);
            board[row][col] = '.';
        }
    }
}

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes)
{
    int maxSolutions =
        1000;  // safe upper bound (works since n <= 9 in LeetCode)
    char*** ans = (char***)malloc(sizeof(char**) * maxSolutions);
    *returnColumnSizes = (int*)malloc(sizeof(int) * maxSolutions);
    *returnSize = 0;

    // initialize board
    char** board = (char**)malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++)
    {
        board[i] = (char*)malloc((n + 1) * sizeof(char));
        for (int j = 0; j < n; j++) board[i][j] = '.';
        board[i][n] = '\0';
    }

    solve(0, board, n, &ans, returnSize, returnColumnSizes);

    // free temp board
    for (int i = 0; i < n; i++) free(board[i]);
    free(board);

    return ans;
}
