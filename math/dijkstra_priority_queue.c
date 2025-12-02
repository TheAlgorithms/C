#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// Graph representation: adjacency list
typedef struct {
    int num_vertices;
    int** adj_list;  // Array of arrays (edges)
    int* adj_sizes;  // Size of each adj list
} Graph;

// Min-heap node
typedef struct {
    int vertex;
    int distance;
} PQNode;

// Min-heap priority queue
typedef struct {
    PQNode* nodes;
    int capacity;
    int size;
} MinHeap;

// Create a new graph
Graph* create_graph(int num_vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->adj_list = (int**)malloc(num_vertices * sizeof(int*));
    graph->adj_sizes = (int*)calloc(num_vertices, sizeof(int));
    for (int i = 0; i < num_vertices; i++) {
        graph->adj_list[i] = NULL;
    }
    return graph;
}

// Add undirected edge (weight is stored as the edge value for simplicity; adjust if needed)
void add_edge(Graph* graph, int src, int dest, int weight) {
    // Resize src list
    graph->adj_list[src] = (int*)realloc(graph->adj_list[src], (graph->adj_sizes[src] + 2) * sizeof(int));
    graph->adj_list[src][graph->adj_sizes[src]++] = dest;
    graph->adj_list[src][graph->adj_sizes[src]++] = weight;

    // For undirected: add reverse
    graph->adj_list[dest] = (int*)realloc(graph->adj_list[dest], (graph->adj_sizes[dest] + 2) * sizeof(int));
    graph->adj_list[dest][graph->adj_sizes[dest]++] = src;
    graph->adj_list[dest][graph->adj_sizes[dest]++] = weight;
}

// Create min-heap
MinHeap* create_min_heap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->nodes = (PQNode*)malloc(capacity * sizeof(PQNode));
    return heap;
}

// Swap two nodes in heap
void swap(PQNode* a, PQNode* b) {
    PQNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify down
void min_heapify(MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->nodes[left].distance < heap->nodes[smallest].distance) {
        smallest = left;
    }
    if (right < heap->size && heap->nodes[right].distance < heap->nodes[smallest].distance) {
        smallest = right;
    }
    if (smallest != idx) {
        swap(&heap->nodes[idx], &heap->nodes[smallest]);
        min_heapify(heap, smallest);
    }
}

// Insert into heap (with check for existing to simulate decrease-key)
void insert_or_decrease(MinHeap* heap, int vertex, int distance) {
    // Check if vertex already in heap
    for (int i = 0; i < heap->size; i++) {
        if (heap->nodes[i].vertex == vertex && distance < heap->nodes[i].distance) {
            heap->nodes[i].distance = distance;
            // Bubble up (simplified decrease-key)
            int parent = (i - 1) / 2;
            while (i > 0 && heap->nodes[parent].distance > heap->nodes[i].distance) {
                swap(&heap->nodes[i], &heap->nodes[parent]);
                i = parent;
                parent = (i - 1) / 2;
            }
            return;
        }
    }
    // Insert new
    if (heap->size < heap->capacity) {
        heap->nodes[heap->size].vertex = vertex;
        heap->nodes[heap->size].distance = distance;
        int i = heap->size++;
        int parent = (i - 1) / 2;
        while (i > 0 && heap->nodes[parent].distance > heap->nodes[i].distance) {
            swap(&heap->nodes[i], &heap->nodes[parent]);
            i = parent;
            parent = (i - 1) / 2;
        }
    }
}

// Extract min
PQNode extract_min(MinHeap* heap) {
    PQNode min = heap->nodes[0];
    heap->nodes[0] = heap->nodes[--heap->size];
    min_heapify(heap, 0);
    return min;
}

// Dijkstra's algorithm
void dijkstra(Graph* graph, int src, int* distances) {
    bool* visited = (bool*)calloc(graph->num_vertices, sizeof(bool));
    MinHeap* pq = create_min_heap(graph->num_vertices);

    for (int i = 0; i < graph->num_vertices; i++) {
        distances[i] = INT_MAX;
    }
    distances[src] = 0;
    insert_or_decrease(pq, src, 0);

    while (pq->size > 0) {
        PQNode min_node = extract_min(pq);
        int u = min_node.vertex;

        if (visited[u]) continue;
        visited[u] = true;

        // Relax neighbors
        for (int i = 0; i < graph->adj_sizes[u]; i += 2) {
            int v = graph->adj_list[u][i];
            int weight = graph->adj_list[u][i + 1];
            if (!visited[v] && distances[u] != INT_MAX && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                insert_or_decrease(pq, v, distances[v]);
            }
        }
    }

    free(visited);
    free(pq->nodes);
    free(pq);
}

// Free graph
void free_graph(Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        free(graph->adj_list[i]);
    }
    free(graph->adj_list);
    free(graph->adj_sizes);
    free(graph);
}

// Main function with example
int main() {
    Graph* graph = create_graph(5);  // 5 vertices

    // Add edges (undirected)
    add_edge(graph, 0, 1, 10);
    add_edge(graph, 0, 3, 5);
    add_edge(graph, 1, 2, 1);
    add_edge(graph, 2, 3, 1);
    add_edge(graph, 3, 4, 3);

    int* distances = (int*)malloc(graph->num_vertices * sizeof(int));
    dijkstra(graph, 0, distances);  // Start from vertex 0

    printf("Shortest distances from 0:\n");
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("To %d: %d\n", i, distances[i]);
    }

    free(distances);
    free_graph(graph);
    return 0;
}