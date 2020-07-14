// Valid Sudoku
// Check if sudoku board is valid

#include <stdbool.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize)
{
    int used_row[9][9] = {0};
    int used_col[9][9] = {0};
    int used_subbox[9][9] = {0};
    int i, j, cur, sub_idx;

    for (i = 0; i < boardSize; i++)
    {
        for (j = 0; j < *boardColSize; j++)
        {
            if (board[i][j] != '.')
            {
                cur = board[i][j] - '0' - 1;
                sub_idx = i / 3 * 3 + j / 3;

                if (used_col[cur][j] || used_row[i][cur] ||
                    used_subbox[sub_idx][cur])
                {
                    return false;
                }

                used_col[cur][j] = 1, used_row[i][cur] = 1;
                used_subbox[sub_idx][cur] = 1;
            }
        }
    }
    return true;
}
