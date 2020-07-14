// Rotate Image
// Rotate matrix 90 degrees in-place

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void rotate(int** matrix, int matrixSize, int* matrixColSize)
{
    int temp = -1;

    for (int i = 0; i < matrixSize / 2; i++)
    {
        for (int j = i; j < matrixSize - i - 1; j++)
        {
            temp = matrix[i][j];
            swap(&temp, &matrix[j][matrixSize - i - 1]);
            swap(&temp, &matrix[matrixSize - i - 1][matrixSize - j - 1]);
            swap(&temp, &matrix[matrixSize - j - 1][i]);
            swap(&temp, &matrix[i][j]);
        }
    }
}
