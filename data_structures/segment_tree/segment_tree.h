#ifndef __SEGMENT_TREE_H__
#define __SEGMENT_TREE_H__

#include <stddef.h>

struct segment_tree;

/**
 * Compare function
 * 
 * @return >0 number if a > b, 0 if a = b, <0 number if a < b
*/
typedef int (*comp_func_t)(const void *a, const void *b);

/**
 * Operation function
 * 
 * @param a first element
 * @param b second element
 * @param result pointer to memory where result of operation should be written in
*/
typedef void (*oper_func_t)(const void *a, const void *b, void *result);

/**
 * Initialization of segment tree
 * 
 * @param tree segment tree element pointer
 * @param size size of array
 * @param elem_size size of element
 * @param data array of elements
*/
void segment_tree_init(struct segment_tree *tree, size_t size, size_t elem_size, void *data,
                         comp_func_t comp_func, oper_func_t oper_func);

/**
 * Builds tree from provided data in segment_tree_init
 * 
 * @param tree segment tree element pointer
*/
void segment_tree_build(struct segment_tree *tree);

/**
 * Updates the element of given position to new_elem
 * 
 * @param tree segment tree element pointer
 * @param pos position where to update with new_elem
 * @param new_elem new value for position pos
*/
void segment_tree_update(struct segment_tree *tree, size_t pos, void *new_elem);

/**
 * Making query on given segment [l, r]
 * 
 * @param tree segment tree element pointer
 * @param l left end of the segment
 * @param r right end of the segment
 * @param result pointer to which query result data should be written in
*/
void segment_tree_query(struct segment_tree *tree, size_t l, size_t r, void *result);

/**
 * Disposes memory allocated for segment tree
 * 
 * @param tree tree of which memory should be disposed
*/
void segment_tree_dispose(struct segment_tree *tree);

#endif
