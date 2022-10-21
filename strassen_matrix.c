#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int **addMatrix(int **a, int **b, int row)
{
    int **sum;
    int i, j, n = sizeof(int);
    sum = (int **)malloc(row * n);
    for (i = 0; i <= row - 1; i++)
    {
        sum[i] = (int *)malloc(row * n);
    }
    for (i = 0; i <= row - 1; i++)
    {
        for (j = 0; j <= row - 1; j++)
        {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }
    return sum;
}
int **subMatrix(int **x, int **y, int row)
{
    int **sub;
    int i, j, n = sizeof(int);
    sub = (int **)malloc(row * n);
    for (i = 0; i <= row - 1; i++)
    {
        sub[i] = (int *)malloc(row * n);
    }
    for (i = 0; i <= row - 1; i++)
    {
        for (j = 0; j <= row - 1; j++)
        {
            sub[i][j] = x[i][j] - y[i][j];
        }
    }
    return sub;
}
int **inputmatrix(int col)
{
    int **a;
    int i, j, n = sizeof(int);
    printf("\n****** Enter matrix *****: \n");
    a = (int **)malloc(col * n);
    for (i = 0; i <= col - 1; i++)
    {
        a[i] = (int *)malloc(col * n);
    }
    for (i = 0; i <= col - 1; i++)
    {
        for (j = 0; j <= col - 1; j++)
        {
            scanf("%d", *(a + i) + j);
        }
    }
    return a;
}
void display(int **a, int row)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        printf("\n");
        for (j = 0; j < row; j++)
            printf(" %d ", a[i][j]);
    }
}
int **vsqmatmul(int **A, int **B, int row)
{
    int i, j, **c;
    int **a11, **a12, **a21, **a22, **b11, **b12, **b21, **b22, **c11, **c12, **c21, **c22, **C;
    int **p1, **p2, **p3, **p4, **p5, **p6, **p7;
    int n = sizeof(int);
    a11 = (int **)malloc(row * n);
    a12 = (int **)malloc(row * n);
    a21 = (int **)malloc(row * n);
    a22 = (int **)malloc(row * n);
    b11 = (int **)malloc(row * n);
    b12 = (int **)malloc(row * n);
    b21 = (int **)malloc(row * n);
    b22 = (int **)malloc(row * n);
    c11 = (int **)malloc(row * n);
    c12 = (int **)malloc(row * n);
    c21 = (int **)malloc(row * n);
    c22 = (int **)malloc(row * n);
    p1 = (int **)malloc(row * n);
    p2 = (int **)malloc(row * n);
    p3 = (int **)malloc(row * n);
    p4 = (int **)malloc(row * n);
    p5 = (int **)malloc(row * n);
    p6 = (int **)malloc(row * n);
    p7 = (int **)malloc(row * n);
    c = (int **)malloc(row * n);
    C = (int **)malloc(row * n);
    for (i = 0; i < row; i++)
    {
        a11[i] = (int *)malloc(row * n);
        a12[i] = (int *)malloc(row * n);
        a21[i] = (int *)malloc(row * n);
        a22[i] = (int *)malloc(row * n);
        b11[i] = (int *)malloc(row * n);
        b12[i] = (int *)malloc(row * n);
        b21[i] = (int *)malloc(row * n);
        b22[i] = (int *)malloc(row * n);
        c11[i] = (int *)malloc(row * n);
        c12[i] = (int *)malloc(row * n);
        c21[i] = (int *)malloc(row * n);
        c22[i] = (int *)malloc(row * n);
        p1[i] = (int *)malloc(row * n);
        p2[i] = (int *)malloc(row * n);
        p3[i] = (int *)malloc(row * n);
        p4[i] = (int *)malloc(row * n);
        p5[i] = (int *)malloc(row * n);
        p6[i] = (int *)malloc(row * n);
        p7[i] = (int *)malloc(row * n);
        c[i] = (int *)malloc(row * n);
        C[i] = (int *)malloc(row * n);
    }
    if (row == 1)
    {
        c[0][0] = *(*A) * *(*B);
        return c;
    }
    else
    {
        for (i = 0; i <= (row) / 2 - 1; i++)
            for (j = 0; j <= (row) / 2 - 1; j++)
            {
                a11[i][j] = A[i][j];
                b11[i][j] = B[i][j];
            }
        for (i = 0; i <= (row) / 2 - 1; i++)
            for (j = (row) / 2; j <= row - 1; j++)
            {
                a12[i][j - (row) / 2] = A[i][j];
                b12[i][j - (row) / 2] = B[i][j];
            }
        for (i = (row) / 2; i <= row - 1; i++)
            for (j = 0; j <= (row) / 2 - 1; j++)
            {
                a21[i - (row) / 2][j] = A[i][j];
                b21[i - (row) / 2][j] = B[i][j];
            }
        for (i = (row) / 2; i <= row - 1; i++)
            for (j = (row) / 2; j <= row - 1; j++)
            {
                a22[i - (row) / 2][j - (row) / 2] = A[i][j];
                b22[i - (row) / 2][j - (row) / 2] = B[i][j];
            }
        p1 = vsqmatmul(a11, subMatrix(b12, b22, row / 2), row / 2);
        p2 = vsqmatmul(addMatrix(a11, a12, row / 2), b22, row / 2);
        p3 = vsqmatmul(addMatrix(a21, a22, row / 2), b11, row / 2);
        p4 = vsqmatmul(a22, subMatrix(b21, b11, row / 2), row / 2);
        p5 = vsqmatmul(addMatrix(a11, a22, row / 2), addMatrix(b11, b22, row / 2), row / 2);
        p6 = vsqmatmul(subMatrix(a12, a22, row / 2), addMatrix(b21, b22, row / 2), row / 2);
        p7 = vsqmatmul(subMatrix(a11, a21, row / 2), addMatrix(b11, b12, row / 2), row / 2);
        c11 = subMatrix(addMatrix(p5, p4, row / 2), subMatrix(p2, p6, row / 2), row / 2);
        c12 = addMatrix(p1, p2, row / 2);
        c21 = addMatrix(p3, p4, row / 2);
        c22 = subMatrix(addMatrix(p1, p5, row / 2), addMatrix(p3, p7, row / 2), row / 2);
        for (i = 0; i <= (row) / 2 - 1; i++)
            for (j = 0; j <= (row) / 2 - 1; j++)
                C[i][j] = c11[i][j];
        for (i = 0; i <= (row) / 2 - 1; i++)
            for (j = (row) / 2; j <= row - 1; j++)
                C[i][j] = c12[i][j - (row) / 2];
        for (i = (row) / 2; i <= row - 1; i++)
            for (j = 0; j <= (row) / 2 - 1; j++)
                C[i][j] = c21[i - (row) / 2][j];
        for (i = (row) / 2; i <= row - 1; i++)
            for (j = (row) / 2; j <= row - 1; j++)
                C[i][j] = c22[i - (row) / 2][j - (row) / 2];
    }
    return C;
}
int **daqmatmul(int **A, int **B, int rows1)
{
    int i, j, **c;
    int **a11, **a12, **a21, **a22, **b11, **b12, **b21, **b22, **c11, **c12, **c21, **c22, **C;
    int n = sizeof(int);
    a11 = (int **)malloc(rows1 * n);
    a12 = (int **)malloc(rows1 * n);
    a21 = (int **)malloc(rows1 * n);
    a22 = (int **)malloc(rows1 * n);
    b11 = (int **)malloc(rows1 * n);
    b12 = (int **)malloc(rows1 * n);
    b21 = (int **)malloc(rows1 * n);
    b22 = (int **)malloc(rows1 * n);
    c11 = (int **)malloc(rows1 * n);
    c12 = (int **)malloc(rows1 * n);
    c21 = (int **)malloc(rows1 * n);
    c22 = (int **)malloc(rows1 * n);
    C = (int **)malloc(rows1 * n);
    c = (int **)malloc(rows1 * n);
    for (i = 0; i < rows1; i++)
    {
        a11[i] = (int *)malloc(rows1 * n);
        a12[i] = (int *)malloc(rows1 * n);
        a21[i] = (int *)malloc(rows1 * n);
        a22[i] = (int *)malloc(rows1 * n);
        b11[i] = (int *)malloc(rows1 * n);
        b12[i] = (int *)malloc(rows1 * n);
        b21[i] = (int *)malloc(rows1 * n);
        b22[i] = (int *)malloc(rows1 * n);
        c11[i] = (int *)malloc(rows1 * n);
        c12[i] = (int *)malloc(rows1 * n);
        c21[i] = (int *)malloc(rows1 * n);
        c22[i] = (int *)malloc(rows1 * n);
        C[i] = (int *)malloc(rows1 * n);
        c[i] = (int *)malloc(rows1 * n);
    }
    if (rows1 == 1)
    {
        c[0][0] = *(*A) * *(*B);
        return c;
    }
    else
    {
        for (i = 0; i <= (rows1) / 2 - 1; i++)
            for (j = 0; j <= (rows1) / 2 - 1; j++)
            {
                a11[i][j] = A[i][j];
                b11[i][j] = B[i][j];
            }
        for (i = 0; i <= (rows1) / 2 - 1; i++)
            for (j = (rows1) / 2; j <= rows1 - 1; j++)
            {
                a12[i][j - (rows1) / 2] = A[i][j];
                b12[i][j - (rows1) / 2] = B[i][j];
            }
        for (i = (rows1) / 2; i <= rows1 - 1; i++)
            for (j = 0; j <= (rows1) / 2 - 1; j++)
            {
                a21[i - (rows1) / 2][j] = A[i][j];
                b21[i - (rows1) / 2][j] = B[i][j];
            }
        for (i = (rows1) / 2; i <= rows1 - 1; i++)
            for (j = (rows1) / 2; j <= rows1 - 1; j++)
            {
                a22[i - (rows1) / 2][j - (rows1) / 2] = A[i][j];
                b22[i - (rows1) / 2][j - (rows1) / 2] = B[i][j];
            }
        c11 = addMatrix(daqmatmul(a11, b11, rows1 / 2), daqmatmul(a12, b21, rows1 / 2), rows1 / 2);
        c12 = addMatrix(daqmatmul(a11, b12, rows1 / 2), daqmatmul(a12, b22, rows1 / 2), rows1 / 2);
        c21 = addMatrix(daqmatmul(a21, b11, rows1 / 2), daqmatmul(a22, b21, rows1 / 2), rows1 / 2);
        c22 = addMatrix(daqmatmul(a21, b22, rows1 / 2), daqmatmul(a22, b22, rows1 / 2), rows1 / 2);
        for (i = 0; i <= (rows1) / 2 - 1; i++)
            for (j = 0; j <= (rows1) / 2 - 1; j++)
                C[i][j] = c11[i][j];
        for (i = 0; i <= (rows1) / 2 - 1; i++)
            for (j = (rows1) / 2; j <= rows1 - 1; j++)
                C[i][j] = c12[i][j - (rows1) / 2];
        for (i = (rows1) / 2; i <= rows1 - 1; i++)
            for (j = 0; j <= (rows1) / 2 - 1; j++)
                C[i][j] = c21[i - (rows1) / 2][j];
        for (i = (rows1) / 2; i <= rows1 - 1; i++)
            for (j = (rows1) / 2; j <= rows1 - 1; j++)
                C[i][j] = c22[i - (rows1) / 2][j - (rows1) / 2];
    }
    return C;
}
int main()
{
    int d, **X, **Y, **Z, c, i, j, n = sizeof(int);
    printf("\n*** Matrix Multiplication Using Divide and Conquer And Strassens Matrix ******\n\n");
    printf(" Enter the dimension of the matrix (square matrix ): ");
    scanf("%d", &d);
    Z = (int **)malloc(d * n);
    X = (int **)malloc(d * n);
    Y = (int **)malloc(d * n);
    for (i = 0; i <= d - 1; i++)
    {
        Z[i] = (int *)malloc(d * n);
        X = (int **)malloc(d * n);
        Y = (int **)malloc(d * n);
    }
    X = inputmatrix(d);
    Y = inputmatrix(d);
    while (1)
    {
        printf("\n-----------Main Menu------- \n\n");
        printf(" 1.Matrix Multiplication by Divide and Conquer algorithm  \n");
        printf(" 2.Matrix Multiplication by Streesens algorithm \n");
        printf(" 3.Exiting from the program (for it press any number greater than 2) \n");
        printf(" Enter your choice : ");
        scanf("%d", &c);
        if (c > 2)
        {
            printf("\nExit From Program\n");
            break;
        }
        switch (c)
        {
        case 1:
        {
            printf("\n-------Multiplication by divide and conqeer algorithm-------\n\n");
            Z = daqmatmul(X, Y, d);
            printf("\n The matrix after multiplication is ---> \n");
            display(Z, d);
            break;
        }
        case 2:
        {
            printf("\n-------Multiplication by strassens algorithm--------\n\n");
            Z = vsqmatmul(X, Y, d);
            printf("\n The matrix after multiplication is -----> \n");
            display(Z, d);
        }
        default:
            break;
        }
    }
}