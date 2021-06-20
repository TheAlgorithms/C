#include <stdio.h>
#include <stdlib.h>

void comb_with_rep (int pos, int *numbers, int *prnt, int size, int subset_size, int start) 
{
	int i;
	if (pos >= subset_size) 
	{
		for (i = 0; i < subset_size; ++i)
			printf("%d ", prnt[i]);
		printf("\n");
		return; 
	}
	for (i = start; i < size; ++i) 
	{
		prnt[pos] = numbers[i];
		comb_with_rep (pos+1, numbers, prnt, size, subset_size, start);
		start++;
	}
}

int main()
{
	int size;
	printf("Insert size of the array: \n");
	scanf("%d", &size);

	int subset_size;
	int *numbers = malloc(size*sizeof(int));
	int *prnt = malloc(size*sizeof(int));

	printf("Insert %d numbers: \n", size);
	for (int i = 0; i < size; ++i)
		scanf("%d", &numbers[i]);
	printf("Insert subset dimension: ");
	scanf("%d", &subset_size);
	printf("\n");
	printf("The %d-combinations with repetitions of the given array are: \n", subset_size);
	comb_with_rep(0, numbers, prnt, size, subset_size, 0);
	free(numbers);
	free(prnt);
	return 0;
}

