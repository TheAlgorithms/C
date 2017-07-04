#include <stdio.h>

// Recursive Function- It returns location of value assuming array arr[l..r] is present, otherwise it returns -1

int binarysearch(int arr[], int l, int r, int value)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;

        // If value is present at middle
        if (arr[mid] == value)  return mid;

        // If value is smaller than middle
        if (arr[mid] > value) return binarysearch(arr, l, mid-1, value);

        // Else element is in right subarray
        return binarysearch(arr, mid+1, r, value);
   }

   // When element is not present in array
   return -1;
}

int main(void)
{
   // give function an array to work with
   int arr[] = {2, 3, 4, 10, 40};
   int arrSize = sizeof(arr)/ sizeof(arr[0]);
   
   int value = 10;
   // set result to what is returned from binarysearch
   int result = binarysearch(arr, 0, arrSize-1, value);
   (result == -1)? printf("Element is not in the array")
                 : printf("Element is present at index %d", result);
   return 0;
}
