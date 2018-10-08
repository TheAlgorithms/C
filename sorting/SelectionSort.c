//sorting of linked list using selection sort
#include<stdio.h>
struct node 
{
 int info;
 struct node *link;
};
struct node *start=NULL;
//func to create node
struct node *createnode()
{
 struct node *p;
 p=(struct node*)malloc(sizeof(struct node));
 return(p);
}
//program to insert at begining
void insert()
{struct node *t;
 t=createnode();
 printf("\nenter the value to insert");
 scanf("%d",&t->info);
 if(start==NULL)
 {start=t;
 }
 else
 {strutc node *p;
  p=start;
  t->link=p;
  start=t;
 }
 //program to sort the linked list using selection sort
 void sort()
 {
  struct node *p,*t;
  t=start;
  int tmp;
  for(t=start;t->link!=NULL;t=t->link)
  {
   for(p=t->link;p!=NULL;p=p->link)
   {
    if(t->info>p->info)
     tmp=t->info;
    t->info=p->info;
    p->info=tmp;
   }
  }
  //program to view sorted list
  void viewlist()
  {
   struct node *p;
   if(start==NULL)
   {
    printf("\nlist is empty");
   }
   else
   {
    p=start;
   while(p!=NULL)
   {
    printf("%d",p->info);
    p=p->link;
   }
  }
 int main()
 {
  int n;
  whhile(1)
  {
   printf("\n1.insert value at beg");
   printf("\n2.sort the list");
   printf("\n3.view value");
   printf("\nenter your choice");
   scanf("%d",&n);
   switch(n)
   {case 1:
    insert();
    break;
    case 2:
    sort();
    break;
    case 3:
    viewlist();
    break;
    default:
    printf("\ninvalid choice");
   }
  }
  return(0);
 }
