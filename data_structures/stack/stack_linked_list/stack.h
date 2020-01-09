#ifndef __STACK__
#define __STACK__

#define T Stack_T
typedef struct T *T;

extern T     Stack_init   (void);
extern int   Stack_size   (T stack);
extern int   Stack_empty  (T stack);
extern void  Stack_push   (T stack, void *val);
extern void *Stack_pop    (T stack);
extern void  Stack_print  (T stack);

#undef T
#endif
