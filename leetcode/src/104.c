/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxval(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}
int maxDepth(struct TreeNode* root){
    if (root == NULL)
        return 0;
    else
        return 1 + maxval(maxDepth(root->left), maxDepth(root->right));
}

