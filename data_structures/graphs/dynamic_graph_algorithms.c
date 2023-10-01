// The code represents a basic dynamic graph in C, which can grow and change over time. It allows you to add and remove connections (edges) between points (vertices) in the graph. 
// This is useful for modeling and solving problems that involve changing relationships between objects, like social networks or transportation systems.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** adjacencyList;
};

struct Graph* createGraph(int V);
void addEdge(struct Graph* graph, int src, int dest);
void removeEdge(struct Graph* graph, int src, int dest);
void printGraph(struct Graph* graph);

int main() {
    int V = 5; // Number of vertices
    struct Graph* graph = createGraph(V);

    // Add edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);

    // Print the initial graph
    printf("Initial Graph:\n");
    printGraph(graph);

    // Remove an edge
    removeEdge(graph, 0, 2);

    // Print the modified graph
    printf("\nGraph after removing edge:\n");
    printGraph(graph);

    return 0;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adjacencyList = (struct Node**)malloc(sizeof(struct Node*) * V);

    for (int i = 0; i < V; i++) {
        graph->adjacencyList[i] = NULL;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = dest;
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;
}

void removeEdge(struct Graph* graph, int src, int dest) {
    struct Node* current = graph->adjacencyList[src];
    struct Node* prev = NULL;

    while (current != NULL && current->data != dest) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Edge does not exist.\n");
        return;
    }

    if (prev == NULL) {
        graph->adjacencyList[src] = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}

void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        struct Node* current = graph->adjacencyList[i];
        printf("Vertex %d:", i);
        while (current != NULL) {
            printf(" -> %d", current->data);
            current = current->next;
        }
        printf("\n");
    }
}
