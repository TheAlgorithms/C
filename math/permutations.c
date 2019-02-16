#include <stdio.h>
#include <stdlib.h>

void permutations (int pos, int *numbers, int *prnt, int *mark, int size) 
{
	int i;
	if (pos == size) {
		for (i = 0; i < size; ++i)
			printf("%d ", prnt[i]);
		printf("\n");
		return;
	}
	for (i = 0; i < size; ++i)
		if (mark[i] == 0) 
		{
			prnt[pos] = numbers[i];
			mark[i] = 1;
			permutations (pos+1, numbers, prnt, mark, size);
			mark[i] = 0;
		}	
}
int main()
{
	int size = 3;
	int *numbers = malloc(size*sizeof(int));
	int *prnt = malloc(size*sizeof(int));
	int *mark = malloc(size*sizeof(int));
	printf("Insert %d numbers: \n", size);
	for (int i = 0; i < size; ++i)
	{
		scanf("%d", &numbers[i]);
		mark[i] = 0;
	}
	printf("\n");
	printf("The permutations of the given array are: \n");
	permutations(0, numbers, prnt, mark, size);
    free(numbers);
    free(prnt);
    free(mark);
	return 0;
}

