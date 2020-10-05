#ifndef _BITMAP_H_
#define _BITMAP_H_

#include <stddef.h>

struct bitnode;

struct bitnode *create_bitmap(size_t n);

void destroy_bitmap(struct bitnode *bitmap);

void set_bit(struct bitnode *bitmap, size_t bitpos);

void clear_bit(struct bitnode *bitmap, size_t bitpos);

int get_bit(struct bitnode *bitmap, size_t bitpos);

#endif
