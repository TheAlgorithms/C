#ifndef GRAPH_H
#define GRAPH_H

/*-----------------------------------------------------------------
    ADJACENT LIST GRAPH
-----------------------------------------------------------------*/

typedef struct node 
{
    int vertex;
    int weight;
    struct node* next;
} Node;

typedef struct al_graph
{
    int V;
    Node** adjList;
} ALGraph;

Node* createNode(int V, int W);

ALGraph* createALGraph(int V);
void addALEdge(ALGraph* graph, int ini, int end, int w);
void printALGraph(ALGraph* graph);
int getNeighbourWeight(ALGraph* graph, int V, int N);

/*-----------------------------------------------------------------
    ADJACENT MATRIX GRAPH
-----------------------------------------------------------------*/

typedef struct am_graph
{
    int V;
    int** matrix;
} AMGraph;

AMGraph* createAMGraph(int V);
void addAMEdge(AMGraph* graph, int ini, int end, int w);
void printAMGraph(AMGraph* graph);

#endif