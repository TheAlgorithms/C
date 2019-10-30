/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *res = NULL;
    while(head) {
        struct ListNode *pre_node = head;
        head = head -> next;
        pre_node -> next = res;
        res = pre_node;
    }
    return res;
}
