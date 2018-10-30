#include<stdio.h>
#include<stdlib.h>
#define MAX 5
char cqueue[MAX];
int front=-1,rear=-1;

void cEnQueue(char ele) {
	if((front==0&&rear==MAX-1)||front==rear+1)
		printf("\nOverflow!!\n\n");
	else if(rear==-1||front==-1) {
		front=rear=0;
		cqueue[rear]=ele;
	}
	else if(rear==MAX-1) {
		rear=0;
		cqueue[0]=ele;
	}
	else
		cqueue[++rear]=ele;
}
void cDeQueue() {	
	if(front==-1)
		printf("\nUndreflow!!\n\n");
	else if(rear==front) {
		front=rear=-1;
	}
	else if(front==MAX-1) {
		front=0;
	}
	else
		++front;
}

void cQDisplay() {
	int i;
	if(rear==-1||front==-1)
		printf("\nEmpty Queue\n\n");
	else if(rear<front) {
		printf("\n\nFront >>");
		for(i=front;i<=MAX-1;++i)
			printf("  %c",cqueue[i]);
		for(i=0;i<=rear;++i)
			printf("  %c",cqueue[i]);
		printf("  << Rear\n\n");
	}
	else if(rear>=front) {
		printf("\n\nFront >>");
		for(i=front;i<=rear;++i)
			printf("  %c",cqueue[i]);
		printf("  << Rear\n\n");
	}
}

int  main() {
	int opt,ch;
	char ele;
	do {
		printf("\n\n\tMENU\n");
		printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your Choice :\t");
		scanf("%d",&ch);
		switch(ch) {
			case 1  : printf("Enter Element to be inserted :\t");
				  scanf(" %c",&ele);
 				  cEnQueue(ele);
				  break;
			case 2  : cDeQueue();
				  break;
			case 3  : cQDisplay();
				  break;
   			case 4  : exit(0);
			default : printf("\nInvalid input !!\n\n");

		}
		printf("\n\nMenu again ?");
		scanf("%d",&opt);
	}while(opt==1);
	return 0;
}
