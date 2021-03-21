/**
 * @file
 * @author [Timothy Maloney] (https://github.com/sl1mb0)
 * @brief [Prim's algorithm] (https://en.wikipedia.org/wiki/Prim%27s_algorithm)
 * implementation of prim's algorithm in C to find the MST of a weighted, connected graph.
 * @details Prim's algorithm uses a greedy approach to generate the MST of a weighted connected graph.
 * The algorithm begins at an arbitrary vertex v, and selects a next vertex u, 
 * where v and u are connected by a weighted edge whose weight is the minimum of all edges connected to v. 
 * @references Page 319 "Introduction to the Design and Analysis of Algorithms" - Anany Levitin
 * To test - enter following adjacency matrix for a  weighted connected graph:
 *	  
 *	  0  1  2  3
 *        1  0  4  6
 *        2  4  0  5
 *        3  6  5  0
 *
 * The minimum spanning tree for the above weighted connected graph is given by the following adj matrix:
 *	   
 *	  0  1  3  2
 *	  1  0  0  0
 *	  3  0  0  0
 *	  2  0  0  0
 *
 * The following link provides a visual representation of graphs that can be used to test / verify the algorithm for adj
 * matrices of other weighted, connected graphs.
 * (https://visualgo.net/en/mst)
 */

#include <stdio.h>
#include <assert.h>

#define MAX 20
#define INF 999

int G[MAX][MAX];    // weighted, connected graph G
int MST[MAX][MAX];  // adj matrix to hold minimum spanning tree of G
int V;              // number of vertices in V in G

/**
 * @brief Function minimum
 * Returns index of minimum element in array composed of edges connected to arbitrary vertex
 * @param arr graph row
 * @param N number of elements in arr
 * @returns index of minimum element in arr
 */
int minimum(int arr[], int N)
{
    int index = 0;
    int min = INF;

    for (int i = 0; i < N; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            index = i;
        }
    }
    return index;
}

/**
 * @brief Function prim
 * Used to find MST of user-generated adj matrix G
 * @returns void
 */
void prim()
{
    int u, v;
    int E_t[MAX], path[MAX];
    int V_t[MAX], no_of_edges;

    E_t[0] = 0;  // edges for current vertex
    V_t[0] = 1;  // list of visited vertices

    for (int i = 1; i < V; i++)
    {
        E_t[i] = G[i][0];
        path[i] = 0;
        V_t[i] = 0;
    }

    no_of_edges = V - 1;

    while (no_of_edges > 0)
    {
        u = minimum(E_t, V);
        while (V_t[u] == 1)
        {
            E_t[u] = INF;
            u = minimum(E_t, V);
        }

        v = path[u];
        MST[u][v] = E_t[u];
        MST[v][u] = E_t[u];
        no_of_edges--;
        V_t[u] = 1;

        for (int i = 1; i < V; i++)
        {
            if (V_t[i] == 0 && G[u][i] < E_t[i])
            {
                E_t[i] = G[u][i];
                path[i] = v;
            }
        }
    }
}

/**
 * @brief Function test
 * @returns 0 on exit
 */


/**
 * @brief Main function
 * @returns 0 on exit
 */
int main(int argc, char const *argv[])
{
    printf("Enter the number of vertices: ");
    scanf(" %d", &V);
    printf("Enter the adj matrix\n");
    int i, j;
    for (i = 0; i < V; ++i)
    {
        for (j = 0; j < V; ++j)
        {
            printf("G[%d][%d]: ", i, j);
            scanf(" %d", &G[i][j]);
            if (G[i][j] == 0)
                G[i][j] = INF;
        }
    }

    prim();

    printf("minimum spanning tree:\n");
    for (i = 0; i < V; ++i)
    {
        printf("\n");
        for (j = 0; j < V; ++j)
        {
            printf("%d\t", MST[i][j]);
        }
    }

    return 0;
}
