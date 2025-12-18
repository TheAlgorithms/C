/*
 * Stack using Linked List
 * -----------------------
 * This program implements a stack data structure using a singly linked list.
 *
 * Operations supported:
 * 1. Push  - Insert an element at the top of the stack
 * 2. Pop   - Remove the top element from the stack
 * 3. Peek  - View the top element without removing it
 * 4. Display - Print all elements of the stack
 *
 * Advantages of Linked List Stack:
 * - Dynamic size (no fixed capacity)
 * - Efficient push and pop operations (O(1))
 *
 * Time Complexity:
 * Push  : O(1)
 * Pop   : O(1)
 * Peek  : O(1)
 *
 * Space Complexity:
 * O(n), where n is the number of elements in the stack
 *
 * Author: Open Source Contributor
 */

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
//Pushes an element on the top of the Stack
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
//Pops the topmost Element
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
//Displays all the Elements of the stack
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
