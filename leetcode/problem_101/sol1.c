/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool checkSymmetric(struct TreeNode *left, struct TreeNode *right)
{
    if (!left || !right)
        return left == right;
    if (left->val != right->val)
        return 0;
    return checkSymmetric(left->left, right->right) &&
           checkSymmetric(left->right, right->left);
}

bool isSymmetric(struct TreeNode *root)
{
    return root == NULL || checkSymmetric(root->left, root->right);
}
