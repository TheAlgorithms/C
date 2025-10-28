/**
 * @file singly_linked_list.c
 * @brief Implementation of a singly linked list in C.
 *
 * This file implements a singly linked list with the following operations:
 * 1. Insert at the beginning
 * 2. Insert at the end
 * 3. Insert at a specific position
 * 4. Delete from the beginning
 * 5. Delete from the end
 * 6. Delete from a specific position
 * 7. Display the linked list
 *
 * Time Complexity:
 *   - Insert at beginning: O(1)
 *   - Insert at end: O(n)
 *   - Insert at position: O(n)
 *   - Delete at beginning: O(1)
 *   - Delete at end: O(n)
 *   - Delete at position: O(n)
 *   - Display: O(n)
 *
 * Author: Rahul Guggilam
 */

#include <stdio.h>
#include <stdlib.h>

/** Node structure for singly linked list */
typedef struct Node
{
    int data;
    struct Node* next;
} Node;

/** Function to create a new node with given data */
Node* create_node(int data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

/** Insert a node at the beginning of the linked list */
void insert_begin(Node** head, int data)
{
    Node* new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

/** Insert a node at the end of the linked list */
void insert_end(Node** head, int data)
{
    Node* new_node = create_node(data);
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

/** Insert a node at a specific position (1-based index) */
void insert_position(Node** head, int data, int position)
{
    if (position < 1)
    {
        printf("Invalid position\n");
        return;
    }
    if (position == 1)
    {
        insert_begin(head, data);
        return;
    }
    Node* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Position exceeds list length, inserting at end\n");
        insert_end(head, data);
        return;
    }
    Node* new_node = create_node(data);
    new_node->next = temp->next;
    temp->next = new_node;
}

/** Delete the first node of the linked list */
void delete_begin(Node** head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

/** Delete the last node of the linked list */
void delete_end(Node** head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }
    Node* temp = *head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

/** Delete a node at a specific position (1-based index) */
void delete_position(Node** head, int position)
{
    if (*head == NULL || position < 1)
    {
        printf("Invalid position or empty list\n");
        return;
    }
    if (position == 1)
    {
        delete_begin(head);
        return;
    }
    Node* temp = *head;
    for (int i = 1; i < position - 1 && temp->next != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        printf("Position exceeds list length\n");
        return;
    }
    Node* del_node = temp->next;
    temp->next = del_node->next;
    free(del_node);
}

/** Display all nodes in the linked list */
void display(Node* head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    Node* temp = head;
    printf("Linked list: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/** Main function demonstrating linked list operations */
int main()
{
    Node* head = NULL;
    int choice, data, pos;

    while (1)
    {
        printf(
            "\n1. Insert at beginning\n2. Insert at end\n3. Insert at "
            "position\n");
        printf(
            "4. Delete at beginning\n5. Delete at end\n6. Delete at "
            "position\n7. Display\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            insert_begin(&head, data);
            break;
        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            insert_end(&head, data);
            break;
        case 3:
            printf("Enter data and position: ");
            scanf("%d %d", &data, &pos);
            insert_position(&head, data, pos);
            break;
        case 4:
            delete_begin(&head);
            break;
        case 5:
            delete_end(&head);
            break;
        case 6:
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            delete_position(&head, pos);
            break;
        case 7:
            display(head);
            break;
        case 8:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
