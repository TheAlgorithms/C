#include <stdio.h>
// function to swap variable
void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
/* partition function takes last element as pivot and places
   the pivot element at its correct position. It means all
   smaller element will be placed to left all greater elements
   to right of pivot
 */
int partition(int arr[], const int left, const int right)
{
    int pivot = arr[right];  // pivot
    int i = (left - 1);
    int j = left;
    for (j = left; j <= (right - 1); j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++;  // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return (i + 1);
}
// Function returns the k'th smallest
// element in the arr within `left…right`
// (i.e., `left <= k <= right`).
int quickselect(int arr[], const int left, const int right, const int k)
{
    // If k is smaller than number of
    // elements in array
    if (k > 0 && k <= (right - left + 1))
    {
        // Partition the array around last
        // element and get position of pivot
        // element in sorted array
        int index = partition(arr, left, right);
        // If position is same as k
        if (index - left == k - 1)
            return arr[index];
        // If position is more, recur
        // for left subarray
        if (index - left > k - 1)
            return quickselect(arr, left, index - 1, k);
        // Else recur for right subarray
        return quickselect(arr, index + 1, right, k - index + left - 1);
    }
}

int main()
{
    int arr[] = {1, 0, 10, 4, 3, 18, 15};
    const int arr_size = sizeof(arr) / sizeof(arr[0]);
    const int k = 2;
    const int smallestElement = quickselect(arr, 0, arr_size - 1, k);
    printf("%d'th smallest element is %d\n", k, smallestElement);
    return 0;
}
