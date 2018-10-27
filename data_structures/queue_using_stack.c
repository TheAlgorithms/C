/* C Program to implement a queue using two stacks */
#include <stdio.h> 
#include <stdlib.h> 
/* structure of a stack node */
struct sNode 
{ 
    int data; 
    struct sNode* next; 
}; 
void push(struct sNode** top_ref, int new_data); 
int pop(struct sNode** top_ref);   
/* structure of queue having two stacks */
struct queue 
{ 
    struct sNode* stack1; 
    struct sNode* stack2; 
}; 
void enQueue(struct queue* q, int x) 
{ 
    push(&q->stack1, x); 
} 
int deQueue(struct queue* q) 
{ 
    int x; 
    if (q->stack1 == NULL && q->stack2 == NULL) 
    { 
        printf("Q is empty"); 
        getchar(); 
        exit(0); 
    } 
/* Move elements from stack1 to stack 2 only if 
       stack2 is empty */
    if (q->stack2 == NULL) 
    { 
        while (q->stack1 != NULL) 
        { 
            x = pop(&q->stack1); 
            push(&q->stack2, x); 
        } 
    } 
    x = pop(&q->stack2); 
    return x; 
} 
void push(struct sNode** top_ref, int new_data) 
{ 
    struct sNode* new_node = (struct sNode*)malloc(sizeof(struct sNode)); 
    if (new_node == NULL) 
    { 
        printf("Stack overflow \n"); 
        getchar(); 
        exit(0); 
    } 
    new_node->data = new_data; 
    new_node->next = (*top_ref); 
    (*top_ref) = new_node; 
} 
int pop(struct sNode** top_ref) 
{ 
    int res; 
    struct sNode* top; 
    if (*top_ref == NULL) 
    { 
        printf("Stack underflow \n"); 
        getchar(); 
        exit(0); 
    } 
    else 
    { 
        top = *top_ref; 
        res = top->data; 
        *top_ref = top->next; 
        free(top); 
        return res; 
    } 
} 
int main() 
{ 
    struct queue* q = (struct queue*)malloc(sizeof(struct queue)); 
    q->stack1 = NULL; 
    q->stack2 = NULL; 
    enQueue(q, 1); 
    enQueue(q, 2); 
    enQueue(q, 3); 
    printf("%d ", deQueue(q)); 
    printf("%d ", deQueue(q)); 
    printf("%d ", deQueue(q)); 
    return 0; 
} 

