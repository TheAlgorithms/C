#include <stdlib.h>
 
typedef struct {
    unsigned int first;
    unsigned int second;
    unsigned int weight;
} weighted_edge;
 
unsigned int kruskal(weighted_edge *edges, unsigned int size, unsigned int order,
        weighted_edge **mst)
{
    *mst = malloc((order - 1) * sizeof(weighted_edge));
    unsigned int *vertices = malloc(order * sizeof(unsigned int));
    unsigned int i;
    unsigned int cost = 0;
    if (*mst == NULL || vertices == NULL) {
        free(*mst);
        free(vertices);
        return 0;
    }
    /* Each vertex starts off in its own tree */
    for (i = 0; i < order; i++) {
        vertices[i] = i;
    }
    /* Sort the edges by weight */
    qsort(edges, size, sizeof(weighted_edge), 
            (int(*)(const void *, const void *))weighted_edge_compare);
    /* Main loop */
    for (i = 0; i < order - 1; i++) {
        /* Find the cheapest edge with endpoints in different trees */
        unsigned int j;
        int cheapest = -1;
        for (j = 0; j < size && cheapest == -1; j++) {
            if (vertices[edges[j].first] != vertices[edges[j].second]) {
                cheapest = j;
            }
        }
        if (cheapest == -1) {
            /* Graph wasn't connected properly */
            free(*mst);
            *mst = NULL;
            free(vertices);
            return 0;
        }
        /* Add the edge */
        (*mst)[i] = edges[cheapest];
        /* Merge the trees it joins */
        for (j = 0; j < order; j++) {
            if (vertices[j] == edges[cheapest].second) {
                vertices[j] = edges[cheapest].first;
            }
        }
        /* Add the cost */
        cost += edges[cheapest].weight;
    }
    free(vertices);
    return cost;
}
/* Construct a complete weighted graph on v vertices */
unsigned int complete_weighted_graph(unsigned int v, weighted_edge **edges)
{
    const unsigned int n = triangular_number(v - 1);
    unsigned int i, j, k;
    *edges = malloc(n * sizeof(weighted_edge));
    if (edges != NULL) {
        for (i = 0, k = 0; i < v - 1; i++) {
            for (j = i + 1; j < v; j++) {
                (*edges)[k].first = i;
                (*edges)[k].second = j;
                (*edges)[k].weight = k + 1;
                k++;
            }
        }
    }
    return n;
}
 
void print_edges(const weighted_edge *edges, unsigned int n)
{
    unsigned int e;
    for (e = 0; e < n; e++) {
        printf("(%u, %u, %u) ", edges[e].first, edges[e].second, edges[e].weight);
    }
    putchar('\n');
}
 
int main(void)
{
    weighted_edge *edges;
    const unsigned int order = 5;
    const unsigned int size = complete_weighted_graph(order, &edges);
    weighted_edge *mst;
    unsigned int cost = kruskal(edges, size, order, &mst);
    printf("Cost is %u\n", cost);
    print_edges(mst, order - 1);
    free(mst);
    free(edges);
    return 0;
}
