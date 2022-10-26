// Dynamic programming can be applied here, because every solved sub-problem has
// an optimal sub-solution
// Searching backwards from end to start, we can incrementally calculate number
// of paths to destination. i.e. start from bottom-right, and calculate
// leftwards (lowest row should all be 1). then go to second-last-row, rightmost
// column, and calculate leftwards the last cell to be calculated is the start
// location (0, 0). The iteration ordering is intentional: the inner loop
// iterates the contents of each vector, the outer loop iterates each vector.
// This is more cache-friendly.

// Example below, calculated from right-to-left, bottom-to-top.
// 7 by 3 grid
// 28 21 15 10  6  3  1
//  7  6  5  4  3  2  1
//  1  1  1  1  1  1  1

int uniquePaths(int m, int n)
{
    int dp[m][n];

    for (int column = 0; column < n; column++)
    {
        dp[0][column] = 1;
    }

    for (int row = 1; row < m; row++)
    {
        dp[row][0] = 1;
    }

    for (int row = 1; row < m; row++)
    {
        for (int column = 1; column < n; column++)
        {
            dp[row][column] = dp[row - 1][column] + dp[row][column - 1];
        }
    }
    return dp[m - 1][n - 1];
}
