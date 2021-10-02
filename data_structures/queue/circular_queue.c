#include <stdio.h>
#define MAX 5
#define TRUE 1
#define FALSE 0

struct Circular_Queue
{
    int info[MAX];
    int rear, front;
    int flag;
};

typedef struct Circular_Queue CQ;

void insert(CQ *, int);
void _delete(CQ *);
void display(CQ );

void main()
{
    CQ s;
    int i, x, y;

    s.rear = s.front = 0;
    s.flag = FALSE;

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
            _delete (&s);
            break;

        case 3:
            display(s);
            break;

        default:
            printf("\n Invalid Choice ....");
        }
        printf("\n Press 1 to continue. otherwise press 0 : ");
        scanf("%d", &i);
    }
}

void insert(CQ *p, int item)
{
    if (p->rear == p->front && p->flag == TRUE)
    {
        printf("\n Queue is Overflowed !!!!");
        return;
    }

    p->info[p->rear] = item;
    p->rear = (p->rear + 1) % MAX;
    p->flag = TRUE;
}

void _delete(CQ *p)
{
    if (p->rear == p->front && p->flag == FALSE)
    {
        printf("\n Queue is Undefined !!!!");
        return;
    }

    printf("\n\n Deleted Elemen is :%d", p->info[++p->front]);
    p->front = (p->front + 1) % MAX;
    p->flag = FALSE;
}

void display(CQ p)
{
    printf("\n\nDisplay all the elementsin the Queue ....\n\n ");
    while (p.rear != p.front || p.flag == TRUE)
    {
        printf("%d\t", p.info[p.front]);
        p.front = (p.front + 1) % MAX;
        p.flag = FALSE;
    }
}