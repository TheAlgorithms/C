#include <stdio.h>
#include <stdlib.h>

/*I translated the python version on wikipedia to C */
void sort (int *numbers, int size) 
{
	int i, item, pos;
	for (i = 0; i < size-1; ++i)
	{
		item = numbers[i];
		pos = i;
		for (int j = i+1; j < size; ++j)
			if (numbers[j] < item)
				pos++;
		if (pos == i)
			continue;
		while (item == numbers[pos])
			pos++;
		int tmp = numbers[pos];
		numbers[pos] = item;
		item = tmp;

		while (pos != i){
			pos = i;
			for (int j = i+1; j < size; ++j)
				if (numbers[i] < item)
					pos++;
			while (item == numbers[pos])
				pos++;
			int tmp = numbers[pos];
			numbers[pos] = item;
			item = tmp;
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
