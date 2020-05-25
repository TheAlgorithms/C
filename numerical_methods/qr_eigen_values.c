#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define LIMS 9

void create_matrix(double **A, int N)
{
    int i, j, tmp, lim2 = LIMS >> 1;
    srand(time(NULL));

    for (i = 0; i < N; i++)
    {
        A[i][i] = (rand() % LIMS) - lim2;
        for (j = i + 1; j < N; j++)
        {
            tmp = (rand() % LIMS) - lim2;
            A[i][j] = tmp;
            A[j][i] = tmp;
        }
    }
}

void print_matrix(double **A, int M, int N)
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

void qr_decompose(double **A, double **Q, double **R, int M, int N)
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

double **mat_mul(double **A, double **B, double **OUT, int R1, int C1, int R2, int C2)
{
    if (C1 != R2)
    {
        perror("Matrix dimensions mismatch!");
        return OUT;
    }
    for (int i = 0; i < R1; i++)
        for (int j = 0; j < C2; j++)
        {
            OUT[i][j] = 0.f;
            for (int k = 0; k < C1; k++)
                OUT[i][j] += A[i][k] * B[k][j];
        }
    return OUT;
}

int main(int argc, char **argv)
{
    int mat_size = 5;
    if (argc == 2)
        mat_size = atoi(argv[1]);

    if (mat_size < 2)
    {
        fprintf(stderr, "Matrix size should be > 2\n");
        return -1;
    }

    int i, rows = mat_size, columns = mat_size;

    double **A = (double **)malloc(sizeof(double) * mat_size);
    double **R = (double **)malloc(sizeof(double) * mat_size);
    double **Q = (double **)malloc(sizeof(double) * mat_size);
    double *eigen_vals = (double *)malloc(sizeof(double) * mat_size);
    if (!Q || !R || !eigen_vals)
    {
        perror("Unable to allocate memory for Q & R!");
        return -1;
    }
    for (i = 0; i < mat_size; i++)
    {
        A[i] = (double *)malloc(sizeof(double) * mat_size);
        R[i] = (double *)malloc(sizeof(double) * mat_size);
        Q[i] = (double *)malloc(sizeof(double) * mat_size);
        if (!Q[i] || !R[i])
        {
            perror("Unable to allocate memory for Q & R.");
            return -1;
        }
    }

    create_matrix(A, mat_size);

    print_matrix(A, mat_size, mat_size);

    int counter = 0, num_eigs = rows - 1;
    double last_eig = 0;

    while (num_eigs > 0)
    {
        while (fabs(A[num_eigs][num_eigs - 1]) > 1e-10)
        {
            last_eig = A[num_eigs][num_eigs];
            for (int i = 0; i < rows; i++)
                A[i][i] -= last_eig; /* A - cI */
            qr_decompose(A, Q, R, rows, columns);

#if defined(DEBUG) || !defined(NDEBUG)
            print_matrix(A, rows, columns);
            print_matrix(Q, rows, columns);
            print_matrix(R, columns, columns);
            printf("-------------------- %d ---------------------\n", ++counter);
#endif
            mat_mul(R, Q, A, columns, columns, rows, columns);
            for (int i = 0; i < rows; i++)
                A[i][i] += last_eig; /* A + cI */
        }

        eigen_vals[num_eigs] = A[num_eigs][num_eigs];
#if defined(DEBUG) || !defined(NDEBUG)
        printf("========================\n");
        printf("Eigen value: % g,\n", last_eig);
        printf("========================\n");
#endif
        num_eigs--;
        rows--;
        columns--;
    }
    eigen_vals[0] = A[0][0];

#if defined(DEBUG) || !defined(NDEBUG)
    print_matrix(R, mat_size, mat_size);
    print_matrix(Q, mat_size, mat_size);
#endif
    printf("Eigen vals: ");
    for (i = 0; i < mat_size; i++)
        printf("% 9.4g\t", eigen_vals[i]);

    for (int i = 0; i < mat_size; i++)
    {
        free(A[i]);
        free(R[i]);
        free(Q[i]);
    }
    free(A);
    free(R);
    free(Q);
    free(eigen_vals);
    return 0;
}