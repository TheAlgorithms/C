/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))

void recursiveSolve(struct TreeNode* node, int* result, int minVal, int maxVal){
    if (node == NULL){
        return;
    }

    *result = max(*result, abs(minVal - node->val));
    *result = max(*result, abs(maxVal - node->val));

    minVal = min(minVal, node->val);
    maxVal = max(maxVal, node->val);

    recursiveSolve(node->left, result, minVal, maxVal);
    recursiveSolve(node->right, result, minVal, maxVal);
}

// Depth First Search
// If The maximum diff is exists it should be the difference of the MAX or MIN value in the tree path to the LEAF
// Runtime: O(n)
// Space: O(1)
int maxAncestorDiff(struct TreeNode* root){
    int result = 0;
    int maxVal = root->val;
    int minVal = root->val;
    recursiveSolve(root, &result, minVal, maxVal);
    return result;
}
