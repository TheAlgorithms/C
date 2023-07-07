class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if( root->val ==1)return true;
        if( root->val ==0)return false;
        if (root->val ==2)return evaluateTree(root->left) or evaluateTree(root->right);
        if(root->val ==3)return evaluateTree(root->left) and evaluateTree (root->right);
        return true;
    }
};
