#include<stdio.h>

const int RUN = 32;
  
void insertionSort(int arr[], int left, int right) 
{ 
	int i;
    for (i = left + 1; i <= right; i++) 
    { 
        int temp = arr[i]; 
        int j = i - 1; 
        while (j >= left && arr[j] > temp) 
        { 
            arr[j+1] = arr[j]; 
            j--; 
        } 
        arr[j+1] = temp; 
    } 
} 
  
void merge(int arr[], int l, int m, int r) 
{ 
	int i,j,k;
    int len1 = m - l + 1, len2 = r - m; 
    int left[len1], right[len2]; 
    for (i = 0; i < len1; i++) 
        left[i] = arr[l + i]; 
    for (i = 0; i < len2; i++) 
        right[i] = arr[m + 1 + i]; 
  
    i = 0; 
    j = 0; 
    k = l; 
  
    while (i < len1 && j < len2) 
    { 
        if (left[i] <= right[j]) 
        { 
            arr[k] = left[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = right[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < len1) 
    { 
        arr[k] = left[i]; 
        k++; 
        i++; 
    } 
  
    while (j < len2) 
    { 
        arr[k] = right[j]; 
        k++; 
        j++; 
    } 
} 
  
void timSort(int arr[], int n) 
{ 
	int i,size,left,right;
    // Sort individual subarrays of size RUN 
    for (i = 0; i < n; i+=RUN){
    	right = (i+31) < (n-1) ? (i+31) : (n-1);
        insertionSort(arr, i, right);
    }
  
    // start merging from size RUN (or 32). It will merge 
    // to form size 64, then 128, 256 and so on .... 
    for (size = RUN; size < n; size = 2*size) 
    { 
        // pick starting point of left sub array. We 
        // are going to merge arr[left..left+size-1] 
        // and arr[left+size, left+2*size-1] 
        // After every merge, we increase left by 2*size 
        for (left = 0; left < n; left += 2*size)
        { 
            // find ending point of left sub array 
            // mid+1 is starting point of right sub array 
            int mid = left + size - 1; 
            right = (left + 2*size - 1)<(n-1) ? (left + 2*size - 1) : (n-1);
  
            // merge sub array arr[left.....mid] & 
            // arr[mid+1....right] 
            merge(arr, left, mid, right); 
        } 
    } 
} 
  
void printArray(int arr[], int n) 
{ 
	int i;
    for (i = 0; i < n; i++) 
        printf("%d  ", arr[i]); 
    printf("\n"); 
} 
  
int main() 
{ 
    int arr[] = {5, 21, 7, 23, 19}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    printf("Given Array is\n"); 
    printArray(arr, n); 
  
    timSort(arr, n); 
  
    printf("After Sorting Array is\n"); 
    printArray(arr, n); 
    return 0; 
}