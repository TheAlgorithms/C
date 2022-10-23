#include <stdio.h>
#include <stdlib.h>

// Data structure to represent a queue
struct queue
{
    int *items;   // array to store queue elements
    int maxsize;  // maximum capacity of the queue
    int front;    // front points to the front element in the queue (if any)
    int rear;     // rear points to the last element in the queue
    int size;     // current capacity of the queue
};

// Utility function to initialize a queue
struct queue *newQueue(int size)
{
    struct queue *pt = NULL;
    pt = (struct queue *)malloc(sizeof(struct queue));

    pt->items = (int *)malloc(size * sizeof(int));
    pt->maxsize = size;
    pt->front = 0;
    pt->rear = -1;
    pt->size = 0;

    return pt;
}

// Utility function to return the size of the queue
int size(struct queue *pt) { return pt->size; }

// Utility function to check if the queue is empty or not
int isEmpty(struct queue *pt) { return !size(pt); }

// Utility function to return the front element of the queue
int front(struct queue *pt)
{
    if (isEmpty(pt))
    {
        printf("Underflow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }

    return pt->items[pt->front];
}

// Utility function to add an element `x` to the queue
void enqueue(struct queue *pt, int x)
{
    if (size(pt) == pt->maxsize)
    {
        printf("Overflow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }

    printf("Inserting %d\t", x);

    pt->rear = (pt->rear + 1) % pt->maxsize;  // circular queue
    pt->items[pt->rear] = x;
    pt->size++;

    printf("front = %d, rear = %d\n", pt->front, pt->rear);
}

// Utility function to dequeue the front element
void dequeue(struct queue *pt)
{
    if (isEmpty(pt))  // front == rear
    {
        printf("Underflow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }

    printf("Removing %d\t", front(pt));

    pt->front = (pt->front + 1) % pt->maxsize;  // circular queue
    pt->size--;

    printf("front = %d, rear = %d\n", pt->front, pt->rear);
}

int main()
{
    struct queue *pt = newQueue(5);

    enqueue(pt, 1);
    enqueue(pt, 2);
    enqueue(pt, 3);
    enqueue(pt, 4);

    dequeue(pt);
    dequeue(pt);
    dequeue(pt);
    dequeue(pt);

    enqueue(pt, 5);
    enqueue(pt, 6);

    printf("size = %d\n", size(pt));

    if (isEmpty(pt))
    {
        printf("The queue is empty");
    }
    else
    {
        printf("The queue is not empty");
    }

    return 0;
}
