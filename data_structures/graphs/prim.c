#include<stdio.h>
#include<stdlib.h>
#define max_edges_of_vertex 100000
/*      max_edges_of_vertex will be used to initialize adjacency list
        you can modify size according to question constraint                        */

#define INFINITY LONG_LONG_MAX

// a structure to represent a weighted edge in graph
typedef struct NODE
{
	long long u;
	long long w;
	struct NODE* next;
}node;

// a structure to represent a connected, undirected Heap
typedef struct HeapNode
{
	long long u;
	long long key;
}heap;

// a function to adjust heap after extracting minimum
void adjust_min_heap(heap *H, long long i, long long new_weight, long long size, long long *pos) {
	long long p = pos[i], u;
	heap temporary = H[p];
	temporary.key = new_weight;
	while(p > 1 && temporary.key < H[p/2].key) {
		H[p] = H[p/2];
		u = H[p].u;
		pos[u] = p;
		p = p/2;
	}
	H[p] = temporary;
	pos[i] = p;
}

// a function to heapfiy the array of edges
void min_heapify(heap *H, long long i, long long size, long long *pos) {
	heap temporary = H[i];
	long long left, right, min, u;
	while((left = 2*i) <= size) {
		right = left+1;
		if(right <= size && H[right].key < H[left].key)
			min = right;
		else
			min = left;
		if(H[min].key < temporary.key) {
			H[i] = H[min];
			u = H[i].u;
			pos[u] = i;
			i = min;
		}
		else
			break;
	}
	H[i] = temporary;
	u = H[i].u;
	pos[u] = i;
}

// a function to extract minimum element from heap
long long extract_min(heap *H, long long *size, long long *pos) {
	long long u = H[1].u;
	H[1] = H[*size];
	pos[H[1].u] = 1;
	*size = *size-1;
	min_heapify(H, 1, *size, pos);
	return u;
}

// The main function to construct MST using Prim's algorithm
void prims_MST(node *adjacency_list[], long long size_of_tree) {
	long long pos[size_of_tree+1], i, u, w, cost = 0;
	long long *key = (long long *)malloc((size_of_tree+1)*sizeof(long long));
	long long *v1 = (long long *)malloc((size_of_tree+1)*sizeof(long long));
	long long *visited = (long long *)malloc((size_of_tree+1)*sizeof(long long));
	long long heap_size = size_of_tree;
	heap *H = (heap *)malloc((heap_size+1)*sizeof(heap));
	for(i = 1; i <= heap_size; i++)
	{
		v1[i] = -1;
		visited[i] = 0;
		key[i] = H[i].key = INFINITY;//u.distance = infinity
		H[i].u = i;
		pos[i] = i;
	}
	key[1] = H[1].key = 0;
	while(heap_size) {
        //while Heap ≠ Φ(empty)
		long long u = extract_min(H, &heap_size, pos);// Extract-min from heap                 
		visited[u] = 1;
		cost += key[u];
		node *q = adjacency_list[u];
		while(q) {
			u = q->u;
			w = q->w; 
			if(visited[u] == 0 && w < key[u]){
				key[u] = w;
				v1[u] = u;
				adjust_min_heap(H, u, w, heap_size, pos);
			}
			q = q->next;
		}
	}
	printf("\n------------------\nCost of MST = %d", cost);
}
int main()
{
	long long i,j,k,w,size_of_tree,e;
    size_of_tree=5;
    e=6;	
	printf("\nNo. of vertices:%d\n",size_of_tree);
	printf("\nNo. of edges:%d\n",e);
	node *adjacency_list[max_edges_of_vertex]={NULL};
        // 1st edge
        //vertex 1 next =vertex 2 , vertex 2 next=vertex 1
		node *t = (node *)malloc(sizeof(node));
		t->u=2;
		t->w=1;
		t->next = adjacency_list[1];
		adjacency_list[1] = t;
		t = (node *)malloc(sizeof(node));
		t->u=1;
		t->w=1;
		t->next=adjacency_list[2];
		adjacency_list[2]=t;
        //2nd edge
        t = (node *)malloc(sizeof(node));
		t->u=3;
		t->w=5;
		t->next = adjacency_list[2];
		adjacency_list[2] = t;
		t = (node *)malloc(sizeof(node));
		t->u=2;
		t->w=5;
		t->next=adjacency_list[3];
		adjacency_list[3]=t;
        //3rd edge
        t = (node *)malloc(sizeof(node));
		t->u=4;
		t->w=1;
		t->next = adjacency_list[2];
		adjacency_list[2] = t;
		t = (node *)malloc(sizeof(node));
		t->u=2;
		t->w=1;
		t->next=adjacency_list[4];
		adjacency_list[4]=t;
        //4th edge
        t = (node *)malloc(sizeof(node));
		t->u=4;
		t->w=8;
		t->next = adjacency_list[3];
		adjacency_list[3] = t;
		t = (node *)malloc(sizeof(node));
		t->u=3;
		t->w=8;
		t->next=adjacency_list[4];
		adjacency_list[4]=t;
        //5th edge
        t = (node *)malloc(sizeof(node));
		t->u=1;
		t->w=7;
		t->next = adjacency_list[5];
		adjacency_list[5] = t;
		t = (node *)malloc(sizeof(node));
		t->u=5;
		t->w=7;
		t->next=adjacency_list[1];
		adjacency_list[1]=t;
        //6th edge
        t = (node *)malloc(sizeof(node));
		t->u=4;
		t->w=1;
		t->next = adjacency_list[5];
		adjacency_list[5] = t;
		t = (node *)malloc(sizeof(node));
		t->u=5;
		t->w=1;
		t->next=adjacency_list[4];
		adjacency_list[4]=t;
	printf("\nGraph:\n");
	for(i=1;i<size_of_tree+1;i++)
	{
		printf("    %d  ->  ",i);
		node *p=adjacency_list[i];
		while(p!=NULL)
		{
			printf("%lld : %lld",p->u,p->w);
            if(p->next!=NULL){
                printf(" : ");
            }
			p=p->next;
		}
        printf("\n");
	}
	prims_MST(adjacency_list, size_of_tree);
	return 0;
}
/* 
    Prim’s algorithm:
        (Time complexity of Prim’s algorithm on G = (V, E), with weights W = [w(e)], n = |V|, m = |E|)
                 Start with any one vertex in the spanning tree
                 Repeatedly add the cheapest edge, and the NEW node it leads to
                 the new vertex is not in the spanning tree
Pseudo Code:
    Prim’s algorithm on G = (V, E), with weights of edges in array W = [w(e)]
    function MST-Prim(G, W, r)                //G = (V, E)
        T = Φ                                 //list of all edges in MST
        X = Φ                                 // list of all vertices in MST
        for each vertex u ε V - {r}
            u.key = ꚙ
            u.π = nil
        r.key = 0
        u.π = nil
        Q = V                                  //sort all in V as a min-binary heap Q based on u.key
        while Q ≠ Φ
            u = Extract-min(Q)                 //and delete the min node in Q
            T = T U {u, u.π}                   //the corresponding edge is added to T
            X = X U {u}                        //the corresponding vertex is added to X
            for each v in G.Adj[u]
                if v in Q and w(u, v) < v.key
                    v.π = u                    //change its parent
                    v.key = w(u, v)            //update its key
                    Adjust-min(Q, v)           //re-adjust the min-heap
        return T, X
*/