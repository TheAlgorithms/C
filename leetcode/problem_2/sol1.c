/**
 * \file
 * \brief [2. Add two numbers](https://leetcode.com/problems/add-two-numbers/)
 * solution \details You are given two non-empty linked lists representing two
 * non-negative integers. The digits are stored in reverse order, and each of
 * their nodes contains a single digit. Add the two numbers and return the sum
 * as a linked list.
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
 * @brief Solution implementation
 *
 * @param l1 first number with digits represented as linked list
 * @param l2 second number with digits represented as linked list
 * @return resulting number with digits represented as linked list
 */
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *head = NULL;
    struct ListNode *walk = NULL;
    struct ListNode *tmp = NULL;

    int carry = 0;
    int val1 = 0;
    int val2 = 0;
    int val = 0;

    while (l1 != NULL || l2 != NULL || carry)
    {
        val1 = 0;
        val2 = 0;
        val = 0;

        if (l1)
        {
            val1 = l1->val;
            l1 = l1->next;
        }

        if (l2)
        {
            val2 = l2->val;
            l2 = l2->next;
        }

        val = carry + val1 + val2;
        carry = val / 10;

        tmp = malloc(sizeof(struct ListNode));
        tmp->val = val % 10;
        tmp->next = NULL;

        if (!head)
        {
            head = walk = tmp;
        }
        else
        {
            walk->next = tmp;
            walk = walk->next;
        }
    }

    return head;
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
    unsigned char num1[] = {2, 4, 3};
    struct ListNode *l1 = list_from_array(num1, 3);
    unsigned char num2[] = {5, 6, 4};
    struct ListNode *l2 = list_from_array(num2, 3);
    struct ListNode *out1 = addTwoNumbers(l1, l2);

    printf("<%s> + ", print_list(l1));
    printf("<%s> = ", print_list(l2));
    printf("<%s>\n", print_list(out1));
    assert(out1->val == 7 && out1->next->val == 0 &&
           out1->next->next->val == 8);
    printf("Test 1 passed.\n");

    free_list(l1);
    free_list(l2);
    free_list(out1);

    return 0;
}
