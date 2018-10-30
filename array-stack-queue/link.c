#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	char usn[100],name[100],branch[100],sem[100];
	int phno;
	struct node *link;
};

struct node * start=NULL;

void create(int);
void insertfront();
void insertback();
void delfront();
void delback();
void display();
int stack();
int queue();

void main()
{
	int ch,n;
	do
	{
		printf("Menu:\n1.create nodes\n2.Insert at front\n3.Insert at back\n4.Delete at front\n5.Delete at end\n6.Display\n7.Stack operations\n8.Queue operations\n9.Exit\nEnter you choice:");
		scanf("%d",&ch);
                switch(ch)
		{
			case 1: printf("Enter the number of nodes\n");
				scanf("%d",&n);
				create(n);
				break;
			case 2: insertfront();
				break;
			case 3: insertback();
				break;
			case 4: delfront();
				break;
			case 5: delback();
				break;
			case 6: display();
				break;
			case 7: stack();
				break;
			case 8: queue();
				break;
			case 9: return;
				break;
			default : printf("INVALID CHOICE");
		}
	}while(ch!=9);
}

void insertfront()
{
	struct node *temp;
        char usn1[100],name1[100],branch1[100],sem1[100];
        int phno1;
	temp=(struct node *)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("Insufficent memory");
		exit(0);
	}	
	printf("Enter the USN\n");
	scanf("%s",usn1);
	printf("Enter the Name\n");
        scanf("%s",name1);
	printf("Enter the branch\n");
        scanf("%s",branch1);
	printf("Enter the sem\n");
        scanf("%s",sem1);
	printf("Enter the phno\n");
	scanf("%d",&phno1);
 
	strcpy(temp->usn,usn1);
	strcpy(temp->name,name1);
	strcpy(temp->sem,sem1);
	strcpy(temp->branch,branch1);
	temp->phno=phno1;

	if(start==NULL)
	{
		start=temp;
		temp->link=NULL;
	}
	else 
	{
		temp->link=start;
		start=temp; 
	}
}

void insertback()
{
        struct node *temp;
        char usn1[100],name1[100],branch1[100],sem1[100];
        int phno1; 
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("Insufficent memory");
                exit(0);
        }   
        
        printf("Enter the USN\n");
        scanf("%s",usn1);
        printf("Enter the Name\n");
        scanf("%s",name1);
        printf("Enter the branch\n");
        scanf("%s",branch1);
        printf("Enter the sem\n");
        scanf("%s",sem1);
	printf("Enter the phno\n");
        scanf("%d",&phno1);
 
        strcpy(temp->usn,usn1);
        strcpy(temp->name,name1);
        strcpy(temp->sem,sem1);
        strcpy(temp->branch,branch1);
        temp->phno=phno1;

        if(start==NULL)
        {
                start=temp;
                temp->link=NULL;
        }
        else 
        {
		struct node *dstart=start; 	
		while(dstart->link != NULL)
			dstart=dstart->link;    
		dstart->link=temp;
		temp->link=NULL;          
	}
}

void create(int n)
{
	int i;
	for(i=1;i<=n;i++)
		insertfront();
}

void delfront()
{
	if(start==NULL)
		printf("Linked list is emepty");
	else 
	{
		free(start);
		start=start->link;
	}
}

void delback()
{
        if(start==NULL)
                printf("Linked list is emepty");
        else 
	{
		struct node *dstart=start; 
		struct node *prev=dstart;
		while(dstart->link!=NULL)
		{
			prev=dstart; 
			dstart=dstart->link; 
		}	
		prev->link=NULL;
		free(dstart); 
		dstart=NULL; 
	}
}
	
void display()
{

	struct node *dstart=start;
	printf("\n\n\n\n\n");
	if(start==NULL)
		printf("The linked list is empty\n");
	else
	{
	while(dstart != NULL)
	{
		printf("USN is %s\n",dstart->usn);
		printf("Name is %s\n",dstart->name);
		printf("Branch is %s\n",dstart->branch);
		printf("Sem is %s\n",dstart->sem);
		printf("phone number is %d\n",dstart->phno);
		dstart=dstart->link;
		printf("\n\n\n");
	}
	}
}

int stack()
{
	int ch;
	start=NULL;
	printf("Stack opeartions:\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
	do
	{
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: insertfront();
				break;
			case 2: delfront();
				break;
			case 3: display();
				break;
			case 4: printf("Back to the main menu\n");
				break;
		}
	}while(ch!=4);
}

int queue()
{
	int ch;
	start=NULL;
	printf("Queue operations:\n1.Push\n2.Pop\n3.Display\n4.Back to main menu\n");
	do
	{
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: insertback();
				break;
			case 2: delfront();
				break;
			case 3: display();
				break;
			case 4: printf("Back to main menu\n");
				break;
		}
	}while(ch!=4);
}
