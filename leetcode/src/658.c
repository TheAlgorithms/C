/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compXClose(const int *i, const int *j, const int* x)
{
    return abs(*i - *x) - abs(*j - *x);
}

int stdcomp(const void * a, const void * b) //what is it returning?
{
   return ( *(int*)a - *(int*)b ); //What is a and b?
}

// Sort by abs(x - arr[i]).
// Runtime: O(n*log(n))
// Space: O(n)
int* findClosestElements(int* arr, int arrSize, int k, int x, int* returnSize){
    qsort_r(arr, arrSize, sizeof (int), (int(*) (const void *, const void *, const void *)) compXClose, &x);

    int* result = malloc(arrSize * sizeof(int));
    for(int i = 0; i < k; i++){
        result[i] = arr[i];
    }

    result = realloc(result, k * sizeof(int));
    qsort(result, k, sizeof (int), (int(*) (const void *, const void *, const void *)) stdcomp);

    *returnSize = k;

    return result;
}
