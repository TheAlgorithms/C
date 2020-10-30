/**
 * \file
 * \brief [11. Container With Most
 * Water](https://leetcode.com/problems/container-with-most-water/)
 * solution
 * \details Given n non-negative integers \f$a_1, a_2, \ldots, a_n\f$, where
 * each represents a point at coordinate \f$\left(i, a_i\right)\f$. `n` vertical
 * lines are drawn such that the two endpoints of the line `i` is at \f$\left(i,
 * a_i\right)\f$ and \f$\left(i, 0\right)\f$. Find two lines, which, together
 * with the x-axis forms a container, such that the container contains the most
 * water.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Fucntion to calculate min of values a and b
 *
 * @param a first number
 * @param b second number
 * @return minimum of `a` and `b`
 */
int min(int a, int b) { return ((a < b) ? a : b); }

/**
 * @brief Two pointer approach to find maximum container area
 *
 * @param height array of heights
 * @param heightSize number of array elements
 * @return maximum area the container can contain
 */
int maxArea(int *height, int heightSize)
{
    // Start with maximum container width
    int start = 0;
    int end = heightSize - 1;
    int res = 0;

    while (start < end)
    {
        // Calculate current area by taking minimum of two heights
        int currArea = (end - start) * min(height[start], height[end]);

        if (currArea > res)
            res = currArea;

        if (height[start] < height[end])
            start = start + 1;
        else
            end = end - 1;
    }

    return res;
}

/**
 * @brief Main function
 * @return 0
 */
int main()
{
    int heights1[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int test1 = maxArea(heights1, 9);
    assert(test1 == 49);
    printf("Test 1 passed\n");
    int heights2[] = {1, 1};
    int test2 = maxArea(heights2, 2);
    assert(test2 == 1);
    printf("Test 2 passed\n");
    int heights3[] = {4, 3, 2, 1, 4};
    int test3 = maxArea(heights3, 5);
    assert(test3 == 16);
    printf("Test 3 passed\n");
    int heights4[] = {1, 2, 1};
    int test4 = maxArea(heights4, 3);
    assert(test4 == 2);
    printf("Test 4 passed\n");

    return 0;
}
