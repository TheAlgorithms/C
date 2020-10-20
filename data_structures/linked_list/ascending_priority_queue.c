/* Ascending priority queue using Linked List - Program to implement Ascending
 * priority queue using Linked List */

/*A priority queue is a special type of queue in which each element is
associated with a priority and is served according to its priority. If elements
with the same priority occur, they are served according to their order in the
queue.

Generally, the value of the element itself is considered for assigning the
priority.

For example: The element with the highest value is considered as the highest
priority element. However, in other cases, we can assume the element with the
lowest value as the highest priority element. In other cases, we can set
priorities according to our needs.

In a queue, the first-in-first-out rule is implemented whereas, in a priority
queue, the values are removed on the basis of priority. The element with the
highest priority is removed first.

insert() - Would insert an element in a queue
delete() -  Would delete the smallest element in the queue
*/

#include <stdio.h>
#include <stdlib.h>
#define NULL ((void *)0)

struct node
{
    int data;
    struct node *next;
};

struct node *front, *rear;

/* This function initializes the queue to empty by making both front and rear as
 * NULL */
void createqueue() { front = rear = NULL; }

int empty()
{
    if (front == NULL)
        return 1;
    else
        return 0;
}

void insert(int x)
{
    struct node *pnode;

    pnode = (struct node *)malloc(sizeof(struct node));
    if (pnode == NULL)
    {
        printf("Memory overflow. Unable to insert.\n");
        exit(1);
    }

    pnode->data = x;
    pnode->next = NULL; /* New node is always last node */

    if (empty())
        front = rear = pnode;
    else
    {
        rear->next = pnode;
        rear = pnode;
    }
}

int removes()
{
    int min;
    struct node *follow, *follow1, *p, *p1;

    if (empty())
    {
        printf("\nQueue Underflow. Unable to remove.");
        exit(1);
    }

    /* finding the node with minimum value in the APQ.*/
    p = p1 = front;
    follow = follow1 = NULL;
    min = front->data;
    while (p != NULL)
    {
        if (p->data < min)
        {
            min = p->data;
            follow1 = follow;
            p1 = p;
        }
        follow = p;
        p = p->next;
    }

    /* Deleting the node with min value */

    if (p1 == front) /* deleting first node.*/
    {
        front = front->next;
        if (front == NULL) /* Deleting the only one node */
            rear = NULL;
    }
    else if (p1 == rear) /* Deleting last node */
    {
        rear = follow1;
        rear->next = NULL;
    }
    else /* deleting any other node.*/
        follow1->next = p1->next;

    free(p1);
    return min; /* DONT FORGET LAST 2 STATEMENTS.*/
}

void show()
{
    struct node *p;

    if (empty())
        printf("Queue empty. No data to display \n");
    else
    {
        printf("Queue from front to rear is as shown: \n");

        p = front;
        while (p != NULL)
        {
            printf("%d ", p->data);
            p = p->next;
        }

        printf("\n");
    }
}

void destroyqueue() { front = rear = NULL; }

int main()
{
    int x, ch;

    createqueue();

    do
    {
        printf("\n\n  Menu: \n");
        printf("1:Insert \n");
        printf("2:Remove \n");
        printf("3:exit \n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter element to be inserted: ");
            scanf("%d", &x);
            insert(x);
            show();
            break;

        case 2:
            x = removes();
            printf("Element removed is: %d\n", x);
            show();
            break;

        case 3:
            break;
        }
    } while (ch != 3);

    destroyqueue();

    return 0;
}

/* Output of the Program*/

/*
  Menu:
1:Insert
2:Remove
3:exit
Enter your choice: 1
Enter element to be inserted: 12
Queue from front to rear is as shown:
12


  Menu:
1:Insert
2:Remove
3:exit
Enter your choice: 1
Enter element to be inserted: 1
Queue from front to rear is as shown:
12 1


  Menu:
1:Insert
2:Remove
3:exit
Enter your choice: 1
Enter element to be inserted: 14
Queue from front to rear is as shown:
12 1 14


  Menu:
1:Insert
2:Remove
3:exit
Enter your choice: 1
Enter element to be inserted: 3
Queue from front to rear is as shown:
12 1 14 3


  Menu:
1:Insert
2:Remove
3:exit
Enter your choice: 1
Enter element to be inserted: 5
Queue from front to rear is as shown:
12 1 14 3 5


  Menu:
1:Insert
2:Remove
3:exit
Enter your choice: 2
Element removed is: 1
Queue from front to rear is as shown:
12 14 3 5


  Menu:
1:Insert
2:Remove
3:exit
Enter your choice: 2
Element removed is: 3
Queue from front to rear is as shown:
12 14 5


  Menu:
1:Insert
2:Remove
3:exit
Enter your choice: 2
Element removed is: 5
Queue from front to rear is as shown:
12 14


  Menu:
1:Insert
2:Remove
3:exit
Enter your choice: 2
Element removed is: 12
Queue from front to rear is as shown:
14


  Menu:
1:Insert
2:Remove
3:exit
Enter your choice: 2
Element removed is: 14
Queue empty. No data to display

*/
