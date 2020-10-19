/**
 * @file
 * @brief Implementation of [Doubly linked list](https://en.wikipedia.org/wiki/Doubly_linked_list)
 * @details
 * A doubly linked list is a data structure with a sequence
 * of components called nodes. Within that nodes there are
 * three elements: a value recorded, a pointer to the next
 * node, and a pointer to the previous node.
 *
 * In this implementation, the functions of creating the list,
 * inserting by position, deleting by position, searching 
 * for value, printing the list, and an example of how the
 * list works were coded.
 *
 * @author  [Gabriel Mota Bromonschenkel Lima](https://github.com/GabrielMotaBLima)
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Doubly linked list struct
 */
typedef struct list
{
    double value;               ///< value saved on each node
    struct list *next, *prev;   ///< directing to other nodes or NULL
} List;

/**
 * @brief   Create list function, a new list containing one node will be created
 * @param   value       a value to be saved into the first list node
 * @returns new_list    the list created
 */
List *create(double value);

/**
 * @brief   Insertion by position into the list function
 * @param   list    a doubly linked List
 * @param   value   a value to be inserted into the list
 * @param   pos     a position into the list for value insertion
 * @returns list    the input list with a node more or the same list
 */
List *insert(List *list, double value, int pos);

/**
 * @brief   Deletion by position into the list function
 * @param   list    a doubly linked List
 * @param   pos     a position into the list for value Deletion
 * @returns list    the input list with deleted values or the same list
 */
List *delete(List *list, int pos);

/**
 * @brief   Search value into the list function
 * @param   list    a doubly linked list
 * @param   value   a value to be looked for into the list
 * @returns `1`     if the looked up value exists
 * @returns `0`     if the looked up value doesn't exist
 */
int search(List *list, double value);

/**
 * @brief   Print list function
 * @param   list    a doubly linked List
 * @returns void
 */
void print(List *list);

/**
 * @brief   Example function
 * @returns void
 */
void example();

/**
 * @brief   Main function
 * @returns 0   on exit
 */
int main()
{
    // examples for better understanding
    example();
    // code here
    return 0;
}

/**
 * @brief   Create list function, a new list containing one node will be created
 * @param   value       a value to be saved into the first list node
 * @returns new_list    the list created
 */
List *create(double value)
{
    List *new_list = (List *)malloc(sizeof(List));
    new_list->value = value;
    new_list->next = NULL;
    new_list->prev = NULL;
    return new_list;
}

/**
 * @brief   Insertion by position into the list function
 * @param   list    a doubly linked List
 * @param   value   a value to be inserted into the list
 * @param   pos     a position into the list for value insertion
 * @returns list    the input list with a node more or the same list
 */
List *insert(List *list, double value, int pos)
{
    // list NULL case
    if (list == NULL)
    {
        list = create(value);
        return list;
    }

    // position existing case
    if (pos > 0)
    {
        List *cpy = list, *tmp = cpy;
        int flag = 1, index = 1, size = 0;

        while (tmp != NULL)
        {
            size++;
            tmp = tmp->next;
        }

        // first position case
        if (pos == 1)
        {
            List *new_node = create(value);
            new_node->next = cpy;
            cpy->prev = new_node;
            list = new_node;
            return list;
        }

        // position existing in list range case
        if (size + 2 > pos)
        {
            while (cpy->next != NULL && index < pos)
            {
                flag++;
                index++;
                cpy = cpy->next;
            }

            List *new_node = (List *)malloc(sizeof(List));
            new_node->value = value;

            // position into list with no poiting for NULL
            if (flag == pos)
            {
                cpy->prev->next = new_node;
                new_node->next = cpy;
                new_node->prev = cpy->prev;
                cpy->prev = new_node;
            }

            // last position case
            if (flag < pos)
            {
                new_node->next = cpy->next;
                new_node->prev = cpy;
                cpy->next = new_node;
            }
        }
        return list;
    }
}

/**
 * @brief   Deletion by position into the list function
 * @param   list    a doubly linked List
 * @param   pos     a position into the list for value Deletion
 * @returns list    the input list with deleted values or the same list
 */
List *delete(List *list, int pos)
{
    // list NULL case
    if (list == NULL)
        return list;

    // position existing case
    if (pos > 0)
    {
        List *cpy = list, *tmp = cpy;
        int flag = 1, index = 1, size = 0;

        while (tmp != NULL)
        {
            size++;
            tmp = tmp->next;
        }

        // first position case
        if (pos == 1)
        {
            if (size == 1)
                return NULL;
            cpy = cpy->next;
            cpy->prev = NULL;
            return cpy;
        }

        // position existing in list range case
        if (size + 2 > pos)
        {
            while (cpy->next != NULL && index < pos)
            {
                flag++;
                index++;
                cpy = cpy->next;
            }

            if (flag == pos)
            {
                // position into list with no poiting for NULL
                if (cpy->next != NULL)
                {
                    cpy->prev->next = cpy->next;
                    cpy->next->prev = cpy->prev;
                }

                // last position case
                else
                    cpy->prev->next = NULL;
            }
        }
        return list;
    }
}

/**
 * @brief   Search value into the list function
 * @param   list    a doubly linked list
 * @param   value   a value to be looked for into the list
 * @returns `1`     if the looked up value exists
 * @returns `0`     if the looked up value doesn't exist
 */
int search(List *list, double value)
{
    if (list == NULL)
        return 0;
    if (list->value == value)
        return 1;
    search(list->next, value);
}

/**
 * @brief   Print list function
 * @param   list    a doubly linked List
 * @returns void
 */
void print(List *list)
{
    if (list != NULL)
    {
        printf("%f\t", list->value);
        print(list->next);
    }
}

/**
 * @brief   Example function
 * @returns void
 */
void example()
{
    List *my_list = NULL;
    double node_value = 0;
    int searching;

    my_list = create(node_value);
    my_list = insert(my_list, 3, 1);
    my_list = insert(my_list, 5, 3);
    my_list = insert(my_list, 10, 3);
    my_list = insert(my_list, 20, 3);

    print(my_list);
    searching = search(my_list, 20);
    printf("\n%d\n", searching);

    my_list = delete (my_list, 1);
    my_list = delete (my_list, 1);
    my_list = delete (my_list, 1);
    my_list = delete (my_list, 1);

    print(my_list);
    searching = search(my_list, 20);
    printf("\n%d\n", searching);
}
