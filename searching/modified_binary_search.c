/**
 * @file
 * @brief [Modified binary search algorithm](https://arxiv.org/abs/1406.1677)
 */
#include <stdio.h>
#include <stdlib.h>

/** This function does Binary search for `x` in `i`-th row from `j_low` to
 * `j_high`.
 * @param mat 2D matrix to search within
 * @param i row to search in
 * @param j_low start column index
 * @param j_high end column index
 * @param x value to search for
 * @return column where `x` was found
 * @return -1 if value not found
 */
int binarySearch(const int **mat, int i, int j_low, int j_high, int x)
{
    while (j_low <= j_high)
    {
        int j_mid = (j_low + j_high) / 2;

        // Element found
        if (mat[i][j_mid] == x)
        {
            printf("Found at (%d,%d)\n", i, j_mid);
            return j_mid;
        }
        else if (mat[i][j_mid] > x)
            j_high = j_mid - 1;
        else
            j_low = j_mid + 1;
    }

    // element not found
    printf("element not found\n");
    return -1;
}

/** Function to perform binary search on the mid values of row to get the
 * desired pair of rows where the element can be found
 * @param [in] mat matrix to search for the value in
 * @param n number of rows in the matrix
 * @param m number of columns in the matrix
 * @param x value to search for
 */
void modifiedBinarySearch(const int **mat, int n, int m, int x)
{  // If Single row matrix
    if (n == 1)
    {
        binarySearch(mat, 0, 0, m - 1, x);
        return;
    }

    // Do binary search in middle column.
    // Condition to terminate the loop when the 2 desired rows are found.
    int i_low = 0, i_high = n - 1, j_mid = m / 2;
    while ((i_low + 1) < i_high)
    {
        int i_mid = (i_low + i_high) / 2;
        // element found
        if (mat[i_mid][j_mid] == x)
        {
            printf("Found at (%d,%d)\n", i_mid, j_mid);
            return;
        }
        else if (mat[i_mid][j_mid] > x)
            i_high = i_mid;
        else
            i_low = i_mid;
    }
    // If element is present on the mid of the two rows
    if (mat[i_low][j_mid] == x)
        printf("Found at (%d,%d)\n", i_low, j_mid);
    else if (mat[i_low + 1][j_mid] == x)
        printf("Found at (%d,%d)\n", i_low + 1, j_mid);

    // Search element on 1st half of 1st row
    else if (x <= mat[i_low][j_mid - 1])
        binarySearch(mat, i_low, 0, j_mid - 1, x);

    // Search element on 2nd half of 1st row
    else if (x >= mat[i_low][j_mid + 1] && x <= mat[i_low][m - 1])
        binarySearch(mat, i_low, j_mid + 1, m - 1, x);

    // Search element on 1st half of 2nd row
    else if (x <= mat[i_low + 1][j_mid - 1])
        binarySearch(mat, i_low + 1, 0, j_mid - 1, x);

    // search element on 2nd half of 2nd row
    else
        binarySearch(mat, i_low + 1, j_mid + 1, m - 1, x);
}

/** Main function */
int main()
{
    int x;     // element to be searched
    int m, n;  // m = columns, n = rows

    scanf("%d %d %d\n", &n, &m, &x);

    int **mat = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < m; i++) mat[i] = (int *)malloc(m * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    modifiedBinarySearch(mat, n, m, x);

    for (int i = 0; i < n; i++) free(mat[i]);
    free(mat);
    return 0;
}
