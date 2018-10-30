#include<stdio.h>
#include<stdlib.h>

#define MAX 5
char cq[MAX];

int front=-1;
int rear=-1;
void insert();
void delete();
void display();

void main()
{
	int c;
	front=rear=-1;
	printf("Menu:\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
	do
	{
		printf("Enter your choice:\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:insert();
					break;
			case 2:delete();
					break;
			case 3:display();
					break;
			case 4:exit(0);
					break;
			default:printf("Invalid choice\n");
		}
	}while(c!=4);
}
void insert()
{
	char x;
	if((front==0&&rear==MAX-1)||(front==rear+1))
		printf("Circular queue is full-Overflow\n");
	else
	{
		if(front==-1)
			front=rear=0;
		else
		{
			if(rear==MAX-1)
				rear=0;
			else
				rear++;
		}
		printf("Enter the character:\n");
		scanf("%s",&x);
		cq[rear]=x;
	}
}
void delete()
{
	char y;
	if(front==-1)
		printf("Circulqr queue is empty-Underflow\n");
	y=cq[front];
	if(front==rear)
		front=rear=-1;
	else
	{
		if(front==MAX-1)
			front=0;
		else
			front++;
	}
}
void display()
{
	int i;
	if(front==-1&&rear==-1)
		printf("Circular queue is empty\n");
	else
	{
		printf("Elements of the circular queue are:\n");
		for(i=front;i!=rear;i++)
			printf("%c\n",cq[i]);
		printf("%c\n",cq[rear]);
	}
}

