#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
 int expo;
 float coeff;
 struct node *next;
};


struct node *insert(struct node *head,int e,int c)
{
struct node *p,*q;
p=(node *)malloc(sizeof(node));

p->expo=e;
p->coeff=c;
p->next=NULL;

if(head=NULL)
{
 head=p;
 head->next=head;
 return head;
}

if(e>head->expo)
{
p->next=head;
head->next=p;
head=p;
return head;
}

if(e==head->expo)
{
head->coeff=head->coeff+c;
return head;
}

q=head;
 while((q->next!=head)&&(e>=q->next->expo))
 {
 q=q->next;
 }

 if(p->expo==q->expo)
   q->coeff=q->coeff+c; 
 else 
   {
     p->next=q->next;
     q->next=p;
   }
 return head;
}

struct node *create()
{

int n,i,e,c;
struct node *head=NULL;

printf("Term's:");
 scanf("%d",&n);

 for(i=0;i<n;i++)
{ 
 printf("Co-eff & Expo:");
  scanf("%d%d",&c,&e);

 head=insert(head,e,c);

}

return head;

}

struct node *add(struct node *p1,struct node *p2)
{
struct node *p;
struct node *head=NULL;

 p=p1->next;

 do{
  head=insert(head,p->expo,p->coeff);
  p=p->next;
   }while(p!=p1->next);

p=p2->next;

 do
{
head=insert(head,p->expo,p->coeff);
p=p->next;
}while(p!=p2->next);

return head;

}

int eval(struct node *head)
{
 struct node *p;
 int x,ans=0;

printf("Enter The Value Of X:\n");
 scanf("%d",&x);

p=head->next;

do
{
 ans=ans+(p->coeff*pow(x,p->expo));
 p=p->next;
}while(p!=head->next);

return head;

}

void display(struct node *head)
{
 struct node *p,*q;
 int n=0;

 q=head->next;
 p=head->next;

 do
 {
 n++;
 q=q->next;
 }while(q!=head->next);

 printf("Polynoial : ");
do
{ 
if(n-1)
 { 
  printf("%dx^(%d)+",p->coeff,p->expo);
  p=p->next;
 }
 else
 { printf("%dx^(%d)",p->coeff,p->expo);
   p=p->next;
}
n--;
}while(p!=head->next);
}


void main()
{
 int a,x,ch;
 char *p1,*p2,*p3;

 p1=p2=p3=NULL;

while(1){ 
 printf("Select Option: 1.Add Two Polynomials\n2.Evaluate A Polynomial");
  scanf("%d",&ch);

 switch(ch)
 {case 1:p1=create();
         p2=create();
         display(p1);
         display(p2);
         p3=add(p1,p2);
         display(p3);
         break;

 case 2:p1=create();
        display(p1);
        a=eval(p1);
        printf("Result Of Evaluation :%d",a);
        break;
 case 3:exit(0);
}}}
