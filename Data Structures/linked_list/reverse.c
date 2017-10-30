#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}

void reverse(struct Node *node)
{
    struct Node* a=node;
    struct Node* b=node;
    struct Node* c=node;
    struct Node* prev=NULL;
    while (c->next != NULL)
        c=c->next;

    b=node;
    a=c;
    while (b != c)
    {
        if (b->next == c)
        {
            prev->next=c;
            a->next=b;
            a=a->next;
            b=node;
            if (prev==node)
                break;
            continue;
        }
        prev=b;
        b=b->next;
    }
    prev->next=NULL;
    a->next=prev;
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
}

int main()
{
    /* new node can be created here as :-
    struct Node* head = NULL;
    push(&head, data);
    and the list can be reversed using :-
    reverse(head);
    */
    return 0;
}