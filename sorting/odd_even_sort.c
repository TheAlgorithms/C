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
#include <stdlib.h>     /// for dynammic memory allocation
#include <time.h>       /// for random number generation

/**
 * @brief Swap numbers by reference(using pointers)
 * @param first pointer to first number
 * @param second pointer to second number
 * @returns void
 */

void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

/**
 * @brief oddEvenSort sorts the array using the algorithm described above.
 * @param arr array to be sorted
 * @param size size of array
 * @returns void
 */

void oddEvenSort(int *arr, int size)
{
    bool isSorted = false;
    while(!isSorted)
    {
        isSorted = true;
        int i;

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
 * @returns void
 */
void test()
{
    int arr1[] = {-9, 2, 3, 1};
    int arr1Soln[] = {-9, 1, 2, 3};
    int arr2[] = {9, 7, 5, 3, 8, 2, 1, 4, 0, 6};
    int arr2Soln[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    oddEvenSort(arr1, 4);
    oddEvenSort(arr2, 10);

     for (int i = 0; i < 4; i++)
     {
         assert(arr1[i] == arr1Soln[i]);    
     }

    for (int i = 0; i < 10; i++)
    {
        assert(arr2[i] == arr2Soln[i]);    
    }
}

/**
 * @brief Main function
 * @returns 0 on exit
 */

int main(void)
{
    test();
    return 0;
}