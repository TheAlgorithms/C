#include <stdio.h>

// Define a struct to represent an array of integers
struct IntArray {
    int *data;
    int size;
};

/**
 * Find the maximum element in the array.
 *
 * @param arr The array to find the maximum element in.
 * @param n   The number of elements in the array.
 * @return    The maximum element in the array.
 */
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

/**
 * Perform counting sort on the array based on the specified digit place (exp).
 *
 * @param arr The array to be sorted.
 * @param n   The number of elements in the array.
 * @param exp The digit place (e.g., 1 for units, 10 for tens).
 */
void countingSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

/**
 * Perform Radix Sort on the given integer array.
 *
 * @param arr The array to be sorted.
 * @param n   The number of elements in the array.
 */
void radixSort(int arr[], int n) {
    int max = findMax(arr, n);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Create a struct to hold the integer array
    struct IntArray array;
    array.size = n;
    array.data = (int *)malloc(n * sizeof(int));

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array.data[i]);
    }

    // Perform Radix Sort
    radixSort(array.data, array.size);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array.data[i]);
    }
    printf("\n");

    // Free the dynamically allocated memory
    free(array.data);

    return 0;
}

