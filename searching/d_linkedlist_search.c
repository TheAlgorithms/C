#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
}*start=NULL;
void add_begin();
void display();
void insert_end();
void insert_pos();
void count_node();
void del_first();
void del_last();
void del_pos();
int main()
{
    int ch;
    printf("Enter 1 to insert at the beginning.\n");
    printf("Enter 2 to insert at the end.\n");
    printf("Enter 3 to insert position wise.\n");
    printf("Enter 4 to count number of node& display the data.\n");
    printf("Enter 5 to Delete at the beginning.\n");
    printf("Enter 6 to delete at the end.\n");
    printf("Enter 7 to delete position wise.\n");
    printf("Enter 8 to display the linked list.\n");
    printf("Enter any other number to exit.\n");
    while(1)
    {
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            add_begin();
            break;
            case 2:
            insert_end();
            break;
            case 3:
            insert_pos();
            break;
            case 4:
            count_node();
            break;
            case 5:
            del_first();
            break;
            case 6:
            del_last();
            break;
            case 7:
            del_pos();
            break;
            case 8:
            display();
            break;
            default:
            exit(0);
        }
    }
    return 0;
}
void add_begin()
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&temp->data);
    temp->prev=NULL;
    if(start==NULL)
    {
        temp->next=NULL;
    }
    else
    {
        temp->next=start;
        start->prev=temp;
    }
    start=temp;
}
void insert_end()
{
    struct node *tmp,*q;
    if(start==NULL)
    {
        printf("No node present.\n");
        return;
    }
    q=start;
    while(q->next!=NULL)
    q=q->next;
    tmp=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&tmp->data);
    tmp->next=q->next;
    tmp->prev=q;
    q->next=tmp;
}
void insert_pos()
{
    struct node *tmp,*q;
    if(start==NULL)
    {
        printf("No node present.\n");
        return;
    }
    q=start;
    int pos;
    printf("Enter the position: \n");
    scanf("%d",&pos);
    for(int i=1;i<pos;i++)
    q=q->next;
    tmp=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&tmp->data);
    tmp->next=q->next;
    tmp->prev=q;
    q->next->prev=tmp;
    q->next=tmp;
}
void count_node()
{
    int a=0;
    struct node *f;
    f=start;
    while(f->next!=NULL)
    {
        f=f->next;
        a++;
    }
    printf("No. of nodes present is: %d\n",a+1);
}
void del_first()
{
    struct node *temp;
    temp=start;
    start=start->next;
    start->prev=NULL;
    free(temp);
    printf("Node deleted sucessfully...\n");
}
void del_last()
{
    struct node *temp,*p;
    temp=start;
    p=start;
    while(p->next!=NULL)
    {
        temp=p;
        p=p->next;
    }
    temp->next=NULL;
    temp->prev=p;
    free(p);
    printf("Last node deleted successfully...\n");
}
void del_pos()
{
    struct node *temp,*p;
    int x;
    printf("Enter the position you want to delete: ");
    scanf("%d",&x);
    p=start;
    x=x-1;
    for(int i=1;i<x;i++)
    p=p->next;
    temp=p->next;
    p->next=temp->next;
    if(p->next!=NULL)
    p->next->prev=p;
    free(temp);
    printf("Node deleted successfully...\n");
}
void display()
{
    struct node *p;
    if(start==NULL)
    {
        printf("No node present.\n");
        return;
    }
    p=start;
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
}
