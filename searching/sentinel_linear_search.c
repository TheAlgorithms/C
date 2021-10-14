/**
 * @file
 * @brief [Linear search](https://en.wikipedia.org/wiki/Linear_search#With_a_sentinel) implementation
 * @details
 * This algorithm saves the last element of the array, 
 * then replaces it with the value to be found and sets it as the sentinel. 
 * When searching, compares each element with the sentinel. 
 * If the same, returns the index. If the index is the index of the sentinel, it means it was not found. 
 * Of course, if the value to be found is the last element, we return the index of the last element.
 * @author [Regan Yue](https://github.com/ReganYue)
 * Time Complexity: O(N)
 */

#include<stdio.h> // for IO operations
#include<assert.h> // for assert

/**
 * search for an element in the array and return the index of the element.
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
	
	int i;
	for(i=0;arr[len-1]!=arr[i];i++){
		if(i==len-1){
			break;
		}
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
	test(); // run self-test implementations
	return 0;
}
