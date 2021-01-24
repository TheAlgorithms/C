/**
 * @file
 * @brief File used to test the malloc_dbg, calloc_dbg and free_dbg functions.
 * @details
 * This file only have a main function that calls malloc, calloc and free.
 * When the program exits, memory leaks must be printed.
 * @author tinouduart33
 * @see malloc_dbg.c, malloc_dbg.h
 */

#include <stdio.h>
#include <stdlib.h>
#include "malloc_dbg.h"


/**
 * @brief Main function
 * @returns 0 on exit
 */
int main(int argc, char* argv[])
{
	int* iptr = malloc(10 * sizeof(int));
	char* cptr = calloc(256, sizeof(char));

	free(iptr);
	// free(cptr);

	return EXIT_SUCCESS;
}
