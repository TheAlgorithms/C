/**
 * @file
 * \brief Compute real eigen values and eigen vectors of a symmetric matrix
 * using [QR decomposition](https://en.wikipedia.org/wiki/QR_decomposition)
 * method.
 * \author [Krishna Vedala](https://github.com/kvedala)
 */
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "qr_decompose.h"
#ifdef _OPENMP
#include <omp.h>
#endif

#define LIMS 9        /**< limit of range of matrix values */
#define EPSILON 1e-10 /**< accuracy tolerance limit */

/**
 * create a square matrix of given size with random elements
 * \param[out] A matrix to create (must be pre-allocated in memory)
 * \param[in] N matrix size
 */
void create_matrix(double **A, int N)
{
    int i, j, tmp, lim2 = LIMS >> 1;

#ifdef _OPENMP
#pragma omp for
#endif
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

/**
 * Perform multiplication of two matrices.
 * * R2 must be equal to C1
 * * Resultant matrix size should be R1xC2
 * \param[in] A first matrix to multiply
 * \param[in] B second matrix to multiply
 * \param[out] OUT output matrix (must be pre-allocated)
 * \param[in] R1 number of rows of first matrix
 * \param[in] C1 number of columns of first matrix
 * \param[in] R2 number of rows of second matrix
 * \param[in] C2 number of columns of second matrix
 * \returns pointer to resultant matrix
 */
double **mat_mul(double **A, double **B, double **OUT, int R1, int C1, int R2,
                 int C2)
{
    if (C1 != R2)
    {
        perror("Matrix dimensions mismatch!");
        return OUT;
    }

    int i;
#ifdef _OPENMP
#pragma omp for
#endif
    for (i = 0; i < R1; i++)
    {
        for (int j = 0; j < C2; j++)
        {
            OUT[i][j] = 0.f;
            for (int k = 0; k < C1; k++) OUT[i][j] += A[i][k] * B[k][j];
        }
    }
    return OUT;
}

/** Compute eigen values using iterative shifted QR decomposition algorithm as
 * follows:
 * 1. Use last diagonal element of A as eigen value approximation \f$c\f$
 * 2. Shift diagonals of matrix \f$A' = A - cI\f$
 * 3. Decompose matrix \f$A'=QR\f$
 * 4. Compute next approximation \f$A'_1 = RQ \f$
 * 5. Shift diagonals back \f$A_1 = A'_1 + cI\f$
 * 6. Termination condition check: last element below diagonal is almost 0
 *   1. If not 0, go back to step 1 with the new approximation \f$A_1\f$
 *   2. If 0, continue to step 7
 * 7. Save last known \f$c\f$ as the eigen value.
 * 8. Are all eigen values found?
 *   1. If not, remove last row and column of \f$A_1\f$ and go back to step 1.
 *   2. If yes, stop.
 *
 * \note The matrix \f$A\f$ gets modified
 *
 * \param[in,out] A matrix to compute eigen values for
 * \param[out] eigen_vals resultant vector containing computed eigen values
 * \param[in] mat_size matrix size
 * \param[in] debug_print 1 to print intermediate Q & R matrices, 0 for not to
 * \returns time for computation in seconds
 */
double eigen_values(double **A, double *eigen_vals, int mat_size,
                    char debug_print)
{
    if (!eigen_vals)
    {
        perror("Output eigen value vector cannot be NULL!");
        return -1;
    }
    double **R = (double **)malloc(sizeof(double *) * mat_size);
    double **Q = (double **)malloc(sizeof(double *) * mat_size);
    if (!Q || !R)
    {
        perror("Unable to allocate memory for Q & R!");
        if (Q)
        {
            free(Q);
        }
        if (R)
        {
            free(R);
        }
        return -1;
    }

    /* allocate dynamic memory for matrices */
    for (int i = 0; i < mat_size; i++)
    {
        R[i] = (double *)malloc(sizeof(double) * mat_size);
        Q[i] = (double *)malloc(sizeof(double) * mat_size);
        if (!Q[i] || !R[i])
        {
            perror("Unable to allocate memory for Q & R.");
            for (; i >= 0; i--)
            {
                free(R[i]);
                free(Q[i]);
            }
            free(Q);
            free(R);
            return -1;
        }
    }

    if (debug_print)
    {
        print_matrix(A, mat_size, mat_size);
    }

    int rows = mat_size, columns = mat_size;
    int counter = 0, num_eigs = rows - 1;
    double last_eig = 0;

    clock_t t1 = clock();
    while (num_eigs > 0) /* continue till all eigen values are found */
    {
        /* iterate with QR decomposition */
        while (fabs(A[num_eigs][num_eigs - 1]) > EPSILON)
        {
            last_eig = A[num_eigs][num_eigs];
            for (int i = 0; i < rows; i++) A[i][i] -= last_eig; /* A - cI */
            qr_decompose(A, Q, R, rows, columns);

            if (debug_print)
            {
                print_matrix(A, rows, columns);
                print_matrix(Q, rows, columns);
                print_matrix(R, columns, columns);
                printf("-------------------- %d ---------------------\n",
                       ++counter);
            }

            mat_mul(R, Q, A, columns, columns, rows, columns);
            for (int i = 0; i < rows; i++) A[i][i] += last_eig; /* A + cI */
        }

        /* store the converged eigen value */
        eigen_vals[num_eigs] = last_eig;

        if (debug_print)
        {
            printf("========================\n");
            printf("Eigen value: % g,\n", last_eig);
            printf("========================\n");
        }

        num_eigs--;
        rows--;
        columns--;
    }
    eigen_vals[0] = A[0][0];
    double dtime = (double)(clock() - t1) / CLOCKS_PER_SEC;

    if (debug_print)
    {
        print_matrix(R, mat_size, mat_size);
        print_matrix(Q, mat_size, mat_size);
    }

    /* cleanup dynamic memory */
    for (int i = 0; i < mat_size; i++)
    {
        free(R[i]);
        free(Q[i]);
    }
    free(R);
    free(Q);

    return dtime;
}

/**
 * test function to compute eigen values of a 2x2 matrix
 * \f[\begin{bmatrix}
 * 5 & 7\\
 * 7 & 11
 * \end{bmatrix}\f]
 * which are approximately, {15.56158, 0.384227}
 */
void test1()
{
    int mat_size = 2;
    double X[][2] = {{5, 7}, {7, 11}};
    double y[] = {15.56158, 0.384227};  // corresponding y-values
    double eig_vals[2] = {0, 0};

    // The following steps are to convert a "double[][]" to "double **"
    double **A = (double **)malloc(mat_size * sizeof(double *));
    for (int i = 0; i < mat_size; i++) A[i] = X[i];

    printf("------- Test 1 -------\n");

    double dtime = eigen_values(A, eig_vals, mat_size, 0);

    for (int i = 0; i < mat_size; i++)
    {
        printf("%d/5 Checking for %.3g --> ", i + 1, y[i]);
        char result = 0;
        for (int j = 0; j < mat_size && !result; j++)
        {
            if (fabs(y[i] - eig_vals[j]) < 0.1)
            {
                result = 1;
                printf("(%.3g) ", eig_vals[j]);
            }
        }

        // ensure that i^th expected eigen value was computed
        assert(result != 0);
        printf("found\n");
    }
    printf("Test 1 Passed in %.3g sec\n\n", dtime);
    free(A);
}

/**
 * test function to compute eigen values of a 2x2 matrix
 * \f[\begin{bmatrix}
 * -4& 4& 2& 0& -3\\
 * 4& -4& 4& -3& -1\\
 * 2& 4& 4& 3& -3\\
 * 0& -3& 3& -1&-1\\
 * -3& -1& -3& -3& 0
 * \end{bmatrix}\f]
 * which are approximately, {9.27648, -9.26948, 2.0181, -1.03516, -5.98994}
 */
void test2()
{
    int mat_size = 5;
    double X[][5] = {{-4, 4, 2, 0, -3},
                     {4, -4, 4, -3, -1},
                     {2, 4, 4, 3, -3},
                     {0, -3, 3, -1, -3},
                     {-3, -1, -3, -3, 0}};
    double y[] = {9.27648, -9.26948, 2.0181, -1.03516,
                  -5.98994};  // corresponding y-values
    double eig_vals[5];

    // The following steps are to convert a "double[][]" to "double **"
    double **A = (double **)malloc(mat_size * sizeof(double *));
    for (int i = 0; i < mat_size; i++) A[i] = X[i];

    printf("------- Test 2 -------\n");

    double dtime = eigen_values(A, eig_vals, mat_size, 0);

    for (int i = 0; i < mat_size; i++)
    {
        printf("%d/5 Checking for %.3g --> ", i + 1, y[i]);
        char result = 0;
        for (int j = 0; j < mat_size && !result; j++)
        {
            if (fabs(y[i] - eig_vals[j]) < 0.1)
            {
                result = 1;
                printf("(%.3g) ", eig_vals[j]);
            }
        }

        // ensure that i^th expected eigen value was computed
        assert(result != 0);
        printf("found\n");
    }
    printf("Test 2 Passed in %.3g sec\n\n", dtime);
    free(A);
}

/**
 * main function
 */
int main(int argc, char **argv)
{
    srand(time(NULL));

    int mat_size = 5;
    if (argc == 2)
    {
        mat_size = atoi(argv[1]);
    }
    else
    {  // if invalid input argument is given run tests
        test1();
        test2();
        printf("Usage: ./qr_eigen_values [mat_size]\n");
        return 0;
    }

    if (mat_size < 2)
    {
        fprintf(stderr, "Matrix size should be > 2\n");
        return -1;
    }

    int i;

    double **A = (double **)malloc(sizeof(double *) * mat_size);
    /* number of eigen values = matrix size */
    double *eigen_vals = (double *)malloc(sizeof(double) * mat_size);
    if (!eigen_vals)
    {
        perror("Unable to allocate memory for eigen values!");
        free(A);
        return -1;
    }
    for (i = 0; i < mat_size; i++)
    {
        A[i] = (double *)malloc(sizeof(double) * mat_size);
        eigen_vals[i] = 0.f;
    }

    /* create a random matrix */
    create_matrix(A, mat_size);

    print_matrix(A, mat_size, mat_size);

    double dtime = eigen_values(A, eigen_vals, mat_size, 0);
    printf("Eigen vals: ");
    for (i = 0; i < mat_size; i++) printf("% 9.4g\t", eigen_vals[i]);
    printf("\nTime taken to compute: % .4g sec\n", dtime);

    for (int i = 0; i < mat_size; i++) free(A[i]);
    free(A);
    free(eigen_vals);
    return 0;
}
