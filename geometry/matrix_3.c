/**
 * @file
 * @brief 3x3 Matrix operations
 * @details
 * Add ways to work with matrix definition
 * @author [William Henrique](https://github.com/Willh-AM)
 * @see geometry_datatype.h
 */

#include <stdio.h>  /// for IO operations

#include "geometry_datatypes.h"  /// for matrix datatype

/**
 * @brief Get matrix determinant
 * @param A a 3x3 matrix
 * @returns double
 */
double get_mat_det(mat_3x3* A)
{
    // simple det calculation by Cramer's rule
    return A->row1[0] * (A->row2[1] * A->row3[2] - A->row3[1] * A->row2[2]) -
           A->row1[1] * (A->row2[0] * A->row3[2] - A->row3[0] * A->row2[2]) +
           A->row1[2] * (A->row2[0] * A->row3[1] - A->row3[0] * A->row2[1]);
}

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test()
{
    /* Try to run without exception */
    mat_3x3 A = {0, 1, 2, 3, 5, 1, 0, 3, 4};
    double detA = get_mat_det(&A);  // if returned any number, the algorithm
                                    // don't generate runtime exception

    printf("No runtime exception\n");
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main()
{
    test();  // run self-test implementations
    // Example
    printf("Usage example\n");
    mat_3x3 A = {1, 3, 3, 4, 5, 1, 0, 3, 4};
    printf("detA = %f\n", get_mat_abs(&A));
    return 0;
}
