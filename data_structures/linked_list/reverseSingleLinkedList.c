#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
};

struct node *AddAtBeginning(struct node *head, int item){
	struct node *new;
	new=(struct node*)malloc(sizeof(struct node));
	new->data=item;
	new->link=head;
	head=new;
	return head;
}

struct node *AddAtEnd(struct node *head, int item){
	struct node *t=head;
	while(t->link!=NULL)
		t=t->link;
	struct node *new;
	new=(struct node *)malloc(sizeof(struct node));
	new->data=item;
	t->link=new;
	new->link=NULL;
	return head;
}

struct node *CreateList(struct node *head){
	int n, item;
	printf("Enter no of nodes to be in the list: ");
	scanf("%d", &n);
	if(n==0)
		return head;
	printf("Enter the next data item: ");
	scanf("%d", &item);
	head=AddAtBeginning(head, item);
	for(int i=2; i<=n; i++){
		printf("Enter the next data item: ");
		scanf("%d", &item);
		head=AddAtEnd(head, item);
	}
	return head;
}

void DisplayList(struct node *head){
	if(head==NULL){
		printf("List is empty.\n");
		return;
	}
	struct node *t=head;
	printf("The data of the nodes are:\n");
	while(t){
		printf("%d ", t->data);
		t=t->link;
	}
	printf("\n");
	return;
}

struct node *ReverseList(struct node *current){
	struct node *previous, *next;
	previous=NULL;
	next=NULL;
	while(current){
		next=current->link;
		current->link=previous;
		previous=current;
		current=next;
	}
	return previous;
}

int main(){
	struct node *head=NULL;
	head=CreateList(head);
	printf("\n--Before--\n");
	DisplayList(head);
	head=ReverseList(head);
	printf("\n--After--\n");
	DisplayList(head);
	return 0;
}