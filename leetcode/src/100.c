/**
 * LeetCode Problem 100 - Same Tree
 * Check if two binary trees are the same.
 *
 * Two binary trees are the same if they are structurally identical and the nodes have the same value.
 */

/**
 * Definition for a binary tree node:
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) {
        return true;
    }
    if (p == NULL || q == NULL) {
        return false;
    }
    return (p->val == q->val) &&
           isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
}
