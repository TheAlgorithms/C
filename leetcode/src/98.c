bool solve(struct TreeNode* root, long long int low, long long int high)
{
    if (root == NULL)
    {
        return 1;
    }
    else if (low <= root->val && root->val <= high)
    {
        bool isBST_left = solve(root->left, low, root->val - 1ll);
        bool isBST_right = solve(root->right, root->val + 1ll, high);

        return (isBST_left && isBST_right);
    }
    else
    {
        return 0;
    }
}

bool isValidBST(struct TreeNode* root)
{
    return solve(root, INT64_MIN, INT64_MAX);
}

