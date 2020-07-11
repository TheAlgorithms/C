#include <string.h>
#include "segment_tree.h"

/**
 * Structure of segment tree
*/
struct segment_tree
{
    comp_func_t comp_func;      /**< compare function */
    oper_func_t oper_func;      /**< operation function */
    size_t elem_size;           /**< size of single element */
    size_t size;                /**< size of data */
    void *data;                 /**< data of tree */
    void *t;                    /**< segment tree */
};


/**
 * Initialization of segment tree
 * 
 * @param tree segment tree element pointer
 * @param size size of array
 * @param elem_size size of element
 * @param data array of elements
*/
void segment_tree_init(struct segment_tree *tree, size_t size, size_t elem_size, void *data,
                         comp_func_t comp_func, oper_func_t oper_func){
    tree -> comp_func = comp_func;
    tree -> oper_func = oper_func;
    tree -> size = size;
    tree -> elem_size = elem_size;
    tree -> data = malloc(elem_size * size);
    tree -> t = malloc(4 * size * elem_size);
    memcpy(tree -> data, data, elem_size * size);
}

/**
 * Builds tree from provided data in segment_tree_init
 * 
 * @param tree segment tree element pointer
*/
void segment_tree_build(struct segment_tree *tree) {
}

/**
 * Updates the element of given position to new_elem
 * 
 * @param tree segment tree element pointer
 * @param pos position where to update with new_elem
 * @param new_elem new value for position pos
*/
void segment_tree_update(struct segment_tree *tree, size_t pos, void *new_elem) {

}

/**
 * Making query on given segment [l, r]
 * 
 * @param tree segment tree element pointer
 * @param l left end of the segment
 * @param r right end of the segment
 * @param result pointer to which query result data should be written in
*/
void segment_tree_query(struct segment_tree *tree, size_t l, size_t r, void *result) {
    
}

/**
 * Disposes memory allocated for segment tree
 * 
 * @param tree tree of which memory should be disposed
*/
void segment_tree_dispose(struct segment_tree *tree){
    free(tree -> data);
    free(tree -> t);
}
