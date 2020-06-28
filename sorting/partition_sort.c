#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low - 1, j = high + 1;

    while (1)
    {
        /* Find leftmost element >= pivot */
        do
        {
            i++;
        } while (arr[i] < pivot);

        /* Find rightmost element <= pivot */
        do
        {
            j--;
        } while (arr[j] > pivot);

        /* if two pointers met */
        if (i >= j)
            return j;

        swap(&arr[i], &arr[j]);
    }
}

void partitionSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int value = partition(arr, low, high);
        partitionSort(arr, low, value);
        partitionSort(arr, value + 1, high);
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[20];
    int i, range = 100;
    for (i = 0; i < 20; i++)
    {
        arr[i] = rand() % range + 1;
    }
    int size = sizeof arr / sizeof arr[0];
    printf("Array: \n");
    printArray(arr, size);
    partitionSort(arr, 0, size - 1);
    printf("Sorted Array: \n");
    printArray(arr, size);

    return 0;
}
