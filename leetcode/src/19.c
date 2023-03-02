/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
    struct ListNode entry, *p_free, *p = head;
    int i, sz = 0;
    entry.next = head;
    while (p != NULL) {
        p = p->next;
        sz++;
    }
    for (i = 0, p = &entry; i < sz - n; i++, p = p -> next)
    ;
    p_free = p->next;
    if (n != 1) {
        p->next = p->next->next;
    } else {
        p->next = NULL;
    }
    free(p_free);
    return entry.next;
}
