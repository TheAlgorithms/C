#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *link;
};
struct node *ins_last(struct node *);
struct node *ins_beg(struct node *);
void display(struct node *);
int main()
{
	struct node *start, *fresh, *ptr;
	start=NULL;
	int choice;
	do
	{
		printf("\n MENU \n");
		printf("\n 1.Insertion at the end");
		printf("\n 2.Displaying the nodes");
		printf("\n 3.exit");
		printf("\n 4.Insertion at the beginning");
		printf("\n Enter your choice:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: start=ins_last(start);
				break;
			case 2: display(start);
				break;
			case 3: exit(0);
			case 4: start=ins_beg(start);
				break;
			default: printf("Invalid Choice\n");
		}
	}while(choice!=3);
  return 0;
}
struct node *ins_last(struct node *start)
{
	struct node *fresh, *ptr;
	int item;
	printf("Enter the item:\n");
	scanf("%d",&item);
	fresh=(struct node *)malloc(sizeof(struct node));
	
	if(fresh==NULL)
	{
		printf("\n Overflow!");
		exit(0);
	}
	fresh->info=item;
	fresh->link=NULL;
	if(start==NULL)
	{
		start=fresh;
	}
	else
	{
		ptr=start;
		while(ptr->link!=NULL)
		{
			ptr=ptr->link;
		}
		ptr->link=fresh;
	}
	return(start);
}

void display(struct node *start)
{
	struct node *ptr;
	ptr=start;
	printf("\nThe elements are:\n");
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->info);
		ptr=ptr->link;
	}
	printf("\n");
	
}
struct node *ins_beg(struct node *start)
{
	struct node *fresh;
	int item;
	printf("Enter the item\n");
	scanf("%d",&item);
	fresh=(struct node *)malloc(sizeof(struct node));
	if(fresh==NULL)
	{
		printf("Overflow\n");
		exit(0);
	}
	else
	{
		fresh->info=item;
		fresh->link=NULL;
	}
	if(start==NULL)
	{
		start=fresh;
	}
	else
	{
		fresh->link=start;
		start=fresh;
	}
	return start;
}
	