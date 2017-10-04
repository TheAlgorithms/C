// Heap sort
#include <stdio.h>

void printArr(int *A, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// heap looks like
// 9 1 2 8 3 4 7 5
//  9   8   4   7
//     9       7
//         9
// the array is heap mean arr[i]>max(arr[i*2+1],arr[i*2+2])
// the arr[0] is max of the array
void heapShift(int *arr, int index, int size)
{
    // put arr[index] to arr[index+1..size-1] follow heap
    int i = index;
    int j = 2 * i + 1;
    while (j < size)
    {
        if (j != size - 1) // there exist j and j+1
        {
            if (arr[j + 1] > arr[j]) // find max of arr[j] and arr[j+1]
                j++;
        }
        if (arr[i] > arr[j]) // already heap
            break;
        swap(&arr[i], &arr[j]);
        // move i, j
        i = j;
        j = i * 2 + 1;
    }
}

void heapSort(int *arr, int size)
{
    // the array is split to to half
    // just care the first half to put heap
    for (int i = size / 2; i >= 0; i--)
    {
        heapShift(arr, i, size);
    }
    for (int i = size - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]); // move max of array to the end
        heapShift(arr, 0, i);   // find max of arr[0..i-1], move to arr[0]
    }
}

int main()
{
    int A[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(A) / sizeof(A[0]);
    heapSort(A, size);
    printArr(A, size);
    return 0;
}
