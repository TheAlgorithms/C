#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

/**
 * Test function type
*/
typedef void (*test_func_t) (void);

/**
 * The template for test function
*/
void test(){
    assert(true);
}

/**
 * Main function
*/
int main(int argc, char **argv) {
    return 0;
}
