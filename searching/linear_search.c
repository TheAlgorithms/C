/**
 * @file
 * @brief Algorithm to Search an Element from the array
 * @details
 * [Liear Search](https://en.wikipedia.org/wiki/Linear_search)
 * This algorithm traverse through the array
 * Check if the current element is equal to the searched element
 * If found it returns the index of the found location
 * Time Complexity: O(N)
 * @author [Shashi Raj](https://github.com/shashirajraja)
 * @author [Gabriel Alves](https://github.com/sp0oks)
 */

#include <assert.h>  /// for assert
#include <stdio.h>   /// for IO operations
#include <stdint.h>  /// for fixed width integer types

/**
 * @brief Function For linear search of the element
 * @details
 * This function takes the array and item to be searched as input
 * Traverse through the array linearly
 * If the element is found during traversal returns the location
 * @param arr the array containing all the items
 * @param size the size of the array
 * @param val the item to be searched
 * @return -1 if not found else the location of the item
 */
uint64_t linearsearch(uint64_t *arr, int64_t size, uint64_t val)
{
    int64_t i;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == val)
            return (i+1);
    }
    return -1;
}


/**
 * @brief Self-test implementations
 * @returns void
 */
static void test() {
	
	uint64_t arr[] = {10,12,52,34,19,36,27,81,9,2,6,5,2,6,21,55};
	
	assert(linearsearch(arr, 16, 52) == 3);
	assert(linearsearch(arr, 16, 10) == 1);
	assert(linearsearch(arr, 16, 6) == 11);
	assert(linearsearch(arr, 16, 55) == 16);
	assert(linearsearch(arr, 16, 19) == 5);
	assert(linearsearch(arr, 16, 36) == 6);
	assert(linearsearch(arr, 16, 91) == -1);
    
	printf("All test cases have successfully passed!\n");
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main()
{
    test();  // run self-test implementations
    return 0;
}
