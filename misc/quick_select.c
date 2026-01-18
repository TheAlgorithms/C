/**
 * @file
 * @brief Kth largest element in linear time [Wikipedia: Selection Algorithm](https://en.wikipedia.org/wiki/Selection_algorithm)[Median of Medians](https://en.wikipedia.org/wiki/Median_of_medians)
 * @details
 * Quick Select is a linear-time algorithm for finding the kth largest element in an unsorted array.
 * It uses the median-of-medians algorithm to guarantee a good pivot selection, achieving O(n) 
 * average time complexity and avoiding the O(n^2) worst-case of naive quickselect.
 * @author [Nothinormuch](https://github.com/Nothinormuch/)
 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>

/**
 * @brief Prints a portion of an array
 */
void print_arr(int * arr, int start, int stop){
    printf("[%d",arr[start]);
    for(int i = start+1; i < stop+1; i ++){
        printf(",%d",arr[i]);
    }
    printf("]");
}

/**
 * @brief Swaps two elements in an array
 * @param arr array pointer
 * @param i Index of first element
 * @param j Index of second element
 */
void swap(int * arr, int i, int j){
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

int partition(int * arr, int start, int stop, int pivot_value);
int median_of_medians(int * arr, int start, int stop);
int median_of_medians_helper(int * arr, int start, int stop);

/**
 * @brief Partitions array so elements greater than pivot are on the left
 * @details
 * Rearranges elements so that all elements greater than the pivot_value
 * are moved to the left side, smaller elements remain on the right.
 * The pivot is placed at the boundary between these two groups.
 * @param arr Pointer to the array
 * @param start Starting index of the partition range
 * @param stop Ending index of the partition range
 * @param pivot_value The value to partition around
 * @returns The final position of the pivot element
 */
int partition(int * arr, int start, int stop, int pivot_value){
    int i = start;  // boundary pointer between larger and smaller elements
    
    // Move all elements greater than pivot to the left
    for (int j = start; j <= stop; j++){
        if (arr[j] > pivot_value){
            swap(arr, i, j);
            i++;
        }
    }
    
    // Find and place the pivot at position i
    for (int j = i; j <= stop; j++){
        if (arr[j] == pivot_value){
            swap(arr, i, j);
            break;
        }
    }
    return i;
}

/**
 * @brief Finds a good pivot value using the median-of-medians algorithm
 * @details
 * Uses a divide-and-conquer strategy: divides the array into groups of 5,
 * finds the median of each group, then recursively finds the median of those medians.
 * This guarantees O(n) linear time complexity regardless of input distribution.
 * @param arr Pointer to the array
 * @param start Starting index of the range
 * @param stop Ending index of the range
 * @returns The median value (suitable for use as a pivot)
 */
int median_of_medians(int * arr, int start, int stop){
    int len = stop - start + 1;
    
    // Base case: small arrays just get sorted and return middle element
    if (len <= 5){
        for (int i = start; i <= stop; i++){
            for (int j = start; j < stop - (i - start); j++){
                if (arr[j] > arr[j + 1]){
                    swap(arr, j, j + 1);
                }
            }
        }
        return arr[start + len / 2];
    }
    
    // Divide into groups of 5
    int num_groups = (len + 4) / 5;  // ceiling division
    int * medians = (int *)malloc(sizeof(int) * num_groups);
    
    for (int i = 0; i < num_groups; i++){
        int sub_start = start + i * 5;
        // Last group may have fewer than 5 elements
        int sub_stop = (sub_start + 4 > stop) ? stop : sub_start + 4;
        int sub_len = sub_stop - sub_start + 1;
        
        // Sort this group
        for (int j = sub_start; j <= sub_stop; j++){
            for (int k = sub_start; k < sub_stop - (j - sub_start); k++){
                if (arr[k] > arr[k + 1]){
                    swap(arr, k, k + 1);
                }
            }
        }
        medians[i] = arr[sub_start + sub_len / 2];  // store median of this group
    }
    
    // Recursively find the median of all medians
    int result = median_of_medians_helper(medians, 0, num_groups - 1);
    free(medians);
    return result;
}

/**
 * @brief Recursive helper for median-of-medians algorithm
 * @details
 * This function implements the same median-of-medians logic as the parent function.
 * It's separated as a helper to manage recursion properly without modifying the original array unexpectedly.
 * @param arr Pointer to the array
 * @param start Starting index of the range
 * @param stop Ending index of the range
 * @returns The median value
 */
int median_of_medians_helper(int * arr, int start, int stop){
    int len = stop - start + 1;
    if (len <= 5){
        for (int i = start; i <= stop; i++){
            for (int j = start; j < stop - (i - start); j++){
                if (arr[j] > arr[j + 1]){
                    swap(arr, j, j + 1);
                }
            }
        }
        return arr[start + len / 2];
    }
    
    int num_groups = (len + 4) / 5;
    int * medians = (int *)malloc(sizeof(int) * num_groups);
    
    for (int i = 0; i < num_groups; i++){
        int sub_start = start + i * 5;
        int sub_stop = (sub_start + 4 > stop) ? stop : sub_start + 4;
        int sub_len = sub_stop - sub_start + 1;
        
        for (int j = sub_start; j <= sub_stop; j++){
            for (int k = sub_start; k < sub_stop - (j - sub_start); k++){
                if (arr[k] > arr[k + 1]){
                    swap(arr, k, k + 1);
                }
            }
        }
        medians[i] = arr[sub_start + sub_len / 2];
    }
    
    int result = median_of_medians_helper(medians, 0, num_groups - 1);
    free(medians);
    return result;
}

/**
 * @brief Finds the kth largest element in an array
 * @details
 * Uses the median-of-medians algorithm to find a good pivot, then partitions
 * the array and recursively searches the appropriate half. The pivot selection
 * guarantees O(n) time complexity in all cases (best, average, and worst).
 * k is 1-based: k=1 returns the largest, k=2 returns the 2nd largest, etc.
 * @param arr Pointer to the array
 * @param k The rank to find (1 = largest, 2 = 2nd largest, ..., n = smallest)
 * @param start Starting index of the search range
 * @param stop Ending index of the search range
 * @returns The kth largest element, or -1 if the range is invalid
 */
int kth_largest(int * arr, int k, int start, int stop){
    if (start > stop) return -1;
    
    // Use median-of-medians to pick a good pivot
    int pivot_value = median_of_medians(arr, start, stop);
    
    // Partition: larger elements go left, smaller go right of partition
    int pivot_index = partition(arr, start, stop, pivot_value);
    // Rank = how many elements are >= pivot_value
    int rank = pivot_index - start + 1;
    
    // Check if we found the answer
    if (rank == k){
        return pivot_value;
    }
    // Kth largest is in left half (larger elements)
    else if (rank > k){
        return kth_largest(arr, k, start, pivot_index - 1);
    }
    // Kth largest is in right half (smaller elements), adjust k by how many are seen
    else{
        return kth_largest(arr, k - rank, pivot_index + 1, stop);
    }
}


/**
 * @brief Test cases
 */
static void test() {
    // Test 1: Simple unsorted array, find 3rd largest (17)
    int arr1[] = {7, 1, 15, 3, 19, 11, 5, 18, 2, 14, 9, 4, 16, 8, 12, 6, 17, 10, 13};
    int result1 = kth_largest(arr1, 3, 0, 18);
    assert(result1 == 17);
    printf("Test 1 passed: 3rd largest in unsorted array is 17\n");

    // Test 2: Find the largest element (k=1)
    int arr2[] = {5, 2, 8, 1, 9, 3};
    int result2 = kth_largest(arr2, 1, 0, 5);
    assert(result2 == 9);
    printf("Test 2 passed: 1st largest (max) is 9\n");

    // Test 3: Find the smallest element (k=n)
    int arr3[] = {5, 2, 8, 1, 9, 3};
    int result3 = kth_largest(arr3, 6, 0, 5);
    assert(result3 == 1);
    printf("Test 3 passed: 6th largest (min) in 6-element array is 1\n");

    // Test 4: Single element array
    int arr4[] = {42};
    int result4 = kth_largest(arr4, 1, 0, 0);
    assert(result4 == 42);
    printf("Test 4 passed: 1st largest in single-element array is 42\n");

    // Test 5: Two elements, find largest
    int arr5[] = {10, 20};
    int result5 = kth_largest(arr5, 1, 0, 1);
    assert(result5 == 20);
    printf("Test 5 passed: 1st largest in two-element array is 20\n");

    // Test 6: Two elements, find smallest
    int arr6[] = {10, 20};
    int result6 = kth_largest(arr6, 2, 0, 1);
    assert(result6 == 10);
    printf("Test 6 passed: 2nd largest in two-element array is 10\n");

    // Test 7: Array with duplicates, find 4th largest
    int arr7[] = {5, 3, 5, 2, 5, 1, 5};
    int result7 = kth_largest(arr7, 4, 0, 6);
    assert(result7 == 5);  // sorted desc: [5,5,5,5,3,2,1], 4th is 5
    printf("Test 7 passed: 4th largest with duplicates is 5\n");

    // Test 8: Already sorted (descending), find middle
    int arr8[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int result8 = kth_largest(arr8, 5, 0, 9);
    assert(result8 == 6);
    printf("Test 8 passed: 5th largest in sorted descending array is 6\n");

    // Test 9: Already sorted (ascending), find 3rd largest
    int arr9[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int result9 = kth_largest(arr9, 3, 0, 9);
    assert(result9 == 8);
    printf("Test 9 passed: 3rd largest in sorted ascending array is 8\n");

    // Test 10: Larger array with random values
    int arr10[] = {45, 23, 78, 12, 89, 34, 56, 90, 67, 21, 98, 54, 32, 11, 88, 77, 42};
    int result10 = kth_largest(arr10, 5, 0, 16);
    assert(result10 == 78);  // 5th largest: 98, 90, 89, 88, 78
    printf("Test 10 passed: 5th largest in random array is 78\n");

    printf("\nAll tests have successfully passed!\n");
}

// Main Function
int main(){
    test();
    return 0;
}
