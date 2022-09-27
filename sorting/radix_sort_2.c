// sorting of array list using Radix sort
#include <stdio.h>
#include <stdlib.h>

#define range 10  // Range for integers is 10 as digits range from 0-9

// Utility function to get the maximum value in ar[]
int MAX(int *ar, int size)
{
    int i, max = ar[0];
    for (i = 0; i < size; i++)
    {
        if (ar[i] > max)
            max = ar[i];
    }
    return max;
}

// Counting sort according to the digit represented by place
void countSort(int *arr, int n, int place)
{
    int i, freq[range] = {0};
    int *output = (int *)malloc(n * sizeof(int));

    // Store count of occurrences in freq[]
    for (i = 0; i < n; i++) freq[(arr[i] / place) % range]++;

    // Change freq[i] so that it contains the actual position of the digit in
    // output[]
    for (i = 1; i < range; i++) freq[i] += freq[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[freq[(arr[i] / place) % range] - 1] = arr[i];
        freq[(arr[i] / place) % range]--;
    }

    // Copy the output array to arr[], so it contains numbers according to the
    // current digit
    for (i = 0; i < n; i++) arr[i] = output[i];
    free(output);
}

/*This is where the sorting of the array takes place
 arr[] --- Array to be sorted
 n --- Array Size
 max --- Maximum element in Array
 */
void radixsort2(int *arr, int n,
                int max)  // max is the maximum element in the array
{
    int mul = 1;
    while (max)
    {
        countSort(arr, n, mul);
        mul *= 10;
        max /= 10;
    }
}

void display(int *arr, int N)
{
    for (int i = 0; i < N; i++) printf("%d, ", arr[i]);
    putchar('\n');
}

int main(int argc, const char *argv[])
{
    int n;
    printf("Enter size of array:\n");
    scanf("%d", &n);  // E.g. 8

    printf("Enter the elements of the array\n");
    int i;
    int *arr = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    display(arr, n);  // Original array : 10 11 9 8 4 7 3 8

    int max;
    max = MAX(arr, n);

    radixsort2(arr, n, max);

    printf("Sorted array: ");
    display(arr, n);  // Sorted array : 3 4 7 8 8 9 10 11

    free(arr);
    return 0;
}
