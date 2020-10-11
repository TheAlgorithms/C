/**
 * \file
 * \brief Project Euler problem 107 (https://projecteuler.net/problem=107)
 * solution using Kruskals
 * \author [David Santamaria](https://github.com/Daves1245)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define NUM_VERTICES 40
#define NUM_LINES 40
#define MAX_LINE_LEN 4 * 40 // a line is at most 40 3-digit numbers and a comma

/*
 * We represent an edge as a 3 tuple (u, v, w),
 * where u and v are the vetices connected by
 * the edge, and w is the weight of the edge
 */
struct edge {
  int u;
  int v;
  int w;
};

/*
 * The union find data structure
 */
struct ufds {
  int rank[NUM_VERTICES], parent[NUM_VERTICES], size[NUM_VERTICES];
  int num_sets;
};

/** Find the representative item of a vertex
 * @param i the queried vertex
 * @param the union find that i belongs within
 * @returnss the index of the vertex that represents
 * the set that i belongs to
 */
int find_set(int i, struct ufds *uf) {
  if (uf->parent[i] != i) {
    return uf->parent[i] = find_set(uf->parent[i], uf);
  }
  return i;
}

/** Find if i and j belong within the same set
 * @param i the first vertex
 * @param j the second vertex
 * @param uf the union find i and j lie within
 * @returns true if i and j are in the same set
 * @returns false otherwise
 */
int in_same_set(int i, int j, struct ufds *uf) {
  return find_set(i, uf) == find_set(j, uf);
}

/** Bring together two sets in a union find
 * @param i the first representative item of one set
 * @param j the second representative item of another set
 * @param uf the union find they lie within
 */
void union_set(int i, int j, struct ufds *uf) {
  if (!in_same_set(i, j, uf)) {
    int ri = find_set(i, uf), rj = find_set(j, uf);
    if (uf->rank[ri] < uf->rank[rj]) {
      uf->parent[ri] = rj;
      uf->size[rj]++;
    } else {
      uf->parent[rj] = ri;
      if (uf->rank[ri] == uf->rank[rj]) {
        uf->rank[rj]++;
        uf->size[rj]++;
      }
    }
    uf->num_sets--;
  }
}

/*
 * The problem specifies an adjacency matrix, which can be used with Prim's
 * algorithm, but this implementation uses kruskal's, so we convert the input
 * into an edge list represented by an array of edges
 */
void generate_edge_list(char *str, struct edge *elist, int *total_weight) {
  char *tmp;
  int n;
  tmp = strtok(str, ",");
  if (!tmp) {
    fprintf(stderr, "input is invalid!\n");
    exit(EXIT_FAILURE);
  }
  for (int i = 0; i < NUM_VERTICES; i++) {
    for (int j = (i == 0) ? 1 : 0; j < NUM_VERTICES; j++) {
      struct edge *entry = &elist[i * NUM_VERTICES + j];
      tmp = strtok(NULL, ",");
      // ignore redundant data symmetric about the line i == j in the matrix
      if (j < i || strcmp(tmp, "-") == 0) {
        continue;
      } else {
        n = atoi(tmp);
        entry->u = i;
        entry->v = j;
        entry->w = n;
        *total_weight += n;
      }
    }
  }
}

/* Compare two edges by their weight */
int my_comp(const void *a, const void *b) {
  return ((struct edge *)a)->w - ((struct edge *)b)->w;
}

/** An implementation of Kruskal's algorithm
 * (https://en.wikipedia.org/wiki/Kruskal%27s_algorithm)
 * @param E the number of edges
 * @param elist the edge list
 * @param uf pointer to union find for keeping track of trees
 */
int kruskals(int E, struct edge *elist, struct ufds *uf) {
  int cost = 0;
  // This is the main cost of kruskal's - O(ElogE) = O(Elog(V^2)) = O(ElogV)
  qsort(elist, NUM_VERTICES * NUM_VERTICES, sizeof(struct edge), my_comp);
  for (int i = 0; i < E; i++) {
    struct edge *e = &elist[i];
    if (!in_same_set(e->u, e->v, uf)) {
      cost += e->w;
      union_set(e->u, e->v, uf);
    }
    if (uf->num_sets == 1) {
      return cost;
    }
  }
  return cost;
}

/*
 * We parse input and generate an edge list
 * we then pass that edge list into kruskals to
 * get the cost of a MST of the network.
 * We then subtract that from the total cost to
 * get the savings and the solution to the problem.
 */

/** Main function */
int main(int argc, char **argv) {
  char input[MAX_LINE_LEN * NUM_LINES] = {0};
  FILE *fp;
  int offset = 0;
  int total_weight = 0;
  int mst_cost = 0;
  struct edge elist[NUM_VERTICES * NUM_VERTICES] = {0};
  struct ufds uf = {0};
  int sol;

  if (argc != 2) {
    fprintf(stderr, "usage: %s [filename]\n", argv[0]);
    return -1;
  }

  fp = fopen(argv[1], "r");
  for (int i = 0; i < NUM_VERTICES; i++) {
    uf.parent[i] = i;
  }
  if (!fp) {
    fprintf(stderr, "could not open the file\n");
    return -1;
  }

  for (int i = 0; i < NUM_VERTICES; i++) {
    fgets(input + offset, MAX_LINE_LEN, fp);
    /* Since we 0-initialized the array,
     * we can find out just how much we read in
     * by calling strlen() on the buffer */
    offset += strlen(input + offset);
    input[offset - 1] = ','; // remove the trailing newline
  }

  generate_edge_list(input, elist, &total_weight);
  mst_cost = kruskals(NUM_VERTICES * NUM_VERTICES, elist, &uf);
  sol = total_weight - mst_cost;
  assert(sol == 259679);
  printf("%d\n", total_weight - mst_cost);
  return 0;
}
