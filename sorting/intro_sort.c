/**
 * @file
 * @brief [IntroSort](https://en.wikipedia.org/wiki/Introsort) algorithm implementation
 * @details
 * IntroSort is a hybrid sorting algorithm that provides both fast average performance
 * and optimal worst-case performance. It begins with QuickSort, switches to HeapSort
 * when the recursion depth exceeds a level based on the logarithm of the number of elements
 * being sorted, and uses InsertionSort for small partitions.
 * 
 * @author [Contributor](https://github.com/kokatesaurabh)
 * Time Complexity: O(n log n) worst-case, O(n log n) average-case
 * Space Complexity: O(log n) due to recursion stack
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* Swap two elements */
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Insertion sort */
void insertionSort(int arr[], int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= low && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/* Heapify */
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

/* Heap sort */
void heapSort(int arr[], int low, int high) {
    int n = high - low + 1;
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr + low, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[low], &arr[low + i]);
        heapify(arr + low, i, 0);
    }
}

/* Hoare partition */
int partition(int arr[], int low, int high) {
    int pivot = arr[low + (high - low) / 2];
    int i = low - 1;
    int j = high + 1;
    while (1) {
        do { i++; } while (arr[i] < pivot);
        do { j--; } while (arr[j] > pivot);
        if (i >= j) return j;
        swap(&arr[i], &arr[j]);
    }
}

/* IntroSort recursive utility */
void introSortUtil(int arr[], int low, int high, int depthLimit) {
    int size = high - low + 1;

    if (size < 16) {
        insertionSort(arr, low, high);
        return;
    }
    if (depthLimit == 0) {
        heapSort(arr, low, high);
        return;
    }
    int p = partition(arr, low, high);
    introSortUtil(arr, low, p, depthLimit - 1);
    introSortUtil(arr, p + 1, high, depthLimit - 1);
}

/* Main IntroSort */
void introSort(int arr[], int n) {
    if (n <= 1 || arr == NULL) return;

    // Calculate depth limit: 2 * floor(log2(n)) using bit hack
    int depthLimit = 2 * (31 - __builtin_clz(n));
    introSortUtil(arr, 0, n - 1, depthLimit);
}

/* Print array */
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* Tests */
static void test() {
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    introSort(arr1, n1);
    for (int i = 0; i < n1 - 1; i++) assert(arr1[i] <= arr1[i + 1]);

    int arr2[] = {1, 2, 3, 4, 5, 6, 7};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    introSort(arr2, n2);
    for (int i = 0; i < n2 - 1; i++) assert(arr2[i] <= arr2[i + 1]);

    int arr3[] = {7, 6, 5, 4, 3, 2, 1};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    introSort(arr3, n3);
    for (int i = 0; i < n3 - 1; i++) assert(arr3[i] <= arr3[i + 1]);

    int arr4[] = {4, 2, 4, 1, 3, 2, 1};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    introSort(arr4, n4);
    for (int i = 0; i < n4 - 1; i++) assert(arr4[i] <= arr4[i + 1]);

    int arr5[] = {42};
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    introSort(arr5, n5);
    assert(arr5[0] == 42);

    int *arr6 = NULL;
    int n6 = 0;
    introSort(arr6, n6); // safe, does nothing

    printf("All tests passed successfully!\n");
}

int main() {
    test();

    int arr[] = {64, 34, 25, 12, 22, 11, 90, 88, 76, 50, 42, 33, 21, 19, 8, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    introSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
