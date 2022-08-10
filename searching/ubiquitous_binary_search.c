#include <assert.h>
#include <stdio.h>

// Returns location of key, or -1 if not found
int BinarySearch(int A[], int l, int r, int key)
{
    int m;
 
    while( l <= r )
    {
        m = l + (r-l)/2;
 
        if( A[m] == key ) // first comparison
            return m;
 
        if( A[m] < key ) // second comparison
            l = m + 1;
        else
            r = m - 1;
    }
 
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
}

/** Main function */
int main(void)
{
    test();
    return 0;
}
