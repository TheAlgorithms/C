/**
 * @file exponential_search2.c
 * @brief Alternative implementation of [Exponential Search](https://en.wikipedia.org/wiki/Exponential_search).
 * @details
 * This version performs range expansion using safe bounds and a tight binary
 * search. It returns the index of the target in a sorted array or -1 if not found.
 * @author [hobostay](https://github.com/hobostay)
 */

#include <assert.h>   /// for assert
#include <stdio.h>    /// for printf

/**
 * @brief Binary search within the closed interval [left, right]
 */
static int bsearch_closed(const int *arr, int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int v = arr[mid];
        if (v == x) {
            return mid;
        }
        if (v < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

/**
 * @brief Exponential search on a sorted array
 * @param arr pointer to sorted array
 * @param n length of array
 * @param x target value to search for
 * @returns index of x if found, otherwise -1
 */
int exponential_search2(const int *arr, int n, int x) {
    if (arr == NULL || n <= 0) {
        return -1;
    }
    if (arr[0] == x) {
        return 0;
    }
    int bound = 1;
    while (bound < n && arr[bound] < x) {
        bound <<= 1;  // double
    }
    int left = bound >> 1;
    int right = (bound < n) ? bound : (n - 1);
    return bsearch_closed(arr, left, right, x);
}

/**
 * @brief Self tests for exponential_search2
 */
static void test(void) {
    printf("Test 1.... ");
    int a1[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int n1 = (int)(sizeof(a1) / sizeof(a1[0]));
    assert(exponential_search2(a1, n1, 1) == 0);
    assert(exponential_search2(a1, n1, 15) == 7);
    assert(exponential_search2(a1, n1, 7) == 3);
    assert(exponential_search2(a1, n1, 4) == -1);
    printf("passed\n");

    printf("Test 2.... ");
    int a2[] = {-10, -5, -1, 0, 2, 4, 8, 16, 32, 64};
    int n2 = (int)(sizeof(a2) / sizeof(a2[0]));
    assert(exponential_search2(a2, n2, -10) == 0);
    assert(exponential_search2(a2, n2, 64) == 9);
    assert(exponential_search2(a2, n2, 32) == 8);
    assert(exponential_search2(a2, n2, 100) == -1);
    printf("passed\n");

    printf("Test 3.... ");
    int a3[] = {2};
    int n3 = (int)(sizeof(a3) / sizeof(a3[0]));
    assert(exponential_search2(a3, n3, 2) == 0);
    assert(exponential_search2(a3, n3, 3) == -1);
    printf("passed\n");

    printf("Test 4.... ");
    assert(exponential_search2(NULL, 0, 1) == -1);
    printf("passed\n");
}

/**
 * @brief Main function
 */
int main(void) {
    test();
    return 0;
}