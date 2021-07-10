/*
Input format:
    First line would contain number n, which represents number of nodes in the graph (1 to n).
    Next n line would represent cost matrix. Where each line, representing a distance vector for that node, will have n numbers (separated by space) to represent direct distance from that node to all other nodes.
    Distance from node to itself and to the non-adjacent node must be 0.
Last line would contain the starting node.

Output format:
    Output is n-1 lines containing the edge and weight of that edge (separated by tab) which is included in the minimum spanning tree.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;

typedef struct Edge 
{
    Node* dest;
    int weight;
}Edge;

struct Node {
    int data;
    Edge** adj_list;
    int connected_vertices;
    int isVisited;
    int weight;
    Node* parent;
};


Edge* createEdge(Node* Dest,int weight){

    Edge* new_Edge = (Edge*)malloc(sizeof(Edge));
    new_Edge->dest = Dest;
    new_Edge->weight = weight;

    return new_Edge;
}

void addEdge(Node* src,int weight,Node* Dest){
    
        Edge* new_Edge = createEdge(Dest,weight);
        src->adj_list[src->connected_vertices++] = new_Edge;

}



void prim(Node** vertices,int N){

    int no_edge=0;
    while (no_edge < N - 1) 
    {

        int min = 999999;
        Node* next;
        int y = 0;

        for (int i = 0; i < N; i++) 
        {
            Node* check = vertices[i];
            if (check->isVisited) 
            {
                for (int j = 0; j < N; j++) 
                {
                    Edge* E = check->adj_list[j];
                    if (E->weight != 0) 
                    {

                        if (!E->dest->isVisited && min >= E->weight) 
                        {
                            min = E->weight;
                            next = E->dest;
                            E->dest->parent = check;
                            E->dest->weight = E->weight;
                        }

                    }
                }
            }
        }

        next->isVisited = 1;
        no_edge++;
    }
}

int main()
{

    Node** vertices;

    int N;

    scanf("%d",&N);


    vertices = malloc(sizeof(Node*)*N);

    for(int i=0;i<N;i++)
    {
        vertices[i]=malloc(sizeof(Node));
        vertices[i]->adj_list = malloc(sizeof(Edge*)*N);
        vertices[i]->data = i+1;
        vertices[i]->isVisited = 0;
        vertices[i]->connected_vertices = 0;
        vertices[i]->weight = INT_MAX;
        vertices[i]->parent = NULL;
    }


    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            int weight;
            scanf("%d",&weight);

            if(j == i && weight != 0)
            {
                printf("Weight of the edge %d - %d must be 0",i+1,j+1);
                exit(0);
            }
            if(j<i && weight != vertices[j]->adj_list[i]->weight)
            {
                printf("Weight of the edge %d - %d must be same as edge %d - %d",j+1,i+1,i+1,j+1);
                exit(0);
            }

            if(weight < 0)
            {
                printf("Weight of the edge %d - %d can not be negative",i+1,j+1);
                exit(0);
            }
            addEdge(vertices[i],weight,vertices[j]);

        }
    }

    int start;
    scanf("%d",&start);
    vertices[start-1]->weight = 0;
    vertices[start-1]->isVisited = 1;
    prim(vertices,N);

    for(int i=0;i<N;i++)
    {
        if(i+1 != start)
            printf("%d - %d\t%d\n",vertices[i]->data,vertices[i]->parent->data,vertices[i]->weight);
    }   
}
