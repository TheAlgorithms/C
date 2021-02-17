/**
 * @file
 * @brief Header file that contains macros used to replace malloc/calloc and free.
 * @details
 * Macros malloc, calloc and free respectively calls malloc_dbg, calloc_dbg and free_dbg.
 * malloc_dbg and calloc_dbg allocates memory using the "real" malloc and calloc and store
 * the pointer returned (with additional informations) in a linked list.
 * Thanks to this linked list, it is possible to check memory leaks.
 * @author [tinouduart33](https://github.com/tinouduart33)
 * @see malloc_dbg.c
 */

#ifndef MALLOC_DBG_H
#define MALLOC_DBG_H

 /** This macro replace the standard malloc function with malloc_dbg.
  * */
#define malloc(bytes) malloc_dbg(bytes, __LINE__, __FILE__, __FUNCTION__)

  /** This macro replace the standard calloc function with calloc_dbg.
   * */
#define calloc(elemCount, elemSize) calloc_dbg(elemCount, elemSize, __LINE__, __FILE__, __FUNCTION__)

   /** This macro replace the standard free function with free_dbg.
	* */
#define free(ptr) free_dbg(ptr)

void* malloc_dbg(size_t bytes, int line, const char* filename, const char* functionName);

void* calloc_dbg(size_t elementCount, size_t elementSize, int line, const char* filename, const char* functionName);

void free_dbg(void* ptrToFree);

void printLeaks(void);

#endif /* MALLOC_DBG_H */
