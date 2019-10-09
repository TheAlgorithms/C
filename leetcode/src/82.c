struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL)
        return NULL;

    if (head->next && head->val == head->next->val) {
        /* Remove all duplicate numbers */
        while (head->next && head->val == head->next->val) {
            head = head -> next;
        }
        return deleteDuplicates(head->next);
    } else {
        head->next = deleteDuplicates(head->next);
    }
    return head;
}
