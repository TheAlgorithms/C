/**
 * Given the head of a linked list, rotate the list to the right by k places.
 *
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k){
    struct ListNode *ptr = NULL, *prev =NULL;
    ptr = head;
    int count = 0;
    while(ptr){
        ptr = ptr->next;
        count++;
    }
    if(count!=0)
        k = k%count;
    while(k--)
    {
        ptr = head;
        if(ptr==NULL)
            return;
        if(ptr->next==NULL)
            return ptr;
        while(ptr->next)
        {
            prev = ptr;
            ptr = ptr->next;
        }
        ptr->next = head;
        head = ptr;
        prev->next = NULL;
    }
    return head;
}