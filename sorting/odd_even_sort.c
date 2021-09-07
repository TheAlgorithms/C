/**
 * @file
 * @author [Edwin Ajong] (https://github.com/eddybruv)
 * @brief [Odd Even Sort] (https://en.wikipedia.org/wiki/Odd%E2%80%93even_sort) implementation
 * @details
 * This algorithm is divided into two phases- Odd and Even Phase.
 * The algorithm runs until the array elements are sorted and in each iteration two phases occurs- Odd and Even Phases.
 * In the odd phase, we perform a bubble sort on odd indexed elements and in the even phase,
 * we perform a bubble sort on even indexed elements.
 * Time Complexity: O(N ^ 2)
 */

#include <assert.h>     /// for assert
#include <stdbool.h>    /// for boolean
#include <stdio.h>      /// for IO operations
#include <inttypes.h>   /// for uint32_t
#include <stdlib.h>     /// for dynammic memory allocation
#include <time.h>       /// for random number generation

/**
 * @brief Swap numbers by reference(using pointers)
 * @param first pointer to first number
 * @param second pointer to second number
 */

void swap(uint32_t *first, uint32_t *second)
{
    uint32_t temp = *first;
    *first = *second;
    *second = temp;
}

/**
 * @brief oddEvenSort sorts the array using the algorithm described above.
 * @param arr array to be sorted
 * @param size size of array
 * @return void
 */

void oddEvenSort(uint32_t *arr, uint32_t size)
{
    bool isSorted = false;
    while(!isSorted)
    {
        isSorted = true;
        uint32_t i;

        //Even phase
        for(i = 0; i <= size - 2; i += 2)
        {
            if(arr[i] > arr[i + 1])
            {
                swap(&arr[i], &arr[i + 1]);
                isSorted = false;
            }
        }

        //Odd phase
        for(i = 1; i <= size - 1; i += 2)
        {
            if(arr[i] > arr[i + 1])
            {
                swap(&arr[i], &arr[i + 1]);
                isSorted = false;
            }
        }
    }
}

/**
 * @brief Self-test implementations
 * @return void
 */
void test()
{
    const int size = 10;
    int *arr = (int *)calloc(size, sizeof(int));

    /* generates size random numbers from -100 to 100 */
    for(int i = 0; i < size; i++)
    {
        arr[i] = (rand() % 200) - 100;
    }

    oddEvenSort(arr, size);

    for (int i = 0; i < size; i++)
    {
        assert(arr[i] <= arr[i++]);    
    }
    
    free(arr);
}

/**
 * @brief Main function
 * @returns 0 on exit
 */

int main(void)
{
    //Initialises random number generator
    srand(time(NULL));

    test();
    return 0;
}