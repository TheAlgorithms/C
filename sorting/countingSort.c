#include <stdio.h>
#include <string.h>	// for memset
#include <assert.h>

int main()
{
	int i, n, l = 0;
	scanf("%d", &n);

	assert(n < 1e7);
	int a[n];


	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		//for now, We can't hash negative indexes
		assert(a[i] >= 0);
		if (a[i] > l)
			l = a[i];
	}
	// to save us from accidenty declaring insanely large array
	assert(l < 1e7);
	// In C,it is considered a bad practice to initialise a array at definition that was initialised at runtime 
	int b[l + 1];
	// Initialising all the values to zero
	memset(b,0,sizeof(b));

	for (i = 0; i < n; i++)
		b[a[i]]++; //hashing number to array index

	for (i = 0; i < (l + 1); i++)
	{
		if (b[i] > 0)
		{
			while (b[i] != 0) //for case when number exists more than once
			{
				printf("%d ", i);
				b[i]--;
			}
		}
	}
	printf("\n");
	return 0;
}