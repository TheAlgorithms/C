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
 * In this implementation, the menu-driven code is written along with functions
 * to insert at the head, insert at the last index, delete the first node,
 * delete the last node, and display list functions are coded.
 *
 * @author [Sahil Kandhare](https://github.com/SahilK-027)
 *
 */

#include <inttypes.h>  /// to provide a set of integer types with universally consistent definitions that are operating system-independent
#include <stdio.h>     /// for IO operations
#include <stdlib.h>  /// for including functions involving memory allocation such as `malloc`

/**
 * @brief Circular Doubly linked list struct
 *
 */
typedef struct node
{
    struct node *prev, *next;  ///< List pointers
    uint64_t value;            ///< Data stored on each node
} ListNode;

/**
 * @brief Create a list node
 *
 * @param data
 * @return ListNode*  newly created list node
 */
ListNode *create_list(uint64_t data)
{
    ListNode *new_list = (ListNode *)malloc(sizeof(ListNode));
    new_list->value = data;
    new_list->next = new_list;
    new_list->prev = new_list;
    return new_list;
}

/**
 * @brief Insert the node at start of list
 *
 * @param head   starting pointer of list
 * @param data   The data which we want to insert into list
 * @return ListNode*
 */
ListNode *insert_at_head(ListNode *head, uint64_t data)
{
    if (head == NULL)
    {
        head = create_list(data);
        return head;
    }
    else
    {
        ListNode *temp;
        ListNode *new_node = create_list(data);
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
 * @brief Insert the node at end of list
 *
 * @param head      starting pointer of list
 * @param data      The data which we want to insert into list
 * @return ListNode*
 */
ListNode *insert_at_last(ListNode *head, uint64_t data)
{
    if (head == NULL)
    {
        head = create_list(data);
        return head;
    }
    else
    {
        ListNode *temp1, *temp2;
        ListNode *new_node = create_list(data);
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
 * @param head      starting pointer of list
 * @return ListNode*
 */
ListNode *delete_first_node(ListNode *head)
{
    if (head == NULL)
    {
        printf("list is Empty\n");
        return head;
    }
    ListNode *temp1, *temp2;
    temp1 = head;
    temp2 = temp1->prev;
    if (temp1 == temp2)
    {
        free(temp2);
        head = NULL;
        printf("\nNode succesfully deleted\n\n");
        return head;
    }
    temp2->next = temp1->next;
    (temp1->next)->prev = temp2;
    head = temp1->next;
    free(temp1);
    temp1 = NULL;
    printf("\nNode succesfully deleted\n\n");
    return head;
}

/**
 * @brief Function for deletion of the last node in list
 *
 * @param head      starting pointer of list
 * @return ListNode*
 */
ListNode *delete_last_node(ListNode *head)
{
    if (head == NULL)
    {
        printf("list is Empty\n");
        return head;
    }

    ListNode *temp1, *temp2;
    temp1 = head;
    temp2 = temp1->prev;
    if (temp1 == temp2)
    {
        free(temp2);
        head = NULL;
        printf("\nNode succesfully deleted\n\n");
        return head;
    }
    (temp2->prev)->next = temp1;
    temp1->prev = temp2->prev;
    free(temp2);
    temp2 = NULL;
    printf("\nNode succesfully deleted\n\n");
    return head;
}

/**
 * @brief The function to reverse the linked list
 *
 * @param head      starting pointer of list
 * @return ListNode*
 */
ListNode *reverseLL(ListNode *head)
{
    if (!head)
        return NULL;

    ListNode *new_head = NULL;
    ListNode *last = head->prev;
    ListNode *curr = last, *prev;

    // traverse list in backward direction
    while (curr->prev != last)
    {
        prev = curr->prev;
        new_head = insert_at_last(new_head, curr->value);
        curr = prev;
    }
    new_head = insert_at_last(new_head, curr->value);

    return new_head;
}

/**
 * @brief The function that will return current size of list
 *
 * @param head      starting pointer of list
 * @return int      size of list
 */
int getsize(ListNode *head)
{
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
 * @param   head   starting pointer of list
 * @returns void
 */

void display(ListNode *head)
{
    printf("\nIts Your Linked-list\n\n");
    ListNode *temp;
    temp = head;
    if (head != NULL)
    {
        while (temp->next != head)
        {
            printf("%lld -> ", temp->value);
            temp = temp->next;
        }
        if (temp->next == head)
        {
            printf("%lld", temp->value);
        }
    }
    else
    {
        printf("list is Empty\n");
    }
    printf("\n");
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main()
{
    // Creating an empty list
    ListNode *head = NULL;
    // Flg to stop loop and value to insert
    int flag = 1;
    uint64_t value = 0;
    while (flag == 1)
    {
        int ch;
        printf("\nWhat do you want to perform?\n");
        printf(
            "ENTER YOUR CHOICE\n1. Insert At head\n2. Insert At End\n3. "
            "Delete First node \n4. Delete Last Node \n5. Reverse List\n6. Get "
            "List size\n7. Display List"
            "\n8. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the data: ");
            scanf("%lld", &value);
            head = insert_at_head(head, value);
            break;
        case 2:
            printf("Enter the data: ");
            scanf("%lld", &value);
            head = insert_at_last(head, value);
            break;
        case 3:
            head = delete_first_node(head);
            break;

        case 4:
            head = delete_last_node(head);
            break;

        case 5:
            head = reverseLL(head);
            printf("\nList succesfully reversed\n\n");
            break;

        case 6:
            printf("\nSize of list is %d\n\n", getsize(head));
            break;

        case 7:
            display(head);
            break;

        case 8:
            flag = 0;
            break;

        default:
            printf("\nIncorrect choice. Re-Enter values.\n\n");
        }
    }
    return 0;
}
