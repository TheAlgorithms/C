void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int j = 0;
    int temp;

    for (int i = m; i < nums1Size; i++)
    {
        nums1[i] = nums2[j];
        j++;
    }
    for (int i = 0; i < nums1Size - 1; i++)
    {
        for (int j = 0; j < nums1Size - i - 1; j++)
        {
            if (nums1[j] > nums1[j + 1])
            {
                temp = nums1[j];
                nums1[j] = nums1[j + 1];
                nums1[j + 1] = temp;
            }
        }
    }
}
