#include <stdlib.h>
#include "bitmap.h"

static void _set_node_bit(struct bitnode *node, size_t bit);
static void _clear_node_bit(struct bitnode *node, size_t bit);
static int get_node_bit(struct bitnode *node, size_t bit);
static unsigned char _get_byte_with_bit_set_on(size_t bit);

struct bitnode {
	unsigned char node_value;
};

struct bitnode *create_bitmap(size_t n)
{
	size_t num = n / 8;

	if (n % 8 != 0)
		num++;

	struct bitnode *bitmap = calloc(num, sizeof(struct bitnode));

	return bitmap;
}

void destroy_bitmap(struct bitnode *bitmap)
{
	free(bitmap);
}

void set_bit(struct bitnode *bitmap, size_t bitpos)
{
	size_t index = bitpos / 8;
	size_t bit_to_set = bitpos % 8;

	struct bitnode *node_to_change = &bitmap[index];
	_set_node_bit(node_to_change, bit_to_set);
}

void clear_bit(struct bitnode *bitmap, size_t bitpos)
{
	size_t index = bitpos / 8;
	size_t bit_to_clear = bitpos % 8;
	
	struct bitnode *node_to_change = &bitmap[index];
	_clear_node_bit(node_to_change, bit_to_clear);
}

int get_bit(struct bitnode *bitmap, size_t bitpos)
{
	size_t index = bitpos / 8;
	size_t bit_to_get = bitpos % 8;
	
	struct bitnode *node_to_get = &bitmap[index];
	return get_node_bit(node_to_get, bit_to_get);
}

static void _set_node_bit(struct bitnode *node, size_t bit)
{
	unsigned char mask = _get_byte_with_bit_set_on(bit);
	node->node_value |= mask;
}

static void _clear_node_bit(struct bitnode *node, size_t bit)
{
	unsigned char mask = ~(_get_byte_with_bit_set_on(bit));
	node->node_value &= mask;
}

static int get_node_bit(struct bitnode *node, size_t bit)
{
	unsigned char mask = _get_byte_with_bit_set_on(bit);

	return !!(node->node_value & mask);
}

static unsigned char _get_byte_with_bit_set_on(size_t bit)
{
	unsigned char mask = 1 << (7 - bit);	/* The mask to set that bit */		

	return mask;
}

