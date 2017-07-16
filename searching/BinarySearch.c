#include <stdio.h>

// Recursive Function- It returns location of x assumiung array arr[l..r] is present, otherwise -1

int binarysearch(int arr[], int l, int r, int x)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;

        // If element is present at middle
        if (arr[mid] == x)  return mid;

        // If element is smaller than middle
        if (arr[mid] > x) return binarysearch(arr, l, mid-1, x);

        // Else element is in right subarray
        return binarysearch(arr, mid+1, r, x);
   }

   // When element is not present in array
   return -1;
}

int main(void)
{
   // give function an array to work with
   int arr[] = {2, 3, 4, 10, 40};
   // get size of array
   int n = sizeof(arr)/ sizeof(arr[0]);
   //set value to look for
   int x = 10;
   // set result to what is returned from binarysearch
   int result = binarysearch(arr, 0, n-1, x);
   // print out result
   (result == -1) ? printf("Element is not in the array\n")
                 : printf("Element is present at index %d\n", result);
   return 0;
}
