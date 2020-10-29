bool isleaf(struct TreeNode *root)
{
    return root->left == NULL && root->right == NULL;
}

int sumOfLeftLeaves(struct TreeNode *root)
{
    if (root == NULL)
        return 0;
    if (root->left)
    {
        if (isleaf(root->left))
            return root->left->val + sumOfLeftLeaves(root->right);
    }
    return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}
