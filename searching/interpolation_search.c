#include <stdio.h>

/* By comparison, binary search always chooses the middle of the remaining
 * search space, discarding one half or the other, depending on the comparison
 * between the key found at the estimated position and the key sought. The
 * remaining search space is reduced to the part before or after the estimated
 * position. The linear search uses equality only as it compares elements
 * one-by-one from the start, ignoring any sorting. On average the interpolation
 * search makes about log(log(n)) comparisons (if the elements are uniformly
 * distributed), where n is the number of elements to be searched. In the worst
 * case (for instance where the numerical values of the keys increase
 * exponentially) it can make up to O(n) comparisons. In
 * interpolation-sequential search, interpolation is used to find an item near
 * the one being searched for, then linear search is used to find the exact
 * item. */

int interpolationSearch(int arr[], int n, int key)
{
    int low = 0, high = n - 1;
    while (low <= high && key >= arr[low] && key <= arr[high])
    {
        /* Calculate the nearest posible position of key */
        int pos =
            low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]);
        if (key > arr[pos])
            low = pos + 1;
        else if (key < arr[pos])
            high = pos - 1;
        else /* Found */
            return pos;
    }
    /* Not found */
    return -1;
}

int main()
{
    int x;
    int arr[] = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\nEnter the number to be searched: ");
    scanf("%d", &x); /* Element to be searched */

    int index = interpolationSearch(arr, n, x);

    /* If element was found */
    if (index != -1)
        printf("Element found at position: %d\n", index);
    else
        printf("Element not found.\n");
    return 0;
}
