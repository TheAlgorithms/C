#include<stdio.h>
#include<stdlib>
#define MAX 100;
void create();
void insert();
void Delete();
void display();
int n,a[MAX];
void main()
{
	int choice;
	printf("1.Create\n2.Insert\n3.Display\n4.Delete);
	printf("\nEnter your option-:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: create();
			break;
		case 2: Insert();
			break;
		case 3: display();
			break;
		case 4: Delete()
			break;
		default: exit(0);
	}
}
void create()
{
	int i;
	printf("Enter the number of elements-\n);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
}
void insert()
{
	int pos,ele,i; 
	printf("Enter the element and position-\n);
	scanf("%d%d",&ele,&pos);
	for(i=n-1;i 










