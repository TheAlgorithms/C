/**
 * @file
 * @brief Program to generate [Cantor ternary
 * set](https://en.wikipedia.org/wiki/Cantor_set)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** structure to define Cantor set */
typedef struct _cantor_set
{
    double start;             /**< start of interval */
    double end;               /**< end of interval */
    struct _cantor_set *next; /**< pointer to next set */
} CantorSet;

/** Iterative constructor of all sets in the current level. This function
 * dynamically allocates memory when creating new sets. These are freed by the
 * function ::free_memory.
 * @param head pointer to interval set instance to update
 */
void propagate(CantorSet *head)
{
    // if input is NULL, ignore the process
    if (head == NULL)
        return;

    CantorSet *temp = head;  // local pointer to track propagation

    // create new node for the new set
    CantorSet *newNode = (CantorSet *)malloc(sizeof(CantorSet));

    // get 1/3rd of interval
    double diff = (((temp->end) - (temp->start)) / 3);

    // update interval ranges
    newNode->end = temp->end;
    temp->end = ((temp->start) + diff);
    newNode->start = (newNode->end) - diff;

    // update pointer to next set in this level
    newNode->next = temp->next;

    // point to next set
    temp->next = newNode;

    // create next set
    propagate(temp->next->next);
}

/** Print sets in the current range to `stdout`
 * @param head pointer to first set in the current level
 */
void print(CantorSet *head)
{
    CantorSet *temp = head;
    while (temp != NULL)  // print while a valid set is found
    {
        printf("\t");
        printf("[%lf] -- ", temp->start);
        printf("[%lf]", temp->end);
        temp = temp->next;
    }

    printf("\n");
}

/** Clear memory allocated by ::propagate function.
 * @param head pointer to first allocated instance.
 */
void free_memory(CantorSet *head)
{
    if (!head)
        return;

    if (head->next)
        free_memory(head->next);

    free(head);
}

/** Main function */
int main(int argc, char const *argv[])
{
    int start_num, end_num, levels;

    if (argc < 2)
    {
        printf("Enter 3 arguments: start_num \t end_num \t levels\n");
        scanf("%d %d %d", &start_num, &end_num, &levels);
    }
    else
    {
        start_num = atoi(argv[1]);
        end_num = atoi(argv[2]);
        levels = atoi(argv[3]);
    }

    if (start_num < 0 || end_num < 0 || levels < 0)
    {
        fprintf(stderr, "All numbers must be positive\n");
        return -1;
    }

    CantorSet head = {.start = start_num, .end = end_num, .next = NULL};

    // loop to propagate each level from top to bottom
    for (int i = 0; i < levels; i++)
    {
        printf("Level %d\t", i);
        print(&head);
        propagate(&head);
        printf("\n");
    }
    printf("Level %d\t", levels);
    print(&head);

    // delete all memory allocated
    free_memory(head.next);

    return 0;
}
