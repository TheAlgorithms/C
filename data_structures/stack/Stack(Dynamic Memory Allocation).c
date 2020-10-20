// This is Stack using  Dynamic array
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

using namespace std;
// Structure is also a kind of Datatype
struct ArrayStack
{
	int top;// 2 bytes
	int capacity;//  2 bytes
	int *array;//  2 bytes
};

struct ArrayStack *CreateStack(int cap)
{
	struct ArrayStack *stack;
	stack=(struct ArrayStack *)malloc(sizeof(struct ArrayStack));//or stack=malloc(6)
    stack->capacity=cap;// This is arrow operator to access the member of structure by a pointer
    stack->top=-1;
    stack->array=(int*)malloc(sizeof(int)*stack->capacity);
    return(stack);
    
} 

int isFull(struct ArrayStack* stack)
{
	if(stack->top == stack->capacity-1)
	   return 1;
	
	else
	   return 0;
	
}

int isEmpty(struct ArrayStack *stack)
{
	if(stack->top == -1)
	 return 1;
	else
	 return 0;
}

int push(struct ArrayStack *stack,int item)
{
	 
	if(!isFull(stack))
	{
		stack->top++;
		stack->array[stack->top]=item; 
	}
	
}
int pop(struct ArrayStack *stack)
{
	int item;
	if(!isEmpty(stack))
	{
		item=stack->array[stack->top];
		stack->top--;
		return item;
		
	}
	return -1;
}

main()
{
	struct ArrayStack *stack;
	stack=CreateStack(4);
	int n,item;
	while(1)//infinite loop
	{
		
		printf("\n 1. Push");
		printf("\n 2. Pop");
		printf("\n 3. Exit");
		printf("\n Enter your choice:");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("\n Enter a number:");
				scanf("%d",&item);
				push(stack,item);
				break;
			case 2:
			    item=pop(stack);
			    if(item==-1)
			    printf("stack is empty");
			    else
				printf("\n The Poped value is %d ",item);
				
			case 3:
			    exit(0);		
				
		}
		getch();
	}
}
