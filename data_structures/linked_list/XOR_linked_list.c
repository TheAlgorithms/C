#include <assert.h> /// to verify assumptions made by the program and print a diagnostic message if this assumption is false.
#include <inttypes.h> /// to provide a set of integer types with universally consistent definitions that are operating system-independent
#include <stdio.h> /// for IO operations
#include <stdlib.h> /// for including functions involving memory allocation such as `malloc`
#include <stdint.h> /// to ensure that the integer types such as uintptr_t are properly defined.

/**
 * @file
 *
 * @brief
 * [XOR List](https://en.wikipedia.org/wiki/XOR_linked_list) combines the properties of a 
 * circular doubly linked list and XOR pointers to save memory and enhance performance. 
 * Each node contains an XOR of the addresses of the previous and next nodes.
 *
 * In this implementation, functions to insert at the head, delete the first node, display list, get
 * list size, and get element at index functions are coded.
 *
 * @author [Sahil Kandhare](https://github.com/SahilK-027)
 */

/**
 * @brief XOR List Node struct
 */
typedef struct node
{
    uintptr_t both; ///< XOR of prev and next pointers
    uint64_t value; ///< Data stored in the node
} XORListNode;

/**
 * @brief Create an XOR list node
 * @param data the data that the node initializes with
 * @return XORListNode* pointer to the newly created XOR list node
 */
XORListNode *create_node(uint64_t data)
{
    XORListNode *new_node = (XORListNode *)malloc(sizeof(XORListNode));
    new_node->value = data;
    new_node->both = 0;
    return new_node;
}

/**
 * @brief Insert a node at the head of the XOR list
 * @param head start pointer of the list
 * @param data the data that the new node initializes with
 * @return XORListNode* pointer to the newly created list node inserted at the head
 */
XORListNode *insert_at_head(XORListNode *head, uint64_t data)
{
    XORListNode *new_node = create_node(data);
    new_node->both = (uintptr_t)head;

    if (head != NULL)
    {
        head->both = (uintptr_t)new_node ^ (head->both);
    }

    return new_node;
}

/**
 * @brief Function for deletion of the first node in the XOR list
 * @param head start pointer of the list
 * @return XORListNode* pointer to the list node after deleting the first node
 */
XORListNode *delete_from_head(XORListNode *head)
{
    if (head == NULL)
    {
        printf("The list is empty\n");
        return head;
    }

    XORListNode *next = NULL;
    XORListNode *new_head = NULL;

    if (head->both != 0)
    {
        next = (XORListNode *)head->both;
        next->both = (uintptr_t)((uintptr_t)next->both ^ (uintptr_t)head);
    }

    if (next != NULL)
    {
        new_head = next;
    }

    free(head);
    return new_head;
}

/**
 * @brief Get the size of the XOR list
 * @param head start pointer of the list
 * @return int size of the list
 */
int get_size(XORListNode *head)
{
    int size = 0;
    XORListNode *prev = NULL;
    XORListNode *curr = head;
    XORListNode *next = NULL;

    while (curr != NULL)
    {
        size++;
        if (curr->both == 0)
        {
            break;
        }
        next = (XORListNode *)((uintptr_t)prev ^ curr->both);
        prev = curr;
        curr = next;
    }

    return size;
}

/**
 * @brief Display XOR list
 * @param head start pointer of the list
 */
void display_list(XORListNode *head)
{
    printf("\nContents of your XOR linked list: ");
    XORListNode *prev = NULL;
    XORListNode *curr = head;
    XORListNode *next = NULL;

    while (curr != NULL)
    {
        printf("%" PRIu64 " ", curr->value);
        if (curr->both == 0)
        {
            break;
        }
        next = (XORListNode *)((uintptr_t)prev ^ curr->both);
        prev = curr;
        curr = next;
    }

    printf("\n");
}

/**
 * @brief access the list by index
 * @param list pointer to the target list
 * @param index access location
 * @returns the value at the specified index,
 *          wrapping around if the index is larger than the size of the target list
 */
uint64_t get(XORListNode *list, const int index)
{
    if (list == NULL || index < 0)
    {
        exit(EXIT_FAILURE);
    }

    XORListNode *prev = NULL;
    XORListNode *curr = list;
    XORListNode *next = NULL;

    for (int i = 0; i < index; ++i)
    {
        if (curr == NULL)
        {
            exit(EXIT_FAILURE);
        }
        next = (XORListNode *)((uintptr_t)prev ^ curr->both);
        prev = curr;
        curr = next;
    }

    if (curr == NULL)
    {
        // Wrap around to the head if the index is larger than the list size
        return get(list, index % get_size(list));
    }

    return curr->value;
}

/**
 * @brief Self-test implementations
 */
static void test()
{
    XORListNode *test_list = NULL;
    unsigned int array[] = {2, 3, 4, 5, 6};

    assert(get_size(test_list) == 0);

    printf("Testing inserting elements at the head:\n");
    for (int i = 0; i < 5; ++i)
    {
        test_list = insert_at_head(test_list, array[i]);
        assert(get(test_list, 0) == array[i]); // Check the head value
        display_list(test_list);
        assert(get_size(test_list) == i + 1);
    }

    printf("\nTesting removing elements from the head:\n");
    for (int i = 4; i >= 0; --i)
    {
        assert(get(test_list, 0) == array[i]); // Check the head value before removal
        display_list(test_list);
        test_list = delete_from_head(test_list);
        assert(get_size(test_list) == i);
    }
}

/**
 * @brief Main function
 * @return 0 on exit
 */
int main()
{
    test(); // run self-test implementations
    return 0;
}
