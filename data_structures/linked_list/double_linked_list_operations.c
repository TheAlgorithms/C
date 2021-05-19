#include <stdio.h>
#include <stdlib.h>


struct node
{
    int value;
    struct node* front;
    struct node* back;
};

struct dll // dll = double linked list
{
    struct node* start;
    struct node* end;
};


struct node* create_node(int value)
{
    struct node* new_node = (struct node*)malloc( sizeof(struct node) );
    new_node->value = value;
    new_node->front = NULL;
    new_node->back = NULL;

    return new_node;
}


struct dll* create_dll()
{
    struct dll* dll =  (struct dll*)malloc( sizeof(struct dll) );
    dll->start = NULL;
    dll->end = NULL;

    return dll;
}


void insert_beginning(int value, struct dll* dll)
{
    struct node* new_start = create_node(value);

    new_start->front = dll->start;

    if(dll->start != NULL)
    {
        dll->start->back = new_start;
    }
    else
    {
        dll->end = new_start;
    }

    dll->start =  new_start;
}


void insert_end(int value, struct dll* dll)
{
    struct node* new_end = create_node(value);

    new_end->back = dll->end;

    if(dll->end != NULL)
    {
        dll->end->front = new_end;
    }
    else
    {
        dll->start = new_end;
    }

    dll->end = new_end;
}


struct node* search(int searched_value, struct node* current)
{
    if(current == NULL)
    {
        return NULL;
    }
    else if( current->value == searched_value )
    {
        return current;
    }
    else
    {
        return search(searched_value, current->front);
    }
}

void remove_node(int searched_value, struct dll* dll)
{
    struct node* searched_node = search(searched_value, dll->start);

    struct node* back_node;
    struct node* front_node;

    if(searched_node != NULL)
    {
        back_node = searched_node->back;
        front_node = searched_node->front;

        free(searched_node);

        if(back_node != NULL)
        {
            back_node->front = front_node;

            if(front_node == NULL) // if the removed node is the end node
            {
                dll->end = back_node;
            }
        }
        if(front_node != NULL)
        {
            front_node->back = back_node;

            if(back_node == NULL) // if the removed node is the start node
            {
                dll->start = front_node;
            }
        }
    }
}

void print(struct node* start)
{
    if(start != NULL)
    {
        printf("%i ",start->value);
        print(start->front);
    }
}


void print_reverse(struct node* end)
{
    if(end != NULL)
    {
        printf("%i ", end->value);
        print_reverse(end->back);
    }
}


int main()
{
    struct dll* dll = create_dll(); // dll: empty

    insert_end(2, dll);       // dll: 2
    insert_beginning(1, dll); // dll: 1 2
    insert_end(3, dll);       // dll: 1 2 3
    insert_end(4, dll);       // dll: 1 2 3 4
    insert_end(5, dll);       // dll: 1 2 3 4 5

    print_reverse(dll->end);  // output expected: 5 4 3 2 1
    printf("\n\n");

    remove_node(3, dll);      // dll: 1 2 4 5
    remove_node(5, dll);      // dll: 1 2 4
    remove_node(1, dll);      // dll: 2 4
    remove_node(0, dll);      // dll: 2 4

    print(dll->start);        // output expected: 2 4

    return 0;
}
