/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 * 
 * Algorithm merges pairwise lists by divide and conquer.
 * Space complexity O(n * k), time complexity O(k * n * log(k)), where n - average size of list and k - number of lists.
 */
struct ListNode *merge_two(struct ListNode *ln1, struct ListNode *ln2) {
    struct ListNode *head, *node;
    if (ln1 == NULL) {
        return ln2;
    } else if (ln2 == NULL) {
        return ln1;
    }
    if (ln1->val < ln2->val) {
        head = ln1;
        ln1 = ln1->next;
    } else {
        head = ln2;
        ln2 = ln2->next;
    }
    node = head;
    while (ln1 != NULL && ln2 != NULL) {
        if (ln1->val < ln2->val) {
            node->next = ln1;
            ln1 = ln1->next;
        } else {
            node->next = ln2;
            ln2 = ln2->next;
        }
        node = node->next;
    }
    if (ln1 != NULL) {
        node->next = ln1;
    } else {
        node->next = ln2;
    }
    return head;
}

struct ListNode *mergeKLists(struct ListNode** lists, int lists_size) {
    if (lists_size == 0) {
        return NULL;
    }
    struct ListNode **ml, *head;
    int i, is_odd, sz = lists_size;
    ml = malloc(sizeof(struct ListNode*) * lists_size);
    for (i = 0; i < lists_size; i++) {
        ml[i] = lists[i];
    }
    while(sz > 1) {
        is_odd = 0;
        for (i = 0; i < sz; i += 2) {
            if (i == sz - 1) {
                ml[i/2] = ml[i];
                is_odd = 1;
            } else {
                ml[i/2] = merge_two(ml[i], ml[i + 1]);
            }
        }
        sz = sz / 2 + is_odd;
    }
	head = ml[0];
	free(ml);
    return head;
}
