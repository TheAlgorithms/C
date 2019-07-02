#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

int main() {
    Stack_T stk;
    stk = Stack_init();
    Stack_push(stk, (int *) 1);
    Stack_push(stk, (int *) 2);
    Stack_push(stk, (int *) 3);
    Stack_push(stk, (int *) 4);
    printf("Size: %d\n", Stack_size(stk));
    Stack_print(stk);
    Stack_pop(stk);
    printf("Stack after popping: \n");
    Stack_print(stk);
    Stack_pop(stk);
    printf("Stack after popping: \n");
    Stack_print(stk);
    return 0;
}
