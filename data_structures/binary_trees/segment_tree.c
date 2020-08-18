/**
 * SEGMENT TREE WITH ONLY POINT UPDATES
 *
 * [LEARN MORE ABOUT SEGMENT TREES](https://codeforces.com/blog/entry/18051)
 *
 * @author [Lakhan Nad](https://github.com/Lakhan-Nad)
 */

#include <assert.h> /**< for assert */
#include <stdio.h>  /**< for scanf printf */
#include <stdlib.h> /**< for malloc, free */
#include <string.h> /**< for memcpy, memset */

/**
 * Function that combines two data to generate a new one
 */
typedef void (*combine_function)(const void *a, const void *b, void *result);

/**
 * Segemnt tree Structure
 */
typedef struct segment_tree {
  void *root;       /**< the root of formed segment tree */
  void *identity;   /**< identity element for combine function */
  size_t elem_size; /**< size of each data element */
  size_t size;      /**< total size of array which segment tree represents*/
  combine_function combine; /**< the function to be used to combine two node's
                               data to form parent's data */
} segment_tree;

/**
 * Builds tree assuming that already
 * the leaves contain data
 */
void segment_tree_build(segment_tree *tree) {
  size_t elem_size = tree->elem_size;
  int index = (tree->size - 2);
  size_t b, l, r;
  char *ptr = (char *)tree->root;
  for (; index >= 0; index--) {
    b = index * elem_size;
    l = (2 * index + 1) * elem_size;
    r = (2 * index + 2) * elem_size;
    tree->combine(ptr + l, ptr + r, ptr + b);
  }
}

/**
 * index is based on 0 based indexing
 */
void segment_tree_update(segment_tree *tree, size_t index, void *val) {
  size_t elem_size = tree->elem_size;
  index = index + tree->size - 1;
  char *base = (char *)tree->root;
  char *t = base + index * elem_size;
  memcpy(t, val, elem_size);
  while (index > 0) {
    index = ((index - 1) >> 1);
    tree->combine(base + (2 * index + 1) * elem_size,
                  base + (2 * index + 2) * elem_size, base + index * elem_size);
  }
}

/**
 * l and r are 0 based indexes and in range [l,r]
 * res is the variable that will keep the result
 * of query
 */
void segment_tree_query(segment_tree *tree, long long l, long long r,
                        void *res) {
  size_t elem_size = tree->elem_size;
  memcpy(res, tree->identity, elem_size);
  elem_size = tree->elem_size;
  char *root = (char *)tree->root;
  l += tree->size - 1;
  r += tree->size - 1;
  while (l <= r) {
    if (!(l & 1)) {
      tree->combine(res, root + l * elem_size, res);
    }
    if (r & 1) {
      tree->combine(res, root + r * elem_size, res);
    }
    r = (r >> 1) - 1;
    l = (l >> 1);
  }
}

/**
 * We initialize memory of segment tree
 * and also fill the leaves of segment tree
 */
segment_tree *segment_tree_init(void *arr, size_t elem_size, size_t size,
                                void *identity, combine_function func) {
  segment_tree *tree = malloc(sizeof(segment_tree));
  tree->elem_size = elem_size;
  tree->size = size;
  tree->combine = func;
  tree->root = malloc(sizeof(char) * elem_size * (2 * size - 1));
  tree->identity = malloc(sizeof(char) * elem_size);
  char *ptr = (char *)tree->root;
  memset(ptr, 0, (size - 1) * elem_size);  // Initializing memory
  ptr = ptr + (size - 1) * elem_size;
  memcpy(ptr, arr, elem_size * size);  // copy the leaf nodes i.e. array data
  memcpy(tree->identity, identity, elem_size);  // copy identity element
  return tree;
}

void segment_tree_dispose(segment_tree *tree) {
  free(tree->root);
  free(tree->identity);
}

/**
 * A utility to print segment tree
 * with data type of int
 */
void segment_tree_print_int(segment_tree *tree) {
  char *base = (char *)tree->root;
  size_t i = 0;
  for (; i < 2 * tree->size - 1; i++) {
    printf("%d ", *(int *)(base + i * tree->elem_size));
  }
  printf("\n");
}

/**
 * A function compare for minimum integers
 */
void minimum(const void *a, const void *b, void *c) {
  *(int *)c = *(int *)a < *(int *)b ? *(int *)a : *(int *)b;
}

/**
 * Testing Segment tree using
 * Range Minimum Queries
 */
void test() {
  int arr[10] = {1, 0, 3, 5, 7, 2, 11, 6, -2, 8};
  int identity = __INT32_MAX__;
  segment_tree *tree =
      segment_tree_init(arr, sizeof(int), 10, &identity, minimum);
  segment_tree_build(tree);
  int result;
  segment_tree_query(tree, 3, 6, &result);
  assert(result == 2);
  segment_tree_query(tree, 8, 9, &result);
  assert(result == -2);
  result = 12;
  segment_tree_update(tree, 5, &result);
  segment_tree_update(tree, 8, &result);
  segment_tree_query(tree, 0, 3, &result);
  assert(result == 0);
  segment_tree_query(tree, 8, 9, &result);
  assert(result == 8);
  segment_tree_dispose(tree);
}

/**
 * Main Function
 */
int main() {
  test();
  return 0;
}