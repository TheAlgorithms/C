struct TreeNode *buildBST(struct ListNode *head, struct ListNode *tail)
{
    if (head == tail)
        return NULL;
    struct ListNode *slow = head, *fast = head;
    while (fast != tail && fast->next != tail)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->val = slow->val;
    node->left = buildBST(head, slow);
    node->right = buildBST(slow->next, tail);
    return node;
}
struct TreeNode *sortedListToBST(struct ListNode *head)
{
    if (!head)
        return NULL;
    else
        return buildBST(head, NULL);
}
