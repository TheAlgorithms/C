#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* head=NULL;
void create(int x)
{
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    struct node* t = head;
    temp->data = x;
    temp->next = NULL;
    if (head== NULL)
        head = temp;
    else
    {
        while (t->next!= NULL)
            t = t->next;
        t->next = temp;
    }
}
void display()
{
    struct node* t= head;
    int p=1;
    if(head==NULL)
        printf("Empty list");
    else
    {
        while(t!=NULL)
        {
            printf("%d.->%d\n",p,t->data);
            p++;
            t=t->next;
        }
    }
}
void reverse()
{
    struct node *t = head;
    struct node* p=NULL;
    struct node* q=NULL;
    while(t!=NULL)
    {
        p=q;
        q=t;
        t=t->next;
        q->next=p;
    }
    head=q;
}
void main(){
    int a,n1,w;
    printf("Enter no. of nodes");
    scanf("%d",&n1);
    for(int i=0;i<n1;i++)
    {
        scanf("%d",&a);
        create(a);
    }
    printf("Before\n");
    display();
    printf("After\n");
    reverse();
    display();
}


