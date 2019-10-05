double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i = 0;
    int j = 0;
    int k = 0;
    int mid = 0;
    int len = nums1Size + nums2Size;
    int arr[len];
    
    while(i < nums1Size && j < nums2Size) {
        if(nums1[i] > nums2[j])
            arr[k++] = nums2[j++];
        else 
            arr[k++] = nums1[i++];
    }
    
    while(i < nums1Size)
        arr[k++] = nums1[i++];
    
    while(j < nums2Size)
        arr[k++] = nums2[j++];
    
    mid = len / 2;
    if (len % 2 == 1)
        return (int)arr[mid];
    else 
        return (arr[mid - 1] + arr[mid]) / 2.0;
    
}

