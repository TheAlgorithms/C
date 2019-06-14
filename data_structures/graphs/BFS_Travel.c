#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>


//Structure for storing a graph
struct Graph{
	int vertexNum;
	int** edges;
};

//Constructs a graph with V vertices and E edges
void createGraph(struct Graph* G,int V){
		G->vertexNum = V;
		G->edges =(int**) malloc(V * sizeof(int*));
		for(int i=0; i<V; i++){
			G->edges[i] = (int*) malloc(V * sizeof(int));
			for(int j=0; j<V; j++)
				G->edges[i][j] = INT_MAX;
			G->edges[i][i] = 0;
		}		
}

//Adds the given edge to the graph 
void addEdge(struct Graph* G, int src, int dst, int weight){
	G->edges[src][dst] = weight;
}

//BFS Travel
int row, col, visited[1000000], order[1000000];
int head, tail;

struct Data {
	int now,v;
	int enque(int cur, int lv) {
		if (visited[cur])
			return 0;
		now = cur, c = nc, v = lv;
		visited[cur] = 1;
		order[cur] = v;
		tail++;
	}
}que[LM * LM];
int BFS()
{
	for (; head < tail; head++)
	{
		for (int i = 0; i <= G->vertexNum; i++) {
			if (G->edges[cur][i] != 0 && G->edges[cur][i] != INT_MAX) {
				Data& t = que[head];
				que[tail].enque(t.r + dr[i] t.v + 1);
			}
		}
	}
	return 0;
}

//Driver Function
int main(){
	int V,E,gsrc;
	int src,dst,weight;
	struct Graph G;
	printf("Enter number of vertices: ");
	scanf("%d",&V);
	printf("Enter number of edges: ");
	scanf("%d",&E);
	createGraph(&G,V);
	for(int i=0; i<E; i++){
		printf("\nEdge %d \nEnter source: ",i+1);
		scanf("%d",&src);
		printf("Enter destination: ");
		scanf("%d",&dst);
		printf("Enter weight: ");
		scanf("%d",&weight);sdfsdf
		addEdge(&G, src, dst, weight);
	}
	printf("\nEnter source:");
	scanf("%d",&gsrc);
	DFS(gsrc,0);

	printf("All Vertices Travel Complete By DFS!\n");
	return 0;
}



