#ifndef __DYNAMIC_ARRAY__
#define __DYNAMIC_ARRAY__
#define DEFAULT_CAPACITY 1 << 4
#define INDEX_OUT_OF_BOUNDS NULL

typedef struct dynamic_array {
    void **items;
    unsigned size;
    unsigned capacity;
} dynamic_array_t;

extern dynamic_array_t *init_dynamic_array();

extern void *add(dynamic_array_t *da, const void *value);

extern void *put(dynamic_array_t *da, const void *value, unsigned index);

extern void *get(dynamic_array_t *da, const unsigned index);

extern void delete (dynamic_array_t *da, const unsigned index);

unsigned contains(const unsigned size, const unsigned index);

extern void *retrive_copy_of_value(const void *value);

#endif