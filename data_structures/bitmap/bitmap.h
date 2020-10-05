/**
 * @file
 * @brief bitmap api
 * @author [Alysson Cirilo](https://github.com/alyssoncs)
 * @see bitma.c
 */
 
#ifndef _BITMAP_H_
#define _BITMAP_H_

#include <stddef.h>

/**
 * @brief forward declaration of the struct that represents a node on a bitmap
 */
struct bitnode;

/**
 * @brief returns a bitmap with size \p n.
 *
 * the pointer returned should be deallocated with destroy_bitmap().
 *
 * @param[in] n the size of the bitmap.
 * @returns a pointer to the created bitmap.
 */
struct bitnode *create_bitmap(size_t n);

/**
 * @brief destroys a bitmap created with create_bitmap().
 *
 * @param[in] bitmap a pointer to a bitmap to be destroyed.
 */
void destroy_bitmap(struct bitnode *bitmap);

/**
 * @brief set the \p bitpos'th bit on \p bitmap as 1.
 *
 * @param[in] bitmap the bitmap that the operation will execute.
 * @param[in] bitpos the bit on the \p bitmap that will be set to 1.
 * 
 */
void set_bit(struct bitnode *bitmap, size_t bitpos);

/**
 * @brief set the \p bitpos'th bit on \p bitmap as 0.
 *
 * @param[in] bitmap the bitmap that the operation will execute.
 * @param[in] bitpos the bit on the \p bitmap that will be set to 0.
 * 
 */
void clear_bit(struct bitnode *bitmap, size_t bitpos);

/**
 * @brief get the \p bitpos'th bit value on \p bitmap.
 *
 * @param[in] bitmap the bitmap that the operation will execute.
 * @param[in] bitpos the bit on the \p bitmap that will be fetch.
 * 
 */
int get_bit(struct bitnode *bitmap, size_t bitpos);

#endif
