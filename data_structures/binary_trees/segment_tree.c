/**
 * @file segment_tree.c
 * @brief segment trees with only point updates
 * @details
 * This code implements segment trees. Segment trees are general structures
 * which allow range based queries in a given array in logN time.
 * Segment tree with point updates allow update of single element in the array
 * in logN time.
 * [Learn more about segment trees
 * here](https://codeforces.com/blog/entry/18051)
 * @author [Lakhan Nad](https://github.com/Lakhan-Nad)
 */

#include <assert.h>   /* for assert */
#include <inttypes.h> /* for int32 */
#include <stdio.h>    /* for scanf printf */
#include <stdlib.h>   /* for malloc, free */
#include <string.h>   /* for memcpy, memset */

/**
 * Function that combines two data to generate a new one
 * The name of function might be misleading actually combine here signifies the
 * fact that in segment trees we take partial result from two ranges and using
 * partial results we derive the result for joint range of those two ranges
 * For Example: array(1,2,3,4,5,6) sum of range [0,2] = 6
 * and sum of range [3,5] = 15 the combined sum of two range is 6+15=21
 * @note The function is same to binary function in Discrete Mathematics
 * @param a pointer to first data
 * @param b pointer to second data
 * @param result pointer to memory location where result of combining a and b is
 * to be stored
 */
typedef void (*combine_function)(const void *a, const void *b, void *result);

/**
 * This structures holds all the data that is required by a segment tree
 */
typedef struct segment_tree
{
    void *root;       /**< the root of formed segment tree */
    void *identity;   /**< identity element for combine function */
    size_t elem_size; /**< size in bytes of each data element */
    size_t length;    /**< total size of array which segment tree represents*/
    /** the function to be used to combine two node's
     * data to form parent's data
     */
    combine_function combine;
} segment_tree;

/**
 * Builds a Segment tree
 * It is assumed that leaves of tree already contains data.
 * @param tree pointer to segment tree to be build
 */
void segment_tree_build(segment_tree *tree)
{
    size_t elem_size = tree->elem_size;
    int index = (tree->length - 2);
    size_t b, l, r;
    char *ptr = (char *)tree->root;
    for (; index >= 0; index--)
    {
        b = index * elem_size;
        l = (2 * index + 1) * elem_size;
        r = (2 * index + 2) * elem_size;
        tree->combine(ptr + l, ptr + r, ptr + b);
    }
}

/**
 * For point updates
 * This function updates the element at given index and also updates segment
 * tree accordingly
 *
 * @param tree pointer to segment tree
 * @param index the index whose element is to be updated (0 based indexing used)
 * @param val pointer to value that is to be replaced at given index
 */
void segment_tree_update(segment_tree *tree, size_t index, void *val)
{
    size_t elem_size = tree->elem_size;
    index = index + tree->length - 1;
    char *base = (char *)tree->root;
    char *t = base + index * elem_size;
    memcpy(t, val, elem_size);
    while (index > 0)
    {
        index = ((index - 1) >> 1);
        tree->combine(base + (2 * index + 1) * elem_size,
                      base + (2 * index + 2) * elem_size,
                      base + index * elem_size);
    }
}

/**
 * Query the segment tree
 * This function helps in range query of segment tree
 * This function assumes that the given range is valid
 * Performs the query in range [l,r]
 * @param tree pointer to segment tree
 * @param l the start of range
 * @param r the end of range
 * @param res the pointer to memory where result of query is stored
 */
void segment_tree_query(segment_tree *tree, long long l, long long r, void *res)
{
    size_t elem_size = tree->elem_size;
    memcpy(res, tree->identity, elem_size);
    elem_size = tree->elem_size;
    char *root = (char *)tree->root;
    l += tree->length - 1;
    r += tree->length - 1;
    while (l <= r)
    {
        if (!(l & 1))
        {
            tree->combine(res, root + l * elem_size, res);
        }
        if (r & 1)
        {
            tree->combine(res, root + r * elem_size, res);
        }
        r = (r >> 1) - 1;
        l = (l >> 1);
    }
}

/**
 * Initializes Segment Tree
 * Accquires memory for segment tree
 * and fill the leaves of segment tree with data from array
 * @param arr the array data upon which segment tree is build
 * @param elem_size size of each element in segment tree
 * @param len total no of elements in array
 * @param identity the identity element for combine_function
 * @param func the combine_function used to build segment tree
 *
 * @returns pointer to sgement tree build
 */
segment_tree *segment_tree_init(void *arr, size_t elem_size, size_t len,
                                void *identity, combine_function func)
{
    segment_tree *tree = malloc(sizeof(segment_tree));
    tree->elem_size = elem_size;
    tree->length = len;
    tree->combine = func;
    tree->root = malloc(sizeof(char) * elem_size * (2 * len - 1));
    tree->identity = malloc(sizeof(char) * elem_size);
    char *ptr = (char *)tree->root;
    memset(ptr, 0, (len - 1) * elem_size);  // Initializing memory
    ptr = ptr + (len - 1) * elem_size;
    memcpy(ptr, arr, elem_size * len);  // copy the leaf nodes i.e. array data
    memcpy(tree->identity, identity, elem_size);  // copy identity element
    return tree;
}

/**
 * Dispose Segment Tree
 * Frees all heap memory accquired by segment tree
 * @param tree pointer to segment tree
 */
void segment_tree_dispose(segment_tree *tree)
{
    free(tree->root);
    free(tree->identity);
}

/**
 * Prints the data in segment tree
 * The data should be of int type
 * A utility to print segment tree
 * with data type of int
 * @param tree pointer to segment tree
 */
void segment_tree_print_int(segment_tree *tree)
{
    char *base = (char *)tree->root;
    size_t i = 0;
    for (; i < 2 * tree->length - 1; i++)
    {
        printf("%d ", *(int *)(base + i * tree->elem_size));
    }
    printf("\n");
}

/**
 * Utility for test
 * A function compare for minimum between two integers
 * This function is used as combine_function for RMQ
 * @param a pointer to integer a
 * @param b pointer to integer b
 * @param c pointer where minimum of a and b is tored as result
 */
void minimum(const void *a, const void *b, void *c)
{
    *(int *)c = *(int *)a < *(int *)b ? *(int *)a : *(int *)b;
}

/**
 * Test RMQ
 * Testing Segment tree using
 * Range Minimum Queries
 * @returns void
 */
static void test()
{
    int32_t arr[10] = {1, 0, 3, 5, 7, 2, 11, 6, -2, 8};
    int32_t identity = __INT32_MAX__;
    segment_tree *tree =
        segment_tree_init(arr, sizeof(*arr), 10, &identity, minimum);
    segment_tree_build(tree);
    int32_t result;
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
 * @brief Main Function
 * @returns 0 on exit
 */
int main()
{
    test();
    return 0;
}
