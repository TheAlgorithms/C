/* min_heap.c -- Min Binary Heap implementation in C */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct MinHeap {
    int *arr;       // pointer to array of elements in heap
    int capacity;   // maximum possible size
    int size;       // current number of elements
} MinHeap;

/* create a new min heap with given initial capacity */
MinHeap* createMinHeap(int capacity) {
    MinHeap *h = (MinHeap*) malloc(sizeof(MinHeap));
    if (!h) { perror("malloc"); exit(EXIT_FAILURE); }
    h->capacity = capacity > 0 ? capacity : 10;
    h->size = 0;
    h->arr = (int*) malloc(sizeof(int) * h->capacity);
    if (!h->arr) { perror("malloc"); exit(EXIT_FAILURE); }
    return h;
}

/* free heap */
void freeMinHeap(MinHeap *h) {
    if (!h) return;
    free(h->arr);
    free(h);
}

/* helper: swap */
static void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/* helper: ensure capacity (resize if full) */
static void ensureCapacity(MinHeap *h) {
    if (h->size < h->capacity) return;
    int newCap = h->capacity * 2;
    int *newArr = (int*) realloc(h->arr, sizeof(int) * newCap);
    if (!newArr) { perror("realloc"); exit(EXIT_FAILURE); }
    h->arr = newArr;
    h->capacity = newCap;
}

/* heapify up (after insert) */
static void heapifyUp(MinHeap *h, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (h->arr[parent] > h->arr[idx]) {
            swap(&h->arr[parent], &h->arr[idx]);
            idx = parent;
        } else break;
    }
}

/* heapify down (after extract/min removed) */
static void heapifyDown(MinHeap *h, int idx) {
    int left, right, smallest;
    while (1) {
        left = 2 * idx + 1;
        right = 2 * idx + 2;
        smallest = idx;

        if (left < h->size && h->arr[left] < h->arr[smallest])
            smallest = left;
        if (right < h->size && h->arr[right] < h->arr[smallest])
            smallest = right;
        if (smallest != idx) {
            swap(&h->arr[idx], &h->arr[smallest]);
            idx = smallest;
        } else break;
    }
}

/* Insert a key into the heap (O(log n)) */
void insertKey(MinHeap *h, int key) {
    ensureCapacity(h);
    h->arr[h->size] = key;
    h->size += 1;
    heapifyUp(h, h->size - 1);
}

/* Get minimum without removing (Peek) (O(1)) */
int getMin(MinHeap *h) {
    if (h->size == 0) return INT_MIN; // or handle error
    return h->arr[0];
}

/* Extract min (remove and return minimum element) (O(log n)) */
int extractMin(MinHeap *h) {
    if (h->size <= 0) return INT_MIN; // indicate empty
    int root = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size -= 1;
    if (h->size > 0) heapifyDown(h, 0);
    return root;
}

/* Search for a value (linear scan) O(n). Returns index or -1 if not found */
int searchHeap(MinHeap *h, int value) {
    for (int i = 0; i < h->size; ++i)
        if (h->arr[i] == value) return i;
    return -1;
}

/* Display the heap array (level-order) O(n) */
void displayHeap(MinHeap *h) {
    if (h->size == 0) {
        printf("(empty heap)\n");
        return;
    }
    printf("Heap (size=%d): ", h->size);
    for (int i = 0; i < h->size; ++i) {
        printf("%d ", h->arr[i]);
    }
    printf("\n");
}

/* Example usage */
int main(void) {
    MinHeap *heap = createMinHeap(10);

    int values[] = { 20, 5, 15, 22, 40, 3, 8, 1, 30 };
    int n = sizeof(values) / sizeof(values[0]);

    printf("Inserting values: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", values[i]);
        insertKey(heap, values[i]);
    }
    printf("\n");
    displayHeap(heap);

    printf("Min element (peek): %d\n", getMin(heap));

    int s = 15;
    int idx = searchHeap(heap, s);
    if (idx >= 0) printf("Found %d at index %d (heap array index)\n", s, idx);
    else printf("%d not found in heap\n", s);

    printf("Extracting min elements:\n");
    while (heap->size > 0) {
        int m = extractMin(heap);
        printf("%d ", m);
    }
    printf("\n");

    freeMinHeap(heap);
    return 0;
}
