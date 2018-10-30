#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int rear=-1,front=-1,queue[MAX];

void add(int  item)
{
	rear=(rear+1)%MAX;
	if(front==rear)
	{
		printf("Queue overflow\n");
		exit(0);
	}
	queue[rear]=item;
}

int delete()
{	
	int item;
	item=queue[front];
	if(front==rear)
	{
		printf("Queue underflow\n");
		exit(0);
	}
	else
	{
		front=(front+1)%MAX;
		return item;
	}
}

int show()
{
	int i;
	if(front==-1)
	   printf("Queue is empty\n");
	else
	{
	  printf("Queue elements are:\n");
	  for(i=front;i<=rear;i++)
    	    printf("%d\t",queue[i]);
	  printf("\n");
	}
}

int main()
{
	int item,ch;
	for(;;) {
	printf("Menu:\n1.Add\n2.Delete\n3.Show\n4.Exit\nEnter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: printf("Enter the item to be inserted:");
			scanf("%d",&item);
			add(item);
			break;
		case 2: printf("The deleted item is:%d\n",delete());
			break;
		case 3: show();
			break;
		case 4: exit(0);
		default:printf("Wrong Entry\n");
	} }
}
