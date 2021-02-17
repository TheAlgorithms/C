#include <stdio.h>
#include <stdlib.h>
#define MAX 20

#include <stdbool.h>
#include <assert.h>

/**
 * Bubble sort implementation
 * @param array_sort the array to be sorted
 */
void bubblesort(int* array_sort)
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
 * @brief Test function
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
    bubblesort(array_sort);

    /* check if array ir correctly ordered */	
    for (int i = 0; i < MAX - 1; i++)
    {
        assert(array_sort[i] <= array_sort[i+1]);
    }
}

int main()
{
    int i, array_sort[MAX] = {0}, is_sorted = false, change_place;

    /* For example
    Insertion random values in array to test
    */

    for (i = 0; i < MAX; i++)
    {
        array_sort[i] = rand() % 101;
    }

    /* Algorithm of bubble methods */

    while (is_sorted)
    {
        is_sorted = false;

        for (i = 0; i < MAX - 1; i++)
        {
            if (array_sort[i] > array_sort[i + 1])
            {
                change_place = array_sort[i];
                array_sort[i] = array_sort[i + 1];
                array_sort[i + 1] = change_place;
                is_sorted = true;
            }
        }
    }

    /* See if it works */

    for (i = 0; i < MAX; i++)
    {
        printf("%d\n", array_sort[i]);
    }

    return EXIT_SUCCESS;
}
