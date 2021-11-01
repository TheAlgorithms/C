/**
 * \file
 * \brief [Shell sort algorithm](https://en.wikipedia.org/wiki/Shell_sort)
 * implementation.
 * \author [Krishna Vedala](https://github.com/kvedala)
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @addtogroup sorting Sorting algorithms
 * @{
 */
/** Helper function to print array values */
void show_data(int *arr, long len)
{
    for (long i = 0; i < len; i++) printf("%3d ", arr[i]);
    printf("\n");
}

/** Function to swap values of two integers
 * @param [in,out] a reference to first variable
 * @param [in,out] b reference to second variable
 */
inline void swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * Shell sort algorithm.\n
 * Optimized algorithm - takes half the time as other
 * @param [in,out] array array to sort
 * @param [in] LEN length of the array
 */
void shell_sort(int *array, long LEN)
{
    const int gaps[] = {701, 301, 132, 57, 23, 10, 4, 1};
    const int gap_len = 8;
    long i, j, g;

    for (g = 0; g < gap_len; g++)
    {  // for each gap
        int gap = gaps[g];
        for (i = gap; i < LEN; i++)
        {  // from gap position to the end
            int tmp = array[i];

            for (j = i; j >= gap && (array[j - gap] - tmp) > 0; j -= gap)
                array[j] = array[j - gap];
            array[j] = tmp;
        }
    }
#ifdef DEBUG
    for (i = 0; i < LEN; i++) printf("%s\t", data[i]);
#endif
}
/** @} */

/** Main function */
int main(int argc, char *argv[])
{
    int i;
    long size = 500;
    if (argc == 2)
        size = atol(argv[1]);
    else if (argc > 2)
        fprintf(stderr, "Usage: ./shell_sort [number of values]\n");

    int *array = (int *)malloc(size * sizeof(int));
    int range = 500;  // range of array values
    double time_spent;

    srand(time(NULL));  // initialize random number generator
    for (i = 0; i < size; i++)
        // fill array with random integers
        array[i] = rand() % range + 1;

    show_data(array, size);   // show array before sorting
    clock_t t1 = clock();     // start timer
    shell_sort(array, size);  // sort the array
    clock_t t2 = clock();     // end timer

    printf("Data Sorted\n");
    show_data(array, size);  // display array after sorting

    printf("Time spent sorting: %.4g s\n", (t2 - t1) / CLOCKS_PER_SEC);

    free(array);
    return 0;
}
