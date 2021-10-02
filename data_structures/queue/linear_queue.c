#include <stdio.h>
#define MAX 5

struct Queue
{
    int info[MAX];
    int rear, front;
};

typedef struct Queue Q;

void insert(Q *, int);
void delete(Q *);
void display(Q *);

void main()
{
    Q s;
    int i, x, y;

    s.rear = s.front = -1;
    i = 1;

    while (i)
    {
        printf("\n***********Menu Bar**********\n");
        printf("\n 1: INSERT INTO QUEUE.\n");
        printf("\n 2: DELETE FROM QUEUE.\n");
        printf("\n 3: DISPLAY QUEUE.\n");
        printf("\n*********************\n");

        printf("\n Enter your choice :");
        scanf("%d", &x);

        switch (x)
        {
        case 1:
            printf("\n\n Enter Data:");
            scanf("%d", &y);
            insert(&s, y);
            break;

        case 2:
            delete (&s);
            break;

        case 3:
            display(&s);
            break;

        default:
            printf("\n Invalid Choice ....");
        }
        printf("\n Press 1 to continue. otherwise press 0 : ");
        scanf("%d", &i);
    }
}

void insert(Q *p, int item)
{
    if (p->rear == MAX - 1)
    {
        printf("\n Queue is Overflowed !!!!");
        return;
    }

    p->info[++p->rear] = item;
}

void delete(Q *p)
{
    if (p->rear == p->front)
    {
        printf("\n Queue is Undefined !!!!");
        return;
    }

    printf("\n\n Deleted Elemen is :%d", p->info[++p->front]);
}

void display(Q *p)
{
    int i;
    if (p->rear == p->front)
    {
        printf("\n Queue is Underflowed !!!!");
        return;
    }

    printf("\n\nDisplay all the elementsin the Queue ....\n ");
    for (i = (p->front + 1); i <= p->rear; i++)
    {
        printf("%d \t", p->info[i]);
    }
}