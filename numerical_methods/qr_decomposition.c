/**
 * @file
 * \brief Program to compute the [QR
 * decomposition](https://en.wikipedia.org/wiki/QR_decomposition) of a given
 * matrix.
 * \author [Krishna Vedala](https://github.com/kvedala)
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "qr_decompose.h"

/**
 * main function
 */
int main(void)
{
    double **A;
    unsigned int ROWS, COLUMNS;

    printf("Enter the number of rows and columns: ");
    scanf("%u %u", &ROWS, &COLUMNS);
    if (ROWS < COLUMNS)
    {
        fprintf(stderr,
                "Number of rows must be greater than or equal to "
                "number of columns.\n");
        return -1;
    }

    printf("Enter matrix elements row-wise:\n");

    A = (double **)malloc(ROWS * sizeof(double *));
    for (int i = 0; i < ROWS; i++)
        A[i] = (double *)malloc(COLUMNS * sizeof(double));

    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLUMNS; j++) scanf("%lf", &A[i][j]);

    print_matrix(A, ROWS, COLUMNS);

    double **R = (double **)malloc(sizeof(double *) * ROWS);
    double **Q = (double **)malloc(sizeof(double *) * ROWS);
    if (!Q || !R)
    {
        perror("Unable to allocate memory for Q & R!");
        return -1;
    }
    for (int i = 0; i < ROWS; i++)
    {
        R[i] = (double *)malloc(sizeof(double) * COLUMNS);
        Q[i] = (double *)malloc(sizeof(double) * ROWS);
        if (!Q[i] || !R[i])
        {
            perror("Unable to allocate memory for Q & R.");
            return -1;
        }
    }

    clock_t t1 = clock();
    qr_decompose(A, Q, R, ROWS, COLUMNS);
    double dtime = (double)(clock() - t1) / CLOCKS_PER_SEC;

    print_matrix(R, ROWS, COLUMNS);
    print_matrix(Q, ROWS, COLUMNS);
    printf("Time taken to compute: %.4g sec\n", dtime);

    for (int i = 0; i < ROWS; i++)
    {
        free(A[i]);
        free(R[i]);
        free(Q[i]);
    }
    free(A);
    free(R);
    free(Q);
    return 0;
}
