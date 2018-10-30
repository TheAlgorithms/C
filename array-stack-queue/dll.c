#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
    char ssn[15],name[25],dept[20],desig[10];
    int phno,sal;
    struct node *nxtlink,*prevlink;
 };

int n;
void create(int);
void insertfront();
void insertend();
void delfront();
void delend();
void display();
void queue();

struct node *start=NULL;
//start=(struct node *)malloc(sizeof(node));
//start=NULL;

void main(){
int i;
 
 while(1)
 {
  printf("\n\nEnter Your Choice :\n");
    printf("1.Create DLL\n2.Display Status and No. Of Nodes of DLL\n3.Insertion At The End\n4.Deletion At End\n5.Insertion At Front \n6.Deletion At Front\n7.Doubly Ended Queue Implementation\n8.Exit\n\n");

scanf("%d",&i);

switch(i)
{
 case 1:printf("Enter The NO. OF Node's : ");
        scanf("%d",&n);
        printf("\n\n");
        create(n);
        break;

 case 2:display();
        break;

 case 3:insertend();
        break;
          
 case 4:delend();
        break;

 case 5:insertfront();
        break;

 case 6:delfront();
        break;

 case 7:queue();
        break;
 
 case 8:exit(0);

 default:printf("Wrong Choice!!!\n\n"); 
}
}
}

void create(int n){
  int i;
    for(i=0;i<n;i++)
      insertfront();
}

void insertfront(){
struct node *temp;
temp=(struct node *)malloc(sizeof(struct node));
if(temp==NULL)
{
printf("Insufficient Memory!!!\n");
exit(0);
}

printf("Enter the SSN:");
scanf("%s",temp->ssn);

printf("Enter The Name:");
 scanf("%s",temp->name);

printf("Enter The Department:");
 scanf("%s",temp->dept);

printf("Enter The Designaton:");
 scanf("%s",temp->desig);

printf("Enter The Salary:");
 scanf("%d",&temp->sal);

printf("Enter The Phone No.:");
 scanf("%d",&temp->phno);
printf("\n");

if(start==NULL){
start=temp;
temp->prevlink=NULL;
temp->nxtlink=NULL;
}
else
{
temp->prevlink=NULL;
temp->nxtlink=start;
start=temp;
}
}

void insertend()
{
struct node *temp;
temp=(struct node *)malloc(sizeof(struct node));

if(temp==NULL)
{
printf("Insufficient Momory!!!\n");
exit(0);
}

printf("Enter the SSN:");
scanf("%s",temp->ssn);

printf("Enter The Name:");
 scanf("%s",temp->name);

printf("Enter The Department:");
 scanf("%s",temp->dept);

printf("Enter The Designaton:");
 scanf("%s",temp->desig);

printf("Enter The Salary:");
 scanf("%d",&temp->sal);

printf("Enter The Phone No.:");
 scanf("%d",&temp->phno);
printf("\n");

if(start==NULL)
{
start=temp;
temp->prevlink=NULL;
temp->nxtlink=NULL;
}
else
{
struct node *Dstart=start;
  while(Dstart->nxtlink!=NULL)
 {  Dstart=Dstart->nxtlink;}
  temp->nxtlink=NULL;
  temp->prevlink=Dstart;
  Dstart->nxtlink=temp;
 }
}

void display(){
struct node *Dstart=start;
 int i=1;
 while(Dstart!=NULL)
   {
       printf("Detail's Of Employee : %d\n",i);
        printf("SSN: %s\n",Dstart->ssn);
        printf("Name: %s\n",Dstart->name);
        printf("Depatment: %s\n",Dstart->dept);
        printf("Salary: %d\n",Dstart->sal);
        printf("Designation: %s\n",Dstart->desig);
        printf("Phone No.: %d\n\n",Dstart->phno);
        Dstart=Dstart->nxtlink;
        i++;
   }
printf("The No. Of Nodes Are : %d",--i);
}

void delfront(){
if(start==NULL)
 printf("Linked List Is Empty!!\n");

else
{
struct node *temp=start->nxtlink;
 free(start);
 start=temp;
 temp->prevlink=NULL;
}
}

void delend(){
if(start==NULL)
 printf("Linked List Is Empty!!\n");

else
 {struct node *Dstart=start;

 while(((Dstart->nxtlink)->nxtlink)!=NULL)
{
 Dstart=Dstart->nxtlink;
}

free(Dstart->nxtlink);
Dstart->nxtlink=NULL;
}
}

void queue(){

	int ch;
	start=NULL;
	printf("\n\nDouble Ended Queue Operations:\n1.Enqueue at front\n2.Enqueue at rear\n3.Dequeues at front\n4.Dequeue at rear\n5.Dispaly\n6.Back To Main Menu\n\n");

	do{
		printf("Enter Ur Choice :");
                 scanf("%d",&ch);
		switch(ch)
		{ 
                  case 1:insertfront();
                         break;
                  case 2:insertend();
                         break;
                  case 3:delfront();
                         break;
                  case 4:delend();
                         break;
                  case 5:display();
                         break;
                  case 6:break;
                    }}
        while(ch!=6);
}
