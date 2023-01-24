/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define max(a,b) (((a)>(b))?(a):(b))

int recursiveSolve(struct TreeNode* node, int* result){
    if (node == NULL){
        return 0;
    }

    int leftSum = max(recursiveSolve(node->left, result), 0);
    int rightSum = max(recursiveSolve(node->right, result), 0);

    // Check if it's possible to make a maximum path from left right and current node
    int maxValueNode = node->val + leftSum + rightSum;
    *result = max(maxValueNode, *result);

    // Choose the max sum val path 
    return node->val + max(leftSum, rightSum);
}

// Depth First Search
// Runtime: O(n), n - the number of nodes in tree.
// Space: O(1)
int maxPathSum(struct TreeNode* root){
    const int LOWER_BOUND = -2147483648
    int result = LOWER_BOUND;
    recursiveSolve(root, &result);
    return result;
}
