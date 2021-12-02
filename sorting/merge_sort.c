/**
 * @file
 * @brief Implementation of [merge
 * sort](https://en.wikipedia.org/wiki/Merge_sort) algorithm
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @addtogroup sorting Sorting algorithms
 * @{
 */
/** Swap two integer variables
 * @param [in,out] a pointer to first variable
 * @param [in,out] b pointer to second variable
 */
void swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

/**
 * @brief Perform merge of segments.
 *
 * @param a array to sort
 * @param l left index for merge
 * @param r right index for merge
 * @param n total number of elements in the array
 */
void merge(int *a, int l, int r, int n)
{
    int *b = (int *)malloc(n * sizeof(int)); /* dynamic memory must be freed */
    int c = l;
    int p1, p2;
    p1 = l;
    p2 = ((l + r) / 2) + 1;
    while ((p1 < ((l + r) / 2) + 1) && (p2 < r + 1))
    {
        if (a[p1] <= a[p2])
        {
            b[c++] = a[p1];
            p1++;
        }
        else
        {
            b[c++] = a[p2];
            p2++;
        }
    }

    if (p2 == r + 1)
    {
        while ((p1 < ((l + r) / 2) + 1))
        {
            b[c++] = a[p1];
            p1++;
        }
    }
    else
    {
        while ((p2 < r + 1))
        {
            b[c++] = a[p2];
            p2++;
        }
    }

    for (c = l; c < r + 1; c++) a[c] = b[c];

    free(b);
}

/** Merge sort algorithm implementation
 * @param a array to sort
 * @param n number of elements in the array
 * @param l index to sort from
 * @param r index to sort till
 */
void merge_sort(int *a, int n, int l, int r)
{
    if (r - l == 1)
    {
        if (a[l] > a[r])
            swap(&a[l], &a[r]);
    }
    else if (l != r)
    {
        merge_sort(a, n, l, (l + r) / 2);
        merge_sort(a, n, ((l + r) / 2) + 1, r);
        merge(a, l, r, n);
    }

    /* no change if l == r */
}
/** @} */

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test()
{
    const int n = 10;
    int *a = (int *)calloc(n, sizeof(int));

    /* generate size random numbers from 0 to 100 */
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
    }
    merge_sort(a, n, 0, n - 1);
    for (int i = 0; i < n - 1; ++i)
    {
        assert(a[i] <= a[i + 1]);
    }
    free(a);
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main(int argc, const char *argv[])
{
    /* Intializes random number generator */
    srand(time(NULL));
    test();  // run self-test implementations
    return 0;
}
