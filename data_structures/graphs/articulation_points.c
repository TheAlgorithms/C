/**
 * @file
 * @brief implementation of the articulation_point
 * @details
 * A vertex in an undirected connected graph is an articulation point (or cut
 * vertex) iff removing it (and edges through it) disconnects the graph.
 * Articulation points represent vulnerabilities in a connected network – single
 * points whose failure would split the network into 2 or more components. They
 * are useful for designing reliable networks. For a disconnected undirected
 * graph, an articulation point is a vertex removing which increases number of
 * connected components. for more information see
 * (https://www.geeksforgeeks.org/articulation-points-or-cut-vertices-in-a-graph)
 * @author [Guy Rozenberg](https://github.com/guyroznb)
 **/

#include <malloc.h>
#include <stdio.h>

#include "Graph.h"

#define MIN(x, y) (((x) < (y)) ? (x) : (y))
int *articulation_point(Graph g);
int *aux_function(Graph g, Vertex v, Vertex p, int *iscutpoint);

// set up global variables
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
    /* get the unweigted graph g and return the articulation points list*/

    /* set the variables and allocate mamory */
    int nV = g->nV;
    int *iscutpoint = NULL;
    visited = (int *)malloc(nV * sizeof(int));

    // mark all the vertices as unvisited
    for (int v = 0; v < nV; v++) visited[v] = 0;
    tin = (int *)malloc(nV * sizeof(int));
    low = (int *)malloc(nV * sizeof(int));
    iscutpoint = (int *)malloc(nV * sizeof(int));
    for (int v = 0; v < nV; v++) iscutpoint[v] = 0;

    // go through all the vertex in the graph and check if they arn't visited.
    // If not then use DFS auxillary function and find the cut vertices
    for (int i = 0; i < nV; i++)
    {
        if (visited[i] == 0)
            iscutpoint = aux_function(g, i, -1, iscutpoint);
    }
    return iscutpoint;
}

int *aux_function(Graph g, Vertex v, Vertex p, int *iscutpoint)
{
    /* A recursive auxillary function that find articulation points using DFS
    traversal v --> the tested vertex p --> the parent of v visited[] --> keeps
    tract of visited vertices tin --> Stores discovery times of visited vertices
    iscutpoint[] --> Store articulation points
    children --> counts the number of chilrders of vertex v
    low[u] = min(tin[u], tin[w])  where w is an ancestor of u and there is a
    back edge in the graph from some descendant of u to w.
    */
    int children = 0;
    visited[v] = 1;
    timer++;
    tin[v] = timer;
    low[v] = timer;
    int nV = g->nV;
    /* go only through the vertices adjacent to v*/
    for (int i = 0; i < nV; i++)
    {
        // Go through all vertices adjaecnt to v
        if (g->edges[i][v] != 0)
        {
            // if the vertex is the parent then continue
            if (i == p)
                continue;

            // Update low value of u for parent function calls.
            if (visited[i])
                low[v] = MIN(low[v], tin[i]);

            // // If i is not visited yet, then make it a child of u in DFS tree
            // and continue with the dfs
            else
            {
                aux_function(g, i, v, iscutpoint);

                // Check if the subtree rooted with v has a connection to one of
                // the ancestors of v
                low[v] = MIN(low[v], low[i]);

                // If v is not root and low value of one of its child is more
                // than discovery value of v, v is an articulation point
                if ((low[i] >= tin[v]) && (p != -1))
                    iscutpoint[v] = 1;
                children++;
            }
        }
    }

    // v is root of DFS tree and has two or more chilren then it is an
    // articulation point
    if ((p == -1) && (children > 1))
        iscutpoint[v] = 1;
    return iscutpoint;
}
