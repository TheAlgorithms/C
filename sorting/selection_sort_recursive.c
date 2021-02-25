/**
 * @file
 * @author [Dhruv Pasricha](https://github.com/DhruvPasricha)
 * @brief [Selection Sort](https://en.wikipedia.org/wiki/Selection_sort)
 * implementation using recursion.
 */
#include <assert.h> /// for assert
#include<stdio.h>   /// for IO operations
#include <stdlib.h> /// for dynamic memory allocation
#include <time.h>   /// for random numbers generation
#include <inttypes.h> /// for uint8_t

/**
 * @brief Swapped two numbers using pointer
 * @param first pointer of first number
 * @param second pointer of second number
 */
void swap(uint8_t *first, uint8_t *second)
{
    uint8_t temp = *first;
    *first = *second;
    *second = temp;
}

/**
 * @brief Returns the index having minimum value using recursion
 * @param arr array to be sorted
 * @param size size of array
 * @return min_index index of element having minimum value.
*/
uint8_t findIndex(const uint8_t *arr, const uint8_t size)
{
    if (size == 1)
    {
        return 0;
    }

    // marking recursive call to reach starting element
    uint8_t min_index = findIndex(arr, size - 1);

    if (arr[size - 1] < arr[min_index])
    {
        min_index = size - 1;
    }

    return min_index;
}

/**
 * @brief Selection Sort algorithm implemented using recursion
 * @param arr array to be sorted
 * @param size size of the array
 * @returns void
 */
void selectionSort(uint8_t *arr, const uint8_t size)
{
    if (size == 1)
    {
        return;
    }

    /* findIndex(arr, size) returned the index having min value*/
    uint8_t min_index = findIndex(arr, size);
    /* arr[min_index] is the minimum value in the array*/

    if (min_index != 0)
    {
        swap(&arr[0], &arr[min_index]);
    }

    /*sorted the remaining array recursively*/
    selectionSort(arr + 1, size - 1);
}

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test()
{
    const uint8_t size = 10;
    uint8_t *arr = (uint8_t *)calloc(size, sizeof(uint8_t));

    /* generate size random numbers from 0 to 100 */
    for (uint8_t i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }
    selectionSort(arr, size);
    for (uint8_t i = 0; i < size - 1; ++i)
    {
        assert(arr[i] <= arr[i + 1]);
    }
    free(arr);
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main()
{
    /* Intializes random number generator */
    srand(time(NULL));
    test();  // run self-test implementations
    return 0;
}
