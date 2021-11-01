#include "stack.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define T Stack_T

typedef struct elem
{
    void *val;
    struct elem *next;
} elem_t;

struct T
{
    int count;
    elem_t *head;
};

/* Initial stack */
T Stack_init(void)
{
    T stack;
    stack = (T)malloc(sizeof(T));
    stack->count = 0;
    stack->head = NULL;
    return stack;
}

/* Check empty stack*/
int Stack_empty(T stack)
{
    assert(stack);
    return stack->count == 0;
}

/* Return size of the stack */
int Stack_size(T stack)
{
    assert(stack);
    return stack->count;
}

/* Push an element into the stack */
void Stack_push(T stack, void *val)
{
    elem_t *t;

    assert(stack);
    t = (elem_t *)malloc(sizeof(elem_t));
    t->val = val;
    t->next = stack->head;
    stack->head = t;
    stack->count++;
}

/* Pop an element out of the stack */
void *Stack_pop(T stack)
{
    void *val;
    elem_t *t;

    assert(stack);
    assert(stack->count > 0);
    t = stack->head;
    stack->head = t->next;
    stack->count--;
    val = t->val;
    free(t);
    return val;
}

/* Print all elements in the stack */
void Stack_print(Stack_T stack)
{
    assert(stack);

    int i, size = Stack_size(stack);
    elem_t *current_elem = stack->head;
    printf("Stack [Top --- Bottom]: ");
    for (i = 0; i < size; ++i)
    {
        printf("%p ", (int *)current_elem->val);
        current_elem = current_elem->next;
    }
    printf("\n");
}
