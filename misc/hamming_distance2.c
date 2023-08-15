/**
 * @file
 * @author [BenSt099](https://github.com/BenSt099)
 * @brief Computes the [Hamming distance](https://en.wikipedia.org/wiki/Hamming_distance)
 * of two Integer-Arrays
 * @details
 * In information theory, the Hamming distance between two strings of
 * equal length is the number of positions at which the corresponding symbols
 * are different.
 * @see  
 */

#include <assert.h>  /// for assert
#include <stdio.h>   /// for IO operations

/**
 * @brief Function that calculates the Hamming distance between two Integer-arrays
 * @param param1 int* Pointer for Hamming distance
 * @param param2 int  length of the two arrays
 * @param param3 int* first int-array
 * @param param4 int* second int-array
 * @returns Pointer to Hamming distance
 */
int* hamming_distance(int length, int* s1, int* s2) {
    int dist = 0;
    int* distptr = &dist;
    int left = 0; // position of first element
    int right = length - 1; // position of last element

    /**
     * The main calculation loop.
     * In each loop, we compute the hamming-distance from left and from right at the same time while
     * moving towards the middle position.
     * Then we set left and right to new position.
     * When the number of elements is even, we're done. When the number is uneven, there is still an element
     * in the middle left.
    */
    while(left < right){
        dist += (int) s1[left] != s2[left];
        dist += (int) s1[right] != s2[right];
        ++left;
        --right;
    }

    // if number of integer is uneven, then add hamming-distance from element in the middle
    dist += (length % 2 != 0) * ((int) s1[(length - 1) / 2] != s2[(length - 1) / 2]);
    return distptr;
}

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test() {

    /* tests if h_dist is calculated correctly with even number of integers */
    int s1[10] = {1,2,6,6,8,9,3,4,0,5}; 
    int s2[10] = {1,2,7,6,8,9,3,2,0,5};
    int* ptr1 = &s1[0];
    int* ptr2 = &s2[0];
    int* h_dist = hamming_distance(10, ptr1, ptr2);
    assert(*h_dist == 2); 

    /* tests if h_dist is calculated correctly with uneven number of integers */
    int s3[13] = {1,2,6,6,8,9,3,4,0,5,6,7,6}; 
    int s4[13] = {1,2,7,6,8,9,3,2,0,5,6,1,6};
    int* ptr3 = &s3[0];
    int* ptr4 = &s4[0];
    int* h_dist2 = hamming_distance(13, ptr3, ptr4);
    assert(*h_dist2 == 3);

    printf("All tests have successfully passed!\n");
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main(void) {
    test();  // run self-test implementations
    return 0;
}
