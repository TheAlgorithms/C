/* 1st way: Using 2 pointers */
int *sortedSquares(int *A, int ASize, int *returnSize)
{
    int i, start = 0, end = ASize - 1;
    int *res = malloc(ASize * sizeof(int));
    *returnSize = ASize;
    for (i = ASize - 1; i >= 0; i--)
    {
        if (abs(A[start]) > A[end])
        {
            res[i] = A[start] * A[start];
            start++;
        }
        else
        {
            res[i] = A[end] * A[end];
            end--;
        }
    }
    return res;
}

/* 2nd way: Using qsort */
int cmpval(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int *sortedSquares(int *A, int ASize, int *returnSize)
{
    int *res = malloc(ASize * sizeof(int));
    for (int i = 0; i < ASize; i++) res[i] = A[i] * A[i];
    *returnSize = ASize;
    qsort(res, ASize, sizeof(int), cmpval);
    return res;
}
