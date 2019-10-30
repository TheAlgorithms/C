//program for stack using array

#include <stdio.h>

void push();
void pop();
void peek();
void update();

int a[100], top = -1;

int main()
{

    int x;
    while (1)
    {
        printf("\n0.exit");
        printf("\n1.push");
        printf("\n2.pop");
        printf("\n3.peek");
        printf("\n4.update");
        printf("\nenter your choice? ");
        scanf("%d", &x);
        switch (x)
        {
        case 0:
            return 0;
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
        default:
            printf("\ninvalid choice");
        }
    }
    return (0);
}

//function for pushing the element
void push()
{
    int n = 0;
    printf("\nenter the value to insert? ");
    scanf("%d", &n);
    top += 1;
    a[top] = n;
}

//function for poping the element out
void pop()
{
    if (top == -1)
    {
        printf("\nstack is empty");
    }
    else
    {
        int item;
        item = a[top];
        top -= 1;
        printf("\npoped item is %d ", item);
    }
}

//function for peeping the element from top of the stack
void peek()
{
    if (top >= 0)
        printf("\n the top element is %d", a[top]);
    else
        printf("\nstack is empty");
}

//function to update the element of stack
void update()
{
    int i, n;
    printf("\nenter the position to update? ");
    scanf("%d", &i);
    printf("\nenter the item to insert? ");
    scanf("%d", &n);
    if (top - i + 1 < 0)
    {
        printf("\nunderflow condition");
    }
    else
    {
        a[top - i + 1] = n;
    }
}