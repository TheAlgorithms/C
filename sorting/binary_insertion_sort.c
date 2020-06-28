/* Sorting of array list using binary insertion sort
 * Using binary search to find the proper location for
 * inserting the selected item at each iteration. */
#include <stdio.h>
#include <stdlib.h>

/*Displays the array, passed to this method*/
void display(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int binarySearch(int *arr, int key, int low, int high)
{
    if (low >= high)
        return (key > arr[low]) ? (low + 1) : low;
    int mid = low + (high - 1) / 2;
    if (arr[mid] == key)
        return mid + 1;
    else if (arr[mid] > key)
        return binarySearch(arr, key, low, mid - 1);
    else
        return binarySearch(arr, key, mid + 1, high);
}
/*This is where the sorting of the array takes place
 arr[] --- Array to be sorted
 size --- Array Size
 */
void insertionSort(int *arr, int size)
{
    int i, j, key, index;
    for (i = 0; i < size; i++)
    {
        j = i - 1;
        key = arr[i];
        /* Use binrary search to find exact key's index */
        index = binarySearch(arr, key, 0, j);
        /* Move all elements greater than key from [index...j]
         * to one position */
        while (j >= index)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        /* Insert key value in right place */
        arr[j + 1] = key;
    }
}

int main(int argc, const char *argv[])
{
    int n;
    printf("Enter size of array:\n");
    scanf("%d", &n);  // E.g. 8

    printf("Enter the elements of the array\n");
    int i;
    int *arr = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    display(arr, n);

    insertionSort(arr, n);

    printf("Sorted array: ");
    display(arr, n);

    free(arr);
    return 0;
}
