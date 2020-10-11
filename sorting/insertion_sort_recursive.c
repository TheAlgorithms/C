/**
 * @file
 * @brief [Insertion sort](https://en.wikipedia.org/wiki/Insertion_sort)
 * algorithm implementation.
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @addtogroup sorting Sorting algorithms
 * @{
 */
/**
 * Insertion sort algorithm implements using Recursion 
 * @param arr array to be sorted
 * @param size size of array
 */
void RecursionInsertionSort(int *arr, int size)
{
    if(size <= 0)
    {
        return;
    }
    
    // marking recursive call to reach starting element
    RecursionInsertionSort(arr,size-1);
    
    int key = arr[size-1];
    int j = size-2;
    // swapping logic for insertion sort
    while(j >= 0 && arr[j] > key)
    {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = key;
}
/** @} */
/** Test function
  * @returns None
  */
static void test()
{
    const int size = rand() % 500; /* random array size */
    int *arr = (int *)calloc(size, sizeof(int));

    /* generate size random numbers from -50 to 49 */  
    for (int i = 0; i < size; i++)
    {
        arr[i] = (rand() % 100) - 50;/* signed random numbers */
    }
    RecursionInsertionSort(arr, size);
    for (int i = 0; i < size  ; ++i)
    {
        assert(arr[i] <= arr[i + 1]);
    }
    free(arr);
}

/** Main function
 *  @returns integer 0
 */
int main(int argc, const char *argv[])
{
    /* Intializes random number generator */
    srand(time(NULL));
    test();
    return 0;
}
