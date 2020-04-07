#include <stdio.h>
#include <math.h>
#include <limits.h>

#define MAX_LEN INT_MAX

int main(int argc, char **argv)
{
	int a[MAX_LEN], n = 10, i, j, temp, sum = 0;
	float mean;

	if (argc == 2)
	{
		n = atoi(argv[1]);
		if (n >= MAX_LEN)
		{
			fprintf(stderr, "Maximum %d!\n", MAX_LEN);
			return 1;
		}
	}

	printf("Random Numbers Generated are : ");
	for (i = 0; i < n; i++)
	{
		a[i] = rand() % 100;
		printf("%2d, ", a[i]);
	}
	putchar('\n');

	for (i = 0; i < n; i++)
		sum = sum + a[i];

	mean = sum / (float)n;
	printf("\nMean :");
	printf("%f", mean);

	return 0;
}
