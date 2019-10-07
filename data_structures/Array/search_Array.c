// C program to implement linear
// search in unsorted array
#include<stdio.h>

// Function to implement search operation
int findElement(int arr[], int n,
                int key)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == key) 
            return i;

    return -1;
}

// Driver Code
int main()
{
    int arr[] = {12, 34, 10, 6, 40};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Using a last element as search element
    int key = 40;
    int position = findElement(arr, n, key);

    if (position == - 1)
        printf("Element not found");
    else
        printf("Element Found at Position: %d", position + 1 );

    return 0;
}
