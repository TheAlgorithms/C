#include<stdio.h>
#include<stdlib.h>

#define MAX 5

typedef struct linkedList
{
	int data;
	struct linkedList *next;
}List;

int hashFunction(int n)
{
	while(n>10)
	{
		n/=10;
	}
	return n;
}

List* createNode()
{
	List* temp=(List*)malloc(sizeof(List));
	temp->next=NULL;
	return temp;
}

int main()
{
	int a[MAX], i, key;
	List* list[10];
	List* temp;

	for(i=0; i<10; i++)
	{
		list[i]=NULL;
	}

	printf("Enter elements\n");
	for(i=0; i<MAX; i++)
	{
		scanf("%d", &a[i]);
	}

	for(i=0; i<MAX; i++)
	{
		key=hashFunction(a[i]);
	
		if(list[key]==NULL)
		{
			list[key]=createNode();
			list[key]->data=a[i];
		}
		else
		{
			while(list[key]!=NULL)
			{
				List* newNode=createNode();
				newNode->data=a[i];
			
				if(a[i]<=(list[key]->data))
				{
					newNode->next=temp->next;
					temp->next=newNode;
				}
			
				if(temp->next==NULL)
				{
					temp->next=newNode;
				}
			
				temp=temp->next;
			}
		}
	}

	int k=0;

	for(i=0; i<10; i++)
	{
		if(list[i]!=NULL)
		{
			temp=list[i];
			while(temp!=NULL)
			{
				a[k]=temp->data;
				temp=temp->next;
				k++;
			}
		}
	}

	printf("\nSorted\n");
	for(i=0; i<MAX; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
