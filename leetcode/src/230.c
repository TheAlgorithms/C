/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* findKthSmallest(struct TreeNode* node, int* k){
    if (node == NULL){
        return NULL;
    }
    
    struct TreeNode* resultNode = findKthSmallest(node->left, k);
    
    if (resultNode != NULL){
        return resultNode;
    }
    
    *k -= 1;

    if (*k == 0){
        return node;
    }
    
    return findKthSmallest(node->right, k);
}

// Depth-First Search
// Runtime: O(n)
// Space: O(1)
int kthSmallest(struct TreeNode* root, int k){
    return findKthSmallest(root, &k)->val;
}
