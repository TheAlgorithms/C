/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int rangeSumBST(struct TreeNode* root, int low, int high){
    if (root == NULL){
        return 0;
    }

    int result = 0;
    if (root->val >= low && root->val <= high){
        result += root->val; 
    }

    result += rangeSumBST(root->left, low, high);
    result += rangeSumBST(root->right, low, high);

    return result;
}
