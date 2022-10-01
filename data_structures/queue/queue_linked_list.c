/*

Title: Queue using Linked List
Time Complexity: O(1)
Other Resources: https://www.geeksforgeeks.org/queue-linked-list-implementation/

*/

#include <stdio.h>
#include <stdlib.h>

//Global declaration of front and rare pointer
struct Queue *f = NULL;
struct Queue *r = NULL;
 
struct Queue
{
    int data;
    struct Queue *next;
};
 
void linkedListTraversal(struct Queue *ptr)
{
    printf("Printing the elements of this linked list\n");
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
 
void enqueue(int val)
{
    struct Queue *n = (struct Queue *) malloc(sizeof(struct Queue));
    if(n==NULL){
        printf("Queue is Full");
    }
    else{
        n->data = val;
        n->next = NULL;
        if(f==NULL){ 
            f=r=n;
        }
        else{
            r->next = n;
            r=n;
        }
    }
}
 
int dequeue()
{
    int val = -1;
    struct Queue *ptr = f;
    if(f==NULL){
        printf("Queue is Empty\n");
    }
    else{
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}
 
int main()
{
    linkedListTraversal(f);
    printf("Dequeuing element %d\n", dequeue());
    enqueue(34);
    enqueue(4);
    enqueue(7);
    enqueue(17);
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    linkedListTraversal(f);
    return 0;
}
