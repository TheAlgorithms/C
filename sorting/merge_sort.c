/**
 * @file
 * @brief Implementation of [merge
 * sort](https://en.wikipedia.org/wiki/Merge_sort) algorithm
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * @addtogroup sorting Sorting algorithms
 * @{
 */

/** Swap two integer variables
 * @param [in,out] a pointer to first variable
 * @param [in,out] b pointer to second variable
 */
void swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

/**
 * @brief Perform merge of segments.
 *
 * @param ar array to sort
 * @param l left index for merge
 * @param r right index for merge
 * @param n total number of elements in the array
 */
void merge(int *ar, int l, int r, int n)
{
    int *new_ar = (int *)malloc(n * sizeof(int)); /* dynamic memory must be freed */
    if (new_ar == NULL)
    {
        printf("Can't Malloc! Please try again.");
        exit(EXIT_FAILURE);
    }
    int c = l;
    int ind1, ind2;
    ind1 = l;
    ind2 = ((l + r) / 2) + 1;
    while ((ind1 < ((l + r) / 2) + 1) && (ind2 < r + 1))
    {
        if (ar[ind1] <= ar[ind2])
        {
            new_ar[c++] = ar[ind1];
            ind1++;
        }
        else
        {
            new_ar[c++] = ar[ind2];
            ind2++;
        }
    }

    if (ind2 == r + 1)
    {
        while ((ind1 < ((l + r) / 2) + 1))
        {
            new_ar[c++] = ar[ind1];
            ind1++;
        }
    }
    else
    {
        while ((ind2 < r + 1))
        {
            new_ar[c++] = ar[ind2];
            ind2++;
        }
    }

    for (c = l; c < r + 1; c++) ar[c] = new_ar[c];

    free(new_ar);
}

/** Merge sort algorithm implementation
 * @param arr array to sort
 * @param n number of elements in the array
 * @param left index to sort from
 * @param right index to sort till
 */
void merge_sort(int *arr, int n, int left, int right)
{
    if (right - left == 1)
    {
        if (arr[left] > arr[right])
            swap(&arr[left], &arr[right]);
    }
    else if (left != right)
    {
        merge_sort(arr, n, left, (left + right) / 2);
        merge_sort(arr, n, ((left + right) / 2) + 1, right);
        merge(arr, left, right, n);
    }

    /* no change if left == right */
}
/** @} */

/** Main function */
int main(void)
{
    int *array, size, i;
    printf("Enter Array size: ");
    scanf("%d", &size);
    if (size <= 0) /* exit program if arraysize is not greater than 0 */
    {
        printf("Array size must be Greater than 0!\n");
        return 1;
    }
    array = (int *)malloc(size * sizeof(int));
    if (array == NULL) /* exit program if can't malloc memory */
    {
        printf("Can't Malloc! Please try again.");
        return 1;
    }
    for (i = 0; i < size; i++)
    {
        printf("Enter number[%d]: ", i);
        scanf("%d", &array[i]);
    }

    merge_sort(array, size, 0, size - 1);
    printf("Sorted Array: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);

    return 0;
}
