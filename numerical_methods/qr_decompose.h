/**
 * @file
 * \brief Library functions to compute [QR
 * decomposition](https://en.wikipedia.org/wiki/QR_decomposition) of a given
 * matrix.
 * \author [Krishna Vedala](https://github.com/kvedala)
 */

#ifndef QR_DECOMPOSE_H
#define QR_DECOMPOSE_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
#include <omp.h>
#endif

/**
 * function to display matrix on stdout
 */
void print_matrix(double **A, /**< matrix to print */
                  int M,      /**< number of rows of matrix */
                  int N)      /**< number of columns of matrix */
{
    for (int row = 0; row < M; row++)
    {
        for (int col = 0; col < N; col++) printf("% 9.3g\t", A[row][col]);
        putchar('\n');
    }
    putchar('\n');
}

/**
 * Compute dot product of two vectors of equal lengths
 *
 * If \f$\vec{a}=\left[a_0,a_1,a_2,...,a_L\right]\f$ and
 * \f$\vec{b}=\left[b_0,b_1,b_1,...,b_L\right]\f$ then
 * \f$\vec{a}\cdot\vec{b}=\displaystyle\sum_{i=0}^L a_i\times b_i\f$
 *
 * \returns \f$\vec{a}\cdot\vec{b}\f$
 */
double vector_dot(double *a, double *b, int L)
{
    double mag = 0.f;
    int i;
#ifdef _OPENMP
// parallelize on threads
#pragma omp parallel for reduction(+ : mag)
#endif
    for (i = 0; i < L; i++) mag += a[i] * b[i];

    return mag;
}

/**
 * Compute magnitude of vector.
 *
 * If \f$\vec{a}=\left[a_0,a_1,a_2,...,a_L\right]\f$ then
 * \f$\left|\vec{a}\right|=\sqrt{\displaystyle\sum_{i=0}^L a_i^2}\f$
 *
 * \returns \f$\left|\vec{a}\right|\f$
 */
double vector_mag(double *vector, int L)
{
    double dot = vector_dot(vector, vector, L);
    return sqrt(dot);
}

/**
 * Compute projection of vector \f$\vec{a}\f$ on \f$\vec{b}\f$ defined as
 * \f[\text{proj}_\vec{b}\vec{a}=\frac{\vec{a}\cdot\vec{b}}{\left|\vec{b}\right|^2}\vec{b}\f]
 *
 * \returns NULL if error, otherwise pointer to output
 */
double *vector_proj(double *a, double *b, double *out, int L)
{
    const double num = vector_dot(a, b, L);
    const double deno = vector_dot(b, b, L);
    if (deno == 0) /*! check for division by zero */
        return NULL;

    const double scalar = num / deno;
    int i;
#ifdef _OPENMP
// parallelize on threads
#pragma omp for
#endif
    for (i = 0; i < L; i++) out[i] = scalar * b[i];

    return out;
}

/**
 * Compute vector subtraction
 *
 * \f$\vec{c}=\vec{a}-\vec{b}\f$
 *
 * \returns pointer to output vector
 */
double *vector_sub(double *a,   /**< minuend */
                   double *b,   /**< subtrahend */
                   double *out, /**< resultant vector */
                   int L        /**< length of vectors */
)
{
    int i;
#ifdef _OPENMP
// parallelize on threads
#pragma omp for
#endif
    for (i = 0; i < L; i++) out[i] = a[i] - b[i];

    return out;
}

/**
 * Decompose matrix \f$A\f$ using [Gram-Schmidt
 *process](https://en.wikipedia.org/wiki/QR_decomposition).
 *
 * \f{eqnarray*}{
 * \text{given that}\quad A &=&
 *\left[\mathbf{a}_1,\mathbf{a}_2,\ldots,\mathbf{a}_{N-1},\right]\\
 * \text{where}\quad\mathbf{a}_i &=&
 *\left[a_{0i},a_{1i},a_{2i},\ldots,a_{(M-1)i}\right]^T\quad\ldots\mbox{(column
 *vectors)}\\
 * \text{then}\quad\mathbf{u}_i &=& \mathbf{a}_i
 *-\sum_{j=0}^{i-1}\text{proj}_{\mathbf{u}_j}\mathbf{a}_i\\
 * \mathbf{e}_i &=&\frac{\mathbf{u}_i}{\left|\mathbf{u}_i\right|}\\
 * Q &=& \begin{bmatrix}\mathbf{e}_0 & \mathbf{e}_1 & \mathbf{e}_2 & \dots &
 *\mathbf{e}_{N-1}\end{bmatrix}\\
 * R &=& \begin{bmatrix}\langle\mathbf{e}_0\,,\mathbf{a}_0\rangle &
 *\langle\mathbf{e}_1\,,\mathbf{a}_1\rangle &
 *\langle\mathbf{e}_2\,,\mathbf{a}_2\rangle & \dots \\
 *                  0 & \langle\mathbf{e}_1\,,\mathbf{a}_1\rangle &
 *\langle\mathbf{e}_2\,,\mathbf{a}_2\rangle & \dots\\
 *                  0 & 0 & \langle\mathbf{e}_2\,,\mathbf{a}_2\rangle & \dots\\
 *                  \vdots & \vdots & \vdots & \ddots
 *      \end{bmatrix}\\
 * \f}
 */
void qr_decompose(double **A, /**< input matrix to decompose */
                  double **Q, /**< output decomposed matrix */
                  double **R, /**< output decomposed matrix */
                  int M,      /**< number of rows of matrix A */
                  int N       /**< number of columns of matrix A */
)
{
    double *col_vector = (double *)malloc(M * sizeof(double));
    double *col_vector2 = (double *)malloc(M * sizeof(double));
    double *tmp_vector = (double *)malloc(M * sizeof(double));
    for (int i = 0; i < N;
         i++) /* for each column => R is a square matrix of NxN */
    {
        int j;
#ifdef _OPENMP
// parallelize on threads
#pragma omp for
#endif
        for (j = 0; j < i; j++) /* second dimension of column */
            R[i][j] = 0.;       /* make R upper triangular */

            /* get corresponding Q vector */
#ifdef _OPENMP
// parallelize on threads
#pragma omp for
#endif
        for (j = 0; j < M; j++)
        {
            tmp_vector[j] = A[j][i]; /* accumulator for uk */
            col_vector[j] = A[j][i];
        }
        for (j = 0; j < i; j++)
        {
            for (int k = 0; k < M; k++) col_vector2[k] = Q[k][j];
            vector_proj(col_vector, col_vector2, col_vector2, M);
            vector_sub(tmp_vector, col_vector2, tmp_vector, M);
        }
        double mag = vector_mag(tmp_vector, M);

#ifdef _OPENMP
// parallelize on threads
#pragma omp for
#endif
        for (j = 0; j < M; j++) Q[j][i] = tmp_vector[j] / mag;

        /* compute upper triangular values of R */
        for (int kk = 0; kk < M; kk++) col_vector[kk] = Q[kk][i];
        for (int k = i; k < N; k++)
        {
            for (int kk = 0; kk < M; kk++) col_vector2[kk] = A[kk][k];
            R[i][k] = vector_dot(col_vector, col_vector2, M);
        }
    }

    free(col_vector);
    free(col_vector2);
    free(tmp_vector);
}

#endif  // QR_DECOMPOSE_H
