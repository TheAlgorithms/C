#include <stdio.h>
#include <stdlib.h>

#include "../includes/graph.h"

/*-----------------------------------------------------------------
    ADJACENT LIST GRAPH
-----------------------------------------------------------------*/

Node* createNode(int V, int W) {

    Node* new_node = malloc(sizeof(Node));

    new_node->vertex = V;
    new_node->weight = W;
    new_node->next = NULL;

    return new_node;
}

ALGraph* createALGraph(int V) {
    
    ALGraph* graph = malloc(sizeof(ALGraph));
    graph->V = V;

    graph->adjList = malloc(V * sizeof(Node*));

    int i;

    for (i = 0; i < V; ++i) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

void addALEdge(ALGraph* graph, int ini, int end, int w) {

    Node* new_node = createNode(end, w);
    new_node->next = graph->adjList[ini];
    graph->adjList[ini] = new_node;
}

void printALGraph(ALGraph* graph) {

    int vertex;

    for (vertex = 0; vertex < graph->V; ++vertex) {

        Node* temp = graph->adjList[vertex];

        printf("%d -> ", vertex);

        while (temp) {

            printf("(%d, %d) ", temp->vertex, temp->weight);
            temp = temp->next;
        }

        printf("\n");
    }
}

int getNeighbourWeight(ALGraph* graph, int V, int N) {
    Node* adjList = graph->adjList[V];

    while (adjList != NULL) {
        if (adjList->vertex == N) return adjList->weight;
        adjList = adjList->next;
    }

    return -1;
}

/*-----------------------------------------------------------------
    ADJACENT MATRIX GRAPH
-----------------------------------------------------------------*/

AMGraph* createAMGraph(int V) {

    AMGraph* graph = malloc(sizeof(AMGraph));

    graph->V = V;
    graph->matrix = malloc(V * sizeof(int*));

    int i, j;

    for (i = 0; i < V; ++i) {
        graph->matrix[i] = malloc(V * sizeof(int));
        
        for (j = 0; j < V; ++j) {
            graph->matrix[i][j] = -1;
        }
    }

    return graph;
}

void addAMEdge(AMGraph* graph, int ini, int end, int w) {
    graph->matrix[ini][end] = w;
}

void printAMGraph(AMGraph* graph) {
    int i, j;

    for (i = 0; i < graph->V; ++i) {
        printf("%d -> ", i);
        for (j = 0; j < graph->V; ++j) {
            if (graph->matrix[i][j] != -1) printf("(%d, %d) ", j, graph->matrix[i][j]);
        }
        printf("\n");
    }
}
