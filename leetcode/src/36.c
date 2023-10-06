/**
 * Check if a Sudoku board is valid.
 *
 * The function takes a 2D character array representing the Sudoku board, the
 * number of rows in the board (boardSize), and an array representing the number
 * of columns in each row (boardColSize). It returns true if the Sudoku board is
 * valid according to Sudoku rules, and false otherwise.
 *
 * Parameters:
 * - board: A 2D character array representing the Sudoku board.
 * - boardSize: The number of rows in the Sudoku board.
 * - boardColSize: An array representing the number of columns in each row of
 * the Sudoku board.
 *
 * Return:
 * - true if the Sudoku board is valid, false otherwise.
 */
bool isValidSudoku(char** board, int boardSize, int* boardColSize)
{
    // Arrays to keep track of numbers encountered in rows, columns, and
    // subgrids
    int m[9][9] = {0};
    int m_row[9][9] = {0};
    int m_col[9][9] = {0};
    int count;

    // Iterate through each cell in the board
    for (int i = 0; i < boardSize; i++)
    {
        if (i < 3)
            count = 0;
        else if (i > 2 && i < 6)
            count = 3;
        else if (i >= 6)
            count = 6;

        for (int j = 0; j < *boardColSize; j++)
        {
            // Check if the cell contains a valid digit (between '1' and '9')
            if (board[i][j] >= '1' && board[i][j] <= '9')
            {
                int num = board[i][j] - '0';
                m_row[i][num - 1]++;
                m_col[j][num - 1]++;
                m[count + j / 3][num - 1]++;
            }
        }
        count = 0;
    }

    // Check for duplicate numbers in rows, columns, and subgrids
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < *boardColSize; j++)
        {
            if (board[i][j] >= '1' && board[i][j] <= '9')
            {
                int num = board[i][j] - '0';
                if (m_row[i][num - 1] > 1 || m_col[j][num - 1] > 1 ||
                    m[(i / 3) * 3 + j / 3][num - 1] > 1)
                {
                    return false;
                }
            }
        }
    }

    return true;
}
