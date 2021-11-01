struct ListNode *detectCycle(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    struct ListNode *slow, *fast;
    slow = fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            struct ListNode *entry = head;
            while (slow != entry)
            {
                slow = slow->next;
                entry = entry->next;
            }
            return entry;
        }
    }
    return NULL;
}
