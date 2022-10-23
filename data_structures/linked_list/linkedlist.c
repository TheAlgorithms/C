#include<stdio.h>
#include<stdlib.h>

struct list
{
    int data;
    struct list *next;
};
struct list *top=NULL,*rear=NULL;

void insert_begin()
{
    struct list *p=(struct list*)malloc(sizeof(struct list));
    int val;
    printf("Enter the data:\n");
    scanf("%d",&val);
    p->data=val;
    if(top==NULL)
    {
        p->next=top;
        top=p;
        rear=p;
        rear->next=NULL;
    }
    else{
        p->next=top;
        top=p;
    }

}
void insert_end()
{   struct list *p=(struct list*)malloc(sizeof(struct list));
    int val;
    printf("Enter the data:\n");
    scanf("%d",&val);
    p->data=val;
    if(top==NULL)
    {
        rear=p;
        top=p;
        p->next=NULL;
    }
    else
    {
        rear->next=p;
        rear=p;
        rear->next=NULL;
    }

}

void display()
{
    struct list *d=top;
    while(d!=NULL)
    {
        printf("%d-->",d->data);
        d=d->next;
    }
    printf("\n");
}

void delete_begin()
{
if(top==NULL)
{
    printf("Linked list empty\n");
}
else
{
    struct list *delete_begin=top;
    printf("Deleted element is %d\n",delete_begin->data);
    top=top->next;
    free(delete_begin);
}
}

void delete_end()
{   if(top==NULL)
    {
    printf("List is empty\n");
    }
    else{
    struct list *delete_end=top;
    printf("Deleted element is:%d\n",rear->data);
    while(delete_end->next!=rear)
    {
        delete_end=delete_end->next;
    }
    rear=delete_end;
    delete_end=delete_end->next;
    free(delete_end);
    rear->next=NULL;
    }
}
void insert_middle()
{
    int n;
    printf("Enter the position value :\n");
    scanf("%d",&n);
    struct list *middle=top;
    while(middle->data!=n)
    {
        middle=middle->next;
    }
    struct list *p=(struct list*)malloc(sizeof(struct list));
    int val;
    printf("Enter the data:\n");
    scanf("%d",&val);
    p->data=val;
    p->next=middle->next;
    middle->next=p;
}

void main(){

int o;
    while (1)
    {
      printf("Enter\n1.insert_begin\n2.insert_middle\n3.insert_end\n4.delete_begin\n5.delete_end\n6.display\n");
      scanf("%d",&o);
      switch(o)
      {
        case 1:insert_begin(); break;

        case 2:insert_middle(); break;

        case 3: insert_end(); break;

        case 4:delete_begin(); break;

        case 5:delete_end(); break;

        case 6:display(); break;

        default : printf("Invalid\n");
        break;
      }  /* code */
    }

}