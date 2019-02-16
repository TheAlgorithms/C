#include <stdio.h>
#define SHRINK 1.3	//suggested shrink factor value

void sort (int *numbers, int size) 
{
	int gap = size;
	while (gap > 1) 	//gap = 1 means that the array is sorted 
	{
		gap = gap/SHRINK;
		int i = 0;
		while ((i + gap) < size) 
		{	//similiar to the Shell Sort
			if (numbers[i] > numbers[i + gap])
			{
				int tmp = numbers[i];
				numbers[i] = numbers[i + gap];
				numbers[i + gap] = tmp;
			}
			i++;
		}
	}
}
int main()
{
	int size = 6;
	int *numbers = malloc(size*sizeof(int));
	printf("Insert %d unsorted numbers: \n", size);
	for (int i = 0; i < size; ++i)
		scanf("%d", &numbers[i]);
	printf("Initial array: ");
	for (int i = 0; i < size; ++i)
		printf("%d ", numbers[i]);
	printf("\n");
	sort(numbers, size);
	printf("Sorted array: ");
	for (int i = 0; i < size; ++i)
		printf("%d ", numbers[i]);
	printf("\n");
    free(numbers);
	return 0;
}
