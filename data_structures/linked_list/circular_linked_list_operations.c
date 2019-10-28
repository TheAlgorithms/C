#include <stdio.h>
#include <stdlib.h>


struct node
{
    int value;
    struct node* next;
};

struct cll // cll = circular linked list
{
    struct node* end;
    struct node* start;
};


struct cll* create_cll()
{
    struct cll* cll = malloc( sizeof(struct cll) );
    cll->start = NULL;
    cll->end = NULL;

    return cll;
}


struct node* create_node(int value)
{
    struct node* new_node = malloc( sizeof(struct node) );
    new_node->next = NULL;
    new_node->value = value;

    return new_node;
}


void insert_beginning(int value, struct cll* cll)
{
    if(cll->end == NULL) // if list in empty
    {
        struct node* new_node = create_node(value);

        new_node->next = new_node; // Points to itself

        cll->start = new_node;
        cll->end = new_node;
    }
    else
    {
        struct node* new_node = create_node(value);

        new_node->next = cll->start; // New first node points to old first node

        cll->end->next = new_node; // last node points to new start

        cll->start = new_node; // start points to new start node
    }
}


void insert_end(int value, struct cll* cll)
{
    if(cll->end == NULL) // if list in empty
    {
        struct node* new_node = create_node(value);

        new_node->next = new_node; // Points to itself

        cll->start = new_node;
        cll->end = new_node;
    }
    else
    {
        struct node* new_node = create_node(value);

        new_node->next = cll->start; // new last node points to first node

        cll->end->next = new_node; // old last node points to new last node

        cll->end = new_node; // end points to new last node
    }
}


struct node* search(int searched_value, struct node* current_node, struct cll* cll)
{
    if(current_node != NULL)
    {
        do
        {
            if(current_node->value == searched_value)
            {
                return current_node;
            }
            else
            {
                current_node = current_node->next;
            }

        }while(current_node != cll->start);
    }

    return NULL;
}


void remove_node(int value, struct cll* cll)
{
    struct node* searched_node = search(value, cll->start, cll);

    if(searched_node != NULL)
    {
        if(searched_node != cll->end)
        {
            struct node* front_node = searched_node->next;

            searched_node->value = front_node->value;

            searched_node->next = front_node->next;

            if(front_node == cll->end)
            {
                cll->end = searched_node;
            }

            free(front_node);
        }
        else // special case: removing the end node
        {
            struct node* back_node = cll->start; // start with first node

            while(back_node->next != cll->end) // back_node get out of the while being the real back node
            {
                back_node = back_node->next;
            }

            cll->end = back_node; // back_node is the new end

            back_node->next = cll->start; // new end points to start

            free(searched_node);
        }
    }
}


void print(struct node* start, struct node* end)
{
    if(start != NULL && start != end)
    {
        printf("%i ", start->value);
        print(start->next, end);
    }
    else if(start != NULL && start == end)
    {
        printf("%i ", start->value);
    }
}


void print_reverse(struct node* start, struct node* end)
{
    if(start != NULL && start != end)
    {
        print_reverse(start->next, end);
        printf("%i ", start->value);
    }
    else if(start != NULL && start == end)
    {
        printf("%i ", start->value);
    }
}



int main()
{
    struct cll* cll = create_cll(); // cll: empty

    insert_end(2, cll);       // cll: 2
    insert_beginning(1, cll); // cll: 1 2
    insert_end(3, cll);       // cll: 1 2 3
    insert_end(4, cll);       // cll: 1 2 3 4
    insert_end(5, cll);       // cll: 1 2 3 4 5
    insert_beginning(0, cll); // cll: 0 1 2 3 4 5

    print_reverse(cll->start, cll->end); // output expected: 5 4 3 2 1 0
    printf("\n\n");

    remove_node(3, cll); // cll: 0 1 2 4 5
    remove_node(3, cll); // cll: 0 1 2 4 5
    remove_node(0, cll); // cll: 1 2 4 5
    remove_node(5, cll); // cll: 1 2 4
    remove_node(2, cll); // cll: 1 4

    print(cll->start, cll->end); // output expected: 1 4

    return 0;
}
