int rangeSumBST(struct TreeNode *root, int L, int R)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root->val >= L && root->val <= R)
    {
        return root->val + rangeSumBST(root->left, L, R) +
               rangeSumBST(root->right, L, R);
    }
    else
    {
        return rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
    }
}
