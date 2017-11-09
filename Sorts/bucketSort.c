#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

/*v[] is the array*/
/*A simple function to receive the values of the array v[]*/
void read(int v[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		v[i] = rand() % n; /*To avoid the worst case, the numbers max range is the total size of the array*/
	}
}

/*Put the values of the array in the output*/
/*mens[] is the message*/
void print(int v[], int n, char mens[])
{
	int i;
	printf("%s\n",mens);
	for(i = 0; i < n; i++)
	{
		printf("%d ", v[i]);
		if(i % 20 == 0) printf("\n");
	}
	printf("\n");
}
typedef struct no
{
	int value;
	struct no* next;
}Node;

/*Insert ordered values to the bucket*/
/*We could just use a simple stable sort algorithm, like InsertionSort.*/
void insert(Node** r, int value)
{
	Node* p;
	Node* aux = NULL;
	Node* current = (*r);
	int cond = 1;

	p = (Node*)malloc(sizeof(Node));

	p->value = value;
	p->next = NULL;

 	while(current != NULL	&& cond)
 	{
 		if(value <  current->value) cond = 0;
 		else
 		{
 			aux = current;
 			current = current->next;
 		}
 	}
 	p->next = current;
 	if(aux == NULL) (*r) = p;
 	else aux->next = p;
}

/*This is our main function*/
void bucketSort(int v[], int n)
{
	Node** bucket = (Node**)malloc(n * sizeof(Node*));
	int i,j;
	/*Start all buckets with NULL*/
	for(i = 0; i < n; i++)
	{
		bucket[i] = NULL;
	}
	/*Sort a large set of floating point numbers which are in range from 0.0 to 1.0 and are uniformly distributed across the range*/
	for(i = 0; i < n; i++)
	{
		/*Take the properly interval*/
		int idx = n * ((double) v[i]/(n + 1));
		/*Insert ordered values to the bucket*/
		insert(bucket+idx, v[i]);

	}

	int idx = 0;
	Node*  b;
	/*Put the values way back to original array*/
	/*Iterate through the bucket*/
	for(i = 0; i < n; i++)
	{
		b = bucket[i];
		while(b != NULL)
		{
			v[idx++] = (b)->value;/*Take the first value of the list and put on the array*/
			bucket[i] = (b)->next;/*Walk through the list*/
			free(b);
			b = bucket[i]; /*Go to the next element in list*/
		}
		free(b);
	}
}
/*------------------------------------------*/
int main()
{
	srand(time(NULL));
	int n;
	printf("Input the array range\n");
	scanf("%d",&n);
	int *v = malloc(sizeof(int)*n);

	int i;

	read(v, n);
	print(v, n, "Before");
	printf("\n");
	bucketSort(v, n);
	printf("\n");
	print(v, n, "After");
	printf("\n\n");

	return 0;
}