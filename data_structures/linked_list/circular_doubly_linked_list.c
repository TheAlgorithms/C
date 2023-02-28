/**
 * @file
 *
 * @details
 * Circular [Doubly Linked
 * List](https://en.wikipedia.org/wiki/Doubly_linked_list) combines the
 * properties of a doubly linked list and a circular linked list in which two
 * consecutive elements are linked or connected by the previous. Next, the
 * pointer and the last node point to the first node via the next pointer, and
 * the first node points to the last node via the previous pointer.
 *
 * In this implementation, functions to insert at the head, insert at the last
 * index, delete the first node, delete the last node, display list, and get
 * list size functions are coded.
 *
 * @author [Sahil Kandhare](https://github.com/SahilK-027)
 *
 */

#include <assert.h>  /// to verify assumptions made by the program and print a diagnostic message if this assumption is false.
#include <inttypes.h>  /// to provide a set of integer types with universally consistent definitions that are operating system-independent
#include <stdio.h>     /// for IO operations
#include <stdlib.h>  /// for including functions involving memory allocation such as `malloc`

/**
 * @brief Circular Doubly linked list struct
 */
typedef struct node
{
    struct node *prev, *next;  ///< List pointers
    uint64_t value;            ///< Data stored on each node
} ListNode;

/**
 * @brief Create a list node
 * @param data                  the data that the node initialises with
 * @return ListNode*            pointer to the newly created list node
 */
ListNode *create_node(uint64_t data)
{
    ListNode *new_list = (ListNode *)malloc(sizeof(ListNode));
    new_list->value = data;
    new_list->next = new_list;
    new_list->prev = new_list;
    return new_list;
}

/**
 * @brief Insert a node at start of list
 * @param head                  start pointer of list
 * @param data                  the data that the node initialises with
 * @return ListNode*            pointer to the newly created list node
 * inserted at the head
 */
ListNode *insert_at_head(ListNode *head, uint64_t data)
{
    if (head == NULL)
    {
        head = create_node(data);
        return head;
    }
    else
    {
        ListNode *temp;
        ListNode *new_node = create_node(data);
        temp = head->prev;
        new_node->next = head;
        head->prev = new_node;
        new_node->prev = temp;
        temp->next = new_node;
        head = new_node;
        return head;
    }
}

/**
 * @brief Insert a node at end of list
 *
 * @param head                  start pointer of list
 * @param data                  the data that the node initialises with
 * @return ListNode*            pointer to the newly added list node that was
 * inserted at the head of list.
 */
ListNode *insert_at_tail(ListNode *head, uint64_t data)
{
    if (head == NULL)
    {
        head = create_node(data);
        return head;
    }
    else
    {
        ListNode *temp1, *temp2;
        ListNode *new_node = create_node(data);
        temp1 = head;
        temp2 = head->prev;
        new_node->prev = temp2;
        new_node->next = temp1;
        temp1->prev = new_node;
        temp2->next = new_node;
        return head;
    }
}

/**
 * @brief  Function for deletion of the first node in list
 *
 * @param head              start pointer of list
 * @return ListNode*        pointer to the list node after deleting first node
 */
ListNode *delete_from_head(ListNode *head)
{
    if (head == NULL)
    {
        printf("The list is empty\n");
        return head;
    }
    ListNode *temp1, *temp2;
    temp1 = head;
    temp2 = temp1->prev;
    if (temp1 == temp2)
    {
        free(temp2);
        head = NULL;
        return head;
    }
    temp2->next = temp1->next;
    (temp1->next)->prev = temp2;
    head = temp1->next;
    free(temp1);
    return head;
}

/**
 * @brief Function for deletion of the last node in list
 *
 * @param head              start pointer of list
 * @return ListNode*        pointer to the list node after deleting first node
 */
ListNode *delete_from_tail(ListNode *head)
{
    if (head == NULL)
    {
        printf("The list is empty\n");
        return head;
    }

    ListNode *temp1, *temp2;
    temp1 = head;
    temp2 = temp1->prev;
    if (temp1 == temp2)
    {
        free(temp2);
        head = NULL;
        return head;
    }
    (temp2->prev)->next = temp1;
    temp1->prev = temp2->prev;
    free(temp2);
    return head;
}

/**
 * @brief The function that will return current size of list
 *
 * @param head      start pointer of list
 * @return int      size of list
 */
int getsize(ListNode *head)
{
    if (!head)
    {
        return 0;
    }
    int size = 1;
    ListNode *temp = head->next;
    while (temp != head)
    {
        temp = temp->next;
        size++;
    }
    return size;
}

/**
 * @brief   Display list function
 * @param   head   start pointer of list
 * @returns void
 */

void display_list(ListNode *head)
{
    printf("\nContents of your linked list: ");
    ListNode *temp;
    temp = head;
    if (head != NULL)
    {
        while (temp->next != head)
        {
            printf("%" PRIu64 " <-> ", temp->value);
            temp = temp->next;
        }
        if (temp->next == head)
        {
            printf("%" PRIu64, temp->value);
        }
    }
    else
    {
        printf("The list is empty");
    }
    printf("\n");
}

/**
 * @brief access the list by index
 * @param list pointer to the target list
 * @param index access location
 * @returns the value at the specified index,
 *          wrapping around if the index is larger than the size of the target
 * list
 */
uint64_t get(ListNode *list, const int index)
{
    if (list == NULL || index < 0)
    {
        exit(EXIT_FAILURE);
    }
    ListNode *temp = list;
    for (int i = 0; i < index; ++i)
    {
        temp = temp->next;
    }
    return temp->value;
}

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test()
{
    ListNode *testList = NULL;
    unsigned int array[] = {2, 3, 4, 5, 6};

    assert(getsize(testList) == 0);

    printf("Testing inserting elements:\n");
    for (int i = 0; i < 5; ++i)
    {
        display_list(testList);
        testList = insert_at_head(testList, array[i]);
        assert(testList->value == array[i]);
        assert(getsize(testList) == i + 1);
    }

    printf("\nTesting removing elements:\n");
    for (int i = 4; i > -1; --i)
    {
        display_list(testList);
        assert(testList->value == array[i]);
        testList = delete_from_head(testList);
        assert(getsize(testList) == i);
    }

    printf("\nTesting inserting at tail:\n");
    for (int i = 0; i < 5; ++i)
    {
        display_list(testList);
        testList = insert_at_tail(testList, array[i]);
        assert(get(testList, i) == array[i]);
        assert(getsize(testList) == i + 1);
    }

    printf("\nTesting removing from tail:\n");
    for (int i = 4; i > -1; --i)
    {
        display_list(testList);
        testList = delete_from_tail(testList);
        assert(getsize(testList) == i);
        // If list is not empty, assert that accessing the just removed element
        // will wrap around to the list head
        if (testList != NULL)
        {
            assert(get(testList, i) == testList->value);
        }
        else
        {
            // If the list is empty, assert that the elements were removed after
            // the correct number of iterations
            assert(i == 0);
        }
    }
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main()
{
    test();  // run self-test implementations
    return 0;
}
