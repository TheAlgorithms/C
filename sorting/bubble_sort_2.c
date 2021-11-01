/**
 * @file
 * @brief implementation of [Bubble sort](https://en.wikipedia.org/wiki/Bubble_sort) algorithm
 * @details
 * worst-case: O(n^2)
 * best-case: O(n)
 * average-complexity: O(n^2)

 * @author Unknown author
 * @author [Gabriel Fioravante](https://github.com/northernSage)
 */

#include <stdlib.h>   /// for rand() calls
#include <assert.h>   /// for assert(<expr>)
#include <stdbool.h>  /// for boolean values: true, false  

#define MAX 20

/**
 * @brief Bubble sort implementation
 * @param array_sort the array to be sorted
 * @returns void
 */
void bubble_sort(int* array_sort)
{
	bool is_sorted = false;

    /* keep iterating over entire array
     * and swaping elements out of order
     * until it is sorted */
    while (!is_sorted)
    {
		is_sorted = true;

        /* iterate over all elements */
        for (int i = 0; i < MAX - 1; i++)
        {
            /* check if adjacent elements are out of order */
            if (array_sort[i] > array_sort[i + 1])
            {
                /* swap elements */
                int change_place = array_sort[i];
                array_sort[i] = array_sort[i + 1];
                array_sort[i + 1] = change_place;
                /* elements out of order were found
                 * so we reset the flag to keep ordering
                 * until no swap operations are executed */
                is_sorted = false;
            }
        }
    }
}

/**
 * @brief Test implementations
 * @returns void
 */
static void test() {
    /* simple int array for testing */
	int array_sort[MAX] = {0};

    /* populate our test array with 
     * random integer numbers */
    for (int i = 0; i < MAX; i++)
    {
        array_sort[i] = rand() % 101;
    }

    /* sort array */
    bubble_sort(array_sort);

    /* check if array ir correctly ordered */	
    for (int i = 0; i < MAX - 1; i++)
    {
        assert(array_sort[i] <= array_sort[i+1]);
    }
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
