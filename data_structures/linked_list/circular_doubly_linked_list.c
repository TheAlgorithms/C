
/* A Menu Driven Program containing all the standard problems of the Circular Doubly Linked List using C*/


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct Node
{
	struct Node *prev;
	int info;
	struct Node *next;
}node;
node *create_C_D_ll(node *first);
void disp(node *p);
void search(node *,int);
void count(node*);
node *insfirst(node*,int); //equal to push()
node *inslast(node*,int);
node *delfirst(node*);  //equal to pop()
node *dellast(node*);
node *delspe(node*,int);
node* delall(node*);
void main()
{
	node *first=NULL;
	int item;
	int ch;
	while(1)
	{
		printf("\n1.create");
		printf("\n2.display");
		printf("\n3.search");
		printf("\n4.count");
		printf("\n5.insert at first(push)");
		printf("\n6.insert at last");
		printf("\n7.delete the first(pop)");
		printf("\n8.Delete last");
		printf("\n9.Delete specific item");
		printf("\n10.Delete All item");
	/*	printf("\n11.del After specific item");
		printf("\n12.del Before specific item");
		printf("\n13.del duplicate item");
		printf("\n14.sort list");
	*/
		printf("\n11.Exit");
		printf("\nEnter ur choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:first=create_C_D_ll(first);
					 break;
			case 2:disp(first);break;
			case 3:printf("\nEnter item to search:");
					 scanf("%d",&item);
					 search(first,item);
					 break;
			case 4:count(first);
					 break;
			case 5:printf("\nEnter item to search:");
					 scanf("%d",&item);
					 first=insfirst(first,item);
					 break;
			case 6:printf("\nEnter item to search:");
					 scanf("%d",&item);
					 first=inslast(first,item);
					 break;
			case 7:
					 first=delfirst(first);
					 break;
			case 8:
					 first=dellast(first);
					 break;
			case 9:printf("enter an item to delete:");
					 scanf("%d",&item);
					 first=delspe(first,item);
					 break;
			case 10:
					 first=delall(first);
					 break;
				case 11:
				printf("program end---THANK U");
				exit(0);
			default:printf("Wrong choice");
		} //end of switch
	} //end of while

}  //MAIN END
node *create_C_D_ll(node *first)
{
	node *curr=NULL,*p=NULL;
	char stop='y';
	while(stop=='y' ||stop=='Y')
	{
		curr=(node *)malloc(sizeof(node));
		if(curr==NULL)
		{
			printf("MAF");
			exit(0);
		}
		printf("\nEnter a number:");
		scanf("%d",&curr->info);
		if(first==NULL)
			first=curr;
		else
		{
			p->next=curr;
			curr->prev=p;
		}
		p=curr;
		printf("\nWant to continue:(y/n)");
		stop=getch();
	} //loop end
	//terminating linked list
	 p->next=first;
	 first->prev=p;
	 return first;
}
void disp(node *first)
{
	//traversing list and printing numbers
	node*p=first;
	if(first==NULL)
		printf("list is empty");
	else
	{
		printf("\nThe numbers are:");
		do
		{
			printf("%d ",p->info);
			p=p->next;
		}while(p!=first);
	}
}
void search(node *first,int item)
{
	node *p=first;
	if(first==NULL)
		printf("list is empty");
	else
	{
		do
		{
			if(p->info==item)
				break;
			p=p->next;
		}while(p!=first);
		if(p->info==item)
			printf("\n\nitem found\n\n");
		else
			printf("\n\nitem not found\n\n");
	}
}//search end
void count(node *first)
{
	node *p=first;
	int c=0;
	if(first==NULL)
		printf("list is empty");
	else
	{
		do
		{
			c++;
			p=p->next;
		}while(p!=first);
		printf("\n\ntotal number of node=%d\n\n",c);
	}
}//count
node*insfirst(node*first,int item) //push()
{
	node*curr,*p;
	curr=(node*)malloc(sizeof(node));
	if(curr==NULL)
	{
		printf("MAF");
		exit(0);
	}
	curr->info=item;
	if(first==NULL)
		first=curr;
	else
	{
		p=first->prev;
		p->next=curr;
		first->prev=curr;
		curr->next=first;
		curr->prev=p;
		first=curr;
	}
	return first;
}
node*inslast(node*first,int item)
{
	node*curr,*p;
	curr=(node*)malloc(sizeof(node));
	if(curr==NULL)
	{
		printf("MAF");
		exit(0);
	}
	curr->info=item;
	if(first==NULL)
		first=curr;
	else
	{
		p=first->prev;
		p->next=curr;
		curr->prev=p;
		curr->next=first;
		first->prev=curr;
	}
	return first;
}
node*delfirst(node*first)   //pop()
{
	node *p;
	if(first==NULL)
		printf("\nList is empty.\n");
	else if(first->prev==first)//single node
	{
		free(first);
		first=NULL;
	}
	else
	{
		p=first->prev;
		p->next=first->next;
		p=first;
		first=first->next;
		first->prev=p->prev;
		p->prev=p->next=NULL;
		free(p);
	}
	return first;
}
node *dellast(node *first)
{
	node* p=NULL;
	if(first==NULL)
		printf("List is empty.");
	else if(first->prev==first->next)
	{
		free(first);
		first=NULL;
	}
	else
	{
		p=first->prev;
		p->prev->next=first;
		first->prev=p->prev;
		p->next=p->prev=NULL;
		free(p);
	}
	return first;
}

node *delspe(node*first,int item)
{
	node *p=NULL;
	int flag=0;
	if(first==NULL)
		printf("List is empty.");
	else
	{
		p=first;
		do
		{
			if(p->info==item)
			{
				flag=1;
				break;
			}
			p=p->next;
		}while(p!=first);
		if(flag==0)
			printf("Item not found.");
		else
		{
			if(first==first->next)//first node & single node
			{
				free(first);
				first=NULL;
			}
			else if(first==p && p->next!=first)
			{
					p=first->prev;
					p->next=first->next;
					p=first;
					first=first->next;
					first->prev=p->prev;
					p->prev=p->next=NULL;
					free(p);
			}
			else if(p->next==first) //last node
			{
				p->prev->next=first;
				first->prev=p->prev;
				p->prev=p->next=NULL;
				free(p);
			}
			else    //middle node
			{
				 p->prev->next=p->next;
				 p->next->prev=p->prev;
				 p->prev=p->next=NULL;
				 free(p);
			}
		}
	}
	return first;
}
/*********************************/
node *delall(node *first)
{
	node* p=NULL;
	if(first==NULL)
		printf("LIst is empty.");
	else if(first->prev==first->next)
	{
		free(first);
		first=NULL;
	}
	else
	{
		p=first;
		do
		{
			first=first->next;
			p->next=p->prev=NULL;
			free(p);
			p=first;
		}while(p!=first);
		first=NULL;
		printf("\n\nAll items are deleted.\n\n");
	}
	return first;
}
