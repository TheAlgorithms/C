#include <stdio.h>
#include <stdlib.h> 
#define MAX 5
int stack[MAX],top=-1,i,ch,elem,flag;
void push()
{
    if(top==MAX-1)//To check if stack is full
    {
        printf("\nstack overflow\n");
        return;
    }
    printf("\nenter the element to be inserted\n");
    scanf("%d",&elem);
    top=top+1; //Incrementing top
    stack[top]=elem;//Inserting element
}
void pop()
{
    if(top==-1)//To check if stack is empty
    {
        printf("\nstack underflow\n");
        return;
    }
    elem=stack[top];//deleting element
    top=top-1;//decrementing top
    printf("\npoped element is %d\n",elem);
}
void peek()
{
    if(top==-1)
    {
        printf("\nstack is empty\n");
        return;
    }
    printf("\ntop element is %d\n",stack[top]);
}
void update()
{
    printf("\nenter the element to be updated\n");
    scanf("%d",&elem);
    printf("\nenter the position\n");
    scanf("%d",&i);
    if(i>top)//To check if position is valid
    {
        printf("\ninvalid position\n");
        return;
    }
    stack[i]=elem;//Updating element
    printf("\nupdated element is %d\n",stack[i]);
}
void display()
{
    int i;
    if(top==-1)
    {
        printf("\nstack is empty\n");
        return;
    }
    printf("\nstack elements are\n");
    for(i=top;i>=0;i--)
    {
        printf("\n%d\n",stack[i]);//Displaying elements
    }
}
void pallindrome()
{
    flag = 1;
    for(i=0;i<=top/2;i++)
    {
        if(stack[i]!=stack[top-i])
        {
            flag = 0;
            break;
        }
    }
    if(flag==1)
    {
        printf("\nstack is pallindrome\n");
    }
    else
    {
        printf("\nstack is not pallindrome\n");
    }
}
int main()
{
    int ch;
    while(1)
    {
        printf("\n1.push\n2.pop\n3.peek\n4.update\n5.display\n6.exit\nenter your choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                update();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("\ninvalid choice");
        }
    }
    return 0;
}
