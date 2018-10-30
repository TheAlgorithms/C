#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>

typedef struct node{
	int data;
	struct node *next,*prev;
}Node;

Node *head=NULL;

void insertFront(int val) {
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->data=val;
	temp->prev=NULL;
	temp->next=head;
	head=temp;
}

void insertI(int val,int pos) {
	int i;
	Node *temp1 = (Node *)malloc(sizeof(Node));
	Node *temp2;
	temp2 = head;
	temp1->data=val;
	temp1->prev=NULL;
	temp1->next=NULL;
	for(i=1;i<=pos-2;++i)
		temp2=temp2->next;
	temp1->next=temp2->next;
	temp1->prev=temp2;
	temp2->next=temp1;
	(temp1->next)->prev=temp1;
}

int main() {
	int value,ans,pos,num,temp;
	Node *temp1;
	srand(time(NULL));
	num = rand() % 6+2;
	temp=num;
	do {
		value = rand() % 10;
		insertFront(value);
		--temp;	
	}while(temp!=0);

	//Display before inserting 
	printf("\n\nNULL <-> ");
	temp1=head;
	while(temp1!=NULL) {
		printf("%d <-> ",temp1->data);
		temp1=temp1->next;
	}
	printf(" NULL\n\n");

	printf("\nEnter position to Enter Node at :\t");
	scanf("%d",&pos);
	if(pos<=0||pos>num){
		printf("\n\nInvalid position !!\n\n");
		exit(1);
	}
	printf("Enter value :\t");
	scanf("%d",&value);

	//Inserting at ith position
	insertI(value,pos);    

	//Display after insertion
	printf("\n\nNULL <-> ");
	temp1=head;
	while(temp1!=NULL) {
		printf("%d <-> ",temp1->data);
		temp1=temp1->next;
	}
	printf(" NULL\n\n");
	return 0;
}
