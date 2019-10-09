int peakIndexInMountainArray(int* A, int ASize) {
    int low = 1, high = ASize;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (A[mid - 1] < A[mid] && A[mid] > A[mid + 1])
            return mid;
        else if(A[mid - 1] < A[mid] && A[mid] < A[mid + 1])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
