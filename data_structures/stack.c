#include<stdio.h>
#include<stdlib.h>
#define MAX 10
struct node
{
	int info;
	struct node *link;
}*top=NULL;
void display()
{
	struct node *ptr;
	ptr=top;
	int i;
	if(top==NULL)
	{
		printf("stack underflow");
		exit(1);
	}
	 printf("stack elements :\n");
	 while(ptr!=NULL)
	 {
	 	printf("%d\n",ptr->info);
	 	ptr=ptr->link;
	 }
    printf("\n");
}
void push(int item)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	if(tmp==NULL)
	 {
	   printf("stack overflow");
	   exit(1);
     }
	 tmp->info=item;
	 tmp->link=top;
	 top=tmp;
}
int pop()
{
	struct node *tmp;
	int item;
	if(top==NULL)
	 {
	  printf("stack underflow");
	  exit(1);
     }
     tmp=top;
     item=tmp->info;
     top=top->link;
     free(tmp);
		return item;
}
int main()
{
	int op,item;
	while(1)
	{
			printf("\nenter 1 for push\t enter 2 for pop\t enter 3 for display\t enter 4 for exit");
	        scanf("%d",&op);
		switch(op)
		{
			case 1:printf("enter elements in array\n");
			       scanf("%d",&item);
			       push(item);
			break;
			case 2: item=pop();
			       printf("the popped elements %d\n", item);
			break;
			case 3: display();
			break;
			case 4: exit(1);
			default:
				printf("Invalid option");
		}
	}
}
