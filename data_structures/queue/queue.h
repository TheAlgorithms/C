/*
 * @file: queue.h
 */

#ifndef __QUEUE_H
#define __QUEUE_H

struct Queue;

typedef void (* QueueDataFreeFunc)(void *data);

extern struct Queue *queue_new();
extern void queue_destroy(struct Queue *queue, QueueDataFreeFunc function);

extern int queue_push_tail(struct Queue *queue, void *data);
extern void *queue_pop_head(struct Queue *queue);
extern int queue_get_length(struct Queue *queue);

#endif
