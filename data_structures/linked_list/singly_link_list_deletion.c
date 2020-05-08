/*Includes structure for a node which can be use to make new nodes of the Linked List.
  It is assumed that the data in nodes will be an integer, though
  function can be modified according to the data type, easily.
  deleteNode deletes a node when passed with a key of the node.
  The linked list can be used as a stack by implementing the functions insertLeft and deleteLeft
  The linked list can be used as a queue by implementing the functions insertRight and deleteLeft
  The linked list can be used as a double ended queue(dequeue) by implementing the functions insertRight and insertLeft to insert nodes on both sides and deleteLeft and deleteRight to delete nodes on both sides
*/
///////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
 int info;
 struct node *link;
}*NODE;
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
NODE insertLeft(NODE start) //function to insert the new node towards the right and function to create node as well
{
  NODE p;
  p=(NODE)malloc(sizeof(struct node));
  printf("enter the number to insert\n");
  scanf("%d",&(p->info));
  p->link=NULL;
  if(start==NULL)
  {
      start=p;
      return start;
  }
  p->link=start;
  start=p;
  return start;

}
///////////////////////////////////////////////////////////
NODE insertRight(NODE start)
{
  NODE p;
  p=(NODE)malloc(sizeof(struct node));
  printf("enter the number to be inserted\n");
  scanf("%d",&(p->info));
  p->link=NULL;
  if(start==NULL)
  {
    start=p;
    return start;
  }
  NODE temp=start;
  while(temp->link!=NULL)
  {
    temp=temp->link;
  }
  temp->link=p;
  return start;

}
///////////////////////////////////////////////////////////
NODE deleteLeft(NODE start)//function to delete from the left
{
    NODE t=NULL;
    if(start==NULL)
    {
        printf("list is empty\n");
        return start;
    }
    t=start;
    start=start->link;
    printf("number deleted is: %d",t->info);
    free(t);
    return start;
}
///////////////////////////////////////////////////////
NODE deleteRight(NODE start)
{
  NODE t=start,prev=NULL;
  while(t->link!=NULL)
  {
    prev=t;
    t=t->link;
  }
  printf("number deleted is: %d",t->info);
  free(t);
  prev->link=NULL;
  return start;

}
///////////////////////////////////////////////////////
void viewlist(NODE start)//function to display values
{
    NODE p=start;
    if(start==NULL)
    {
        printf("list is empty\n");
        return;
    }
    while(p->link!=NULL)
    {
      printf("%d\t",p->info);
      p=p->link;
    }
    printf("%d",p->info);
}
//////////////////////////////////////////////////////////////////////

int main()
{
    int ch;
    NODE start=NULL;
    do
    {
      printf("\nenter choice:\n1:insert left\n2:insert right\n3:delete left\n4:delete right\n5:display\n6:exit\n");
      scanf("%d",&ch);
      switch(ch)
      {
        case 1:
        start=insertLeft(start);
        break;
        case 2:
        start=insertRight(start);
        break;
        case 3:
        start=deleteLeft(start);
        break;
        case 4:
        start=deleteRight(start);
        break;
        case 5:
        viewlist(start);
        break;
        case 6:
        printf("exiting...");
        break;
      }
    }while(ch!=6);
}

