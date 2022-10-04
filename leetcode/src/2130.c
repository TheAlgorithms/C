/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int pairSum(struct ListNode* head)
{
    struct ListNode* dup = head;
    int count = 0, i = 0, max = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    int* arr = malloc(count * sizeof(int));
    while (dup != NULL)
    {
        arr[i++] = dup->val;
        dup = dup->next;
    }
    for (i = 0; i < count / 2; ++i)
    {
        if (arr[i] + arr[count - i - 1] > max)
            max = arr[i] + arr[count - i - 1];
    }
    return max;
}
