#include "hello_world.h"
#include <stdlib.h>
#include <string.h>

const char *hello(void)
{
    char * ans = malloc(sizeof(char) * strlen("Hello, World!") + 1); /* Allocate as many bytes as needed +1 for the NUL-terminator*/
    if (!ans) {
        return NULL;
    }
    
    strcpy(ans, "Hello, World!");
    
    return  ans;
}
