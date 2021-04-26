/**
 * \file
 * \brief [4. Median of two sorted
 * arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/) solution
 * \details
 * Given two sorted arrays `nums1` and `nums2` of size `m` and `n` respectively,
 * return the median of the two sorted arrays.
 */

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Computes median of two sorted arrays
 *
 * @param nums1 sorted array 1
 * @param nums1Size size of strted array 1
 * @param nums2 sorted array 2
 * @param nums2Size size of sorted array 2
 * @return median of the two arrays
 */
double findMedianSortedArrays(int *nums1, size_t nums1Size, int *nums2,
                              size_t nums2Size)
{
    double out;
    int index1 = 0;
    int index2 = 0;
    int *v = (int *)malloc((nums1Size + nums2Size) * sizeof(int));
    int v_index = 0;

    while (index1 < nums1Size && index2 < nums2Size)
    {
        if (nums1[index1] <= nums2[index2])
        {
            v[v_index++] = nums1[index1++];
        }
        else
        {
            v[v_index++] = nums2[index2++];
        }
    }
    if (index1 < nums1Size)
    {
        while (index1 < nums1Size)
        {
            v[v_index++] = nums1[index1++];
        }
    }
    if (index2 < nums2Size)
    {
        while (index2 < nums2Size)
        {
            v[v_index++] = nums2[index2++];
        }
    }
    if (v_index == 1)
    {
        out = v[0];
        free(v);
        return out;
    }
    if (v_index % 2 == 0)
    {
        double n1, n2;
        n1 = v[v_index >> 1];
        n2 = v[(v_index >> 1) - 1];
        out = (n1 + n2) / 2;
        free(v);
        return out;
    }
    int new_index = (int)v_index >> 1;
    int i = 0;
    out = v[new_index];
    free(v);
    return out;
}

/** Main function
 * @returns 0
 */
int main()
{
    int array1[] = {1, 3};
    int array2[] = {2};
    double median1 = findMedianSortedArrays(array1, 2, array2, 1);
    assert(fabs(median1 - 2.f) <= 0.01);
    printf("Test 1 passed.\n");

    int array3[] = {1, 2};
    int array4[] = {3, 4};
    double median2 = findMedianSortedArrays(array3, 2, array4, 2);
    assert(fabs(median2 - 2.5f) <= 0.01);
    printf("Test 2 passed.\n");

    int array5[] = {0, 0};
    int array6[] = {0, 0};
    double median3 = findMedianSortedArrays(array5, 2, array6, 2);
    assert(fabs(median3 - 0.f) <= 0.01);
    printf("Test 3 passed.\n");

    return 0;
}
