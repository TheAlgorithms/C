#include<stdio.h>
#define sizeQueue 10
int totalElement;
struct queue{
	int info[sizeQueue];
	int start,end;
};

typedef struct queue Queue;

void enqueue(Queue *q,int n){
	if(totalElement == sizeQueue){
		printf("Queue is full!");
		//printf("%d %d %d",q->start,q->end,totalElement);
		return;
	}
	q->end = (q->end + 1)%sizeQueue;
	q->info[q->end] = n;
	totalElement++;
	if(totalElement == 0){
		q->start = (q->start + 1)%sizeQueue;
		//printf("%d %d %d",q->start,q->end,totalElement);
		return;
	}
	//printf("%d %d %d",q->start,q->end,totalElement);
}

int dequeue(Queue *q){
	if(totalElement == 0){
		printf("Queue is empty!");
		//printf("%d %d %d",q->start,q->end,totalElement);
		return -1;
	}
	totalElement--;
	//printf("%d %d %d",q->start,q->end,totalElement);
	q->start = (q->start + 1)%sizeQueue;
	return q->info[q->start];
}

void display(Queue q){
	int i,j=totalElement;
	//printf("%d %d",q.start,q.end);
	for(i = (q.start+1)%sizeQueue; j-- ; i = (i+1)%sizeQueue)
		printf("%d\n",q.info[i]);
}

void main(){
	char c;
	int i;
	Queue qu;
	qu.start = sizeQueue -1;
	qu.end = sizeQueue -1;
	do{
		printf("Enter 1 to enqueue.\nEnter 2 to dequeue.\nEnter 3 to display queue.\nEnter 4 to exit.\n");
		printf("Enter your choice:\t");
		scanf(" %c",&c);
		if(c == '4')
			break;
		switch(c){
			case '1':
				printf("Enter the number:\t");
				scanf("%d",&i);
				enqueue(&qu,i);
				break;
			case '2':
				i = dequeue(&qu);
				printf("%d is dequeued.\n",i);
				break;
			case '3':
				display(qu);
				break;
		}
		printf("\n\n");
	}while(1);
}
