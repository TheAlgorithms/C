#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>

typedef struct node{
	int data;
	struct node *link;
}Node;

Node *head=NULL;

void insertFront(int val) {
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->data=val;
	temp->link=head;
	head=temp;
}

void rev() {	
	Node *curr = (Node *)malloc(sizeof(Node));
	Node *next = (Node *)malloc(sizeof(Node));
	Node *prev = (Node *)malloc(sizeof(Node));
	curr=head;
	next=prev=NULL;
	while(curr!=NULL) {
		next=curr->link;
		curr->link=prev;
		prev=curr;
		curr=next;
	}
	head=prev;
}

int main() {
	int value,num,temp;
	Node *temp1;
	srand(time(NULL));
	num = rand() % 5 + 2;
	temp=num;
	do {
		value = rand() % 10;
		insertFront(value);
		--temp;	
	}while(temp!=0);
	
	temp1=head;
	while(temp1!=NULL) {
		printf("%d --> ",temp1->data);
		temp1=temp1->link;
	}
	printf(" NULL\n\n");

	rev();

	temp1=head;
	while(temp1!=NULL) {
		printf("%d --> ",temp1->data);
		temp1=temp1->link;
	}
	printf(" NULL\n\n");
	return 0;
}
