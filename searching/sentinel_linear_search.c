/**
 * @file
 * @brief [Linear Search with Sentinel](https://en.wikipedia.org/wiki/Linear_search#With_a_sentinel) algorithm implementation
 * @details
 * This algorithm saves the last element of the array, 
 * then replaces it with the value to be found and sets it as the sentinel. 
 * When searching, compares each element with the sentinel. 
 * If the same, returns the index. If the index is the index of the sentinel, it means it was not found. 
 * Of course, if the value to be found is the last element, we return the index of the last element.
 * @author [Regan Yue](https://github.com/ReganYue)
 * Time Complexity: O(N)
 */

#include <stdio.h>   /// for IO operations
#include <assert.h>  /// for assert

/**
 * @brief Utility function to search for an element in the array and return the index of the element
 * @details 
 * The so-called "sentinel" is to use a special value as the boundary key of the array. 
 * One less judgment statement can be used. 
 * The purpose is to avoid checking whether the entire array is searched at each step in the search 
 * process, so as to improve the efficiency of the program.
 * We can use the last value of the array as the "sentinel", the data storage index i 
 * starts from 0 and ends at len-1, then the position where the index of arr is n-1 indicates 
 * that there is no data temporarily, which is the "sentinel" key.
 * If the last element of the array is equal to the key, directly return the index of the last element. 
 * Before setting the last element of the array as the key, we hand over the last element of the array to temp for temporary storage. 
 * Then go to the array to find the key. If the key is found, stop the search, and then compare the found element index with len-1. 
 * If it is equal, it means it was not found. If it is not equal, it is found.
 * @param arr this is an array containing elements
 * @param len this is the number of elements in the array
 * @param key the value we want to search
 * @return i if found, otherwise -1 is returned.
 */
int sentinel_linear_search( int arr[], int len, int key ){
	if(key == arr[len-1]){
		return len-1;
	}
	
	int temp = arr[len-1]; 
	arr[len-1] = key;
	
	int i = 0;
	while (arr[len-1] != arr[i]) {
		i++;
	}
	
	arr[len-1] = temp;
	
	return i != len-1 ? i : -1;
	 
}

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test(){
	int n,i;
	n = 5;
	/* init array */
	int arr[] = { 1, 2, 2, 6, 99, 100, 999 };

	assert(sentinel_linear_search( arr, n, 1 )==0);
	assert(sentinel_linear_search( arr, n, 2 )==1);
	assert(sentinel_linear_search( arr, n, 6 )==3);
	assert(sentinel_linear_search( arr, n, 101 )==-1);
	printf("All test cases have successfully passed!\n");
} 

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main(){
	test();  // run self-test implementations
	return 0;
}
