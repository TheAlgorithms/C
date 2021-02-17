#include <stdio.h>
#include <stdlib.h>
#define MAX 20

#include <stdbool.h>

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
