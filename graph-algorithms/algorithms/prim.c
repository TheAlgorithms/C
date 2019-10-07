#include <stdio.h>
#include <stdlib.h>

#include "../includes/builder.h"
#include "../includes/pqueue.h"

/****************************

Phyllipe Matheus Bezerra Alves
Universidade Federal de Alagoas
Ciencia da Computacao

*****************************/

#define DEBUG if(0)

ALGraph* prim(ALGraph* graph, int ini);

int main(int argc, char const *argv[])
{
    ALGraph* graph = createALGraphFromInput();

    ALGraph* MST = prim(graph, 0);
    printALGraph(MST);

    return 0;
}

ALGraph* prim(ALGraph* graph, int ini) {

    int V = graph->V;
    int visited[V];
    int i, cost;

    for (i = 0; i < V; ++i) {
        visited[i] = 0;
    }

    ALGraph* MST = createALGraph(V);
    PriorityQueue* queue = createPriorityQueue();
    visited[ini] = 1;

    cost = 0;
    int *edge = malloc(2 * sizeof(int));
    edge[0] = 0;
    edge[1] = ini;

    enqueue(queue, (void*) edge, 0);

    while (!isPQEmpty(queue)) {

        QueueNode* current = dequeue(queue);
        void* deqEdge = current->item;
        int from = ((int*)deqEdge)[0];
        int to = ((int*)deqEdge)[1];
        int weight = current->priority;

        if (!visited[to]) {
            visited[to] = 1;
            cost += weight;
            addALEdge(MST, from, to, weight);
            addALEdge(MST, to, from, weight);
        }

        Node* neighbor = graph->adjList[to];

        while (neighbor != NULL) {
            if (!visited[neighbor->vertex]) {
                int *E = malloc(2 * sizeof(int));
                E[0] = to;
                E[1] = neighbor->vertex;

                enqueue(queue, (void*) E, neighbor->weight);
            }

            neighbor = neighbor->next;
        }
    }

    printf("MST Cost: %d\n", cost);
    return MST;
}