/**
 * @krushkals.c
 * @reference:https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/
 * @details
 * Kruskal’s algorithm is a greedy algorithm in graph theory that finds a minimum spanning tree for a connected weighted graph.
 * theory that finds a minimum spanning tree for a connected weighted graph.
 * It finds a subset of the edges that forms a tree that includes every vertex, * where the total weight of all the edges in the tree is minimized.
 * @author [Ankit Akash](https://github.com/ankit-akash)
 */
 
  #include <stdio.h>   //for input or output
    #include <stdlib.h>  //It is a standard lib which is for general utility

    
    //This is where we will store the cost of each vertex to its parents.
    int min, mincost = 0, cost[9][9], parent[9];
    int find(int);
    int uni(int, int);
    void main() {
      int i, j, k, a, b, u, v, n, ne = 1;
      printf("\n\tImplementation of Kruskal's Algorithm\n");
      printf("\nEnter the no. of vertices:");
      scanf("%d", & n);
      printf("\nEnter the cost adjacency matrix:\n");
      for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
          scanf("%d", & cost[i][j]);
          if (cost[i][j] == 0)
            cost[i][j] = 999;
        }
      }
      //Then it prints out what edges make up the Minimum Cost Spanning Tree for each iteration of the loop using printf().
      printf("The edges of Minimum Cost Spanning Tree are\n");
      
      //After this there is a while loop that goes through all nine vertices until it finds one with minimum cost (ne < n).
      while (ne < n) {
        for (i = 1, min = 999; i <= n; i++) {
          for (j = 1; j <= n; j++) {
            if (cost[i][j] < min) {
              min = cost[i][j];
              a = u = i;
              b = v = j;
            }
          }
        }
        u = find(u);
        v = find(v);
        if (uni(u, v)) {
          printf("%d edge (%d,%d) =%d\n", ne++, a, b, min);
          mincost += min;
        }
        cost[a][b] = cost[b][a] = 999;
      }
      printf("\n\tMinimum cost = %d\n", mincost);
      getch();
    }
    int find(int i) {
      while (parent[i])
        i = parent[i];
      return i;
    }
    int uni(int i, int j) {
      if (i != j) {
        parent[j] = i;
        return 1;
      }
      return 0;
    }

/*OUTPUT:
Implementation of Kruskal's Algorithm
 
Enter the no. of vertices:3  
 
Enter the cost adjacency matrix: 
9
8
7
6
5
4
3
2
3
The edges of Minimum Cost Spanning Tree are  
1 edge (3,2) =2  
2 edge (3,1) =3  
 
Minimum cost = 5
*/
