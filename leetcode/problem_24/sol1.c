/**
 * \file
 * \brief [24. Swap Nodes in
 * Pairs](https://leetcode.com/problems/swap-nodes-in-pairs/) solution
 * \details
 * Given a linked list, swap every two adjacent nodes and return its head.
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
 * @brief Recursive implementation
 *
 * @param head input linked list
 * @return pair-swapped list
 */
struct ListNode *swapPairs(struct ListNode *head)
{
    if (!head || !head->next)
        return head;
    struct ListNode *tmp = head->next;
    head->next = swapPairs(head->next->next);
    tmp->next = head;
    return tmp;
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
}

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
    unsigned char num1[] = {1, 2, 3, 4};
    struct ListNode *l1 = list_from_array(num1, 4);
    struct ListNode *test1 = swapPairs(l1);
    printf("Test 1: <%s>\n", print_list(test1));

    unsigned char num2[] = {1};
    struct ListNode *l2 = list_from_array(num2, 1);
    struct ListNode *test2 = swapPairs(l2);
    printf("Test 2: <%s>\n", print_list(test2));

    free_list(l1);
    free_list(l2);

    return 0;
}
