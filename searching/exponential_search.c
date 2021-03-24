/**
 *  \file
 *  \link Algorithm explanation:
 *  https://github.com/TheAlgorithms/Algorithms-Explanation/blob/master/en/Search%20Algorithms/Exponential%20Search.md
 *  \author [Alessio Farinelli] (https://github.com/faridevnz)
 */
#include <assert.h>

#define ELEMENT -10

int binary_search(const int* arr, const int l_index, const int r_index, const int n);
int exponential_search(const int* arr, const int length, const int n);
void test(void);

/**
 *  Function: exponential_search
 *  ----------------------------
 *  \param arr:         array where search the element
 *  \param length:      the total length of the given array (arr)
 *  \param n:           element to find in the array (arr)
 * 
 *  \returns:           the index of the element (n) in the array (arr)
 *  \returns:           -1 if the element wasn't found
 */
int exponential_search(const int* arr, const int length, const int n) 
{
    // find the upperbound
    int upper_bound = 1;
    while ( upper_bound <= length && arr[upper_bound] < n ) upper_bound = upper_bound * 2;
    // calculate the range ( between lower_boud and upper_bound )
    int lower_bound = upper_bound/2;
    if ( upper_bound > length ) upper_bound = length;
    // apply the binary search in the range
    return binary_search(arr, lower_bound, upper_bound, n);
}

/**
 *  Function: binary_search
 *  ----------------------------
 *  \param arr:         array where search the element
 *  \param l_index:     start index of the array (arr) to apply the algorithm
 *  \param r_index:     end index of the array (arr) to apply the algorithm
 *  \param n:           element to find in the array (arr)
 * 
 *  \returns:           the index of the element (n) in the array (arr)
 *  \returns:           -1 if the n element wasn't found
 */
int binary_search(const int* arr, const int l_index, const int r_index, const int n) 
{
    // calculate the middle index of the array
    int middle_index = l_index + ( r_index - l_index ) / 2;
    // base cases
    if ( l_index > r_index ) return -1;
    if ( arr[middle_index] == n ) return middle_index;
    // recursion
    if ( arr[middle_index] > n ) return binary_search(arr, l_index, middle_index-1, n); // left
    return binary_search(arr, middle_index+1, r_index, n); // right
}

/**
 *  Function: main
 *  --------------
 */
int main(void) 
{
    // perform the tests
    test();
    return 0;
}

/**
 *  Function: test
 *  --------------
 */
void test(void)
{
    // empty array
    int arr_empty[] = {};
    assert(exponential_search(arr_empty, 0, 10) == -1);
    // elent not found
    int arr_found[] = {1, 2, 3};
    assert(exponential_search(arr_found, 3, 10) == -1);
    // element found in an array of length 1
    int arr_one[] = {1};
    assert(exponential_search(arr_found, 1, 1) == 0);
    // find the first element in an array of length 2
    int arr_first_2[] = {1, 2};
    assert(exponential_search(arr_first_2, 2, 1) == 0);
    // find the last element in an array of length 2
    int arr_last_2[] = {1, 2};
    assert(exponential_search(arr_last_2, 2, 2) == 1);
    // find the first element in an array of length n
    int arr_first_n[] = {-1, 2, 4, 6, 8};
    assert(exponential_search(arr_first_n, 5, -1) == 0);
    // find the last element in an array of length n
    int arr_last_n[] = {-1, 2, 4, 6, 8};
    assert(exponential_search(arr_last_n, 5, 8) == 4);
    // find an element in an array of length n
    int arr_middle[] = {-1, 2, 4, 6, 8};
    assert(exponential_search(arr_middle, 5, 6) == 3);
}
