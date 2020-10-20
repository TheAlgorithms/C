#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
	struct node *prev;
};
int c=-1;
struct node *head=NULL;
void insert(int val);
void insertbeg(int val);
void insertmid(int val, int pos);
void deletebeg();
void deleteend();
void deletepos(int pos);
void display();
void main(){
	int option,val,pos;
	do{
		printf("\ncases:\n(1)insert at end\n(2)insert at beginning\n(3)insert at position\n(4)delete from beginning\n(5)delete from end\n(6)delete from a position\n(7)display\n(8)exit\n");
		printf("\nenter an option: ");
		scanf("%d",&option);
		switch(option){
			case 1:
				printf("\nenter a value to be inserted: ");
				scanf("%d",&val);
				insert(val);
				break;
			case 2:
				printf("\nenter the value to be inserted: ");
				scanf("%d",&val);
				insertbeg(val);
				break;
			case 3:
				printf("\nenter the value to be inserted: ");
				scanf("%d",&val);
				printf("\nenter the position after which the value has to be inserted: ");
				scanf("%d",&pos);
				insertmid(val,pos);
				break;
			case 4:
				deletebeg();
				break;
			case 5:
				deleteend();
				break;
			case 6:
				printf("\nenter the position from which the value has to be deleted: ");
				scanf("%d",&pos);
				deletepos(pos);
				break;
			case 7:
				display();
				break;
			case 8:
				printf("\nThank You");
				break;
			default:
				printf("\nenter a valid option");
		}
	}while(option!=8);
	
}
void insert(int val){
	if(head==NULL){
		head=(struct node *)malloc(sizeof(struct node));
		head->next=NULL;
		head->prev=NULL;
		head->data=val;
		c+=1;
		printf("\n%d has been inserted",head->data);
	}
	else{
		int i;
		struct node *new_node=NULL;
		new_node=(struct node *)malloc(sizeof(struct node));
		new_node->data=val;
		struct node *p=NULL;
		p=(struct node *)malloc(sizeof(struct node));
		p=head;
		for(i=1;i<=c;i++){
			p=p->next;
		}
		new_node->prev=p;
		p->next=new_node;
		new_node->next=NULL;
		printf("\n%d has been inserted",new_node->data);
		c+=1;
	}
}
void display(){
	if(head==NULL){
		printf("\nthe list is empty");
	}
	else{
		int i;
		struct node *p=NULL;
		p=(struct node *)malloc(sizeof(struct node));
		p=head;
		printf("\nhe list is:\n");
		for(i=0;i<=c;i++){
			if(i==0){
				printf("NULL<-%d->",p->data);
			}
			else if(i<c){
				printf("<-%d->",p->data);
			}
			else{
				printf("<-%d->NULL",p->data);
			}
			p=p->next;
		}
	}
}
void insertbeg(int val){
	struct node *new_node=NULL;
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=val;
	new_node->prev=NULL;
	head->prev=new_node;
	new_node->next=head;
	head=new_node;
	c+=1;
	printf("\n%d has been inserted",new_node->data);
}
void insertmid(int val, int pos){
	int i;
	struct node *new_node=NULL;
	new_node=(struct node *)malloc(sizeof(struct node));
	struct node *p=NULL;
	p=(struct node *)malloc(sizeof(struct node));
	p=head;
	struct node *n=NULL;
	n=(struct node *)malloc(sizeof(struct node));
	for(i=0;i<pos;i++){
		n=p;
		p=p->next;
	}
	new_node->next=p;
	new_node->prev=n;
	new_node->data=val;
	n->next=new_node;
	p->prev=new_node;
	c+=1;
	printf("\n%d has been inserted",new_node->data);
}
void deletebeg(){
	struct node *n=NULL;
	n=(struct node *)malloc(sizeof(struct node));
	printf("\n%d has been deleted",head->data);
	n=head->next;
	n->prev=NULL;
	free(head);
	head=n;
	c-=1;
}
void deleteend(){
	int i;
	struct node *p=NULL;
	p=(struct node *)malloc(sizeof(struct node));
	p=head;
	for(i=1;i<=c;i++){
		p=p->next;
	}
	p->prev->next=NULL;
	printf("\n%d has been deleted",p->data);
	free(p);
	c-=1;
}
void deletepos(int pos){
	int i;
	struct node *p=NULL;
	p=(struct node *)malloc(sizeof(struct node));
	struct node *n=NULL;
	n=(struct node *)malloc(sizeof(struct node));
	p=head;
	for(i=0;i<pos;i++){
		n=p;
		p=p->next;
	}
	if(p==NULL){
		deleteend();
	}
	else{
		printf("\n%d has been deleted",n->data);
		//free(p->prev);
		n->prev->next=p;
		p->prev=n->prev;
		free(n);
		c-=1;
	}
}