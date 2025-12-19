/* Circularly Linked List (Basic Operations) - Program to create a Circularly
 * linked list abstract data type and perform various operation on it */

#include <stdio.h>
#include <stdlib.h>

/* Assume that the data portion of each node consists of ONLY an integer.*/
struct node
{
    int data;
    struct node* next;
};

/* Circular Linked List as a standalone structure
   first : marks the beginning of linked list
   last : marks the last node of linked list
*/
struct circularLinkedList
{
    struct node* first;
    struct node* last;
};

/* This function create a new node and returns its pointer. */
struct node* createNode(int data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

/* This function deletes a node */
void deleteNode(struct node* n)
{
    if (n)
    {
        free(n);
    }
}

/* This function creates a new Circular Linked List from scratch.
CLL stands for "Circular Linked List"*/
struct circularLinkedList* createCLL()
{
    struct circularLinkedList* list =
        (struct circularLinkedList*)malloc(sizeof(struct circularLinkedList));

    list->first = NULL;
    list->last = NULL;

    return list;
}

/* This function adds a new node at the front. */
void addNodeAtFront(struct circularLinkedList* cll, int data)
{
    struct node* newNode = createNode(data);

    if (cll->first == NULL)
    {
        cll->first = newNode;
        cll->last = newNode;
        newNode->next = newNode;
        return;
    }

    newNode->next = cll->first;
    cll->first = newNode;
    cll->last->next = cll->first;
}

/* This function adds a new node at the rear. */
void addNodeAtRear(struct circularLinkedList* cll, int data)
{
    struct node* newNode = createNode(data);

    if (cll->first == NULL)
    {
        cll->first = newNode;
        cll->last = newNode;
        newNode->next = newNode;
        return;
    }

    cll->last->next = newNode;
    cll->last = newNode;
    cll->last->next = cll->first;
}

/* This function deletes the node at the front of the Circular Linked List. */
void deleteFront(struct circularLinkedList* cll)
{
    if (cll->first == NULL)
    {
        printf("Circularly Linked List Empty\n");
        return;
    }

    struct node* temp = cll->first;

    if (cll->first == cll->last)
    {
        cll->first = NULL;
        cll->last = NULL;
    }
    else
    {
        cll->first = cll->first->next;
        cll->last->next = cll->first;
    }

    deleteNode(temp);
}

/* This function deletes the node at the end of Circular Linked List. */
void deleteRear(struct circularLinkedList* cll)
{
    if (cll->first == NULL)
    {
        printf("Circularly Linked List Empty\n");
        return;
    }

    struct node* temp = cll->last;
    if (cll->first == cll->last)
    {
        cll->first = NULL;
        cll->last = NULL;
    }
    else
    {
        struct node* current = cll->first;
        while (current->next != cll->last)
        {
            current = current->next;
        }
        cll->last = current;
        cll->last->next = cll->first;
    }
    deleteNode(temp);
}

/* This function deletes the node with the given value. */
void deleteNodeWithValue(struct circularLinkedList* cll, int data)
{
    if (cll->first == NULL)
    {
        printf("Circularly Linked List Empty\n");
        return;
    }

    struct node* current = cll->first;
    struct node* previous = cll->last;
    do
    {
        if (current->data == data)
        {
            if (current == cll->first)
            {
                deleteFront(cll);
            }
            else if (current == cll->last)
            {
                deleteRear(cll);
            }
            else
            {
                previous->next = current->next;
                deleteNode(current);
            }
            return;
        }
        previous = current;
        current = current->next;
    } while (current != cll->first);

    printf("Required node not found.\n");
}

void traverse(struct circularLinkedList* cll)
{
    if (cll->first == NULL)
    {
        printf("Circularly Linked List Empty\n");
        return;
    }

    struct node* current = cll->first;
    printf("Circularly Linked List is as shown:\n");
    do
    {
        printf("%d ", current->data);
        current = current->next;
    } while (current != cll->first);
    printf("\n");
}

int main()
{
    struct circularLinkedList* cll = createCLL();

    addNodeAtRear(cll, 10);
    addNodeAtRear(cll, 20);
    addNodeAtFront(cll, 5);
    traverse(cll);

    deleteNodeWithValue(cll, 20);
    traverse(cll);

    deleteFront(cll);
    traverse(cll);

    deleteRear(cll);
    traverse(cll);

    return 0;
}
