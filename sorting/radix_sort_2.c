// sorting of array list using Radix sort
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define range 10  // Range for integers is 10 as digits range from 0-9

// Utility function to get the maximum value in arr[]
int MAX(int *arr, int size)
{
    int i, max = arr[0];
    for (i = 0; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Utility function to get the minimum value in arr[]
int MIN(int *arr, int size)
{
    int i, min = arr[0];
    for (i = 0; i < size; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

// Counting sort according to the digit represented by place
void countSort(int *arr3, int pos, int place)
{
    int i, freq[range] = {0};
    int *output = (int *)malloc(pos * sizeof(int));

    // Store count of occurrences in freq[]
    for (i = 0; i < pos; i++) freq[(arr3[i] / place) % range]++;

    // Change freq[i] so that it contains the actual position of the digit in
    // output[]
    for (i = 1; i < range; i++) freq[i] += freq[i - 1];

    // Build the output array
    for (i = pos - 1; i >= 0; i--)
    {
        output[freq[(arr3[i] / place) % range] - 1] = arr3[i];
        freq[(arr3[i] / place) % range]--;
    }

    // Copy the output array to arr[], so it contains numbers according to the
    // current digit
    for (i = 0; i < pos; i++) arr3[i] = output[i];
    free(output);
}

// Reverse counting sort according to the digit represented by place
void reverseSort(int *arr2, int neg, int place)
{
    int i, freq[range] = {0};
    int *output = (int *)malloc(neg * sizeof(int));

    // Store count of occurrences in freq[]
    for (i = 0; i < neg; i++) freq[-(arr2[i] / place) % range]++;

    // Change freq[i] so that it contains the actual position of the digit in
    // output[]
    for (i = range - 1; i > 0; i--) freq[i - 1] += freq[i];

    // Build the output array
    for (i = neg - 1; i >= 0; i--)
    {
        output[freq[-(arr2[i] / place) % range] - 1] = arr2[i];
        freq[-(arr2[i] / place) % range]--;
		// printf("freq[(arr[i] / place) %% range]: freq[%d]\n", ((arr[i] / place) % range));
    }

    // Copy the output array to arr[], so it contains numbers according to the
    // current digit
    for (i = 0; i < neg; i++) arr2[i] = output[i];
    free(output);
}

// Counting negative numbers in arr[]
int numNeg(int *arr, int n)
{
	int j = 0;
	int i;
	for (i = 0; i < n; i++)
	{
		if(arr[i] < 0)
			j++;
	}
	return j;
}

// Creates an integer array with negative numbers
int *takeNeg(int *arr, int n, int neg)
{
	int *arr2 = (int *)malloc(neg * sizeof(int));
	int j = 0;
	int i;
	for (i = 0; i < n; i++)
	{
		if(arr[i] < 0)
        {
			arr2[j] = arr[i];
		    j++;
        }
	}
	return arr2;
}

// Counting positive numbers and 0 in arr[]
int numPos(int *arr, int n)
{
	int j = 0;
	int i;
	for (i = 0; i < n; i++)
	{
		if(arr[i] >= 0)
			j++;
	}
	return j;
}

// Creates an integer array with positive numbers
int *takePos(int *arr, int n, int pos)
{
	int *temp = (int *)malloc(pos * sizeof(int));
	int j = 0;
	int i;
	for (i = 0; i < n; i++)
	{
		if(arr[i] >= 0)
        {
			temp[j] = arr[i];
		    j++;
        }
	}
	return temp;
}

//Sorts positive numbers
void sortPos(int *arr3, int pos, int max)
{
	int place = 1;
    while (max)
    {
        countSort(arr3, pos, place);
        place *= 10;
        max /= 10;
    }
}

//Sorts negative numbers
void sortNeg(int *arr2, int neg, int min)
{
	int place = 1;
	min *= -1;
    while (min)
    {
        reverseSort(arr2, neg, place);
        place *= 10;
        min /= 10;
    }
}

//Combines sorted negative number array and positive number array
int *combine(int *arr, int *first, int *second, int f, int s)
{
    int i;
    for (i = 0; i < f; i++) arr[i] = first[i];
    for (int j = 0; j < s; j++) arr[i + j] = second[j];
    free(first);
    free(second);
    return arr;
}


/*This is where the sorting of the array takes place
 arr[] --- Array to be sorted
 n --- Array Size
 min --- Minimum element in Array
 max --- Maximum element in Array
 */
void radixsort2(int *arr, int n,
				int min,  // min is the minimum element in the array
                int max)  // max is the maximum element in the array
{
    int *arr2;
    int *arr3;
    int neg = numNeg(arr, n);
	int pos = numPos(arr, n);
    arr2 = takeNeg(arr, n, neg);
    arr3 = takePos(arr, n, pos);
	sortNeg(arr2, neg, min);
	sortPos(arr3, pos, max);
    arr = combine(arr, arr2, arr3, neg, pos);
}


void display(int *arr, int N)
{
    for (int i = 0; i < N; i++) printf("%d, ", arr[i]);
    putchar('\n');
}

int main(void)
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
    display(arr, n);  // Original array : -78, 5, 9, 4, 6, -752, 658, 59, 70, -8, 0, 1, -1, 1000, -1000

    int max;
    max = MAX(arr, n);
	int min;
	min = MIN(arr, n);

	radixsort2(arr, n, min, max);

    printf("Sorted array: ");
    display(arr, n);  // Sorted array : -1000, -752, -78, -8, -1, 0, 1, 4, 5, 6, 9, 59, 70, 658, 1000

    free(arr);
    return 0;
}