/*
 * Deletes a node with the given key from a Binary Search Tree (BST).
 * Handles three cases: deleting a leaf node, a node with one child,
 * and a node with two children (replaced by its in-order successor).
 */

struct TreeNode* deleteNode(struct TreeNode* root, int key)
{
    if (root == NULL)
        return NULL;

    if (key < root->val)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->val)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            return NULL;
        }
        else if (root->left == NULL)
        {
            return root->right;
        }
        else if (root->right == NULL)
        {
            return root->left;
        }
        else
        {
            struct TreeNode* min_node = root->right;
            while (min_node->left != NULL) min_node = min_node->left;

            root->val = min_node->val;
            root->right = deleteNode(root->right, min_node->val);
        }
    }
    return root;
}
