#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
    char usn[15],name[25],branch[20],sem[10];
    int phno;
    struct node *link;
 };

int n;
void create(int);
void insertfront();
void insertend();
void delfront();
void delend();
void display();
void stack();
void queue();

struct node *start=NULL;
//start=(struct node *)malloc(sizeof(node));
//start=NULL;

void main(){
int i;
 
 while(1)
 {
  printf("\n\nEnter Your Choice :\n");
    printf("1.Create SLL\n2.Display Status and No. Of Nodes of SLL\n3.Insertion At The End\n4.Deletion At End\n5.Insertion At Front \n6.Deletion At Front\n7.Stack Implementation\n8.Queue Implementation\n9.Exit\n\n");

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

 case 7:stack();
        break;
 
 case 8:queue();
	break;
 
 case 9:exit(0);

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

printf("Enter the USN:");
scanf("%s",temp->usn);

printf("Enter The Name:");
 scanf("%s",temp->name);

printf("Enter The Branch:");
 scanf("%s",temp->branch);

printf("Enter The Sem:");
 scanf("%s",temp->sem);

printf("Enter The Phone No.:");
 scanf("%d",&temp->phno);
printf("\n");

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

void insertend()
{
struct node *temp;
temp=(struct node *)malloc(sizeof(struct node));

if(temp==NULL)
{
printf("Insufficient Momory!!!\n");
exit(0);
}

printf("Enter The USN:");
 scanf("%s",temp->usn);

printf("Enter The Name:");
 scanf("%s",temp->name);

printf("Enter The Branch:");
 scanf("%s",temp->branch);

printf("Enter The Sem:");
 scanf("%s",temp->sem);

printf("Enter The Phone No.:");
 scanf("%d",&temp->phno);
printf("\n");
if(start==NULL)
{
start=temp;
temp->link=NULL;
}

else
{
struct node *Dstart=start;
  while(Dstart->link!=NULL)
 {  Dstart=Dstart->link;}
  temp->link=NULL;
 Dstart->link=temp;

}
}

void display(){
struct node *Dstart=start;
 int i=1;
 while(Dstart!=NULL)
   {
       printf("Detail's Of Student : %d\n",i);
        printf("USN: %s\n",Dstart->usn);
        printf("Name: %s\n",Dstart->name);
        printf("Branch: %s\n",Dstart->branch);
        printf("Sem: %s\n",Dstart->sem);
        printf("Phone No.: %d\n\n",Dstart->phno);
        Dstart=Dstart->link;
        i++;
   }
printf("The No. Of Nodes Are : %d",--i);
}

void delfront(){
if(start==NULL)
 printf("Linked List Is Empty!!\n");

else
{
struct node *temp=start->link;
 free(start);
 start=temp;
}
}

void delend(){
if(start==NULL)
 printf("Linked List Is Empty!!\n");

else
 {struct node *Dstart=start;

 while(((Dstart->link)->link)!=NULL)
{
 Dstart=Dstart->link;
}

free(Dstart->link);
Dstart->link=NULL;
}
}

void stack(){

int ch;
start=NULL;
 printf("\n\nStack Operations :\n1.Push\n2.Pop\n3.Display\n4.Back To Main Menu\n\n");

do 
{
printf("Enter Ur Choice :");
 scanf("%d",&ch);

switch(ch){

case 1:insertend();break;
case 2:delfront();break;
case 3:display();break;
case 4:break;

}
}
while(ch!=4);
}

void queue(){

	int ch;
	start=NULL;
	printf("\n\nQueue Operations:\n1.Enqueue\n2.Dequeue\n3.Display\n4.Back To Main Menu\n\n");

	do{
		printf("Enter Ur Choice :");
                 scanf("%d",&ch);
		switch(ch)
		{ 
                  case 1:insertend();
                         break;
                  case 2:delend();
                         break;
                  case 3:display();
                         break;
                  case 4:break;
                }
          }
        while(ch!=4);
}
