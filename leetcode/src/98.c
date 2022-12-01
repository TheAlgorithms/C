/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// Depth first search approach.
// Runtime: O(n)
// Space: O(1)
bool checkIsBst(struct TreeNode* node, bool leftBoundInf, int leftBound, bool rightBoundInf, int rightBound){
    return 
        (node == NULL)
        || (leftBoundInf || node->val > leftBound)
        && (rightBoundInf || node->val < rightBound)
        && checkIsBst(node->left, leftBoundInf, leftBound, false, node->val)
        && checkIsBst(node->right, false, node->val, rightBoundInf, rightBound);
}

bool isValidBST(struct TreeNode* root){
    return checkIsBst(root, true, INT_MIN, true, INT_MAX);
}
