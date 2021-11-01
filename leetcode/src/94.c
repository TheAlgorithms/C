void processTraversal(struct TreeNode *root, int *res, int *size)
{
    if (!root)
        return;
    processTraversal(root->left, res, size);
    res[*size] = root->val;
    *size = *size + 1;
    processTraversal(root->right, res, size);
}

int *inorderTraversal(struct TreeNode *root, int *returnSize)
{
    int *res = malloc(256 * sizeof(int));
    *returnSize = 0;
    processTraversal(root, res, returnSize);
    return res;
}
