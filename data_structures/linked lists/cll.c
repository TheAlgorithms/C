#include<stdio.h>
#include<stdlib.h>

// Structure definition:

typedef struct NODE{
	int data;
	struct NODE* link;
} node;

// Function Prototypes:

node *InsertAtBeg(node *, int);
node *InsertAtEnd(node *, int);
node *InsertAfter(node *, int, int);
void menu(node *);
void disp(node *);

// MAIN:

int main()
{
    node *last=NULL;
    menu(last);
    exit(0);
}

void menu(node *last)
{
    int x,y; char ch;
    do{
    disp(last);
    printf("Enter your Choice:\n(a).Insert at the beginning of the list");
    printf("\n(b).Insert at the End of the List.\n(c).Insert after a num");
    printf("ber in the list.\n(e).Exit\n");
    scanf("\n%c",&ch);
    switch(ch)
    {
	case 'a':printf("Enter the node which you want to insert\t");
		 scanf("%d",&x);
		 last = InsertAtBeg(last,x);
		 break;

	case 'b':printf("Enter the node which you want to insert\t");
		 scanf("%d",&x);
		 last = InsertAtEnd(last,x);
		 break;

	case 'c':printf("Enter the node after which you want to insert\t");
		 scanf("%d",&y);
	         printf("Enter the node which you want to insert\t");
		 scanf("%d",&x);
		 last = InsertAfter(last,y,x);
		 break;
/*
	case 'd':printf("Enter the node to be deleted\t");
		 scanf("%d",&y);
		 last = DeleteNode(last,y);
		 break;
*/
	case 'e':exit(0);break;

	default:printf("Invalid Option.\n");break;
    }
    }while(1);
}

node *InsertAtBeg(node *last, int x)
{
    if(!last)
    {
    	node *tmp = (node*)malloc(sizeof(node));
    	tmp->data=x;
    	tmp->link=tmp;
	last=tmp;
	return last;
    }
    node *tmp = (node*)malloc(sizeof(node));
    tmp->data=x;
    tmp->link=last->link;
    last->link=tmp;
    return last;
}

node *InsertAtEnd(node *last, int x)
{
    if(!last){
	last=InsertAtBeg(last,x);return last;}
    node *tmp = (node*)malloc(sizeof(node));
    tmp->data=x;
    tmp->link=last->link;
    last->link=tmp;
    last=tmp;
    return last;
}


node *InsertAfter(node *last, int y, int x)
{
    if(!last)
	return NULL;
    node *tmp = (node*)malloc(sizeof(node));
    node *temp;
    temp = last->link;
    tmp->data=x;
    do{
	if(temp->data == y)
	{
	    tmp->link = temp->link;
	    temp->link = tmp;
	    if(temp==last)
		last=temp;
	    return last;
	}
	temp=temp->link;
    }
    while(temp != last->link);
    printf("Item not found in the list. Enter accurate data\n");
    return last;
}
/*
node *DeleteNode(node *last, int y)
{
    node *prev=NULL, *cur=last;
    if(!last)//Empty CLL
	return NULL:
    while(cur->data != y){//cur->link condn is for
	// full traversal of the CLL.
	if(cur->link==last)// ^^
    	{
	   printf("Node couldn't be found. Enter accurate data\n");
	   return last;
    	}
    	prev=cur; cur=cur->link;
    }
    if(!prev && cur->link==last) // Single Node
    {
	free(last);
	return NULL;
    }
    if(cur==last)// First Node
    {
	prev=last;
	while(prev->next != cur)
	    prev=prev->next;
	last=cur->nexr;
	prev->next=last;
	free(cur);
	return last;
    }
    if(cur->link==last)//Last Node
    {
	prev->link=last;
	free(cur);
	return last;
    }
    prev->link=cur->link;
    free(cur);
    return last;
}
*/
void disp(node *last)
{
    printf("\n\n");
    if(!last)
	return;
    node *tmp=last->link;
/*    if(last->link==last){//Single node
	printf("Data: %d\n",tmp->data);return;}
    while(tmp->link!=last){
	printf("Data: %d\n",tmp->data);
	tmp = tmp->link;}
    printf("Data: %d\n",tmp->data);
*/
   int a=0;
    if(last->link==last){//Single node
	printf("Data: %d\n",tmp->data);return;}
   while(tmp!=last||!a)
   {
	printf("Data: %d\n",tmp->data);
	tmp=tmp->link;
	a=1;
   }
   printf("Data: %d\n",tmp->data);
   printf("\n\n");
}
