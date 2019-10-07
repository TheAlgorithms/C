#ifndef PQUEUE_H
#define PQUEUE_H

typedef struct q_node {
    void* item;
    int priority;
    struct q_node* next;
} QueueNode;

typedef struct queue {
    int size;
    QueueNode* body;
} PriorityQueue;

QueueNode* createQueueNode(void* item, int priority);

int isPQEmpty(PriorityQueue* queue);
PriorityQueue* createPriorityQueue();
void enqueue(PriorityQueue* queue, void* item, int priority);
QueueNode* dequeue(PriorityQueue* queue);
void printPriorityQueue(PriorityQueue* queue);
    
#endif //PQUEUE_H