#include <stdio.h>
#include <stdlib.h>
void bubblesort(int*, int);
void printArr(int*, int);

int main()
{
	int arr[] = {9,8,7,6,5,4,3,2,1};
	int size = sizeof(arr) / sizeof(arr[0]);

	bubblesort(arr, size);
	printArr(arr,size);
	
	return 0;
}

void bubblesort(int* arr, int size)
{
	int temp;
	for (int i=0; i<size; i++)
	{
		for (int j=0; j<size-i-1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void printArr(int * arr, int size)
{
	for(int i=0; i<size; i++)
	{
		printf("%d ", arr[i]);
	}
}


