/**
 * @file
 * @brief Program to perform [binary
 * search](https://en.wikipedia.org/wiki/Binary_search_algorithm) of a target
 * value in a given *sorted* array.
 * @authors [James McDermott](https://github.com/theycallmemac) - recursive
 * algorithm
 * @authors [Krishna Vedala](https://github.com/kvedala) - iterative algorithm
 */
#include <assert.h>
#include <stdio.h>

/** Recursive implementation
 * \param[in] arr array to search
 * \param l left index of search range
 * \param r right index of search range
 * \param x target value to search for
 * \returns location of x assuming array arr[l..r] is present
 * \returns -1 otherwise
 */
int binarysearch1(const int *arr, int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        // If element is present at middle
        if (arr[mid] == x)
            return mid;

        // If element is smaller than middle
        if (arr[mid] > x)
            return binarysearch1(arr, l, mid - 1, x);

        // Else element is in right subarray
        return binarysearch1(arr, mid + 1, r, x);
    }

    // When element is not present in array
    return -1;
}

/** Iterative implementation
 * \param[in] arr array to search
 * \param l left index of search range
 * \param r right index of search range
 * \param x target value to search for
 * \returns location of x assuming array arr[l..r] is present
 * \returns -1 otherwise
 */
int binarysearch2(const int *arr, int l, int r, int x)
{
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            // If element is smaller than middle
            r = mid - 1;
        else
            // Else element is in right subarray
            l = mid + 1;
    }

    // When element is not present in array
    return -1;
}

/** Test implementations */
void test()
{
    // give function an array to work with
    int arr[] = {2, 3, 4, 10, 40};
    // get size of array
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Test 1.... ");
    // set value to look for
    int x = 10;
    // set result to what is returned from binarysearch
    int result = binarysearch1(arr, 0, n - 1, x);
    assert(result == 3);
    printf("passed recursive... ");
    result = binarysearch2(arr, 0, n - 1, x);
    assert(result == 3);
    printf("passed iterative...\n");

    printf("Test 2.... ");
    x = 5;
    // set result to what is returned from binarysearch
    result = binarysearch1(arr, 0, n - 1, x);
    assert(result == -1);
    printf("passed recursive... ");
    result = binarysearch2(arr, 0, n - 1, x);
    assert(result == -1);
    printf("passed iterative...\n");

    // Empty ranges must not read the array or report an out-of-range match.
    assert(binarysearch1(NULL, 0, -1, 2) == -1);
    assert(binarysearch2(NULL, 0, -1, 2) == -1);
    assert(binarysearch1(arr, 2, 1, 4) == -1);
    assert(binarysearch2(arr, 2, 1, 4) == -1);

    // Search boundaries and values outside the array's range.
    assert(binarysearch1(arr, 0, n - 1, 2) == 0);
    assert(binarysearch2(arr, 0, n - 1, 2) == 0);
    assert(binarysearch1(arr, 0, n - 1, 40) == n - 1);
    assert(binarysearch2(arr, 0, n - 1, 40) == n - 1);
    assert(binarysearch1(arr, 0, n - 1, 1) == -1);
    assert(binarysearch2(arr, 0, n - 1, 1) == -1);
    assert(binarysearch1(arr, 0, n - 1, 41) == -1);
    assert(binarysearch2(arr, 0, n - 1, 41) == -1);

    // Single-element ranges, with and without a match.
    assert(binarysearch1(arr, 0, 0, 2) == 0);
    assert(binarysearch2(arr, 0, 0, 2) == 0);
    assert(binarysearch1(arr, 0, 0, 3) == -1);
    assert(binarysearch2(arr, 0, 0, 3) == -1);
}

/** Main function */
int main(void)
{
    test();
    return 0;
}
