/*
@ file magic_square.c

@ brief Constructs normal magic squares of arbitrary valid order.

@ Implements three construction methods for normal magic squares:
    - TURAGAGATI for odd orders.
    - SAMPUTAVIDHI for doubly even orders.
    - VISHAMAGARBHA SUTRA for singly even orders.

@ Author -> Naman Hegde

@ These algorithms are taken from an Indian Mathematician Narayana Pandita
@ Narayana Pandita was an 14th century mathematician who mentions about magic
sqaures in his book Ganita Kaumudi

@ The construction of each magic square requires O(n²) time and O(n²) space for
the output matrix.
@ The singly-even and doubly-even implementations perform additional
    temporary allocations, but their total auxiliary space remains O(n²).

@ some variables are named according to the source book
*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
@ initialize all values of the matrix to zero
*/

void set_zero(int n, int (*ptr)[n]) { memset(ptr, 0, n * n * sizeof(int)); }

void swap(int* ptr1, int* ptr2)
{
    int temp;
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

/*
            TURAGAGATI Algorithm

@ for odd numbered matrix
@ starting from 1 in top row middle column
@ filling numbers continuously by moving like Knight in chess
@ all rows and columns are wrapped
@ If square is already filled fill the square below the home square
*/

void odd_numbers(int n, int (*ptr)[n])
{
    int i;
    int mid = n / 2;
    int end = n * n;
    ptr[0][mid] = 1;
    int oldrow = 0, oldcol = mid;
    int rows = 0;
    int columns = mid;
    for (i = 2; i <= end; i++)
    {
        rows += 2;
        columns += 1;
        if (rows >= n)
        {
            rows -= n;
        }
        if (columns >= n)
        {
            columns -= n;
        }
        if (ptr[rows][columns])
        {
            oldrow += 1;
            if (oldrow >= n)
            {
                oldrow -= n;
            }
            rows = oldrow;
            columns = oldcol;
        }
        ptr[rows][columns] = i;
        oldrow = rows;
        oldcol = columns;
    }
}

/*
            SAMPUTAVIDHI Algorithm

@ for doubly even matrix
@ an array containing 1 to n elements -> mulapankti
@ another array containing 0 to (n^2) - n elements -> gunapankti
@ mulapankti arranged in specific order in a 2D matrix of n*n -> chadya (to be
covered)
@ gunapankti arranged in specific order in a 2D matrix of n*n -> chadaka (which
covers)
@ both chadya and chadaka are folded (added) where chadaka's rows are reversed
*/

void doubly_even(int n, int (*ptr)[n])
{
    int* mulapankti = malloc(n * sizeof(int));
    int* gunapankti = malloc(n * sizeof(int));

    if (mulapankti == NULL || gunapankti == NULL)
    {
        free(mulapankti);
        free(gunapankti);
        return;
    }
    int square = n * n;
    int* start;
    int* end;
    int mid = n / 2;
    int (*chadya)[n] = malloc(n * sizeof *chadya);
    int (*chadaka)[n] = malloc(n * sizeof *chadaka);

    if (chadya == NULL || chadaka == NULL)
    {
        free(chadya);
        free(chadaka);
        free(mulapankti);
        free(gunapankti);
        return;
    }
    int rows = 0;
    int columns = 0;
    for (int i = 1; i <= n; i++)
    {
        mulapankti[i - 1] = i;
    }
    start = mulapankti + (mid - 1);
    end = mulapankti + (mid);
    for (columns = 0; columns < n; columns += 2)
    {
        chadya[rows][columns] = *start;
        chadya[rows][columns + 1] = *end;
        chadya[rows + mid][columns] = *end;
        chadya[rows + mid][columns + 1] = *start;
    }
    for (rows = 1; rows < mid; rows++)
    {
        start--;
        end++;
        for (columns = 0; columns < n; columns += 2)
        {
            chadya[rows][columns] = *start;
            chadya[rows][columns + 1] = *end;
            chadya[rows + mid][columns] = *end;
            chadya[rows + mid][columns + 1] = *start;
        }
    }
    int element = 0;
    for (int j = 0; j < square; j += n)
    {
        gunapankti[element] = j;
        element++;
    }
    rows = 0;
    columns = 0;
    start = gunapankti;
    end = gunapankti + (n - 1);
    for (rows = 0; rows < n; rows += 2)
    {
        chadaka[rows][columns] = *start;
        chadaka[rows + 1][columns] = *end;
        chadaka[rows][columns + mid] = *end;
        chadaka[rows + 1][columns + mid] = *start;
    }
    for (columns = 1; columns < mid; columns++)
    {
        start++;
        end--;
        for (rows = 0; rows < n; rows += 2)
        {
            chadaka[rows][columns] = *start;
            chadaka[rows + 1][columns] = *end;
            chadaka[rows][columns + mid] = *end;
            chadaka[rows + 1][columns + mid] = *start;
        }
    }
    rows = 0;
    columns = 0;
    for (rows = 0; rows < n; rows++)
    {
        for (columns = 0; columns < n; columns++)
        {
            ptr[rows][columns] =
                chadya[rows][columns] + chadaka[(n - 1) - rows][columns];
        }
    }

    free(chadya);
    free(chadaka);
    free(mulapankti);
    free(gunapankti);
}

/*
            VISHAMAGARBHA SUTRA

@ for singly even squared matrix
@ 1 to n^2 digits are continuously filled inside matrix
@ diagonal swapping is made
@ row and column swapping is done to achieve the required sum
@ shlishta -> number of rows between first row and top middle row. Needed for
swapping operations
@ pita -> variable name
*/

void singly_even(int n, int (*ptr)[n])
{
    int rows;
    int cols;
    int num = 1;
    int i;
    int shlishta = (n / 2) - 2;
    int pita;
    for (rows = 0; rows < n; rows++)
    {
        for (cols = 0; cols < n; cols++)
        {
            ptr[rows][cols] = num;
            num++;
        }
    }
    int* ptr1 = &ptr[0][0];
    int* ptr2 = &ptr[n - 1][n - 1];

    // for main diagonal
    for (i = 0; i < (n / 2); i++)
    {
        ptr1 = &ptr[i][i];
        ptr2 = &ptr[n - 1 - i][n - 1 - i];
        swap(ptr1, ptr2);
    }

    // for another diagonal
    for (i = 0; i < (n / 2); i++)
    {
        ptr1 = &ptr[i][n - 1 - i];
        ptr2 = &ptr[n - 1 - i][i];
        swap(ptr1, ptr2);
    }

    ptr1 = &ptr[(n / 2) - 1][n - 1];
    ptr2 = &ptr[n / 2][n - 1];
    swap(ptr1, ptr2);

    int flag = 0;
    int k = 1;
    pita = shlishta - 1;
    while (pita != 0)
    {
        if (!flag)
        {
            ptr1 = &ptr[(n / 2) - 1][k];
            ptr2 = &ptr[n / 2][k];
            swap(ptr1, ptr2);
            pita -= 1;
            flag = 1;
        }
        else
        {
            ptr1 = &ptr[(n / 2) - 1][n - 1 - k];
            ptr2 = &ptr[n / 2][n - 1 - k];
            swap(ptr1, ptr2);
            pita -= 1;
            flag = 0;
            k += 1;
        }
    }

    int count;
    int column = 0;
    int row = 0;

    // row exchange
    for (i = 0; i < ((n / 2) - 1); i++)
    {
        count = shlishta;
        column = i;
        while (count != 0)
        {
            if ((i + column + 1) != (n - 1))
            {
                ptr1 = &ptr[i][column + 1];
                ptr2 = &ptr[n - 1 - i][column + 1];
                swap(ptr1, ptr2);
                column++;
                count--;
            }
            else
            {
                column++;
            }
        }
    }

    // column exchange
    flag = 0;
    int columnsum;
    int sum = (n * ((n * n) + 1)) / 2;
    int shortage;
    int fill;
    for (i = 0; i < (n / 2); i++)
    {
        pita = shlishta;
        columnsum = 0;
        for (int j = 0; j < n; j++)
        {
            columnsum += ptr[j][i];
        }
        row = 0;
        shortage = sum - columnsum;
        fill = shortage / shlishta;
        for (row = 0; row < n; row++)
        {
            if ((row != i) && (row != (n - 1 - i)))
            {
                ptr1 = &ptr[row][i];
                ptr2 = &ptr[row][n - 1 - i];
                if ((*ptr2) - (*ptr1) == fill)
                {
                    swap(ptr1, ptr2);
                    pita -= 1;
                }
                else
                {
                    if (pita > 1)
                    {
                        ptr1 = &ptr[row][i];
                        ptr2 = &ptr[n - 1 - row][n - 1 - i];
                        if ((*ptr2) - (*ptr1) == fill)
                        {
                            swap(ptr1, ptr2);
                            ptr1 = &ptr[n - 1 - row][i];
                            ptr2 = &ptr[row][n - 1 - i];
                            swap(ptr1, ptr2);
                            pita -= 2;
                        }
                    }
                }
            }

            if (pita == 0)
            {
                break;
            }
        }
    }
}

/*
@ fills the board based on their type
*/

bool fill_board(int n, int (*ptr)[n])
{
    if (n < 1 || n == 2)
    {
        return false;
    }

    if (n == 1)
    {
        ptr[0][0] = 1;
    }

    else if (n % 2 != 0)
    {
        odd_numbers(n, ptr);
    }

    else if (n % 4 == 0)
    {
        doubly_even(n, ptr);
    }

    else
    {
        singly_even(n, ptr);
    }

    return true;
}

/*
            Print Board
*/
void print_board(int n, int (*ptr)[n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%4d ", ptr[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");
    int sum = n * ((n * n) + 1) / 2;
    printf("Sum = %d\n\n", sum);
}

/*
@ checks whether the generated board is magic board or not
*/

bool is_magic_square(int n, int (*board)[n])
{
    int target = n * (n * n + 1) / 2;
    for (int i = 0; i < n; ++i)
    {
        int row_sum = 0;
        int col_sum = 0;

        for (int j = 0; j < n; ++j)
        {
            row_sum += board[i][j];
            col_sum += board[j][i];
        }

        if (row_sum != target || col_sum != target)
            return false;
    }

    int diagonal1 = 0;
    int diagonal2 = 0;

    for (int i = 0; i < n; ++i)
    {
        diagonal1 += board[i][i];
        diagonal2 += board[i][n - 1 - i];
    }

    return diagonal1 == target && diagonal2 == target;
}

/*
            Test
*/

void test(void)
{
    for (int n = 3; n <= 20; n++)
    {
        // 2X2 magic board cannot be made

        int (*magic_board)[n] = malloc(n * sizeof *magic_board);

        if (magic_board == NULL)
            return;

        set_zero(n, magic_board);
        fill_board(n, magic_board);

        print_board(n, magic_board);
        assert(is_magic_square(n, magic_board));

        free(magic_board);
    }
}

/*
            Main Function
*/

int main()
{
    test();

    return 0;
}
