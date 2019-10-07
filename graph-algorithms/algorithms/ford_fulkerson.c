#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../includes/builder.h"
#include "../includes/pqueue.h"

/****************************

Phyllipe Matheus Bezerra Alves
Universidade Federal de Alagoas
Ciencia da Computacao

*****************************/

#define DEBUG if(0)
#define min(a, b) a <= b ? a : b

int bfs(AMGraph* graph, int source, int sink, int* parent);
int fordFulkerson(AMGraph* graph, int source, int sink);

int main(int argc, char const *argv[])
{
    AMGraph* graph = createAMGraphFromInput();

    printAMGraph(graph);

    int ini, end;

    scanf("%d %d", &ini, &end);

    int MF = fordFulkerson(graph, ini, end);
    
    printf("\nFrom %d to %d:\n", ini, end);
    printf("Max Flow: %d\n", MF);

    return 0;
}

int bfs(AMGraph* graph, int source, int sink, int* parent) {

    int V = graph->V;
    int visited[V];
    int i;

    for (i = 0; i < V; ++i) visited[i] = 0;

    PriorityQueue* queue = createPriorityQueue();
    enqueue(queue, (void*)source, 0);
    visited[source] = 1;

    while (!isPQEmpty(queue)) {

        QueueNode* qnode = dequeue(queue);
        int current_parent = ((int) qnode->item);

        int current_w;

        for (int i = 0; i < V; ++i) {

            if (graph->matrix[current_parent][i] != -1) {
                current_w = graph->matrix[current_parent][i];

                if (!visited[i] && current_w > 0) {
                    enqueue(queue, (void *) i, 0);
                    visited[i] = 1;
                    parent[i] = current_parent;
                }
            }
        }

        // while (current_node != NULL) {

        //     if (!visited[current_node->vertex] && current_node->weight > 0) {
        //         enqueue(queue, (void*)current_node->vertex, 0);
        //         visited[current_node->vertex] = 1;
        //         parent[current_node->vertex] = current_parent;
        //     }

        //     current_node = current_node->next;
        // }
    }

    return visited[sink];
}

int fordFulkerson(AMGraph* graph, int source, int sink) {

    int V = graph->V;
    int *parent = malloc(V * sizeof(int));
    int i, max_flow;

    for (i = 0; i < V; ++i) parent[i] = -1;

    max_flow = 0;

    while (bfs(graph, source, sink, parent)) {

        int path_flow = (int) INFINITY;
        int S = sink;

        while (S != source) {

            path_flow = min(path_flow, graph->matrix[parent[S]][S]);
            S = parent[S];
        }

        max_flow += path_flow;

        int U;
        S = sink;
        while (S != source) {

            U = parent[S];
            graph->matrix[U][S] -= path_flow;
            graph->matrix[S][U] += path_flow;
            S = U;
        }
    }

    return max_flow;
}