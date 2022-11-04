/*Includes structure for a node which can be use to make new nodes of the Linked
  List. It is assumed that the data in nodes will be an integer, though function
  can be modified according to the data type, easily. deleteNode deletes a node
  when passed with a key of the node.
*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *start = NULL;
///////////////////////////////////////////////////////////
struct node *createnode()  // function to create node
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    return (t);
}
////////////////////////////////////////////////////////
int insert(int pos)  // function to insert at first location
{
    struct node *new;
    new = createnode();
    printf("\nenter the number to be inserted :");
    scanf("%d", &new->info);
    if(pos==1)
    {
    new->link = NULL;
       if (start == NULL)
      {
        start = new;
      }
      else
      {
        new->link = start;
        start = new;
       }
    }
    else{
       struct node *pre=start;
       for(int i=1;i<pos-1;i++)
       {
           if (pre==NULL){
             printf("Position not found!");
             return;
            }
           pre=pre->link;
       }
          new->link=pre->link;
          pre->link=new;
          
       }
    return 0;
}
///////////////////////////////////////////////////////////
int deletion(int pos)  // function to delete from any position
{
    struct node *t;
    if (start == NULL)
        {
           printf("\nlist is empty");
        }
    else
    {
        if(pos==1)
        {
            struct node *p;
            p = start;
            start = start->link;
            free(p);
         }
         else
         {
            struct node *prev=start;
            for(int i=2;i<pos;i++)
            {
              if (prev==NULL){
             printf("Position not found!");
             return;
            }
              prev=prev->link;
            }
           struct node *n=prev->link;   //n points to required node to be deleted
           prev->link=n->link;
           free(n);
        }
    }
  return 0;
}
///////////////////////////////////////////////////////
void viewlist()  // function to display values
{
    struct node *p;
    if (start == NULL)
    {
        printf("\nlist is empty");
    }
    else
    {
        p = start;
        while (p != NULL)
        {
            printf("%d ", p->info);
            p = p->link;
        }
    }
}
//////////////////////////////////////////////////////////////////////

int main()
{
    int n=0,pos=0,p=0;
    while (1)
    {
        printf("\n1.add value at the given location");
        printf("\n2.delete value at the given location");
        printf("\n3.view value");
        printf("\nenter your choice :");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
        printf("enter the position where the element is to be added :");
            scanf("%d",&p);
            insert(p);
            break;
        case 2:
           
            printf("enter the position where the element is to be deleted :");
            scanf("%d",&pos);
            deletion(pos);
            break;
        case 3:
            viewlist();
            break;
        default:
            printf("\ninvalid choice");
        }
    }
    return (0);
}
