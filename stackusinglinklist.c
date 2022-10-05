#include<stdio.h>
#include<stdlib.h>
struct student *head;
struct student *top=NULL;
struct student
{
    int data;
    struct student *next;
};


void push(int n)
{
    struct student *p;
    p=(struct student*)malloc(sizeof(struct student));
    p->data=n;
    p->next=top;
    top=p;

    
}

int pop()
{
    int x=top->data;
    top=top->next;
    return x;

}
void display()
{
    struct student *p=top;
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;
       // top=p;
    }

    
}

int main()
{
    int ch,n;
    while(1)
    {
        printf("enter 1 for push,2 for pop,3 for display,4 to exit:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("\nenter the data to be inserted");
            scanf("%d",&n);
            push(n);
            break;
        
        case 2:
            if(top==NULL)
            {
                printf("underflow\n");
            }
            else
            printf("%d",pop());
            break;
        case 3:
            display();
            break;
        case 4:
             exit(0);
             break;
        }
        

    }
}