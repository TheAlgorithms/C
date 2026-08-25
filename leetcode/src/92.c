/*
 * 92. Reverse Linked List II
 * https://leetcode.com/problems/reverse-linked-list-ii/
 *
 * Given the head of a singly linked list and two integers left
 * and right where left <= right, reverse the nodes of the list
 * from position left to position right (1-indexed), and return
 * the reversed list.
 *
 * Approach: use a dummy node before head to simplify edge cases
 * (e.g. left == 1). Walk to the node just before position `left`,
 * then reverse the next (right - left + 1) nodes in place using
 * the same prev/curr pointer technique as a full list reversal,
 * finally reconnecting the reversed segment to the rest of the list.
 * Time: O(n), Space: O(1)
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *reverseBetween(struct ListNode *head, int left, int right) {
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode *before = &dummy;
    for (int i = 1; i < left; i++) {
        before = before->next;
    }

    struct ListNode *curr = before->next;
    struct ListNode *prev = NULL;

    for (int i = 0; i <= right - left; i++) {
        struct ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    before->next->next = curr;
    before->next = prev;

    return dummy.next;
}