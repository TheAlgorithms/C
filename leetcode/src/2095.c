/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* deleteMiddle(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    struct ListNode *fast, *slow, *prev;
    int n = 0;
    fast = head;
    slow = head;
    while (fast != NULL)
    {
        n = n + 1;
        fast = fast->next;
    }
    fast = head;
    while (fast->next != NULL && fast->next->next != NULL)  // finds mid node
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (n % 2 == 0)
    {
        prev = slow;
        slow = slow->next;
        prev->next = slow->next;
    }
    else
        prev->next = slow->next;
    return head;
}
