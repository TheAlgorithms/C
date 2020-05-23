/* Ascending priority queue using Linked List - Program to implement Ascending priority queue using Linked List */

#include  <stdio.h>
#include  <stdlib.h>  
#define  NULL  0

struct  node
{
  int  data ;
  struct  node  *next ;
} ;

struct  node  *front , *rear ;

/* This function initializes the queue to empty by making both front and rear as NULL */
void createqueue()
{
  front=rear=NULL ;
}

int  empty()
{
  if(front==NULL)
    return  1 ;
  else
    return  0 ;
}

void  insert(int  x)
{
  struct  node  *pnode ;

  pnode=(struct node*)malloc(sizeof(struct node)) ;
  if(pnode==NULL)
  {
    printf("Memory overflow. Unable to insert.\n") ;
    getch();
    exit(1) ;
  }

  pnode->data=x ;  
  pnode->next=NULL;   /* New node is always last node */

  if(empty())
      front=rear=pnode ;
  else
  {
      rear->next=pnode ;
      rear=pnode ;
  }
}

int  removes()
{
  int  min ;
  struct  node  *follow , *follow1 , *p , *p1 ;

  if(empty())
  {
    printf("\nQueue Underflow. Unable to remove.") ;
    getch() ;
    exit(1) ;
  }

  /* finding the node with minimum value in the APQ.*/
  p=p1=front ;
  follow=follow1=NULL ;
  min=front->data ;
  while(p!=NULL)
  {
    if(p->data<min)
    {
   min=p->data ;
   follow1=follow ;
   p1=p ;
    }
    follow=p ;
    p=p->next ;
  }

  /* Deleting the node with min value */

  if(p1==front)  /* deleting first node.*/
  {
    front=front->next ;
    if(front==NULL)  /* Deleting the only one node */
      rear=NULL ;
  }
  else if(p1==rear)  /* Deleting last node */
  {
      rear=follow1 ;
      rear->next=NULL ;
  }
  else      /* deleting any other node.*/
      follow1->next=p1->next ;


  free(p1) ;
  return  min ;  /* DONT FORGET LAST 2 STATEMENTS.*/
}

void  show()
{
  struct  node  *p ;

  if(empty())
    printf("Queue empty. No data to display \n") ;
  else
  {
    printf("Queue from front to rear is as shown: \n") ;

    p=front ;
    while(p!=NULL)
    {
      printf("%d ",p->data) ;
      p=p->next ;
    }

    printf("\n") ;
  }
}

void  destroyqueue()
{
  front=rear=NULL ;
}

int  main()
{
  int  x , ch ;

  createqueue() ;


  do
  {
    printf("\n\n  Menu: \n") ;
    printf("1:Insert \n") ;
    printf("2:Remove \n") ;
    printf("3:exit \n") ;
    printf("Enter your choice: ") ;
    scanf("%d",&ch) ;

    switch(ch)
    {
      case 1:
      printf("Enter element to be inserted: ") ;
      scanf("%d",&x) ;
      insert(x) ;
      show() ;
      break ;

      case 2:
      x=removes() ;
      printf("Element removed is: %d\n",x) ;
      show() ;
      break ;

      case 3:
      break ;
    }
  }
  while(ch!=3) ;

  destroyqueue() ;

  return 0;
}

