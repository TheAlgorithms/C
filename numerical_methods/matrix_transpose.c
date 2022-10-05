#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * @brief Matrix struct for dynamically allocated memory
 */
typedef struct {
    int rows;
    int cols;
    double *data;
} Matrix;

/**
 * @brief Create an uninitialized matrix object
 * 
 * @param rows height
 * @param cols width
 * @return Matrix 
 */
Matrix create_matrix(size_t rows, size_t cols) {
    Matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = malloc(rows * cols * sizeof(double));
    return m;
}

/**
 * @brief Helper to create an initialized matrix object from a 2D array
 * 
 * @param rows height
 * @param cols width
 * @param data array of values
 * @return Matrix 
 */
Matrix matrix_from_array(size_t rows, size_t cols, double *data) {
    Matrix m = create_matrix(rows, cols);
    for (size_t i = 0; i < rows * cols; i++) m.data[i] = data[i];
    return m;
}

/**
 * @brief Checks if two matrices are equal in size and values.
 * 
 * @param a Matrix
 * @param b Matrix
 * @return true if both matrices are equal in size and values
 * @return false otherwise
 */
bool equals(Matrix a, Matrix b) {
    if (a.rows != b.rows || a.cols != b.cols)
    {
        return false;
    }

    for (int i = 0; i < a.rows; i++)
    {
        for (int j = 0; j < a.cols; j++)
        {
            if (a.data[i * a.cols + j] != b.data[i * b.cols + j])
            {
                return false;
            }
        }
    }

    return true;
}

/**
 * @brief Frees a matrices allocated memory.
 * 
 * @param m Matrix to free
 */
void free_matrix(Matrix m) { 
    free(m.data); 
}

/**
 * @brief Matrix transpose
 * 
 * @param m Matrix to transpose
 * @return Matrix Newly allocated matrix with transposed data of m
 */
Matrix transpose(Matrix m) {
    Matrix t = create_matrix(m.cols, m.rows);

    for (int i = 0; i < m.rows; i++)
    {
        for (int j = 0; j < m.cols; j++)
        {
            t.data[j * t.cols + i] = m.data[i * m.cols + j];
        }
    }

    return t;
}

static void test() {
    /*
     *  [1 2 3] T = [1 4]
     *  [4 5 6]     [2 5]
     *              [3 6]
     */
    Matrix a = matrix_from_array(2, 3, (double[]){1, 2, 3, 4, 5, 6});
    Matrix b = matrix_from_array(3, 2, (double[]){1, 4, 2, 5, 3, 6});
    Matrix c = transpose(a);
    assert(equals(b, c));

    free_matrix(a);
    free_matrix(b);
    free_matrix(c);

    /*
     *  [1 2 3 4] T = [1 5]
     *  [5 6 7 8]     [2 6]
     *                [3 7]
     *                [4 8]
     */
    a = matrix_from_array(2, 4, (double[]){1, 2, 3, 4, 5, 6, 7, 8});
    b = matrix_from_array(4, 2, (double[]){1, 5, 2, 6, 3, 7, 4, 8});
    c = transpose(a);
    assert(equals(b, c));

    free_matrix(a);
    free_matrix(b);
    free_matrix(c);
}

int main() {
    test();
    return 0;
}
