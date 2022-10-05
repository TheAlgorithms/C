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

struct student *top;

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

void deletenthpos(int pos)
{
    int c;
    struct student *q=head;
    if(pos==1)
    {
        q=head;
        head=head->next;
    }
    else{
    while(c<pos-1)
    {
        q = q -> next;
        c++;

    }
    q->next=q->next->next;
     if(q->next==NULL)
    {
        tail=q;
    }
    }

}

void srchdelete(int n)
{
   
    struct student *p=head;
    int flag=0,c=1;
    while(p!=NULL)
    {
        if(p->roll==n)
        {
        flag=1;
        break;}
         
        p=p->next;
        c++;
    }
   
    if (flag==0)
    printf("not found");
    else{ 
         
    int ch;
    
    printf("data found at %d",c);
    
    while (1)
    {
        printf("enter 1 to delete 2 display 3 to exit");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            deletenthpos(c);
            break;
        case 2:
            display();
            break;
        case 3:
            exit(0);
        }
    }
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
	int ch,n,i=1,a;
	
	while(1)
	{
		printf("Enter 1 to create, 2 to display, 3 to insert 4 to delete 5 to srchdelete");
		scanf("%d",&ch);
	
	switch(ch){
		case 1 : create();
		         break;
		case 2 : display();
		         break; 
		case 3 : 
		        printf("enetr to select the position:");
		        scanf("%d",&n);
		        insert(n);
		         break;    
        /*case 4:
                printf("enter the position to  be deleted");
                scanf("%d",&i); 
                deletenthpos(i);
                break; */   
        case 5:
            
            printf("enter the data to be searched:");
            scanf("%d",&a);
            srchdelete(a);
            break; 
          
	}
	
	}
	return 0;
	
}
