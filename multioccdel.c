#include<stdio.h>
#include<stdlib.h>
struct student *head;
struct student *tail;
struct student
{
    int roll;
    char name[50];
    struct student *next;
};

int create()
{
	struct student *p;
	p=(struct student*)malloc(sizeof(struct student));
	printf("Enter roll no & name : ");
	scanf("%d",&p -> roll);
	gets(p -> name);
	p -> next = NULL;
	if(head==NULL)
	{
		head=tail=p;
	}
	else{
		tail -> next=p;
		tail=p;
	}
	
}
int getCurrSize(struct student* p){
    int size=0;

    while(p !=NULL){
        p = p->next;
        size++;
    }
    return size;
}
int insert(int pos)
{
	struct student *p, *q;
	int n;
	int size = getCurrSize(head);
	p=(struct student*)malloc(sizeof(struct student));
	printf("Enter roll no & name : ");
	scanf("%d",&p -> roll);
	gets(p -> name);
	
	if(pos<0 || pos>size)
	{
		printf("Insertion is not possible");
	}
	 else if(pos == 0){
        p->next = head; 
        head = p;
	}
    else if(head==NULL&&pos==1)
	{
		head=tail=p;
		
	}
	else if (head!=NULL&&pos==1){
		tail -> next=p;
		tail=p;
	}
	
	
	else
	{
		 q=head;
		 while(--pos)
		 {
		 	q=q->next;
		 	p -> next = q -> next;
		    q -> next = p;
		    
	
	}
	
}
}

void delmultioccur(int x)
{
    while (head && head->roll == x)
        head = head->next; 
    struct student *p=head,*q=NULL;
    while(p)
    {
        if(p->roll==x)
        q->next=p->next;
        else
        q=p;
        p=p->next;
    }
}
int display(){
	struct student *p;
	p=head;
	while(p!=NULL){
		printf("%d",p -> roll);
		puts(p -> name);
		p = p -> next;
	}
}
int main()
{
	head=tail=NULL;
	int ch,n,p;
	
	while(1)
	{
		printf("Enter 1 to create, 4 to display, 3 to insert 2 to delete multioccur");
		scanf("%d",&ch);
	
	switch(ch){
		case 1 : create();
		         break;
		case 2 : 
				
				printf("enter the num u wanna dlt:");
				scanf("%d",&p);
				delmultioccur(p);
		        break;
           
		case 3 : 
		        printf("enetr to select the position:");
		        scanf("%d",&n);
		        insert(n);
		         break;
		case 4:
				display();
		         break;
		        
	}
	
	}
	return 0;
}
	