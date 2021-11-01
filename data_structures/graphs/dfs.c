#include <stdio.h>
#include <stdlib.h>

// A vertex of the graph
struct node
{
    int vertex;
    struct node *next;
};
// Some declarations
struct node *createNode(int v);
struct Graph
{
    int numVertices;
    int *visited;
    struct node *
        *adjLists;  // we need int** to store a two dimensional array. Similary,
                    // we need struct node** to store an array of Linked lists
};
struct Graph *createGraph(int);
void addEdge(struct Graph *, int, int);
void printGraph(struct Graph *);
void dfs(struct Graph *, int);

int main()
{
    int vertices, edges, source, i, src, dst;
    printf("Enter the number of vertices\n");
    scanf("%d", &vertices);
    struct Graph *graph = createGraph(vertices);
    printf("Enter the number of edges\n");
    scanf("%d", &edges);
    for (i = 0; i < edges; i++)
    {
        printf("Edge %d \nEnter source: ", i + 1);
        scanf("%d", &src);
        printf("Enter destination: ");
        scanf("%d", &dst);
        addEdge(graph, src, dst);
    }
    printf("Enter source of DFS\n");
    scanf("%d", &source);
    printf("DFS from %d is:\n", source);
    dfs(graph, source);
    printf("\n");

    // Uncomment below part to get a ready-made example
    /*struct Graph* graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    printf("DFS from 0 is:\n");
    dfs(graph,0);
    printf("\n");*/

    return 0;
}
// Recursive dfs approach
void dfs(struct Graph *graph, int vertex)
{
    struct node *adjList = graph->adjLists[vertex];
    struct node *temp = adjList;

    // Add vertex to visited list and print it
    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    // Recursively call the dfs function on all unvisited neighbours
    while (temp != NULL)
    {
        int connectedVertex = temp->vertex;
        if (graph->visited[connectedVertex] == 0)
        {
            dfs(graph, connectedVertex);
        }
        temp = temp->next;
    }
}
// Allocate memory for a node
struct node *createNode(int v)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
// Allocate memory for the entire graph structure
struct Graph *createGraph(int vertices)
{
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct node *));

    graph->visited = malloc(vertices * sizeof(int));

    int i;
    for (i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}
// Creates a bidirectional graph
void addEdge(struct Graph *graph, int src, int dest)
{
    // Add edge from src to dest
    struct node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}
// Utility function to see state of graph at a given time
void printGraph(struct Graph *graph)
{
    int v;
    for (v = 0; v < graph->numVertices; v++)
    {
        struct node *temp = graph->adjLists[v];
        printf("\n Adjacency list of vertex %d\n ", v);
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}
