/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head = NULL;
    struct ListNode *walk = NULL;
    struct ListNode *tmp = NULL;

    int carry = 0;
    int val1 = 0;
    int val2 = 0;
    int val = 0;

    while(l1 != NULL || l2 != NULL || carry) {
            val1 = 0;
            val2 = 0;
            val = 0;

            if(l1) {
                val1 = l1->val;
                l1 = l1->next;
            }

            if(l2) {
                val2 = l2->val;
                l2 = l2->next;
            }

            val = carry + val1 + val2;
            carry = val / 10;

            tmp = malloc(sizeof(struct ListNode));
            tmp->val = val % 10;
            tmp->next = NULL;

            if(!head) {
                head = walk = tmp;
            } else {
                walk->next = tmp;
                walk = walk->next;
            }
        }

        return head;
}

