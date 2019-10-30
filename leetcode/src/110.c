int max(int a, int b) {
    return a >= b ? a : b;
}

int height(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    else
        return 1 + max(height(root->left), height(root->right));
}

bool isBalanced(struct TreeNode* root){
    if (root == NULL)
        return 1;
    int left = height(root->left);
    int right = height(root->right);
    return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

