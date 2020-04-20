#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define ROWS 4
#define COLUMNS 3

double A[ROWS][COLUMNS] = {
    {1, 2, 3},
    {3, 6, 5},
    {5, 2, 8},
    {8, 9, 3}};

void print_matrix(double A[][COLUMNS], int M, int N)
{
    for (int row = 0; row < M; row++)
    {
        for (int col = 0; col < N; col++)
            printf("% 9.3g\t", A[row][col]);
        putchar('\n');
    }
    putchar('\n');
}

void print_2d(double **A, int M, int N)
{
    for (int row = 0; row < M; row++)
    {
        for (int col = 0; col < N; col++)
            printf("% 9.3g\t", A[row][col]);
        putchar('\n');
    }
    putchar('\n');
}

double vector_dot(double *a, double *b, int L)
{
    double mag = 0.f;
    for (int i = 0; i < L; i++)
        mag += a[i] * b[i];

    return mag;
}

double vector_mag(double *vector, int L)
{
    double dot = vector_dot(vector, vector, L);
    return sqrt(dot);
}

double *vector_proj(double *a, double *b, double *out, int L)
{
    double num = vector_dot(a, b, L);
    double deno = vector_dot(b, b, L);
    for (int i = 0; i < L; i++)
        out[i] = num * b[i] / deno;

    return out;
}

double *vector_sub(double *a, double *b, double *out, int L)
{
    for (int i = 0; i < L; i++)
        out[i] = a[i] - b[i];

    return out;
}

void qr_decompose(double A[][COLUMNS], double **Q, double **R, int M, int N)
{
    double *col_vector = (double *)malloc(M * sizeof(double));
    double *col_vector2 = (double *)malloc(M * sizeof(double));
    double *tmp_vector = (double *)malloc(M * sizeof(double));
    for (int i = 0; i < N; i++) /* for each column => R is a square matrix of NxN */
    {
        for (int j = 0; j < i; j++) /* second dimension of column */
            R[i][j] = 0.;           /* make R upper triangular */

        /* get corresponding Q vector */
        for (int j = 0; j < M; j++)
        {
            tmp_vector[j] = A[j][i]; /* accumulator for uk */
            col_vector[j] = A[j][i];
        }
        for (int j = 0; j < i; j++)
        {
            for (int k = 0; k < M; k++)
                col_vector2[k] = Q[k][j];
            vector_proj(col_vector, col_vector2, col_vector2, M);
            vector_sub(tmp_vector, col_vector2, tmp_vector, M);
        }
        double mag = vector_mag(tmp_vector, M);
        for (int j = 0; j < M; j++)
            Q[j][i] = tmp_vector[j] / mag;

        /* compute upper triangular values of R */
        for (int kk = 0; kk < M; kk++)
            col_vector[kk] = Q[kk][i];
        for (int k = i; k < N; k++)
        {
            for (int kk = 0; kk < M; kk++)
                col_vector2[kk] = A[kk][k];
            R[i][k] = vector_dot(col_vector, col_vector2, M);
        }
    }

    free(col_vector);
    free(col_vector2);
    free(tmp_vector);
}

int main(void)
{
    // double A[][COLUMNS] = {
    //     {1, -1, 4},
    //     {1, 4, -2},
    //     {1, 4, 2},
    //     {1, -1, 0}};

    print_matrix(A, ROWS, COLUMNS);

    double **R = (double **)malloc(sizeof(double) * COLUMNS * COLUMNS);
    double **Q = (double **)malloc(sizeof(double) * ROWS * COLUMNS);
    if (!Q || !R)
    {
        perror("Unable to allocate memory for Q & R!");
        return -1;
    }
    for (int i = 0; i < ROWS; i++)
    {
        R[i] = (double *)malloc(sizeof(double) * COLUMNS);
        Q[i] = (double *)malloc(sizeof(double) * COLUMNS);
        if (!Q[i] || !R[i])
        {
            perror("Unable to allocate memory for Q & R.");
            return -1;
        }
    }

    qr_decompose(A, Q, R, ROWS, COLUMNS);

    print_2d(R, ROWS, COLUMNS);
    print_2d(Q, ROWS, COLUMNS);

    for (int i = 0; i < ROWS; i++)
    {
        free(R[i]);
        free(Q[i]);
    }
    free(R);
    free(Q);
    return 0;
}