#include<stdio.h>
#define sizeQueue 10

int totalElement;

struct queue{
	int info[sizeQueue];
	int start,end;
};

typedef struct queue Queue;

void enqueueE(Queue *q,int n){
	if(totalElement == sizeQueue){
		printf("Queue is full!");
		printf("%d %d %d",q->start,q->end,totalElement);
		return;
	}
	q->end = (q->end + 1)%sizeQueue;
	q->info[q->end] = n;
	if(totalElement == 0){
		q->start = (q->start + 1)%sizeQueue;
	}
	totalElement++;
	printf("%d %d %d",q->start,q->end,totalElement);
}

void enqueueF(Queue *q,int n){
	if(totalElement == sizeQueue){
		printf("Queue is full!");
		printf("%d %d %d",q->start,q->end,totalElement);
		return;
	}
	q->start = (q->start - 1)%sizeQueue;
	q->info[q->start] = n;
	if(totalElement == 0){
		q->end = (q->end - 1)%sizeQueue;
	}
	totalElement++;
	printf("%d %d %d",q->start,q->end,totalElement);
}

int dequeueF(Queue *q){
    int temp;
	if(totalElement == 0){
		printf("Queue is empty!");
		printf("%d %d %d",q->start,q->end,totalElement);
		return -1;
	}
	totalElement--;
	printf("%d %d %d",q->start,q->end,totalElement);
	temp = q->info[q->start];
	q->start = (q->start + 1)%sizeQueue;
	return temp;
}

int dequeueE(Queue *q){
    int temp;
	if(totalElement == 0){
		printf("Queue is empty!");
		printf("%d %d %d",q->start,q->end,totalElement);
		return -1;
	}
	totalElement--;
	printf("%d %d %d",q->start,q->end,totalElement);
	temp = q->info[q->end];
	q->end = (q->end - 1)%sizeQueue;
	return temp;
}

void display(Queue q){
	int i,j=totalElement;
	printf("%d %d\n",q.start,q.end);
	for(i = q.start; j--; i = (i+1)%sizeQueue)
		printf("%d ",q.info[i]);
}

void main(){
	int c;
	int i;
	Queue qu;
	qu.start = sizeQueue -1;
	qu.end = sizeQueue -1;
	printf("%d %d %d\n",qu.start,qu.end,totalElement);
	do{
		printf("Enter 1 to enqueue from Front.\nEnter 2 to enqueue from End.\nEnter 3 to dequeue from Front.\nEnter 4 to dequeue from End.\nEnter 5 to display queue.\nEnter 6 to exit.\n");
		printf("Enter your choice:\t");
		scanf("%d",&c);
		if(c == 6)
			break;
		switch(c){
			case 1:
				printf("Enter the number:\t");
				scanf("%d",&i);
				enqueueF(&qu,i);
				break;
			case 2:
				printf("Enter the number:\t");
				scanf("%d",&i);
				enqueueE(&qu,i);
				break;
			case 3:
				i = dequeueF(&qu);
				printf("%d is dequeued.\n",i);
				break;
			case 4:
				i = dequeueE(&qu);
				printf("%d is dequeued.\n",i);
				break;
			case 5:
				display(qu);
				break;
		}
		printf("\n\n");
	}while(1);
}
