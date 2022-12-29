// program for stack using array
#include <stdio.h>

void push();
void pop();
void peek();
void update();
void display();

int a[100], top = -1;

int main()
{
    int x;
    while (1)
    {
        printf("\n0 or CTRL-C to Exit ");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek");
        printf("\n4. Update");
        printf("\n5. Display");
        printf("\nEnter your choice? \n");
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
        case 5:
            display();
            break;
        default:
            printf("\nInvalid choice,\nPlease try again.\n");
        }
    }
    return (0);
}

// function for pushing the element
void push()
{
    int n = 0;
    printf("\nEnter the value to be inserted: ");
    scanf("%d", &n);
    top += 1;
    a[top] = n;
}

// function for poping the element out
void pop()
{
    if (top == -1)
    {
        printf("\nStack is empty");
    }
    else
    {
        int item;
        item = a[top];
        top -= 1;
        printf("\nPoped item is %d ", item);
    }
}

// function for peeping the element from top of the stack
void peek()
{
    if (top >= 0)
        printf("\nThe top element is %d", a[top]);
    else
        printf("\nStack is empty");
}

// function to update the element of stack
void update()
{
    int i, n;
    printf("\nEnter the position to update? ");
    scanf("%d", &i);
    printf("\nEnter the item to insert? ");
    scanf("%d", &n);
    if (top - i + 1 < 0)
    {
        printf("\nUnderflow condition ");
    }
    else
    {
        a[top - i + 1] = n;
    }
}
// function to view entire stack
void display()
{
    if (top == -1)
    {
        printf("\nStack is empty");
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", a[i]);
        }
    }
}
