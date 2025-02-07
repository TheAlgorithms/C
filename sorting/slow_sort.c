#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Displays array passed as parameter*/
void display(int arr[], int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");
}

/*Swaps the two values passed to the function*/
void swap(int *num1, int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = *num1;
}

/*
  Slow sort function
  @param arr The array to be sorted
  @param low The starting index
  @param high The ending index
*/
void slowsort(int arr[], int low, int high)
{
	if (low >= high)
		return;

	int middle = (low + high) / 2;

	slowsort(arr, low, middle);
	slowsort(arr, middle+1, high);

	if (arr[high] < arr[middle])
		swap(&arr[high], &arr[middle]);

	slowsort(arr, low, high - 1);
}

/*Test function*/
void test()
{
	const int size = 20;

	int *arr = (int *)calloc(size, sizeof(int));

	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
	}

	slowsort(arr, 0, size-1);

	display(arr, size);

	free(arr);
}

int main()
{
	srand(time(NULL));
	test();
	return 0;
}
