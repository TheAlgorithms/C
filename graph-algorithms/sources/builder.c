#include <stdio.h>
#include "../includes/builder.h"

ALGraph* createALGraphFromInput() {
    int V, E, D;

    scanf("%d %d %d", &V, &E, &D);

    int i;
    int ini, end, weight;

    ALGraph* graph = createALGraph(V);

    if (D == 0) {
        for (i = 0; i < E; ++i) {
            scanf("%d %d %d", &ini, &end, &weight);

            addALEdge(graph, ini, end, weight);
            addALEdge(graph, end, ini, weight);
        }
    } else {
        for (i = 0; i < E; ++i) {
            scanf("%d %d %d", &ini, &end, &weight);

            addALEdge(graph, ini, end, weight);
        }
    }

    return graph;
}

AMGraph* createAMGraphFromInput() {
    int V, E, D;

    scanf("%d %d %d", &V, &E, &D);

    int i;
    int ini, end, weight;

    AMGraph* graph = createAMGraph(V);

    if (D == 0) {

        for (i = 0; i < E; ++i) {
            scanf("%d %d %d", &ini, &end, &weight);

            addAMEdge(graph, ini, end, weight);
            addAMEdge(graph, end, ini, weight);
        }
    } else {
        for (i = 0; i < E; ++i) {
            scanf("%d %d %d", &ini, &end, &weight);

            addAMEdge(graph, ini, end, weight);
        }
    }

    return graph;
}