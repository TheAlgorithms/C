/**
 * @file
 * @brief Implementation of [Min Binary
 * Heap](https://en.wikipedia.org/wiki/Binary_heap)
 * @details
 * A Min Binary Heap is a complete binary tree-based data structure where the
 * value of each node is less than or equal to the values of its children. This
 * property ensures that the minimum element is always at the root, allowing
 * efficient retrieval and removal of the smallest element.
 *
 * @author [Aryan Singh](https://github.com/Dibbu-cell)
 */

#include <assert.h>   /// for assert
#include <stdbool.h>  /// for bool type
#include <stdio.h>    /// for IO operations
#include <stdlib.h>   /// for malloc, realloc, free

/**
 * @brief Structure representing a Min Binary Heap
 */
struct min_binary_heap
{
    int *arr;         ///< pointer to the heap array
    size_t size;      ///< current number of elements in the heap
    size_t capacity;  ///< current capacity of the heap array
};

/**
 * @brief Create a new Min Binary Heap with given initial capacity
 * @param capacity initial capacity of the heap
 * @returns pointer to the created heap, or NULL on failure
 */
struct min_binary_heap *min_heap_create(size_t capacity)
{
    struct min_binary_heap *heap =
        (struct min_binary_heap *)malloc(sizeof(struct min_binary_heap));
    if (!heap)
        return NULL;
    heap->arr = (int *)malloc(capacity * sizeof(int));
    if (!heap->arr)
    {
        free(heap);
        return NULL;
    }
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

/**
 * @brief Free the memory used by the heap
 * @param heap pointer to the heap
 */
void min_heap_destroy(struct min_binary_heap *heap)
{
    if (heap)
    {
        free(heap->arr);
        free(heap);
    }
}

/**
 * @brief Swap two integers
 * @param a pointer to first integer
 * @param b pointer to second integer
 */
static void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief Heapify up to maintain min-heap property after insertion
 * @param heap pointer to the heap
 * @param idx index of the newly inserted element
 */
static void heapify_up(struct min_binary_heap *heap, size_t idx)
{
    if (idx == 0)
        return;
    size_t parent = (idx - 1) / 2;
    if (heap->arr[parent] > heap->arr[idx])
    {
        swap(&heap->arr[parent], &heap->arr[idx]);
        heapify_up(heap, parent);
    }
}

/**
 * @brief Heapify down to maintain min-heap property after extraction
 * @param heap pointer to the heap
 * @param idx index to heapify down from
 */
static void heapify_down(struct min_binary_heap *heap, size_t idx)
{
    size_t left = 2 * idx + 1;
    size_t right = 2 * idx + 2;
    size_t smallest = idx;

    if (left < heap->size && heap->arr[left] < heap->arr[smallest])
        smallest = left;
    if (right < heap->size && heap->arr[right] < heap->arr[smallest])
        smallest = right;

    if (smallest != idx)
    {
        swap(&heap->arr[idx], &heap->arr[smallest]);
        heapify_down(heap, smallest);
    }
}

/**
 * @brief Insert a value into the min binary heap
 * @param heap pointer to the heap
 * @param value value to insert
 * @returns true if insertion succeeded, false otherwise
 */
bool min_heap_insert(struct min_binary_heap *heap, int value)
{
    if (!heap)
        return false;
    if (heap->size == heap->capacity)
    {
        size_t new_capacity = heap->capacity * 2;
        int *new_arr = (int *)realloc(heap->arr, new_capacity * sizeof(int));
        if (!new_arr)
            return false;
        heap->arr = new_arr;
        heap->capacity = new_capacity;
    }
    heap->arr[heap->size] = value;
    heapify_up(heap, heap->size);
    heap->size++;
    return true;
}

/**
 * @brief Extract the minimum value from the heap
 * @param heap pointer to the heap
 * @param out pointer to store the extracted value
 * @returns true if extraction succeeded, false if heap is empty
 */
bool min_heap_extract_min(struct min_binary_heap *heap, int *out)
{
    if (!heap || heap->size == 0)
        return false;
    if (out)
        *out = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapify_down(heap, 0);
    return true;
}

/**
 * @brief Get the minimum value from the heap without removing it
 * @param heap pointer to the heap
 * @param out pointer to store the minimum value
 * @returns true if heap is not empty, false otherwise
 */
bool min_heap_peek(const struct min_binary_heap *heap, int *out)
{
    if (!heap || heap->size == 0)
        return false;
    if (out)
        *out = heap->arr[0];
    return true;
}

/**
 * @brief Search for a value in the heap (linear search)
 * @param heap pointer to the heap
 * @param value value to search for
 * @returns true if value is found, false otherwise
 */
bool min_heap_search(const struct min_binary_heap *heap, int value)
{
    if (!heap)
        return false;
    for (size_t i = 0; i < heap->size; ++i)
    {
        if (heap->arr[i] == value)
            return true;
    }
    return false;
}

/**
 * @brief Display the heap elements in array order
 * @param heap pointer to the heap
 */
void min_heap_display(const struct min_binary_heap *heap)
{
    if (!heap)
        return;
    printf("Heap elements: ");
    for (size_t i = 0; i < heap->size; ++i) printf("%d ", heap->arr[i]);
    printf("\n");
}

/**
 * @brief Self-test implementations for Min Binary Heap
 * @returns void
 */
static void test_min_binary_heap()
{
    struct min_binary_heap *heap = min_heap_create(4);
    assert(heap != NULL);

    // Test insertion
    assert(min_heap_insert(heap, 10));
    assert(min_heap_insert(heap, 4));
    assert(min_heap_insert(heap, 15));
    assert(min_heap_insert(heap, 20));
    assert(min_heap_insert(heap, 0));  // triggers resize

    // Test display (should be in heap order, not sorted)
    min_heap_display(heap);

    // Test search
    assert(min_heap_search(heap, 10) == true);
    assert(min_heap_search(heap, 99) == false);

    // Test peek
    int min_val = -1;
    assert(min_heap_peek(heap, &min_val));
    assert(min_val == 0);

    // Test extract min
    int extracted = -1;
    assert(min_heap_extract_min(heap, &extracted));
    assert(extracted == 0);

    assert(min_heap_peek(heap, &min_val));
    assert(min_val == 4);

    // Extract all and check order
    int prev = -1;
    while (heap->size > 0)
    {
        assert(min_heap_extract_min(heap, &extracted));
        if (prev != -1)
            assert(prev <= extracted);  // Should be non-decreasing
        prev = extracted;
    }

    // Heap should be empty now
    assert(min_heap_peek(heap, &min_val) == false);

    min_heap_destroy(heap);

    printf("All Min Binary Heap tests have successfully passed!\n");
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main(void)
{
    test_min_binary_heap();  // run self-test implementations
    return 0;
}
