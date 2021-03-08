/**
 * @file
 * @author [Dhruv Pasricha](https://github.com/DhruvPasricha)
 * @brief [Heap Sort](https://en.wikipedia.org/wiki/Heapsort) implementation
 */

#include <assert.h>   /// for assert
#include <stdio.h>    /// for IO operations
#include <stdlib.h>   /// for dynamic memory allocation
#include <time.h>     /// for random numbers generation
#include <inttypes.h> /// for uint8_t, int8_t

/**
 * @brief Swapped two numbers using pointer
 * @param first pointer of first number
 * @param second pointer of second number
 */
void swap(int8_t *first, int8_t *second)
{
    int8_t temp = *first;
    *first = *second;
    *second = temp;
}

/**
 * @brief heapifyDown Adjusts new root to the correct position in the heap
 * @param arr array to be sorted
 * @param size size of array
 * @return void
*/

void heapifyDown(int8_t *arr, const uint8_t size)
{
    uint8_t i = 0;

    while (2 * i + 1 < size)
    {
        uint8_t maxChild = 2 * i + 1;

        if (2 * i + 2 < size && arr[2 * i + 2] > arr[maxChild])
        {
            maxChild = 2 * i + 2;
        }

        if (arr[maxChild] > arr[i])
        {
            swap(&arr[i], &arr[maxChild]);
            i = maxChild;
        }
        else
        {
            break;
        }
    }
}

/**
 * @brief heapifyUp Adjusts arr[i] to the correct position in the heap
 * @param arr array to be sorted
 * @param i index of the pushed element
 * @return void
*/
void heapifyUp(int8_t *arr, uint8_t i)
{
    while (i > 0 && arr[i / 2] < arr[i])
    {
        swap(&arr[i / 2], &arr[i]);
        i /= 2;
    }
}

/**
 * @brief Heap Sort algorithm
 * @param arr array to be sorted
 * @param size size of the array
 * @returns void
 */
void heapSort(int8_t *arr, const uint8_t size)
{
    if (size <= 1)
    {
        return;
    }

    for (uint8_t i = 0; i < size; i++)
    {
        /*Pushing arr[i] to the heap*/

        /*heapifyUp Adjusts arr[i] to the correct position in the heap*/
        heapifyUp(arr, i);
    }

    for (uint8_t i = size - 1; i >= 1; i--)
    {
        /*Moving current root to the end*/
        swap(&arr[0], &arr[i]);

        /*heapifyDown Adjusts new root to the correct position in the heap*/
        heapifyDown(arr, i);

    }
}

/**
 * @brief Self-test implementations
 * @returns void
 */
static void
test()
{
    const uint8_t size = 10;
    int8_t *arr = (int8_t *)calloc(size, sizeof(int8_t));

    /* generate size random numbers from 0 to 100 */
    for (uint8_t i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }
    heapSort(arr, size);
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
    // Intializes random number generator
    srand(time(NULL));

    test(); // run self-test implementations
    return 0;
}
