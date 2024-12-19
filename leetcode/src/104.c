/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxDepth(struct TreeNode *root)
{
    if (root == NULL)
        return 0;
    else {
        // return 1 + maxval(maxDepth(root->left), maxDepth(root->right));
        int leftDepth = maxDepth(root -> left);
        int rightDepth = maxDepth(root -> right);

        return leftDepth > rightDepth ? 1 + leftDepth : 1 + rightDepth;
    }
}
