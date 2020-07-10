/**
 * \file: queue.c
 * \brief Data structure implementation of queue
 * \author [shubham patil](https://github.com/shubhamdp)
 */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Content of header file begins */

/** Structure of a node in queue */
struct node
{
    /** Pointer data in a node */
    void *data;
    /** Pointer to next node in queue */
    struct node *next;
};

/** Structure of a queue */
struct Queue
{
    /** Length of a queue */
    int length;
    /** Head pointer of a queue */
    struct node *head;
    /** Tail pointer of a queue */
    struct node *tail;
};

/**
 * Prototype for Queue Data Free Function
 *
 * \param[in] data arguments to free function, this will be the data entry in
 * queue
 */
typedef void (*QueueDataFreeFunc)(void *data);

/**
 * Creates and initialise the queue
 *
 * \return pointer pointer to newly created queue
 * \return NULL in case of no memory
 */
extern struct Queue *queue_new();

/**
 * Destroy and free up all the data in queue
 *
 * \param[in,out] queue pointer to the queue, returned by queue_new
 * \param[in] function callback function which is used to free the entries in
 * queue
 */
extern void queue_destroy(struct Queue *queue, QueueDataFreeFunc function);

/**
 * Enqueue the data at the end of queue
 *
 * \param[in,out] queue pointer to the queue, returned by queue_new
 * \param[in] data pointer to the data to be queued
 *
 * \return 0       enqueu is successful
 * \return -1      parameter queue is NULL
 * \return -ENOMEM not enough memory to perform the operation
 */
extern int queue_push_tail(struct Queue *queue, void *data);

/**
 * Dequeue the data at the start of queue
 *
 * \param[in,out] queue pointer to the queue, returned by queue_new
 *
 * \return pointer pointer to data
 * \return NULL if parameter queue is null or queue is empty
 */
extern void *queue_pop_head(struct Queue *queue);

/* Content of header file ends */

/* Content of implementation begins */

/**
 * Get the length of queue
 *
 * \param[in] queue pointer to the queue, returned by queue_new
 *
 * \return value length of queue
 */
extern int queue_get_length(struct Queue *queue);

/** Creates a node with provided data
 *
 * \param[in] data data to be passed stored
 *
 * \return entry newly created node
 * \return NULL not enough memory
 */
static struct node *createnode(void *data)
{
    struct node *entry;

    entry = (struct node *)malloc(sizeof(struct node));
    if (entry == NULL)
    {
        fprintf(stderr, "failed to allocate memory\n");
        return NULL;
    }

    entry->data = data;
    entry->next = NULL;

    return entry;
}

int queue_push_tail(struct Queue *queue, void *data)
{
    struct node *entry;

    if (queue == NULL)
        return -1;

    entry = createnode(data);
    if (entry == NULL)
    {
        return -ENOMEM;
    }

    /* For empty queue */
    if (queue->head == NULL)
        queue->head = entry;
    else
        queue->tail->next = entry;
    queue->tail = entry;

    queue->length++;
    return 0;
}

void *queue_pop_head(struct Queue *queue)
{
    void *data;
    struct node *entry;

    if (queue == NULL || queue->length == 0)
        return NULL;

    if (queue->head == NULL)
    {
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
    if (queue == NULL)
    {
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

    if (queue == NULL || queue->length == 0)
        goto cleanup;

    if (queue->head == NULL)
        free(queue);
    else
    {
        tmp = queue->head;
        while (queue->head != NULL)
        {
            tmp = queue->head->next;
            if (function != NULL)
                function(queue->head->data);
            free(queue->head);
            queue->head = tmp;
        }
    }

cleanup:
    free(queue);
}

/* Content of implementation ends */

/* Content of Unit Test case begins */

static void print_len(struct Queue *q)
{
    printf("queue_len: %d\n", queue_get_length(q));
}

/**
 * main function
 */
int main(int argc, char **argv)
{
    char *str;
    char *entry;
    struct Queue *q_str = queue_new();

    entry = "hello";
    printf("enqueue: %s\n", entry);
    queue_push_tail(q_str, strdup(entry));
    print_len(q_str);

    entry = "world";
    printf("enqueue: %s\n", entry);
    queue_push_tail(q_str, strdup(entry));
    print_len(q_str);

    entry = "in";
    printf("enqueue: %s\n", entry);
    queue_push_tail(q_str, strdup(entry));
    print_len(q_str);

    entry = "C";
    printf("enqueue: %s\n", entry);
    queue_push_tail(q_str, strdup(entry));
    print_len(q_str);

    str = queue_pop_head(q_str);
    printf("dequeue: %s\n", str);
    free(str);
    print_len(q_str);

    str = queue_pop_head(q_str);
    printf("dequeue: %s\n", str);
    free(str);
    print_len(q_str);

    entry = "bye";
    printf("enqueue: %s\n", entry);
    queue_push_tail(q_str, strdup(entry));
    print_len(q_str);
    queue_destroy(q_str, free);

    return 0;
}

/* Centent of Unit Test Case ends */
