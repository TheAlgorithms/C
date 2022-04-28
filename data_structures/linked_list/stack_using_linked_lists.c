#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *top = NULL, *temp;
void push(struct node *);
void pop(struct node *);
void display(struct node *);

int main()
{
    int x = 0, item;
    printf("\t****stack using linked list****\n");
    while (x != 4)
    {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            push(top);
            break;
        case 2:
            pop(top);
            break;
        case 3:
            display(top);
            break;
        case 4:
            return 0;
        }
    }
}

void push(struct node *p)
{
    int item;
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter element to be inserted: ");
    scanf("%d", &item);
    temp->info = item;

    temp->link = top;
    top = temp;

    printf("Inserted successfully.\n");
}
void pop(struct node *p)
{
    int item;
    struct node *temp;

    if (top == NULL)
        printf("\nStack is empty.\n");
    else
    {
        item = top->info;
        temp = top;
        top = top->link;
        free(temp);
        printf("\nElement popped is %d.\n", item);
    }
}

void display(struct node *p)
{
    if (top == NULL)
        printf("\nStack is empty.\n");
    else
    {
        printf("\nElements in the stack are:\n");
        while (p != NULL)
        {
            printf("\t%d\n", p->info);
            p = p->link;
        }
        // printf("%d\n",p->info);
    }
}
