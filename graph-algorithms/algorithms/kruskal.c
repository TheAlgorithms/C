#include <stdio.h>
#include <stdlib.h>

#include "../includes/builder.h"
#include "../includes/union_find.h"
#include "../includes/pqueue.h"

/****************************

Phyllipe Matheus Bezerra Alves
Universidade Federal de Alagoas
Ciencia da Computacao

*****************************/

ALGraph* kruskal(ALGraph* graph);

int main(int argc, char const *argv[])
{
    ALGraph* graph = createALGraphFromInput();

    ALGraph* MST = kruskal(graph);

    printALGraph(MST);
    
    return 0;
}

ALGraph* kruskal(ALGraph* graph) {

    int V, i, cost;

    cost = 0;
    V = graph->V;

    PriorityQueue* queue = createPriorityQueue();
    UnionFind union_find = createUnionFind(V);

    ALGraph* MST = createALGraph(V);

    for (i = 0; i < V; ++i) {
        Node* current = graph->adjList[i];

        while (current != NULL) {
            int *edge = malloc(2 * sizeof(int));
            edge[0] = i;
            edge[1] = current->vertex;
            
            enqueue(queue, (void*) edge, current->weight);
            current = current->next;
        }
    }


    while (!isPQEmpty(queue)) {
        QueueNode* elToAdd = dequeue(queue);
        void* edge = elToAdd->item;
        int weight = elToAdd->priority;

        if (!isSameSet(union_find, ((int*)edge)[0], ((int*)edge)[1])) {
            cost += weight;
            addALEdge(MST, ((int*)edge)[0], ((int*)edge)[1], weight);
            addALEdge(MST, ((int*)edge)[1], ((int*)edge)[0], weight);
            mergeSets(union_find, ((int*)edge)[0], ((int*)edge)[1]);
        }
    }

    printf("MST Cost: %d\n", cost);

    return MST;
}
