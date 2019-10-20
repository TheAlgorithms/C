/*
 * @file: queue.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "queue.h"

struct node {
	void *data;
	struct node *next;
};

struct Queue {
	int length;
	struct node *head;
	struct node *tail;
};

/* allocates memory for node and initialize it */
static struct node *createnode(void *data)
{
	struct node *entry;

	entry = (struct node *)malloc(sizeof(struct node));
	if(entry == NULL) {
		fprintf(stderr, "failed to allocate memory\n");
		return NULL;
	}

	entry->data = data;
	entry->next = NULL;

	return entry;
}

/* push data to queue tail */
int queue_push_tail(struct Queue *queue, void *data)
{
	struct node *entry;

	if(queue == NULL)
		return -1;

	entry = createnode(data);
	if(entry == NULL) {
		return -ENOMEM;
	}

	/* For empty queue */
	if(queue->head == NULL)
		queue->head = entry;
	else
		queue->tail->next = entry;
	queue->tail = entry;

	queue->length++;
	return 0;
}

/* removes head and return its data */
void *queue_pop_head(struct Queue *queue)
{
	void *data;
	struct node *entry;

	if(queue == NULL || queue->length == 0)
		return NULL;

	if(queue->head == NULL) {
		return NULL;
	}

	entry = queue->head;
	queue->head = queue->head->next;
	data = entry->data;
	queue->length--;
	free(entry);

	return data;
}

int queue_get_length(struct Queue *queue)
{
	if (queue == NULL)
		return 0;

	return queue->length;
}

struct Queue *queue_new()
{
	struct Queue *queue;

	queue = (struct Queue *)malloc(sizeof(struct Queue));
	if(queue == NULL) {
		fprintf(stderr, "failed to allocate memory\n");
		return NULL;
	}

	queue->length = 0;
	queue->head = NULL;
	queue->tail = NULL;

	return queue;
}

void queue_destroy(struct Queue *queue, QueueDataFreeFunc function)
{
	struct node *tmp;

	if(queue == NULL || queue->length == 0)
		goto cleanup;

	if(queue->head == NULL)
		free(queue);
	else {
		tmp = queue->head;
		while(queue->head != NULL) {
			tmp = queue->head->next;
			if (function != NULL)
				function(queue->head->data);
			free(queue->head);
			queue->head=tmp;
		}
	}

cleanup:
	free(queue);
}

