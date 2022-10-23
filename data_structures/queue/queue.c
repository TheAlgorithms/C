////////////////////////////////////////////////////////////////////////////////
// INCLUDES
#include "include.h";

////////////////////////////////////////////////////////////////////////////////
// GLOBAL VARIABLES
int count;

////////////////////////////////////////////////////////////////////////////////
// MAIN ENTRY POINT

int main(int argc, char const *argv[])
{
    create();
    enque(5);

    return 0;
}

void create()
{
    head = NULL;
    tail = NULL;
}

/**
 * Puts an item into the Queue.
 */
void enque(int x)
{
    if (head == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        head->data = x;
        head->pre = NULL;
        tail = head;
    }
    else
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->data = x;
        tmp->next = tail;
        tail = tmp;
    }
}

/**
 * Takes the next item from the Queue.
 */
int deque()
{
    int returnData = 0;
    if (head == NULL)
    {
        printf("ERROR: Deque from empty queue.\n");
        exit(1);
    }
    else
    {
        returnData = head->data;
        if (head->pre == NULL)
            head = NULL;
        else
            head = head->pre;
        head->next = NULL;
    }
    return returnData;
}

/**
 * Returns the size of the Queue.
 */
int size() { return count; }

//Queue using array
/*#include<stdio.h>
int data[10];
int f=0;
int r=-1;
void insert()
{
    if(r==9)
    {
        printf("Queue is full\n");
    }
        else
        {
            r++;
            printf("Enter the data:\n");
            scanf("%d",&data[r]);
        }
    
}
void delete()
{
    if(f==-1||f>r)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Deleted element is :%d\n",data[f]);
        f++;
    }
}
void display()
{
    for(int i=f;i<=r;i++)
    {
        printf("%d-->",data[i]);
    }
}
void main()
{  
    int o;
    while (1)
    {
      printf("Enter\n1.push\n2.pop\n3.display\n");
      scanf("%d",&o);
      switch(o)
      {
        case 1:insert(); break;

        case 2:display(); break;

        case 3: display(); break;

        default : printf("Invalid\n");
        break;
      }  /* code */
    }
    
}*/
