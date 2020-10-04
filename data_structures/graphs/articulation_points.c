#include <malloc.h>
#include <stdio.h>

#include "Graph.h"

#define MIN(x, y) (((x) < (y)) ? (x) : (y))
int *articulation_point(Graph g);
int *aux_function(Graph g, Vertex v, Vertex p, int *iscutpoint);

int *visited;
int *tin, *low;
int timer = 0;

int main(void)
{
    int nV = 10;
    Graph g = newGraph(nV);
    Edge e;
    e.v = 0;
    e.w = 1;
    insertEdge(g, e);
    e.v = 0;
    e.w = 2;
    insertEdge(g, e);
    e.v = 0;
    e.w = 5;
    insertEdge(g, e);
    e.v = 1;
    e.w = 5;
    insertEdge(g, e);
    e.v = 2;
    e.w = 3;
    insertEdge(g, e);
    e.v = 3;
    e.w = 4;
    insertEdge(g, e);
    e.v = 3;
    e.w = 5;
    insertEdge(g, e);
    e.v = 3;
    e.w = 8;
    insertEdge(g, e);
    e.v = 4;
    e.w = 5;
    insertEdge(g, e);
    e.v = 4;
    e.w = 7;
    insertEdge(g, e);
    e.v = 4;
    e.w = 8;
    insertEdge(g, e);
    e.v = 5;
    e.w = 6;
    insertEdge(g, e);
    e.v = 7;
    e.w = 8;
    insertEdge(g, e);
    e.v = 7;
    e.w = 9;
    insertEdge(g, e);
    e.v = 8;
    e.w = 9;
    insertEdge(g, e);
    int *iscutpoint = articulation_point(g);
    return 0;
}

int *articulation_point(Graph g)
{
    /* get the unweigted graph g and return the articulation point*/
    /* set the variables and allocate mamory */
    int nV = g->nV;
    int *iscutpoint = NULL;
    visited = (int *)malloc(nV * sizeof(int));
    for (int v = 0; v < nV; v++) visited[v] = 0;
    tin = (int *)malloc(nV * sizeof(int));
    low = (int *)malloc(nV * sizeof(int));
    iscutpoint = (int *)malloc(nV * sizeof(int));
    for (int v = 0; v < nV; v++) iscutpoint[v] = 0;
    for (int i = 0; i < nV; i++)
    {
        if (visited[i] == 0)
            iscutpoint = aux_function(g, i, -1, iscutpoint);
    }
    return iscutpoint;
}

int *aux_function(Graph g, Vertex v, Vertex p, int *iscutpoint)
{
    int children = 0;
    visited[v] = 1;
    timer++;
    tin[v] = timer;
    low[v] = timer;
    int nV = g->nV;
    for (int i = 0; i < nV; i++)
    {
        /* go only through the vertices adjacent to v*/
        if (g->edges[i][v] != 0)
        {
            if (i == p)
                continue;
            if (visited[i])
                low[v] = MIN(low[v], tin[i]);
            else
            {
                aux_function(g, i, v, iscutpoint);
                low[v] = MIN(low[v], low[i]);
                if ((low[i] >= tin[v]) && (p != -1))
                    iscutpoint[v] = 1;
                children++;
            }
        }
    }
    if ((p == -1) && (children > 1))
        iscutpoint[v] = 1;
    return iscutpoint;
}
