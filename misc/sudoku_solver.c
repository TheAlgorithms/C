/**
 * @file
 * @brief Sudoku Solver using recursive implementation of brute-force algorithm
 *
 * @details
 * Given an incomplete N*N Sudoku and asked to solve it using the
 * following recursive algorithm:
 * 1. Scan the Sudoku from left to right row-wise to search for an empty cell.
 * 2. If there are no empty cells, print the Sudoku. Go to step 5.
 * 3. In the empty cell, try putting numbers 1 to N
 * while ensuring that no two numbers in a single row, column, or box are same.
 * Go back to step 1.
 * 4. Declare that the Sudoku is Invalid.
 * 5. Exit.
 *
 * @authors [Anuj Shah](https://github.com/anujms1999)
 * @authors [Krishna Vedala](https://github.com/kvedala)
 */
#include <assert.h>
#include <inttypes.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** @addtogroup sudoku Sudoku solver
 * @{
 */
/** Structure to hold the matrix and dimensions
 */
struct sudoku
{
    uint8_t *a; /**< matrix as a flattened 1D row-major array */
    uint8_t N;  /**< number of elements */
    uint8_t N2; /**< block of elements */
};

/**
 * Check if `x`^th row is valid
 * @param a ::sudoku to check
 * @param x row to check
 * @param y ignored column
 * @param v value to check if it repeats
 * @returns `true` if valid
 * @returns `false` if in-valid
 */
bool OKrow(const struct sudoku *a, int x, int y, int v)
{
    int offset = x * a->N;
    for (int j = 0; j < a->N; j++)
        if (a->a[offset + j] == v)
            // if the value is found in the row
            return false;
    return true;
}

/**
 * Check if `y`^th column is valid
 * @param a ::sudoku to check
 * @param x ignored row
 * @param y column to check
 * @param v value to check if it repeats
 * @returns `true` if valid
 * @returns `false` if in-valid
 */
bool OKcol(const struct sudoku *a, int x, int y, int v)
{
    for (int i = 0; i < a->N; i++)
        if (a->a[i * a->N + y] == v)
            // if the value is found in the column
            return false;
    return true;
}

/**
 * Check if a 3x3 box is valid
 * @param a matrix to check
 * @param x row index of the element to check
 * @param y column index of the element to check
 * @param v value to check if it repeats
 * @returns `true` if valid
 * @returns `false` if in-valid
 */
bool OKbox(const struct sudoku *a, int x, int y, int v)
{
    /* get start indices of the box that the current (x,y) lies in
       remember that in C/C++, division operation always rounds towards
       -infinity for signed integers and towards 0 for unsigned integers
    */
    int bi = x - x % a->N2, bj = y - y % a->N2;
    // printf("Checking box: (%d,%d)\n", bi, bj);

    for (int i = bi; i < (bi + a->N2); i++)
        for (int j = bj; j < (bj + a->N2); j++)
            if (a->a[i * a->N + j] == v)
                // if the value is found in the box
                return false;
    return true;
}

/**
 * Check if element `v` is valid to place at (x,y) location.
 * @param a ::sudoku to check
 * @param x row to place value
 * @param y column to place value
 * @param v value to check if it is valid
 * @returns `true` if valid
 * @returns `false` if in-valid
 */
bool OK(const struct sudoku *a, int x, int y, int v)
{
    bool result = OKrow(a, x, y, v);
    if (result)
        result = OKcol(a, x, y, v);
    if (result)
        result = OKbox(a, x, y, v);

    return result;
}

/**
 * Print the matrix to stdout
 * @param [in] a array to print
 */
void print(const struct sudoku *a)
{
    int i, j;
    for (i = 0; i < a->N; i++)
        for (j = 0; j < a->N; j++)
            printf("%" SCNu8 "%c", a->a[i * a->N + j],
                   (j == a->N - 1 ? '\n' : ' '));
}

/**
 * @brief Find and get the location for next empty cell.
 *
 * @param [in] a pointer to sudoku instance
 * @param [out] x pointer to row index of next unknown
 * @param [out] y pointer to column index of next unknown
 * @returns `true` if an empty location was found
 * @returns `false` if no more empty locations found
 */
bool get_next_unknown(const struct sudoku *a, int *x, int *y)
{
    for (int i = 0; i < a->N; i++)
    {
        for (int j = 0; j < a->N; j++)
        {
            if (a->a[i * a->N + j] == 0)
            {
                *x = i;
                *y = j;
                return true;
            }
        }
    }

    /* no unknown locations found */
    return false;
}

/**
 * @brief Function to solve a partially filled sudoku matrix. For each unknown
 * value (0), the function fills a possible value and calls the function again
 * to check forvalid solution.
 *
 * @param [in,out] a sudoku matrix to solve
 * @return `true` if solution found
 * @return `false` if no solution found
 */
bool solve(struct sudoku *a)
{
    static uint32_t counter = 0;
    int i, j;
    static char prefix[100] = "";  // enough memory

    if (!get_next_unknown(a, &i, &j))
    {
        /* no more empty location found
           implies all good in the matrix
         */
        return true;
    }

    /* try all possible values for the unknown */
    for (uint8_t v = 1; v <= a->N; v++)
    { /* try all possible values 1 thru N */
        printf("%sTry (%d,%d) = %" SCNu8 "... ", prefix, i, j, v);
        counter++;
        if (OK(a, i, j, v))
        {
            /* if assignment checks satisfy, set the value and
             continue with remaining elements */
            printf("passed (counter=%" SCNu32 ")\n", counter);
            a->a[i * a->N + j] = v;
            strcat(prefix, "  ");
            if (solve(a))
            {
                /* solution found */
                return true;
            }

            printf("%sBacktrack (%d,%d) <- %" SCNu8 " (counter=%" SCNu32 ")\n",
                   prefix, i, j, a->a[i * a->N + j], counter);

            prefix[strlen(prefix) - 2] = '\0';  // truncate the prefix
            a->a[i * a->N + j] = 0;
        }
        else
        {
            printf("\r");
        }
    }

    return false;
}

/** @} */

void test()
{
    printf("Test begin...\n");

    uint8_t test_array[] = {3, 0, 6, 5, 0, 8, 4, 0, 0, 5, 2, 0, 0, 0, 0, 0, 0,
                            0, 0, 8, 7, 0, 0, 0, 0, 3, 1, 0, 0, 3, 0, 1, 0, 0,
                            8, 0, 9, 0, 0, 8, 6, 3, 0, 0, 5, 0, 5, 0, 0, 9, 0,
                            6, 0, 0, 1, 3, 0, 0, 0, 0, 2, 5, 0, 0, 0, 0, 0, 0,
                            0, 0, 7, 4, 0, 0, 5, 2, 0, 6, 3, 0, 0};
    struct sudoku a = {.N = 9, .N2 = 3, .a = test_array};
    assert(solve(&a));  // ensure that solution is obtained

    uint8_t expected[] = {3, 1, 6, 5, 7, 8, 4, 9, 2, 5, 2, 9, 1, 3, 4, 7, 6,
                          8, 4, 8, 7, 6, 2, 9, 5, 3, 1, 2, 6, 3, 4, 1, 5, 9,
                          8, 7, 9, 7, 4, 8, 6, 3, 1, 2, 5, 8, 5, 1, 7, 9, 2,
                          6, 4, 3, 1, 3, 8, 9, 4, 7, 2, 5, 6, 6, 9, 2, 3, 5,
                          1, 8, 7, 4, 7, 4, 5, 2, 8, 6, 3, 1, 9};
    for (int i = 0; i < a.N; i++)
        for (int j = 0; j < a.N; j++)
            assert(a.a[i * a.N + j] == expected[i * a.N + j]);

    printf("Test passed\n");
}

/** \brief Main function */
int main()
{
    test();

    struct sudoku a;  // store the matrix as a 1D array
    scanf("%" SCNu8, &(a.N));
    a.a = (uint8_t *)malloc(a.N * a.N * sizeof(uint8_t));
    a.N2 = (uint8_t)sqrt(a.N);

    for (int i = 0; i < a.N; i++)
        for (int j = 0; j < a.N; j++) scanf("%" SCNu8, &(a.a[i * a.N + j]));

    printf("Entered a %udx%ud matrix with block size: %" SCNu8 "\n", a.N, a.N,
           a.N2);
    // print(&a);
    printf("\n\n");
    if (solve(&a))
        printf("Valid solution found!\n");
    else
        printf("Invalid\n");
    print(&a);

    free(a.a);
    return 0;
}
