struct ListNode *getIntersectionNode(struct ListNode *headA,
                                     struct ListNode *headB)
{
    struct ListNode *cur1 = headA, *cur2 = headB;
    if (cur1 == NULL || cur2 == NULL)
        return NULL;
    while (cur1 && cur2 && cur1 != cur2)
    {
        cur1 = cur1->next;
        cur2 = cur2->next;
        if (cur1 == cur2)
            return cur1;
        if (!cur1)
            cur1 = headB;
        if (!cur2)
            cur2 = headA;
    }
    return cur1;
}
