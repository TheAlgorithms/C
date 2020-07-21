/**
 * @file union_find.c
 * @brief [Union
 * find](https://en.wikipedia.org/wiki/Disjoint-set_data_structure) algorithm.
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000 /**< maximum number of elements in the set */

/**
 * @brief Find index of or value in an array
 *
 * @param [in,out] p array to search and update
 * @param x value to search
 * @return value at the index `x`
 */
int find(int *p, int x)
{
    if (x >= MAX_SIZE)
    {
        fprintf(stderr, "Out-of bounds value\n");
        exit(EXIT_FAILURE);
    }

    if (p[x] == x)
    {
        return x;
    }
    else
    {
        p[x] = find(p, p[x]);
        return p[x];
    }
}

/**
 * @brief Function to join
 * @param [in,out] p array to join in
 * @param x value or index to join to
 * @param y value or index to join from
 */
void join(int *p, int x, int y) { p[find(p, x)] = find(p, y); }

/** Main function */
int main()
{
    int union_set[MAX_SIZE];

    // Have all array indexes that you need to use reference themselves
    for (int i = 0; i < 10; i++)
    {
        union_set[i] = i;
    }
    // p = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}

    join(union_set, 3, 5);
    printf("The array is now: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", union_set[i]);
    }
    printf("\n");
    // Now 3 and 5 are groupped together, that is find(3) = find(5)
    // p = {0, 1, 2, 5, 4, 5, 6, 7, 8, 9}

    join(union_set, 3, 8);
    printf("The array is now: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", union_set[i]);
    }
    printf("\n");

    // Now 3, 5 and are groupped together, find(3) = find(5) = find(8)
    // p = {0, 1, 2, 5, 4, 8, 6, 7, 8, 9}
    join(union_set, 0, 5);
    if (find(union_set, 0) == find(union_set, 3))
    {
        printf("0 and 3 are groupped together\n");
    }
    printf("The array is now: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", union_set[i]);
    }
    printf("\n");

    return 0;
}
