/**
 * @file
 * @brief Program to perform [binary
 * search](https://en.wikipedia.org/wiki/Binary_search_algorithm) of a target
 * value in a given *sorted* array.
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
int binarysearch(const int *arr, int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        // If element is present at middle
        if (arr[mid] == x)
            return mid;

        // If element is smaller than middle
        if (arr[mid] > x)
            return binarysearch(arr, l, mid - 1, x);

        // Else element is in right subarray
        return binarysearch(arr, mid + 1, r, x);
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
    int result = binarysearch(arr, 0, n - 1, x);
    assert(result == 3);
    printf("passed\n");

    printf("Test 2.... ");
    x = 5;
    // set result to what is returned from binarysearch
    result = binarysearch(arr, 0, n - 1, x);
    assert(result == -1);
    printf("passed\n");
}

/** Main function */
int main(void)
{
    test();
    return 0;
}
