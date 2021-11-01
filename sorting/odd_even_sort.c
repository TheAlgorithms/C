/**
 * @file
 * @author [Edwin Ajong](https://github.com/eddybruv)
 * @brief [Odd Even Sort](https://en.wikipedia.org/wiki/Odd%E2%80%93even_sort) implementation
 * @details
 * This algorithm is divided into two phases- Odd and Even Phase.
 * The algorithm runs until the array elements are sorted and in each iteration two phases occurs- Odd and Even Phases.
 * In the odd phase, we perform a bubble sort on odd indexed elements and in the even phase,
 * we perform a bubble sort on even indexed elements.
 * Time Complexity: O(N ^ 2)
 */

#include <assert.h>     /// for assert
#include <stdbool.h>    /// for bool
#include <stdio.h>      /// for IO operations
#include <stdlib.h>     /// for dynammic memory allocation
#include <time.h>       /// for random number generation
#include <inttypes.h>   /// for int32_t types

/**
 * @brief Swap numbers by reference(using pointers)
 * @param first pointer to first number
 * @param second pointer to second number
 * @returns void
 */
void swap(int32_t *first, int32_t *second)
{
    int32_t temp = *first;
    *first = *second;
    *second = temp;
}

/**
 * @brief oddEvenSort sorts the array using the algorithm described above.
 * @details 
 * A boolean varaible(isSorted) is declared and initialised to "false".
 * In the while loop, the variable(isSorted) is then set to "true".
 * During even phase the for loop loops through the array, touching just the even indexes.
 * i.e arr[0], arr[2], arr[4] and so on.
 * While during the odd phase, the for loop loops through the array, touching just the odd indexes.
 * i.e arr[1], arr[3], arr[5] and so on.
 * During these phases, if the if statement check if the interger at the current position in the array
 * is greater than the interger at the next array index (i.e arr[index + 2], to make sure the index is odd
 * during the odd phase and even during the even phase).
 * If the condition is true, the function "swap" is called and address of the intergers in question are passed as
 * parameters. After the swap is completed, "isSorted" is set to "false".
 * The while loop will keep running till the array is propertly sorted.
 * @param arr array to be sorted
 * @param size the size of the array
 * @returns void
 */
void oddEvenSort(int *arr, int size)
{
    bool isSorted = false;
    while(!isSorted)
    {
        isSorted = true;
        int32_t i;

        // Even phase
        for(i = 0; i <= size - 2; i += 2)
        {
            if(arr[i] > arr[i + 1])
            {
                swap(&arr[i], &arr[i + 1]);
                isSorted = false;
            }
        }

        // Odd phase
        for(i = 1; i <= size - 2; i += 2)
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
 * @details Two tests (unsorted) arrays were created and their corresponding solution(sorted) arrays were also created.
 * The test arrays and their respective sizes are then passed in to the oddEvenSort function.
 * To test if the algorithm works, a for loop is assigned to loop through the both arrays(test and solution) and check if the array elements 
 * of the test array correspond to the elements of the solution array.
 * @returns void
 */
static void test()
{
    int32_t arr1[] = {-9, 2, 3, 1};
    int32_t arr1Soln[] = {-9, 1, 2, 3};
    int32_t arr2[] = {9, 7, 5, 3, 8, 2, 1, 4, 0, 6};
    int32_t arr2Soln[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    oddEvenSort(arr1, 4);
    oddEvenSort(arr2, 10);

     for (int32_t i = 0; i < 4; i++)
     {
         assert(arr1[i] == arr1Soln[i]);    
     }

    for (int32_t i = 0; i < 10; i++)
    {
        assert(arr2[i] == arr2Soln[i]);    
    }
    printf("All tests have passed!\n");
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main()
{
    test();  // run self-test implementations
    return 0;
}
