/**
 * @file jump_search.c
 * @brief Implementation of [jump
 * search](https://en.wikipedia.org/wiki/Jump_search) algorithm.
 */
#include <assert.h>
#include <math.h>
#include <stdio.h>

/**
 * @brief Macro to return the minimum of two values
 */
#define min(X, Y) ((X) < (Y) ? (X) : (Y))

/**
 * @brief Implement Jump-search algorithm
 *
 * @param [in] arr Array to search within
 * @param x value to search for
 * @param n length of array
 * @return index where the value was found
 * @return -1 if value not found
 */
int jump_search(const int *arr, int x, size_t n)
{
    int step = floor(sqrt(n));
    int prev = 0;

    while (arr[min(step, n) - 1] < x)
    {
        prev = step;
        step += floor(sqrt(n));
        if (prev >= n)
        {
            return -1;
        }
    }

    while (arr[prev] < x)
    {
        prev = prev + 1;
        if (prev == min(step, n))
        {
            return -1;
        }
    }
    if (arr[prev] == x)
    {
        return prev;
    }
    return -1;
}

/**
 * @brief Test implementation of the function
 *
 */
void test()
{
    int arr[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
    size_t n = sizeof(arr) / sizeof(int);

    int x = 55;
    printf("Test 1.... ");
    int index = jump_search(arr, x, n);
    assert(index == 10);
    printf("passed\nTest 2.... ");
    x = 56;
    index = jump_search(arr, x, n);
    assert(index == -1);
    printf("passed\nTest 3.... ");
    x = 13;
    index = jump_search(arr, x, n);
    assert(index == 7);
    printf("passed\n");
}

/**
 * @brief Main function
 */
int main()
{
    test();
    return 0;
}
