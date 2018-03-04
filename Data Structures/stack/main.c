//program for stack using array 

#include<stdio.h>
void push();
void pop();
void peep();
void update();
int main()
{
    int n,a[100],top=0;
    //function for pushing the element 
    void push()
    {
        printf("\nenter the value to insert");
        scanf("%d",&n);
        top=top+1;
        a[top]=n;
    }
    //function for poping the element out
    void pop()
    {
        if(top==0)
        {
            printf("\nstack is empty");
        }
        else
        {
            int item;
            item=a[top];
            top=top-1;
            printf("\npoped item is %d ",item);
        }
    }
    //function for peeping the element from top of the stack
    void peep()
    {
        int i;
        printf("\nenter the element position to view from top");
        scanf("%d",&i);
        if(top-i+1<0)
        {
            printf("\nunderflow condition");
        }
        else
        {
            int x;
            x=a[top-i+1];
            printf("\nthe %dth element from top is %d",i,x);
        }
    }
    //function to update the element of stack
    
    void update()
    {
        int i,n;
        printf("\nenter the position to update");
        scanf("%d",&i);
        printf("\nenter the item to insert");
        scanf("%d",&n);
        if(top-i+1<0)
        {
            printf("\nunderflow condition");
        }
        else
        {
            a[top-i+1]=n;
        }
    }
    int x;
    while(1)
    {
        printf("\n1.push");
        printf("\n2.pop");
        printf("\n3.peep");
        printf("\n4.update");
        printf("\nenter your choice");
        scanf("%d",&x);
        switch(x)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peep();
            break;
        case 4:
            update();
            break;
        default:
            printf("\ninvalid choice");
        }
    }
    return(0);
}

