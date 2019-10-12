struct TreeNode * newNode (int item) {
    struct TreeNode *node =  (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = item;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2){
    if (t1 == NULL && t2 == NULL)
        return NULL;
    int item = (t1 == NULL ? 0 : t1->val) + (t2 == NULL ? 0 : t2->val);
    struct TreeNode *node = newNode(item);
    node->left = mergeTrees(t1 == NULL ? NULL : t1->left, t2 == NULL ? NULL : t2->left);
    node->right = mergeTrees(t1 == NULL ? NULL : t1->right, t2 == NULL ? NULL : t2->right);
    return node;
}
