/**
 *@author [Bama Charan Chhandogi](https://github.com/BamaCharanChhandogi)
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
// Function to merge two sorted subarrays into one sorted array
void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays to store the left and right subarrays
    int L[n1], R[n2];

    // Copy data to temporary arrays
    for (i = 0; i < n1; i++) L[i] = arr[left + i];
    for (j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L and R, if any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/** Merge sort algorithm implementation
 * @param arr the array
 * @param left index to sort from
 * @param right index to sort till
 */
void merge_sort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // Sort the left and right halves separately
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        // Merge the two sorted halves
        merge(arr, left, mid, right);
    }
}

#define MAX 100  // Maximum array size for testing
// Function to check if an array is sorted in ascending order
int is_sorted(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return 0;  // Not sorted
        }
    }
    return 1;  // Sorted
}

// Test function for merge sort
static void test_merge_sort()
{
    int test_arr[MAX];

    // Populate the test array with random integers
    for (int i = 0; i < MAX; i++)
    {
        test_arr[i] = rand() % 1000;  // Using a larger range for better testing
    }

    // Perform merge sort on the test array
    merge_sort(test_arr, 0, MAX - 1);

    // Check if the array is sorted
    assert(is_sorted(test_arr, MAX));

    printf("Merge sort test passed!\n");
}
/**
 * @brief main function
 * @returns 0 on successful exit
 **/
int main()
{
    // Run the merge sort test function
    test_merge_sort();

    return 0;
}
