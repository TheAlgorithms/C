#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE {
	int data;
	struct _NODE* next;
} node;

typedef struct _QUEUE {
	struct _NODE* front;
	struct _NODE* back;
	int size;
}queue;	


void initQueue(queue* q)
{
	q->front = q->back = NULL;
	q->size = 0;
}

void push(queue* q, int data)
{
	node* newNode = (node *)malloc(sizeof(node));

	newNode->data = data;
	if (q->front == NULL)
	{
		newNode->next = NULL;
		q->front = newNode;
	}
	else if (q->back == NULL)
	{
		q->front->next = newNode;
		q->back = newNode;
	}
	else
	{
		q->back->next = newNode;
		q->back = newNode;
		q->back->next = NULL;
	}

	q->size++;
}

void pop(queue* q)
{
	node* delNode = q->front;
	q->front = delNode->next;
	free(delNode);
	q->size--;

}

void printQueue (queue q)
{
	node* printData;
	while (q.front != NULL)
	{
		printData = q.front;
		printf("%d ", printData->data);
		q.front = printData->next;
	}
	printf("\n");
}

int getTop(queue q)
{
	return q.size;
}

int main(int argc, char** argv)
{
	queue myQ;

	initQueue(&myQ);
	push(&myQ, 10);
	push(&myQ, 11);
	push(&myQ, 12);
	push(&myQ, 13);
	
	printQueue(myQ);
	printf("%d\n", getTop(myQ));

	pop(&myQ);
	pop(&myQ);
	printQueue(myQ);
	
	printf("%d\n",getTop(myQ));

	return 0;
}