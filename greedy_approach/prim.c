/**
 * prim.c
 * implementation of prim's algorithm to find the MST of a weighted, connected
 * graph. Author: sl1mb0 [Timothy Maloney] (https://github.com/sl1mb0) Date:
 * 03/18/21 References: page 319 "Introduction to the Design and Analysis of
 * Algorithms" - Anany Levitin
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 20
#define INF 999

int G[MAX][MAX];
int MST[MAX][MAX];
int V;

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
