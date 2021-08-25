/**
 * @file
 * @brief File used to test the malloc_dbg, calloc_dbg and free_dbg functions.
 * @details
 * This file only have a main function that calls malloc, calloc and free.
 * When the program exits, memory leaks must be printed.
 * @author [tinouduart33](https://github.com/tinouduart33)
 * @see malloc_dbg.c, malloc_dbg.h
 */

#include <stdio.h> /// For IO operations if needed.
#include <stdlib.h> /// For the EXIT_SUCCESS macro and the "real" malloc, calloc and free functions.
#include "malloc_dbg.h" /// For the macros malloc, calloc and free and the malloc_dbg, calloc_dbg and free_dbg functions.


/**
 * @brief Main function
 * @param argc number of arguments (not used)
 * @param argv list of arguments (not used)
 * @returns 0 on exit
 */
int main(int argc, char* argv[])
{
    // TEST 1
    int* iptr = malloc(10 * sizeof(int));
    char* cptr = calloc(256, sizeof(char));

    free(iptr);
    // free(cptr);

    // TEST 2
    // Initialize an array then free it.
    int* test_list[5] = {NULL};

    for (unsigned i = 0; i < 5; i++)
    {
        test_list[i] = malloc(sizeof(int));
    }

    for (unsigned i = 0; i < 2; i++)
    {
        free(test_list[i]);
    }

    /*
     * Expected output on exit: 
     * == == == == == == == == == == == == == == == == == ==
     * SUMMARY : 
     * 268 bytes lost in 4 blocks
    */
	return 0;
}
