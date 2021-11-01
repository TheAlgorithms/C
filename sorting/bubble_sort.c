/**
 * @file
 * @brief [Bubble sort](https://en.wikipedia.org/wiki/Bubble_sort) algorithm
 * implementation
 */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Display elements of array
 * @param arr array to be display
 * @param n length of array
 */
void display(const int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * Swap two values by using pointer
 * @param first first pointer of first number
 * @param second second pointer of second number
 */
void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

/**
 * Bubble sort algorithm implementation
 * @param arr array to be sorted
 * @param size size of array
 */
void bubbleSort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {                         /* for each array index */
        bool swapped = false; /* flag to check if any changes had to be made */
        /* perform iterations until no more changes were made or outer loop
            executed for all array indices */
        for (int j = 0; j < size - 1 - i; j++)
        { /* for each element in the array */
            if (arr[j] > arr[j + 1])
            { /* if the order of successive elements needs update */
                swap(&arr[j], &arr[j + 1]);
                swapped = true; /* set flag */
            }
        }
        if (!swapped)
        {
            /* since no more updates we made, the array is already sorted
                this is an optimization for early termination */
            break;
        }
    }
}

/**
 * Test function
 */
void test()
{
    const int size = 10;
    int *arr = (int *)calloc(size, sizeof(int));

    /* generate size random numbers from 0 to 100 */
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }
    bubbleSort(arr, size);
    for (int i = 0; i < size - 1; ++i)
    {
        assert(arr[i] <= arr[i + 1]);
    }
    free(arr);
}

/** Driver Code */
int main(int argc, const char *argv[])
{
    /* Intializes random number generator */
    srand(time(NULL));
    test();
    return 0;
}
