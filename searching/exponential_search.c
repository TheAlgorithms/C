/**
 *  \file
 *  \brief [Exponential Search](https://github.com/TheAlgorithms/Algorithms-Explanation/blob/master/en/Search%20Algorithms/Exponential%20Search.md)
 *  \author [Alessio Farinelli](https://github.com/faridevnz)
 */
#include <assert.h>    /// for assert
#include <inttypes.h>  /// for int64_t, uint16_t
#include <stdio.h>     /// for printf

#define ELEMENT -10

int64_t binary_search(const int64_t* arr, const uint16_t l_index, const uint16_t r_index, const int64_t n); ///< used to perform the binary search over the given array
int64_t exponential_search(const int64_t* arr, const uint16_t length, const int64_t n); ///< used to perform the exponential search over the given array
static void test(); ///< used to run the self-test implementations

/**
 * Function: exponential_search
 * \brief algorithm that search the index of the given item
 * \details recursive function that take an array and quickly find the range 
 * where to apply the binary search algorithm to find the given element
 * ----------------------------
 * \param arr array where search the element
 * \param length the total length of the given array (arr)
 * \param n element to find in the array (arr)
 * 
 * \returns the index of the element (n) in the array (arr)
 * \returns -1 if the element wasn't found
 */
int64_t exponential_search(const int64_t* arr, const uint16_t length, const int64_t n) 
{
    if ( length == 0 ) { return -1; }
    // find the upperbound
    uint32_t upper_bound = 1;
    while ( upper_bound <= length && arr[upper_bound] < n ) { upper_bound = upper_bound * 2; }
    // calculate the range ( between lower_boud and upper_bound )
    uint16_t lower_bound = upper_bound/2;
    if ( upper_bound > length ) { upper_bound = length; }
    // apply the binary search in the range
    return binary_search(arr, lower_bound, upper_bound, n);
}

/**
 * Function: binary_search
 * \brief algorithm that search the index of the given item
 * \details recursive function that search the given element in
 * the array using the [Binary Search](https://github.com/TheAlgorithms/Algorithms-Explanation/blob/master/en/Search%20Algorithms/Binary%20Search.md)
 * ----------------------------
 * \param arr array where search the element
 * \param l_index start index of the array (arr) to apply the algorithm
 * \param r_index end index of the array (arr) to apply the algorithm
 * \param n element to find in the array (arr)
 *
 * \returns the index of the element (n) in the array (arr)
 * \returns -1 if the n element wasn't found
 */
int64_t binary_search(const int64_t* arr, const uint16_t l_index, const uint16_t r_index, const int64_t n) 
{
    // calculate the middle index of the array
    uint16_t middle_index = l_index + ( r_index - l_index ) / 2;
    // base cases
    if ( l_index > r_index ) { return -1; }
    if ( arr[middle_index] == n ) { return middle_index; }
    // recursion
    if ( arr[middle_index] > n ) { return binary_search(arr, l_index, middle_index-1, n); } // left
    return binary_search(arr, middle_index+1, r_index, n); // right
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

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test()
{
    // empty array
    int64_t arr_empty[] = { 0 };
    assert(exponential_search(arr_empty, 0, 10) == -1);
    // elent not found
    int64_t arr_found[] = {1, 2, 3};
    assert(exponential_search(arr_found, 3, 10) == -1);
    // element found in an array of length 1
    int64_t arr_one[] = {1};
    assert(exponential_search(arr_found, 1, 1) == 0);
    // find the first element in an array of length 2
    int64_t arr_first_2[] = {1, 2};
    assert(exponential_search(arr_first_2, 2, 1) == 0);
    // find the last element in an array of length 2
    int64_t arr_last_2[] = {1, 2};
    assert(exponential_search(arr_last_2, 2, 2) == 1);
    // find the first element in an array of length n
    int64_t arr_first_n[] = {-1, 2, 4, 6, 8};
    assert(exponential_search(arr_first_n, 5, -1) == 0);
    // find the last element in an array of length n
    int64_t arr_last_n[] = {-1, 2, 4, 6, 8};
    assert(exponential_search(arr_last_n, 5, 8) == 4);
    // find an element in an array of length n
    int64_t arr_middle[] = {-1, 2, 4, 6, 8};
    assert(exponential_search(arr_middle, 5, 6) == 3);

    printf("All tests have successfully passed!\n");
}
