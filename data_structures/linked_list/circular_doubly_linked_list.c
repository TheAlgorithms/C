/*
 * circular_doubly_linked_list.c
 *
 * @details
 Circular Doubly Linked List combines the properties of a doubly linked list and a circular linked list in which two consecutive elements are linked or connected by the previous and next pointer and the last node points to the first node via the next pointer and the first node points last node via the previous pointer.

 In this implementation, the menu driven code is written along with functions to insert at start, insrt at last, delete first node, delete last node and display list functions are coded.

 * Author: [Sahil Kandhare](https://github.com/SahilK-027)
 * Created on 12/10/2002
 *
 *
 * Cicular doubly linked list in C
 *
 * Compiled in Visual Studio Code
 *
 */

#include <stdio.h>   /// for IO operations
#include <stdlib.h>  /// for including functions involving memory allocation such as `malloc`
/**
 * @brief Node Structure Cicular Doubly linked list.
 */
struct node
{
    struct node *prev, *next;         ///< List pointers
    int value = 0;                   ///> Data stored on each node
};

/**
 * @brief   Insert the node at start of list
 * @param   start   starting pointer of list
 * @param   data    the data which we want to insert into list
 * @returns void
 */
void insert_at_start(struct node **start, int data)
{
    struct node *n1;
    n1 = (struct node *)malloc(sizeof(struct node));
    n1->value = data;
    if (*start == NULL)
    {
        n1->next = n1;
        n1->prev = n1;
        *start = n1;
    }
    else
    {
        struct node *temp;
        temp = (*start)->prev;
        n1->next = *start;
        (*start)->prev = n1;
        n1->prev = temp;
        temp->next = n1;
        *start = n1;
    }
    printf("\nNode succesfully inserted\n\n");
}

/**
 * @brief   Insert the node at end of list
 * @param   start   starting pointer of list
 * @param   data    the data which we want to insert into list
 * @returns void
 */
void insert_at_last(struct node **start, int data)
{
    struct node *n1;
    n1 = (struct node *)malloc(sizeof(struct node));
    n1->value = data;
    if (*start == NULL)
    {
        n1->next = n1;
        n1->prev = n1;
        *start = n1;
    }
    else
    {
        struct node *temp1, *temp2;
        temp1 = *start;
        temp2 = (*start)->prev;
        n1->prev = temp2;
        n1->next = temp1;
        temp1->prev = n1;
        temp2->next = n1;
    }
    printf("\nNode succesfully inserted\n\n");
}

/**
 * @brief   Deletion of the first node in list function
 * @param   start   starting pointer of list
 * @returns void
 */
void delete_fist_node(struct node **start)
{
    if (*start == NULL)
    {
        printf("⚠️list is Empty⚠️\n");
    }
    else
    {
        struct node *temp1, *temp2;
        temp1 = *start;
        temp2 = temp1->prev;
        if (temp1 == temp2)
        {
            free(temp2);
            *start = NULL;
        }
        else
        {
            temp2->next = temp1->next;
            (temp1->next)->prev = temp2;
            *start = temp1->next;
            free(temp1);
            temp1 = NULL;
        }
        printf("\nNode succesfully deleted\n\n");
    }
}

/**
 * @brief   Deletion of the last node in list function
 * @param   start   starting pointer of list
 * @returns void
 */
void delete_last_node(struct node **start)
{
    if (*start == NULL)
    {
        printf("list is Empty\n");
    }
    else
    {
        struct node *temp1, *temp2;
        temp1 = *start;
        temp2 = temp1->prev;
        if (temp1 == temp2)
        {
            free(temp2);
            *start = NULL;
        }
        else
        {
            (temp2->prev)->next = temp1;
            temp1->prev = temp2->prev;
            free(temp2);
            temp2 = NULL;
        }
        printf("\nNode succesfully deleted\n\n");
    }
}

/**
 * @brief   Display list function
 * @param   start   starting pointer of list
 * @returns void
 */
void Display(struct node *start)
{
    printf("\nIts Your Linked-list\n\n");
    struct node *temp;
    temp = start;
    if (start != NULL)
    {
        while (temp->next != start)
        {
            printf("%d -> ", temp->value);
            temp = temp->next;
        }
        if (temp->next == start)
        {
            printf("%d", temp->value);
        }
    }
    else
    {
        printf("list is Empty\n");
    }
    printf("\n");
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main()
{
    // Creating an empty list
    struct node *start = NULL;
    // Flg to stop loop and value to insert
    int flag = 1, value;
    while (flag == 1)
    {
        int ch;
        printf("\nWhat do you want to perform?\n");
        printf("ENTER YOUR CHOISE\n1. Insert At Start\n2. Insert At End\n3. DISPLAY LINKED LIST\n4. Delete First node\n5. Delete Last Node\n6. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the data ");
            scanf("%d", &value);
            insert_at_start(&start, value);
            break;
        case 2:
            printf("Enter the data ");
            scanf("%d", &value);
            insert_at_last(&start, value);
            break;
        case 3:
            Display(start);
            break;
        case 4:
            delete_fist_node(&start);
            break;
        case 5:
            delete_last_node(&start);
            break;
        case 6:
            flag = 0;
            break;
        default:
            printf("\nIncorrect choice Re-Enter\n\n");
        }
    }
    return 0;
}
