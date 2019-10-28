#include <stdio.h>
#include <stdlib.h>
#define debug printf("Here")

// Node of the linked list
typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// Handle of the list. Its head points to the first node in the list.
typedef struct DLList
{
    Node *head;
    int number_of_nodes;
}DLList;

// initializes a linked list
DLList* initialize_list();

// Creates a node and stores the data in it.
Node* create_node(int data);

// Inserts data at the beginning of the DLList
void insert_back(DLList* dll, int data);

// Deletes the node at position pos. No operation if pos is out of range.
void delete_back(DLList* dll);

// Return index of key in the list(0-based). Return -1 if not found
void reverse_list(DLList* dll);

// Prints the entire list. Prints "EMPTY" if the list is empty.
void display(DLList* dll);

// Deallocates resources held by the list
void destroy_list(DLList*);

int main()
{
    DLList* dll = initialize_list();
    int ele, choice;
    //To get the user choice
    do
    {   printf("\n1. Insert at the end of the list \n2. Delete at the end of the list\n3. Reverse the list\n4. Display   the list\nEnter your choice:\n");
        scanf("%d",&choice);
        printf("\n");
        // Perform function based on choice
        switch(choice)
        {
            // Insert at the end of the list
            case 1:
                printf("Enter the element to insert:\n");
                scanf("%d", &ele);
                insert_back(dll, ele);
                break;

            // Delete at the end of the list
            case 2:
                delete_back(dll);
                break;

            // Search for element
            case 3:
                reverse_list(dll);
                break;

            // Print entire list
            case 4:
                display(dll);
                printf("Updated List :\n");
                break;
        }
    } while (choice != 0);

    destroy_list(dll);
    return 0;
}

DLList* initialize_list()
{
    DLList* temp = (DLList*)malloc(sizeof(DLList));
    temp->head = NULL;
    temp->number_of_nodes = 0;
    return temp;
}

Node* create_node(int data)
{
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}

void insert_back(DLList* dll, int data)
{
    Node* temp = create_node(data), *ptr = dll->head;
    if(dll->head==NULL)
    {
        dll->head = temp;
    }
    else
    {
        while(ptr->next!=NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->prev = ptr;
    }
    printf("Element has been added\nUpdated List :\n");
    display(dll);
}

void delete_back(DLList* dll)
{
    Node* ptr = dll->head, *previous = NULL;
        if(dll->head==NULL);
        else
        {
            while(ptr->next!=NULL)
            {
                previous = ptr;
                ptr=ptr->next;
            }
            if(previous==NULL)
            {
                free(ptr);
                dll->head=NULL;
            }
            else
            {
                previous->next = NULL;
                ptr->prev = NULL;
                free(ptr);
            }

        }
        printf("Element has been deleted.\nUpdated List  :");
        display(dll);
}

void reverse_list(DLList* dll)
{
    Node *curr = dll->head, *ptr;
    if(dll->head==NULL);
    else
    {
        while(curr!=NULL)
        {
            ptr = curr->next;
            curr->next = curr->prev;
            curr->prev = ptr;
            if(curr->prev==NULL)
            dll->head = curr;
            curr = curr->prev;

        }

    }
    printf("List has been reversed.\nUpdated List is :");
    display(dll);
}

void display(DLList* dll)
{
    Node *ptr = dll->head;
    if(dll->head==NULL)
    {
        printf("EMPTY");
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
    printf("\n");
}

void destroy_list(DLList* dll)
{

    if(dll->head==NULL);
    else
    {
        while(dll->head!=NULL)
        {
            Node *temp = dll->head;
            dll->head = dll->head->next;
            free(temp);
        }

    }

}
