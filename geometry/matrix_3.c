#include <stdio.h>

#include "geometry_datatypes.h"

/**
 * Obtain the 3x3 matrix determinant.
 * @param[A] an 3x3 matrix
 * @returns a = det(A)
 */
double get_mat_det(mat_3x3* A) 
{
    // simple det calculation by Cramer's rule
    return 
        A->row1[0] * (A->row2[1]*A->row3[2] - A->row3[1]*A->row2[2]) -
        A->row1[1] * (A->row2[0]*A->row3[2] - A->row3[0]*A->row2[2]) +
        A->row1[2] * (A->row2[0]*A->row3[1] - A->row3[0]*A->row2[1]);
}

int main() {
    mat_3x3 A = {1,3,3,4,5,1,0,3,4};
    printf("%f\n", get_mat_abs(&A));
    return 0;
}