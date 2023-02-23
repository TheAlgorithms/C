/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
    struct ListNode *p_free, *p = head;
    int i, sz = 0;
    while (p != NULL) {
        p = p->next;
        sz++;
    }
    if (n == sz) {
        p_free = head;
        p = head->next;
        free(p_free);
        return p;
    }
    for (i = 0, p = head; i < sz - n - 1; i++, p = p -> next)
    ;
    p_free = p->next;
    if (n != 1) {
        p->next = p->next->next;
    } else {
        p->next = NULL;
    }
    free(p_free);
    return head;
}
