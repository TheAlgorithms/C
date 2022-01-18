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
 * for value, reversing the list, printing the list, and an example of how the
 * list and its functions work were coded.
 *
 * @author  [Gabriel Mota Bromonschenkel Lima](https://github.com/GabrielMotaBLima)
 * @author [Yannick Brenning](https://github.com/ybrenning)
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Doubly linked list struct
 */
typedef struct list {
    double value;               ///< value saved on each node
    struct list *next, *prev;   ///< directing to other nodes or NULL
} List;

/**
 * @brief Create list function, a new list containing one node will be created
 * @param value a value to be saved into the first list node
 * @returns new_list the list created
 */
List *create(double value) {
    List *new_list = (List *) malloc(sizeof(List));
    new_list->value = value;
    new_list->next = NULL;
    new_list->prev = NULL;

    return new_list;
}

/**
 * @brief Insertion by position into the list function
 * @param list head of a doubly linked List
 * @param value a value to be inserted into the list
 * @param pos position to insert the new node at
 * @returns list the input list with the added node or the same list
 */
List *insert(List *list, double value, int pos) {
    if (list == NULL) {
        list = create(value);
        return list;
    }

    // position existing case
    if (pos > 0) {
        List *cpy = list, *tmp = cpy;
        int flag = 1, index = 1, size = 0;

        while (tmp != NULL) {
            size++;
            tmp = tmp->next;
        }

        // first position case
        if (pos == 1) {
            List *new_node = create(value);
            
            new_node->next = cpy;
            cpy->prev = new_node;
            list = new_node;

            return list;
        }

        // position existing in list range case
        if (size + 2 > pos) {
            while (cpy->next != NULL && index < pos) {
                flag++;
                index++;
                cpy = cpy->next;
            }

            List *new_node = (List *) malloc(sizeof(List));
            new_node->value = value;

            // position into list with no positioning for NULL
            if (flag == pos) {
                cpy->prev->next = new_node;
                new_node->next = cpy;
                new_node->prev = cpy->prev;
                cpy->prev = new_node;
            }

            // last position case
            if (flag < pos) {
                new_node->next = cpy->next;
                new_node->prev = cpy;
                cpy->next = new_node;
            }
        }

        return list;
    }
}

/**
 * @brief Deletion of node at certain position
 * @param list head of a doubly linked List
 * @param pos position of node to be deleted
 * @returns list the updated list
 */
List *delete(List *list, int pos) {
    if (list == NULL) {
        return list;
    }

    // position existing case
    if (pos > 0) {
        List *cpy = list, *tmp = cpy;
        int flag = 1, index = 1, size = 0;

        while (tmp != NULL) {
            size++;
            tmp = tmp->next;
        }

        // first position case
        if (pos == 1) {
            if (size == 1) {
                return NULL;
            }

            cpy = cpy->next;
            cpy->prev = NULL;

            return cpy;
        }

        // position existing in list range case
        if (size + 2 > pos) {
            while (cpy->next != NULL && index < pos) {
                flag++;
                index++;
                cpy = cpy->next;
            }

            if (flag == pos) {
                if (cpy->next != NULL) {
                    // position into list with no positioning for NULL
                    cpy->prev->next = cpy->next;
                    cpy->next->prev = cpy->prev;
                } else {
                    // last position case
                    cpy->prev->next = NULL;
                }
            }
        }

        return list;
    }
}

/**
 * @brief Search value within the list function
 * @param list head of a doubly linked list
 * @param value a value to be searched for into the list
 * @returns `1` if the searched for value exists
 * @returns `0` if the searched for value doesn't exist
 */
int search(List *list, double value) {
    if (list == NULL) {
        return 0;
    }

    if (list->value == value) {
        return 1;
    }
    
    search(list->next, value);
}

/**
 * @brief Reverse a given list
 * @param list pointer to head of list to be reversed
 * @return reversed list
 */
List *reverse(List **list) {
    // Case 1: linked list is empty or only has one node
    if (*list == NULL || (*list)->next == NULL) {
        return *list;
    }

    // Case 2: linked list is reverseable
    List *current = *list, *temp;
    while (current != NULL) {
        // Use a temp pointer to swap next and prev pointers
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Continue traversal (keep in mind `prev` is now
        // pointing to what used to be the `next` node in the list )
        current = current->prev;
    }

    // Last step: set new head node to old tail node
    *list = temp->prev;

    return *list;
}

/**
 * @brief Prints list onto console
 * @param list head of a doubly linked List
 * @returns void
 */
void print(List *list) {
    if (list != NULL) {
        printf("%f\t", list->value);
        print(list->next);
    }
}

/**
 * @brief Example function
 * @returns void
 */
void example() {
    List *my_list = NULL;
    double node_value = 0;
    int searching;

    my_list = create(node_value);
    my_list = insert(my_list, 3, 1);
    my_list = insert(my_list, 5, 3);
    my_list = insert(my_list, 10, 3);
    my_list = insert(my_list, 20, 3);

    print(my_list);
    printf("\n");

    reverse(&my_list);
    print(my_list);
    printf("\n");

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

int main() {
    example();
    return 0;
}
