/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* bstFromPreorder(int* preorder, int preorderSize)
{
    struct TreeNode* new;
    int left_ptr;

    new = malloc(sizeof(struct TreeNode));
    new->val = preorder[0];

    if (preorderSize == 1)
    {
        new->right = NULL;
        new->left = NULL;
        return new;
    }

    left_ptr = 1;
    while ((left_ptr < preorderSize) && (preorder[left_ptr] < preorder[0]))
        left_ptr++;
    if (left_ptr == 1)
        new->left = NULL;
    else
        new->left = bstFromPreorder(preorder + 1, left_ptr - 1);
    if (left_ptr < preorderSize)
        new->right =
            bstFromPreorder(preorder + left_ptr, preorderSize - left_ptr);
    else
        new->right = NULL;

    return new;
}
