

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2,
                              int nums2Size)
{
    int index1 = 0;
    int index2 = 0;
    int v[nums1Size + nums2Size];
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
        return v[0];
    }
    if (v_index % 2 == 0)
    {
        double n1, n2;
        n1 = v[v_index / 2];
        n2 = v[(v_index / 2) - 1];
        return (n1 + n2) / 2;
    }
    int new_index = (int)v_index / 2;
    int i = 0;
    return v[new_index];
}
