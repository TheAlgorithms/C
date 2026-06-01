/**
 * @file tournament_sort.c
 * @brief Implementation of Tournament Sort algorithm
 * @see https://en.wikipedia.org/wiki/Tournament_sort
 *
 * Tournament Sort improves upon naive Selection Sort by using a min-heap
 * (priority queue) to find the minimum element in O(log n) instead of O(n),
 * giving an overall time complexity of O(n log n).
 *
 * @author drori12
 */

#include <assert.h>  /// for assert
#include <stdio.h>   /// for printf
#include <stdlib.h>  /// for malloc, free

/**
 * @brief Restores the min-heap property by sifting down from index i
 * @param arr   heap array
 * @param n     size of heap
 * @param i     index to sift down from
 */
static void heapify(int *arr, int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i)
    {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        heapify(arr, n, smallest);
    }
}

/**
 * @brief Sorts an array using tournament sort (min-heap based selection)
 * @param arr   array to sort
 * @param n     number of elements
 */
void tournament_sort(int *arr, int n)
{
    if (n <= 1)
        return;

    /* Copy into a heap */
    int *heap = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        heap[i] = arr[i];

    /* Build min-heap */
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(heap, n, i);

    /* Extract elements one by one */
    for (int i = 0; i < n; i++)
    {
        arr[i] = heap[0];
        heap[0] = heap[n - i - 1];
        heapify(heap, n - i - 1, 0);
    }

    free(heap);
}

/**
 * @brief Self-test implementations
 */
static void test_tournament_sort(void)
{
    /* Test 1: regular unsorted array */
    int arr1[] = {5, 3, 1, 4, 2};
    tournament_sort(arr1, 5);
    for (int i = 0; i < 4; i++)
        assert(arr1[i] <= arr1[i + 1]);

    /* Test 2: already sorted */
    int arr2[] = {1, 2, 3, 4, 5};
    tournament_sort(arr2, 5);
    for (int i = 0; i < 4; i++)
        assert(arr2[i] <= arr2[i + 1]);

    /* Test 3: reverse sorted */
    int arr3[] = {5, 4, 3, 2, 1};
    tournament_sort(arr3, 5);
    for (int i = 0; i < 4; i++)
        assert(arr3[i] <= arr3[i + 1]);

    /* Test 4: single element */
    int arr4[] = {42};
    tournament_sort(arr4, 1);
    assert(arr4[0] == 42);

    /* Test 5: duplicates */
    int arr5[] = {3, 1, 2, 1, 3};
    tournament_sort(arr5, 5);
    for (int i = 0; i < 4; i++)
        assert(arr5[i] <= arr5[i + 1]);

    /* Test 6: negative numbers */
    int arr6[] = {-3, 0, -1, 5, 2};
    tournament_sort(arr6, 5);
    for (int i = 0; i < 4; i++)
        assert(arr6[i] <= arr6[i + 1]);

    printf("All tests passed!\n");
}

/**
 * @brief Main function
 * @return 0 on success
 */
int main(void)
{
    test_tournament_sort();

    int arr[] = {5, 3, 1, 4, 2};
    int n = 5;
    tournament_sort(arr, n);
    printf("Sorted: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
