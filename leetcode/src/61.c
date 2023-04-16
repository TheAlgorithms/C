/**
* Given the head of a linked list, rotate the list to the right by k places.
*
* This code takes a singly-linked list head and an integer k as input and rotates the list to the right by k positions.
* The function returns a pointer to the new head of the rotated list.

* The first while loop iterates over the linked list to count the number of nodes. This loop takes O(n) time
* The next if statement takes O(1) time.
* The second while loop rotates the linked list by k positions. The loop runs k times and performs a constant amount of work in each iteration, including traversing the linked list to find the last node, setting the new head, and updating the pointers. The loop takes O(k) time.
* Time complexity of the code is O(n * k) in worst case.
*
* The code uses only a constant amount of extra memory, regardless of the size of the input. Therefore, the space complexity of the code is O(1).

* Definition for singly-linked list.
* struct ListNode {
* int val;
* struct ListNode *next;
* };
*/

struct ListNode* rotateRight(struct ListNode* head, int k) {

    struct ListNode *ptr = head, *prev =NULL;
    int count = 0;

    while(ptr) {
        ptr = ptr->next;
        count++;
    }
    if(count!=0)
        k = k%count;
    while(k--) {
        ptr = head;
        if(ptr==NULL)
            return NULL;
        if(ptr->next==NULL)
            return ptr;
        while(ptr->next) {
            prev = ptr;
            ptr = ptr->next;
        }
        ptr->next = head;
        head = ptr;
        prev->next = NULL;
    }
    return head;

}
