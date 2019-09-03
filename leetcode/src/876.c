/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    struct ListNode *fast, *slow;
    fast = slow = head;
    while(fast && fast->next) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

