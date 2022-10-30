#include <stdio.h>
int search(int arr[], int n, int x)
{
    // Normal Binary Search
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
            return mid;

        // Binary Search In Left Half Sorted
        if (arr[low] < arr[mid])
        {
            if (x >= arr[low] && x <= arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        // Binary Search In Right Half Sorted
        else
        {
            if (x > arr[mid] && x <= arr[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 8, 9};
    int n = 7;
    int x = 30;
    int pos = search(arr, n, x);
    if (pos == -1)
        printf("Element Not Found In The Array");
    else
        printf("The Position of Element in the array is %d", pos);
}