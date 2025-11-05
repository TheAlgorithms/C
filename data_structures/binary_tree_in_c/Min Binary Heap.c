/**
 * @file Min Binary Heap.c
 * @brief Implementation of a Min Binary Heap using a dynamic array in C.
 * * A Min Heap is a complete binary tree where the value of each node is less
 * than or equal to the values of its children. The smallest element is always
 * at the root. This implementation supports: Insert, Extract Min, Peek Min,
 * Search, and Display. It uses dynamic memory management to create and destroy
 * the heap structure.
 */

#include <limits.h>  // For INT_MAX (used for error checking/sentinel value)
#include <stdio.h>
#include <stdlib.h>

// --- STRUCTURE DEFINITION ---

/**
 * @brief Represents the Min Heap structure.
 * * The heap is stored in a 0-indexed array where:
 * Parent(i) = (i - 1) / 2
 * LeftChild(i) = 2 * i + 1
 * RightChild(i) = 2 * i + 2
 */
typedef struct MinHeap
{
    int* arr;      // Pointer to the dynamic array holding the heap elements
    int size;      // Current number of elements in the heap
    int capacity;  // Maximum number of elements the array can hold
} MinHeap;

// --- UTILITY FUNCTIONS ---

/**
 * @brief Swaps two integer values.
 */
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief Calculates the index of the parent node.
 */
int parent(int i) { return (i - 1) / 2; }

/**
 * @brief Calculates the index of the left child.
 */
int left_child(int i) { return 2 * i + 1; }

/**
 * @brief Calculates the index of the right child.
 */
int right_child(int i) { return 2 * i + 2; }

// --- HEAP LIFE CYCLE MANAGEMENT ---

/**
 * @brief Creates a new MinHeap structure with a given capacity.
 * @param capacity The maximum number of elements the heap can hold.
 * @return Pointer to the newly created MinHeap.
 */
MinHeap* createMinHeap(int capacity)
{
    // Allocate memory for the structure itself
    MinHeap* h = (MinHeap*)malloc(sizeof(MinHeap));
    if (h == NULL)
    {
        perror("Failed to allocate MinHeap structure");
        exit(EXIT_FAILURE);
    }

    // Set properties
    h->capacity = capacity;
    h->size = 0;

    // Allocate memory for the underlying array
    h->arr = (int*)malloc(capacity * sizeof(int));
    if (h->arr == NULL)
    {
        perror("Failed to allocate array memory");
        free(h);  // Clean up the structure memory
        exit(EXIT_FAILURE);
    }

    return h;
}

/**
 * @brief Frees the memory allocated for the MinHeap.
 * @param h Pointer to the MinHeap to be destroyed.
 */
void destroyMinHeap(MinHeap* h)
{
    if (h == NULL)
        return;
    free(h->arr);  // Free the dynamic array first
    free(h);       // Free the structure memory
    printf("\nMinHeap successfully destroyed. Memory freed.\n");
}

// --- HEAP PROPERTY MAINTENANCE ---

/**
 * @brief Corrects the Min Heap property by moving the element at index i DOWN
 * the tree. This is primarily used after Extract Min. Time Complexity: O(log n)
 * @param h Pointer to the MinHeap.
 * @param i The index of the element to heapify down.
 */
void heapify_down(MinHeap* h, int i)
{
    int l = left_child(i);
    int r = right_child(i);
    int smallest = i;  // Assume current node is the smallest

    // Check if left child exists and is smaller than the current smallest
    if (l < h->size && h->arr[l] < h->arr[smallest])
    {
        smallest = l;
    }

    // Check if right child exists and is smaller than the current smallest
    if (r < h->size && h->arr[r] < h->arr[smallest])
    {
        smallest = r;
    }

    // If the smallest is not the current node, swap and recursively move down
    if (smallest != i)
    {
        swap(&h->arr[i], &h->arr[smallest]);
        heapify_down(h, smallest);
    }
}

/**
 * @brief Corrects the Min Heap property by moving the element at index i UP the
 * tree. This is primarily used after Insert. Time Complexity: O(log n)
 * @param h Pointer to the MinHeap.
 * @param i The index of the element to heapify up.
 */
void heapify_up(MinHeap* h, int i)
{
    // Check if current node is not root AND if element is smaller than its
    // parent
    while (i > 0 && h->arr[parent(i)] > h->arr[i])
    {
        // Swap the current element with its parent
        swap(&h->arr[parent(i)], &h->arr[i]);

        // Move up to the parent's index and repeat
        i = parent(i);
    }
}

// --- CORE HEAP OPERATIONS ---

/**
 * @brief Inserts a new key into the MinHeap.
 * Time Complexity: O(log n)
 * @param h Pointer to the MinHeap.
 * @param key The value to be inserted.
 */
void insert(MinHeap* h, int key)
{
    if (h->size == h->capacity)
    {
        printf("Error: Heap is full (Capacity: %d). Cannot insert %d.\n",
               h->capacity, key);
        return;
    }

    // 1. Place the new element at the next available spot (end of the array)
    h->size++;
    int i = h->size - 1;
    h->arr[i] = key;

    // 2. Restore the heap property by moving the element up
    heapify_up(h, i);
    printf("Inserted %d. Heap size: %d\n", key, h->size);
}

/**
 * @brief Removes and returns the minimum element (root) from the MinHeap.
 * Time Complexity: O(log n)
 * @param h Pointer to the MinHeap.
 * @return The minimum element, or INT_MAX if the heap is empty.
 */
int extract_min(MinHeap* h)
{
    if (h->size <= 0)
    {
        printf("Error: Heap is empty. Cannot extract.\n");
        return INT_MAX;
    }

    // 1. Store the minimum element (root)
    int root = h->arr[0];

    // 2. Replace the root with the last element
    h->arr[0] = h->arr[h->size - 1];

    // 3. Decrease the size
    h->size--;

    // 4. Restore the heap property by moving the new root down
    heapify_down(h, 0);

    return root;
}

/**
 * @brief Returns the minimum element (root) without removing it.
 * Time Complexity: O(1)
 * @param h Pointer to the MinHeap.
 * @return The minimum element, or INT_MAX if the heap is empty.
 */
int peek_min(MinHeap* h)
{
    if (h->size <= 0)
    {
        printf("Error: Heap is empty.\n");
        return INT_MAX;
    }
    return h->arr[0];  // Simply return the root element
}

/**
 * @brief Performs a linear search for a key in the heap.
 * Time Complexity: O(n)
 * @param h Pointer to the MinHeap.
 * @param key The value to search for.
 * @return The array index of the key if found, or -1 otherwise.
 */
int search(MinHeap* h, int key)
{
    // Linear search through the underlying array
    for (int i = 0; i < h->size; i++)
    {
        if (h->arr[i] == key)
        {
            return i;  // Found at index i
        }
    }
    return -1;  // Not found
}

/**
 * @brief Prints all elements of the heap in array order (not tree order).
 * Time Complexity: O(n)
 * @param h Pointer to the MinHeap.
 */
void display(MinHeap* h)
{
    if (h->size == 0)
    {
        printf("Heap is empty.\n");
        return;
    }
    printf("Current Heap elements (Array Order, size=%d): ", h->size);
    for (int i = 0; i < h->size; i++)
    {
        printf("%d ", h->arr[i]);
    }
    printf("\n");
}

// --- MAIN FUNCTION FOR DEMONSTRATION ---

int main()
{
    // Define the initial capacity
    int capacity = 10;
    MinHeap* heap = createMinHeap(capacity);

    printf("--- Min Binary Heap Demonstration ---\n");
    printf("1. Initializing Heap with Capacity: %d\n", capacity);

    // 2. Insert Operations
    printf("\n2. Inserting elements: 10, 5, 20, 2, 4, 8\n");
    insert(heap, 10);
    insert(heap, 5);
    insert(heap, 20);
    insert(heap, 2);
    insert(heap, 4);
    insert(heap, 8);
    display(heap);
    // Expected Array Order: [2, 4, 8, 10, 5, 20] (Min Heap Property satisfied)

    // 3. Peek Min Operation (O(1))
    printf("\n3. Peek Min (O(1)): %d\n", peek_min(heap));
    display(heap);

    // 4. Extract Min Operations (O(log n))
    int min1 = extract_min(heap);
    printf("\n4. Extracted Min (O(log n)): %d\n", min1);
    display(heap);

    int min2 = extract_min(heap);
    printf("Extracted Min: %d\n", min2);
    display(heap);

    // 5. Search Operation (O(n))
    int search_val = 10;
    int index = search(heap, search_val);
    if (index != -1)
    {
        printf("5. Search: Value %d found at array index %d.\n", search_val,
               index);
    }
    else
    {
        printf("5. Search: Value %d not found.\n", search_val);
    }

    search_val = 99;
    index = search(heap, search_val);
    if (index != -1)
    {
        printf("5. Search: Value %d found at array index %d.\n", search_val,
               index);
    }
    else
    {
        printf("5. Search: Value %d not found.\n", search_val);
    }

    // 6. Final cleanup (Crucial for memory management)
    destroyMinHeap(heap);

    return 0;
}
