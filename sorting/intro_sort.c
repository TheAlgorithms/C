// Implementation of IntroSort (Introspective Sort)
// Author: sgindeed
// Description:
// IntroSort is a hybrid sorting algorithm that starts with QuickSort,
// switches to HeapSort when recursion depth exceeds a limit, and uses
// InsertionSort for small arrays. It combines average-case speed of QuickSort
// with the worst-case performance guarantee of HeapSort.
//
// Time Complexity: O(n log n)
// Space Complexity: O(log n) due to recursion stack
//
// References:
// - Musser, David R. "Introspective Sorting and Selection Algorithms." Software: Practice and Experience (1997)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 50
#define INSERTION_SORT_THRESHOLD 16

/* -------------------- Utility Functions -------------------- */

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* -------------------- Insertion Sort -------------------- */

void insertionSort(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/* -------------------- Heap Sort -------------------- */

void heapify(int arr[], int n, int i, int start) {
    int largest = i;
    int left = 2 * (i - start) + 1 + start;
    int right = 2 * (i - start) + 2 + start;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest, start);
    }
}

void heapSort(int arr[], int start, int end) {
    int n = end - start + 1;

    // Build heap (rearrange array)
    for (int i = start + n / 2 - 1; i >= start; i--)
        heapify(arr, end + 1, i, start);

    // Extract elements one by one
    for (int i = end; i >= start; i--) {
        swap(&arr[start], &arr[i]);
        heapify(arr, i, start, start);
    }
}

/* -------------------- Quick Sort (used in IntroSort) -------------------- */

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void introSortUtil(int arr[], int low, int high, int depthLimit) {
    int size = high - low + 1;

    // Use insertion sort for small arrays
    if (size < INSERTION_SORT_THRESHOLD) {
        insertionSort(arr, low, high);
        return;
    }

    // If depth limit is 0, use heap sort
    if (depthLimit == 0) {
        heapSort(arr, low, high);
        return;
    }

    // Otherwise, use QuickSort
    int pivot = partition(arr, low, high);

    introSortUtil(arr, low, pivot - 1, depthLimit - 1);
    introSortUtil(arr, pivot + 1, high, depthLimit - 1);
}

/* -------------------- Main IntroSort Function -------------------- */

void introSort(int arr[], int n) {
    int depthLimit = 2 * log(n);
    introSortUtil(arr, 0, n - 1, depthLimit);
}

/* -------------------- Display Utility -------------------- */

void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* -------------------- Driver Code -------------------- */

int main() {
    int arr[SIZE];

    // Generate random numbers
    for (int i = 0; i < SIZE; i++)
        arr[i] = rand() % (SIZE << 1); // random numbers from 0 to 2*SIZE

    printf("Original array:\n");
    display(arr, SIZE);

    introSort(arr, SIZE);

    printf("\nSorted array:\n");
    display(arr, SIZE);

    return 0;
}
