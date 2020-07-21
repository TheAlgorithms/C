/*
Randomised quick sort implementation in C language.
In normal quick sort, pivot chosen to partition is either the first or the last
element of the array. This can take time O(n*n) to sort in the worst case. Now
in randomised quick sort, pivot is randomly chosen and then recursively sort the
left and right sub-arrays. The expected running time of the algorithm is
O(nlog(n)).
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getBig(int *a, int i, int right, int pivot)
{
    for (int k = i; k <= right; k++)
    {
        if (a[k] > pivot)
            return k;
    }
    return right + 1;
}

int getSmall(int *a, int j, int left, int pivot)
{
    for (int k = j; k >= left; k--)
    {
        if (a[k] < pivot)
            return k;
    }
    return -1;
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void random_quick(int *a, int left, int right)
{
    if (left >= right)
        return;
    int index = left + (rand() % (right - left)), i = left, j = right;
    int pivot_index = index;
    int pivot = a[index];
    // storing index of element greater than pivot
    i = getBig(a, i, right, pivot);
    // storing index of element smaller than pivot
    j = getSmall(a, j, left, pivot);
    while (i <= j)
    {
        swap(&a[i], &a[j]);
        i = getBig(a, i, right, pivot);
        j = getSmall(a, j, left, pivot);
    }
    // after separating the smaller and greater elements, there are 3 cases
    // possible
    if (pivot_index > j && pivot_index > i)
    {
        // case 1. When the pivot element index is greater than both i and j
        swap(&a[i], &a[pivot_index]);
        random_quick(a, left, i - 1);
        random_quick(a, i + 1, right);
    }
    else if (pivot_index < j && pivot_index < i)
    {
        // case 2. When the pivot element index is smaller than both i and j
        swap(&a[j], &a[pivot_index]);
        random_quick(a, left, j - 1);
        random_quick(a, j + 1, right);
    }
    else
    {
        // the pivot element is at its origin position.
        random_quick(a, left, pivot_index - 1);
        random_quick(a, pivot_index + 1, right);
    }
}

int main()
{
    srand(time(0));
    int num;
    scanf("%d", &num);
    int *arr = (int *)malloc(num * sizeof(int));
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }
    random_quick(arr, 0, num - 1);
    for (int i = 0; i < num; i++)
    {
        printf("%d ", arr[i]);
    }

    free(arr);
    printf("\n");
}
