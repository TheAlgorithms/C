#include <stdio.h>
#include <math.h>

#include "../includes/builder.h"
#include "../includes/pqueue.h"

/****************************

Phyllipe Matheus Bezerra Alves
Universidade Federal de Alagoas
Ciencia da Computacao

*****************************/

int dijkstra(ALGraph* graph, int ini, int end);

int main(int argc, char const *argv[])
{
    ALGraph* graph = createALGraphFromInput();

    printALGraph(graph);

    int ini, end;

    scanf("%d %d", &ini, &end);

    int shortest_path = dijkstra(graph, ini, end);
    
    if (shortest_path == -1) {
        printf("\n[%d -> %d] Could not found any path.\n", ini, end);
    }

    return 0;
}

int dijkstra(ALGraph* graph, int ini, int end) {

    int V = graph->V;
    int distance[V];
    int visited[V];
    int i;

    for (i = 0; i < V; ++i) {
        distance[i] = (int) INFINITY;
        visited[i] = 0;
    }

    PriorityQueue* queue = createPriorityQueue();

    distance[ini] = 0;
    visited[ini] = 1;

    enqueue(queue, (void*) ini, 0);

    QueueNode* current = dequeue(queue);

    while (current != NULL) {

        int current_distance, current_vertex;
        current_distance = current->priority;
        current_vertex = (int) current->item;

        visited[current_vertex] = 1;

        if (current_vertex == end) {

            printf("\nFrom %d to %d with cost %d.\n", ini, end, current_distance);
            return current_distance;
        }
        
        Node* vertex_adj_head = graph->adjList[current_vertex];

        // printf("(%d, %d)\n", current_vertex, current_distance);

        while (vertex_adj_head != NULL) {
            
            if (visited[vertex_adj_head->vertex] == 0) {
                
                if (current_distance + vertex_adj_head->weight < distance[vertex_adj_head->vertex]) {
                    
                    distance[vertex_adj_head->vertex] = current_distance + vertex_adj_head->weight;
                    enqueue(queue, (void*) vertex_adj_head->vertex, distance[vertex_adj_head->vertex]);
                
                }
            }

            vertex_adj_head = vertex_adj_head->next;
        }

        current = dequeue(queue);
    }

    return -1;
}