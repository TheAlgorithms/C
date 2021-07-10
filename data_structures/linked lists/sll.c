#include<stdio.h>
#include<stdlib.h>

// Structure definition:

typedef struct NODE{
	int data;
	struct NODE* link;
} node;

// Function Prototypes:

node *InsertAtBeg(node *first,int x);
void  InsertAtEnd(node *first, int x);
void  InsertAfter(node *first, int y, int x);
node *DeleteNode(node *first,int y);
void menu(node *first);
void disp(node *);

// MAIN:

int main()
{
    node *first=NULL;
    menu(first);
    exit(0);
}

void menu(node *first)
{
    int x,y; char ch;
    do{
    disp(first);
    printf("Enter your Choice:\n(a).Insert at the beginning of the list");
    printf("\n(b).Insert at the End of the List.\n(c).Insert after a num");
    printf("ber in the list.\n(d).Delete a node.\n(e).Exit\n");
    scanf("\n%c",&ch);
    switch(ch)
    {
	case 'a':printf("Enter the node which you want to insert\t");
		 scanf("%d",&x);
		 first = InsertAtBeg(first,x);
		 break;

	case 'b':printf("Enter the node which you want to insert\t");
		 scanf("%d",&x);
		 InsertAtEnd(first,x);
		 break;

	case 'c':printf("Enter the node after which you want to insert\t");
		 scanf("%d",&y);
	         printf("Enter the node which you want to insert");
		 scanf("%d",&x);
		 InsertAfter(first,y,x);
		 break;

	case 'd':printf("Enter the node to be deleted\t");
		 scanf("%d",&y);
		 first = DeleteNode(first,y);
		 break;

	case 'e':exit(0);break;

	default:printf("Invalid Option.\n");break;
    }
    }while(1);
}

node *InsertAtBeg(node *first, int x)
{
    node *tmp = (node*)malloc(sizeof(node));
    tmp->data=x;
    tmp->link=first;
    first=tmp;
    return first;
}

void InsertAtEnd(node *first, int x)
{
    node *tmp = (node*)malloc(sizeof(node));
    while(first->link)
	first=first->link;
    tmp->data=x;
    first->link=tmp;
    tmp->link=NULL;
}


void InsertAfter(node *first, int y, int x)
{
    node *tmp = (node*)malloc(sizeof(node));

    tmp->data=x;
    while(first && first->data != y)
	first = first->link;
    if(!first)
    {
	printf("Node couldn't be found. Enter accurate data\n");
	return;
    }
    tmp->link = first->link;
    first->link = tmp;
}

node *DeleteNode(node *first, int y)
{
    node *prev=NULL, *cur=first;
    while(first && cur->data != y){
	prev=cur;
	cur = cur->link;}
    if(!cur)
    {
	printf("Node couldn't be found. Enter accurate data\n");
	return first;
    }
    if(!prev && !first)
    {
	free(first);
	return NULL;
    }
    if(!prev)
    {
	first=first->link;
	free(cur);
	return first;
    }
    prev->link=cur->link;
    free(cur);
    return first;
}

void disp(node *first)
{
    printf("\n\n");
    while(first){
	printf("Data: %d\n",first->data);
	first = first->link;}
    printf("\n\n");
}
