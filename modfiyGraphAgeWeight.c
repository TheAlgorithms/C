#include <stdio.h>

#define MAX_DATA_POINTS 100

// Define a structure to represent a data point (age and weight)
struct DataPoint {
    int age;
    double weight;
};

// Define a structure to represent the graph
struct Graph {
    struct DataPoint data[MAX_DATA_POINTS];
    int size;
};

// Initialize the graph
void initializeGraph(struct Graph *graph) {
    graph->size = 0;
}

// Add a new data point to the graph
void addDataPoint(struct Graph *graph, int age, double weight) {
    if (graph->size < MAX_DATA_POINTS) {
        graph->data[graph->size].age = age;
        graph->data[graph->size].weight = weight;
        graph->size++;
    } else {
        printf("Graph is full. Cannot add more data points.\n");
    }
}

// Modify the weight for a specific age
void modifyWeight(struct Graph *graph, int age, double newWeight) {
    for (int i = 0; i < graph->size; i++) {
        if (graph->data[i].age == age) {
            graph->data[i].weight = newWeight;
            return; // Exit the loop once the modification is done
        }
    }
    printf("Age not found in the graph.\n");
}

int main() {
    struct Graph ageWeightGraph;
    initializeGraph(&ageWeightGraph);

    // Add some data points
    addDataPoint(&ageWeightGraph, 25, 70.5);
    addDataPoint(&ageWeightGraph, 30, 80.2);
    addDataPoint(&ageWeightGraph, 35, 90.0);

    // Modify the weight for age 30
    modifyWeight(&ageWeightGraph, 30, 85.5);

    // Display the graph
    printf("Age   Weight\n");
    for (int i = 0; i < ageWeightGraph.size; i++) {
        printf("%d     %.1lf\n", ageWeightGraph.data[i].age, ageWeightGraph.data[i].weight);
    }

    return 0;
}
