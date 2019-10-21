// Sorting of array list using stooge sort
#include <stdio.h>
#include <stdlib.h>

// Displays the array, passed to this method
void display(int arr[], int n)
{

    int i;
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

}

// Swap function to swap two values
void swap(int *first, int *second)
{

    int temp = *first;
    *first = *second;
    *second = temp;

}

// Function to sort the array using stooge sort
void stoogesort(int arr[], int l, int h)
{
    if (l >= h)
        return;

    // If first element is smaller than last, swap them
    if (arr[l] > arr[h])
        swap(&arr[l], &arr[h]);

    // If there are more than 2 elements in the array
    if (h - l + 1 > 2)
    {
        int t = (h - l + 1) / 3;

        // Recursively sort first 2/3 elements
        stoogesort(arr, l, h - t);

        // Recursively sort last 2/3 elements
        stoogesort(arr, l + t, h);

        // Recursively sort first 2/3 elements
        // again to confirm
        stoogesort(arr, l, h - t);
    }
}

// Driver program to test above function
int main()
{
    int n;  // Size of array elements
    int arr[n];

    printf("Enter size of array:\n");
    scanf("%d", &n); // E.g. 8

    printf("Enter the elements of the array\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i] );
    }

    printf("Original array: ");
    display(arr, n);

    stoogesort(arr, 0, n - 1);
    printf("Sorted array: ");
    display(arr, n);

    return 0; 
}