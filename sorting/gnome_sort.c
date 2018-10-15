#include <stdio.h>
#include <stdlib.h>
void sort(int *numbers, int size)
{
	int pos = 0;
	while (pos < size)
	{
		if (pos == 0 || (numbers[pos] >= numbers[pos-1]))
			pos++;
		else 
		{
			int tmp = numbers[pos];
			numbers[pos] = numbers[pos-1];
			numbers[pos-1] = tmp;
			pos--;
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
	return 0;
}

