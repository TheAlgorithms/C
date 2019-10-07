#include <stdio.h>
#include <stdlib.h>

#include "../includes/pqueue.h"

QueueNode* createQueueNode(void* item, int priority) {

    QueueNode* new_node = malloc(sizeof(QueueNode));

    new_node->item = item;
    new_node->priority = priority;
    new_node->next = NULL;
}

PriorityQueue* createPriorityQueue() {
    PriorityQueue* new_queue = malloc(sizeof(PriorityQueue));

    new_queue->size = 0;
    new_queue->body = NULL;

    return new_queue;
}

int isPQEmpty(PriorityQueue* queue) {
    return queue->size == 0;
}

void enqueue(PriorityQueue* queue, void* item, int priority) {

    QueueNode* new_node = createQueueNode(item, priority);
    ++queue->size;

    if (queue->body == NULL) {
        queue->body = new_node;
    } else {
        
        if (queue->body->priority >= new_node->priority) {
            new_node->next = queue->body;
            queue->body = new_node;
        } else {

            QueueNode* current = queue->body;

            while (current->next != NULL && current->next->priority < priority) {

                current = current->next;
            }

            new_node->next = current->next;
            current->next = new_node;
        }
    }
}

QueueNode* dequeue(PriorityQueue* queue) {
    
    if (isPQEmpty(queue)) return NULL;

    QueueNode* temp = queue->body;
    queue->body = queue->body->next;

    --queue->size;

    return temp;
}

void printPriorityQueue(PriorityQueue* queue) {
    QueueNode* current = queue->body;

    printf("Queue : [ ");

    while (current != NULL) {
        printf("(%d, %d, %d) ", ((int *)current->item)[0], ((int *)current->item)[1], current->priority);
        current = current->next;
    }

    printf("]\n");
}