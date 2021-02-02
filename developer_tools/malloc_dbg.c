/**
 * @file
 * @brief This file contains malloc_dbg, calloc_dbg, free_dbg and printLeaks implementations.
 * @author tinouduart33
 */

#include <stdlib.h> /// For the malloc, calloc and free functions.
#include <stdio.h> /// For IO operations (printf).
#include <string.h> /// For the memcmp function.
#include "malloc_dbg.h" /// Header file which contains the prototypes of malloc_dbg, calloc_dbg and fre_dbg.

 /* We must undef these macros in order to use the real malloc / calloc and free functions */
#undef malloc
#undef calloc
#undef free

/**
 * @brief Structure used to save an allocated pointer
 */
typedef struct MEMORY_INFORMATION
{
	void* ptr; ///< Pointer returned by malloc / calloc
	const char* fileName; ///< File in which malloc or calloc has been called
	const char* functionName; ///< Function in which malloc or calloc has been called
	size_t bytes; ///< Number of bytes allocated
	int line; ///< Line number (in file) corresponding to the malloc / calloc call
	struct MEMORY_INFORMATION* next; ///< Next element in the list
	struct MEMORY_INFORMATION* previous; ///< Previous element in the list
} mem_info;

/** We use a global variable for the list so we can use it at any time.
 * */
mem_info* memoryInformation = NULL;

/** Another global variable. This one is used to know if we already call the atexit function.
 * */
int atexitCalled = 0;


/**
 * @brief addMemInfo function
 * @details This function creates a new element and add it on top of the list
 * @returns mem_info pointer if it succeeds, NULL otherwise
 */
mem_info* addMemInfo(mem_info* memoryInfo, void* ptrToReturn, size_t bytes, int line, const char* filename, const char* functionName)
{
	mem_info* newMemInfo = (mem_info*)malloc(sizeof(mem_info));
	if (!newMemInfo)
		return NULL;

	newMemInfo->ptr = ptrToReturn;
	newMemInfo->bytes = bytes;
	newMemInfo->line = line;
	newMemInfo->fileName = filename;
	newMemInfo->functionName = functionName;
	newMemInfo->next = memoryInfo;
	newMemInfo->previous = NULL;
	if (memoryInformation)
		memoryInformation->previous = newMemInfo;

	return newMemInfo;
}

/**
 * @brief inList function
 * @details This function is used to know if an allocation in a specific file at a specific line already exists in the list.
 * @returns Position of the element in the list if the element is found, -1 otherwise.
 */
int inList(const char* filename, int line)
{
	mem_info* tmp = memoryInformation;
	int counter = 0;
	int len = strlen(filename);

	while (tmp)
	{
		if (len == strlen(tmp->fileName))
		{
			if (!memcmp(filename, tmp->fileName, len) && tmp->line == line)
				return counter;
		}
		tmp = tmp->next;
		counter++;
	}
	return -1;
}

/**
 * @brief editInfo function
 * @details This function is used to edit the number of bytes allocated at a specific line.
 * @returns Nothing.
 */
void editInfo(int elemPos, size_t bytes)
{
	int counter = 0;
	mem_info* tmp = memoryInformation;

	while (counter != elemPos)
	{
		tmp = tmp->next;
		counter++;
	}
	tmp->bytes += bytes;
}

/**
 * @brief malloc_dbg function
 * @details This function calls malloc and allocates the number of bytes passed in the parameters.
 * If the allocation succeeds then it add the pointer returned by malloc in the mem_info list.
 * @returns Pointer returned by malloc if it's valid, NULL otherwhise.
 */
void* malloc_dbg(size_t bytes, int line, const char* filename, const char* functionName)
{
	void* ptrToReturn = malloc(bytes);
	int pos = 0;
	if (!ptrToReturn)
		return NULL;

	/* We must check atexitCalled value to know if we already called the function */
	if (!atexitCalled)
	{
		atexit(printLeaks); /* Used to call printLeaks when the program exit */
		atexitCalled = 1;
	}

	pos = inList(filename, line);
	if (pos == -1)
	{
		/* Add a new element in the mem_info list */
		memoryInformation = addMemInfo(memoryInformation, ptrToReturn, bytes, line, filename, functionName);
		if (!memoryInformation)
		{
			free(ptrToReturn);
			return NULL;
		}
	}
	else
	{
		editInfo(pos, bytes);
	}
	return ptrToReturn;
}

/**
 * @brief calloc_dbg function
 * @details This function calls calloc and allocates the number of bytes passed in the parameters.
 * If the allocation succeeds then it add the pointer returned by malloc in the mem_info list.
 * @returns Pointer returned by calloc if it's valid, NULL otherwhise.
 */
void* calloc_dbg(size_t elementCount, size_t elementSize, int line, const char* filename, const char* functionName)
{
	void* ptrToReturn = calloc(elementCount, elementSize);
	if (!ptrToReturn)
		return NULL;

	/* We must check atexitCalled value to know if we already called the function */
	if (!atexitCalled)
	{
		atexit(printLeaks); /* Used to call printLeaks when the program exit */
		atexitCalled = 1;
	}

	/* Add a new element in the mem_info list */
	memoryInformation = addMemInfo(memoryInformation, ptrToReturn, elementCount * elementSize, line, filename, functionName);
	if (!memoryInformation)
	{
		free(ptrToReturn);
		return NULL;
	}

	return ptrToReturn;
}

/**
 * @brief free_dbg function
 * @details This function free the memory pointed by the pointer passed in parameter.
 * To free this pointer, we loop through the mem_info list and check if we find the pointer.
 * Once it's found, the pointer is freed and the element is deleted from the list.
 * @returns Nothing.
 */
void free_dbg(void* ptrToFree)
{
	mem_info* tmp = memoryInformation;
	mem_info* toFree = NULL;
	mem_info* previous = NULL;

	/* Check if the head contains the pointer to free */
	if (tmp->ptr == ptrToFree)
	{
		toFree = tmp;
		memoryInformation = tmp->next;
		free(toFree->ptr);
		free(toFree);
		if (memoryInformation)
			memoryInformation->previous = NULL;
		return;
	}

	/* We can loop through the list without any problems, the head is not the pointer */
	while (tmp)
	{
		if (tmp->ptr == ptrToFree) /* If we found the pointer that must be freed */
		{
			toFree = tmp;
			tmp = tmp->next;
			previous = toFree->previous;

			if (previous)
				previous->next = tmp;
			if (tmp)
				tmp->previous = previous;

			free(toFree->ptr);
			if (toFree == memoryInformation)
				memoryInformation = NULL;
			free(toFree);
			return;
		}
		tmp = tmp->next;
	}
}

/**
 * @brief printLeaks function
 * @details This function is called when the program exits. It loop through the mem_info list and if it's not empty,
 * it prints the memory leaks.
 * @returns Nothing.
 */
void printLeaks()
{
	mem_info* tmp = memoryInformation;
	mem_info* previous = NULL;
	size_t sum = 0;
	int nbBlocks = 0;

	if (tmp)
		printf("Memory Leaks detected.\n");

	while (tmp)
	{
		previous = tmp;
		printf("\n%ld bytes lost\n", tmp->bytes);
		printf("address : 0x%p in %s\t%s:%d\n", tmp->ptr, tmp->functionName, tmp->fileName, tmp->line);
		printf("\n====================================\n");
		sum += tmp->bytes;
		tmp = tmp->next;
		free(previous);
		nbBlocks++;
	}

	printf("SUMMARY :\n%ld bytes lost in %d blocks\n", sum, nbBlocks);
}
