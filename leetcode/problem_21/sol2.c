/**
 * \file
 * \brief [21. Merge Two Sorted
 * Lists](https://leetcode.com/problems/merge-two-sorted-lists/) solution
 * (Recursive method)
 * \details Merge two sorted linked lists and return it as a
 * new sorted list. The new list should be made by splicing together the nodes
 * of the first two lists.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Definition for singly-linked list.
 */
struct ListNode
{
    int val;               /**< value at node */
    struct ListNode *next; /**< pointer to next node in the list */
};

/**
 * @brief Resursive implementation.
 *
 * @param l1 pointer to the root of first list
 * @param l2 pointer to the root of second list
 * @return merged list
 */
struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;
    if (l1->val < l2->val)
    {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

/**
 * @brief Function to free dynamically allocated list
 *
 * @param node pointer to head of the list
 */
void free_list(struct ListNode *node)
{
    if (node->next != NULL)
        free_list(node->next);

    free(node);
    node = NULL;
};

/**
 * @brief Generate a node list from an array of digits
 *
 * @param num array of digits. index of units place is '0'
 * @param num_digits total number of digits
 * @return pointer to the node containing the units place of the number
 */
struct ListNode *list_from_array(const unsigned char num[],
                                 unsigned int num_digits)
{
    struct ListNode *prev_node = NULL;
    struct ListNode *root_node = NULL;

    for (unsigned int i = 0; i < num_digits; i++)
    {
        struct ListNode *node = malloc(sizeof(struct ListNode));
        node->val = num[i];
        node->next = NULL;
        if (!prev_node)
        {
            prev_node = node;
            root_node = node;
        }
        else
        {
            prev_node->next = node;
            prev_node = node;
        }
    }

    return root_node;
}

/**
 * @brief Support function to print the list of digits
 *
 * @param node pointer to units digit
 * @return string representation of the digits with units place to he left
 */
const char *print_list(const struct ListNode *node)
{
    static char out_str[256];
    memset(out_str, '\0', 256);
    const struct ListNode *ptr = node;
    while (ptr)
    {
        if (ptr == node)
            snprintf(out_str, 256, "%d", ptr->val);
        else
            snprintf(out_str, 256, "%s, %d", out_str, ptr->val);
        ptr = ptr->next;
    }

    return out_str;
}

/**
 * @brief Main function
 * @return 0
 */
int main()
{
    unsigned char num1[] = {1, 2, 4};
    struct ListNode *l1 = list_from_array(num1, 3);
    unsigned char num2[] = {1, 3, 4};
    struct ListNode *l2 = list_from_array(num2, 3);
    struct ListNode *test1 = mergeTwoLists(l1, l2);
    assert(test1->val == 1 && test1->next->val == 1 &&
           test1->next->next->val == 2 && test1->next->next->next->val == 3 &&
           test1->next->next->next->next->val == 4 &&
           test1->next->next->next->next->next->val == 4);

    free_list(test1);

    return 0;
}
