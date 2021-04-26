struct TreeNode *insertIntoBST(struct TreeNode *root, int val)
{
    if (root == NULL)
    {
        struct TreeNode *new_val = malloc(sizeof(struct TreeNode));
        new_val->val = val;
        new_val->left = new_val->right = NULL;
        return new_val;
    }
    else
    {
        if (root->val >= val)
            root->left = insertIntoBST(root->left, val);
        else
            root->right = insertIntoBST(root->right, val);
    }
    return root;
}
