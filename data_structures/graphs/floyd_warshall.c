#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing a graph
struct Graph
{
    int vertexNum;
    int **edges;
};

// Constructs a graph with V vertices and E edges
void createGraph(struct Graph *G, int V)
{
    G->vertexNum = V;
    G->edges = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
    {
        G->edges[i] = (int *)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) G->edges[i][j] = INT_MAX;
        G->edges[i][i] = 0;
    }
}

// Adds the given edge to the graph
void addEdge(struct Graph *G, int src, int dst, int weight)
{
    G->edges[src][dst] = weight;
}

// Utility function to print distances
void print(int dist[], int V)
{
    printf("\nThe Distance matrix for Floyd - Warshall\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i * V + j] != INT_MAX)
                printf("%d\t", dist[i * V + j]);
            else
                printf("INF\t");
        }
        printf("\n");
    }
}

// The main function that finds the shortest path from a vertex
// to all other vertices using Floyd-Warshall Algorithm.
void FloydWarshall(struct Graph *graph)
{
    int V = graph->vertexNum;
    int dist[V][V];

    // Initialise distance array
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) dist[i][j] = graph->edges[i][j];

    // Calculate distances
    for (int k = 0; k < V; k++)
        // Choose an intermediate vertex

        for (int i = 0; i < V; i++)
            // Choose a source vertex for given intermediate

            for (int j = 0; j < V; j++)
                // Choose a destination vertex for above source vertex

                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
                    dist[i][k] + dist[k][j] < dist[i][j])
                    // If the distance through intermediate vertex is less than
                    // direct edge then update value in distance array
                    dist[i][j] = dist[i][k] + dist[k][j];

    // Convert 2d array to 1d array for print
    int dist1d[V * V];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) dist1d[i * V + j] = dist[i][j];

    print(dist1d, V);
}

// Driver Function
int main()
{
    int V, E;
    int src, dst, weight;
    struct Graph G;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);
    createGraph(&G, V);
    for (int i = 0; i < E; i++)
    {
        printf("\nEdge %d \nEnter source: ", i + 1);
        scanf("%d", &src);
        printf("Enter destination: ");
        scanf("%d", &dst);
        printf("Enter weight: ");
        scanf("%d", &weight);
        addEdge(&G, src, dst, weight);
    }
    FloydWarshall(&G);

    return 0;
}
