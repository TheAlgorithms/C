//MULTIPLE STACK
#include<stdio.h>
#include<conio.h>
#define size 10
int stack[10];
int topx=-1, topy=10;
void push_x(int *);
void push_y(int *);
void pop_x(int *);
void pop_y(int *);
void displayx(int stack[])
{
	int i;
	//printf("\nTop=%d\n",topx);
	if(topx==-1)
	{
		printf("Stack is empty");
		return;
	}
	else
	for(i=topx;i>=0;i--)
	{
		printf("%d ",stack[i]);
	}
}
void displayy(int stack[])
{
	int i;
	//printf("\nTop%d\n",topy);
	if(topy>=size)
	{
		printf("Stack is overflow");
		return;
	}
	else
	for(i=topy;i<size;i++)
	{
		printf("%d ",stack[i]);
		
	}
}
void main()
{
	int ch;
	char con;
	clrscr();
	printf("1-PUSH_X\n2-PUSH_Y\n3-POP_X\n4-POP_Y\n5-EXIT");
	do{
		printf("\nEnter your choice ");
		scanf("%d",&ch);
		if (ch==5)
			break;
		switch(ch)
		{
			case 1:
			{
				push_x(stack);
				break;
			}
			case 2:
			{
				push_y(stack);break;}
			case 3:
			{
				pop_x(stack);
				break;
			}
			case 4:
			{
				pop_y(stack);
				break;
			}
			default:
			{
			printf("\nEnter a valid choice");
			break;
			}
		}
		printf("\nDO YOU WANT TO CONTINUE");
		con=getch();
	}
		while(con=='y'||con=='Y');
}
void push_x(int stack[])
{
	int data;
	if(topx>=size)
	{
		printf("\n?Push error! - the stack is in overflow condition");
		return;
	}
	else
	{
		printf("\nEnter the Element ");
		scanf("%d",&data);
		topx++;
		stack[topx]=data;
	}

displayx(stack);
}
void push_y(int stack[])
{
	int data;
	if(topy<=-1)
	{
		printf("\nPush error! - the stack is in underflow condition");
		return;
	}
	else
	{
		printf("\nEnter the Element ");
		scanf("%d",&data);
		topy--;
		stack[topy]=data;
	}
displayy(stack);	
}
void pop_x(int stack[])
{
	if(topx==-1)
	{
		printf("\nPop error! - the stack is in underflow condition");
	}
	else
	{
		printf("Element Deleted = %d\n",stack[topx]);
		topx--;
	}
displayx(stack);
}
void pop_y(int stack[])
{
	if(topy==size)
	{
		printf("\nPop error! - the stack is in Overflow condition");
	}
	else
	{
		printf("Element Deleted = %d\n",stack[topy]);
		topy++;
	}
displayy(stack);
}
