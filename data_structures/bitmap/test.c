#include <assert.h>

#include "bitmap.h"

static void test(void);
static void should_create_bitmap();
static void shoud_clear_all_bits_on_creation();
static void should_set_bit();
static void should_clear_bit();
static void integration();

static const int BITMAP_SIZE = 50;
static struct bitnode *bitmap;

int main(void)
{
	test();
}

static void test(void)
{
	should_create_bitmap();
	shoud_clear_all_bits_on_creation();
	should_set_bit();
	should_clear_bit();
	integration();
}

static void should_create_bitmap()
{
	bitmap = create_bitmap(BITMAP_SIZE);

	assert(bitmap != NULL);
	
	destroy_bitmap(bitmap);
}

static void shoud_clear_all_bits_on_creation()
{
	bitmap = create_bitmap(BITMAP_SIZE);

	for (int i = 0; i < BITMAP_SIZE; i++)
		assert(get_bit(bitmap, i) == 0);
	
	destroy_bitmap(bitmap);
}

static void should_set_bit()
{
	bitmap = create_bitmap(BITMAP_SIZE);

	set_bit(bitmap, BITMAP_SIZE-1);

	assert(get_bit(bitmap, BITMAP_SIZE-1) == 1);
	
	destroy_bitmap(bitmap);
}

static void should_clear_bit()
{
	bitmap = create_bitmap(BITMAP_SIZE);

	set_bit(bitmap, BITMAP_SIZE-1);
	clear_bit(bitmap, BITMAP_SIZE-1);

	assert(get_bit(bitmap, BITMAP_SIZE-1) == 0);
	
	destroy_bitmap(bitmap);
}

static void integration()
{
	bitmap = create_bitmap(BITMAP_SIZE);

	for (int i = 0; i < BITMAP_SIZE; i++)
		if (i%2 == 0)
			set_bit(bitmap, i);
	
	for (int i = 0; i < BITMAP_SIZE; i++)
		if (i%2 == 0)
			assert(get_bit(bitmap, i) == 1);
		else
			assert(get_bit(bitmap, i) == 0);
	
	destroy_bitmap(bitmap);
}

