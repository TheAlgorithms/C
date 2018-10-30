#define MAX 3

#include<stdio.h>
#include<stdlib.h>

void insert();
void delete();
void display();
void check();


char Q[MAX];
int front=-1;
int rear=-1;
void main()
{int x;
while(1){
printf("Enter Ur Choice :\n");
 printf("1.Enqueue\n2.Dequeue\n3.Check For Underflow or Overflow\n4.Display\n5.Exit\n\n");
scanf("%d",&x);


switch(x){
case 1:insert();break;
case 2:delete();break;
case 3:check();break;
case 4:display();break;
case 5:exit(0);

default: printf("Wrong Choice!!!!!\n\n");
}
printf("\n\n");
}
}


void insert()
{
char x;

if(((front==0)&&(rear==(MAX-1)))||(front==(rear+1)))
 { printf("Queue is Overflow!!\n");
 return;
 }
if(front==-1)
  front=rear=0;
else{
if(rear==MAX-1)
 rear=0;
else
rear++;
}

printf("ENTER THE CHARACTER:\n");
 scanf(" %c",&x);

Q[rear]=x;
return;
}

void delete(){
char y;
if(front==-1)
{
printf("Queue is UnderFlow!!\n");
return;
}
y=Q[front];
printf("Element deleted is : %c",y);

if(front==rear)
front=rear=-1;
else 
{if(front==MAX-1)
 front=0;
else
front++;
}
return;
}

void display(){
int i;

if((front==-1)&&(rear==-1))
{
printf("Queue Is Empty!!\n");
return;
}
printf("Elements Of Circular Queue are: \n");
 for(i=front;i!=rear;i=(i+1)%MAX)
  printf("%c\t",Q[i]);
printf("%c\t",Q[rear]);
return;
}

void check()
{
if((front==-1)&&(rear==-1))
 printf("Queue Is Underflow!!\n");

if(((front==0)&&(rear==MAX-1))||(front==(rear+1)))
 printf("Queue Is Overflow!!!\n");
return;
}
