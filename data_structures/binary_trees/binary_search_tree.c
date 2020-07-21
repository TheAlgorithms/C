/**
 * @file
 * @brief A basic unbalanced binary search tree implementation in C.
 * @details The implementation has the following functionalities implemented:
 * - Insertion
 * - Deletion
 * - Search by key value
 * - Listing of node keys in order of value (from left to right)
 */
#include <stdio.h>
#include <stdlib.h>

/** Node, the basic data structure in the tree */
typedef struct node
{
    struct node *left;  /**< left child */
    struct node *right; /**< right child */
    int data;           /**< data of the node */
} node;

/** The node constructor, which receives the key value input and returns a node
 * pointer
 * @param data data to store in a new node
 * @returns new node with the provided data
 * @note the node must be deleted before program terminates to avoid memory
 * leaks
 */
node *newNode(int data)
{
    // creates a slug
    node *tmp = (node *)malloc(sizeof(node));

    // initializes the slug
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;

    return tmp;
}

/** Insertion procedure, which inserts the input key in a new node in the tree
 * @param root pointer to parent node
 * @param data value to store int he new node
 * @returns pointer to parent node
 */
node *insert(node *root, int data)
{
    // If the root of the subtree is null, insert key here
    if (root == NULL)
    {
        root = newNode(data);
    }
    else if (data > root->data)
    {
        // If it isn't null and the input key is greater than the root key,
        // insert in the right leaf
        root->right = insert(root->right, data);
    }
    else if (data < root->data)
    {  // If it isn't null and the input key is lower than the root key, insert
       // in the left leaf
        root->left = insert(root->left, data);
    }
    // Returns the modified tree
    return root;
}

/** Utilitary procedure to find the greatest key in the left subtree
 * @param root pointer to parent node
 * @returns pointer to parent node
 */
node *getMax(node *root)
{
    // If there's no leaf to the right, then this is the maximum key value
    if (root->right != NULL)
    {
        return getMax(root->right);
    }
    return root;
}

/** Deletion procedure, which searches for the input key in the tree and removes
 * it if present
 * @param root pointer to parent node
 * @param data value to search for int the node
 * @returns pointer to parent node
 */
node *delete (node *root, int data)
{
    // If the root is null, nothing to be done
    if (root == NULL)
    {
        return root;
    }
    else if (data > root->data)
    {  // If the input key is greater than the root's, search in the right
        // subtree
        root->right = delete (root->right, data);
    }
    else if (data < root->data)
    {  // If the input key is lower than the root's, search in the left subtree
        root->left = delete (root->left, data);
    }
    else if (data == root->data)
    {
        // If the input key matches the root's, check the following cases
        // termination condition
        if ((root->left == NULL) && (root->right == NULL))
        {  // Case 1: the root has no leaves, remove the node
            free(root);
            return NULL;
        }
        else if (root->left == NULL)
        {  // Case 2: the root has one leaf, make the leaf the new root and
            // remove
            // the old root
            node *tmp = root;
            root = root->right;
            free(tmp);
            return root;
        }
        else if (root->right == NULL)
        {
            node *tmp = root;
            root = root->left;
            free(tmp);
            return root;
        }
        else
        {  // Case 3: the root has 2 leaves, find the greatest key in the left
            // subtree and switch with the root's

            // finds the biggest node in the left branch.
            node *tmp = getMax(root->left);

            // sets the data of this node equal to the data of the biggest node
            // (lefts)
            root->data = tmp->data;
            root->left = delete (root->left, tmp->data);
        }
    }
    return root;
}

/** Search procedure, which looks for the input key in the tree and returns 1 if
 * it's present or 0 if it's not in the tree
 * @param root pointer to parent node
 * @param data value to store int he new node
 * @returns 0 if value not found in the nodes
 * @returns 1 if value was found
 */
int find(node *root, int data)
{
    // If the root is null, the key's not present
    if (root == NULL)
    {
        return 0;
    }
    else if (data > root->data)
    {
        // If the input key is greater than the root's, search in the right
        // subtree
        return find(root->right, data);
    }
    else if (data < root->data)
    {
        // If the input key is lower than the root's, search in the left subtree
        return find(root->left, data);
    }
    else if (data == root->data)
    {
        // If the input and the root key match, return 1
        return 1;
    }
    else
    {  // unknown result!!
        return 0;
    }
}

/** Utilitary procedure to measure the height of the binary tree
 * @param root pointer to parent node
 * @param data value to store int he new node
 * @returns 0 if value not found in the nodes
 * @returns height of nodes to get to data from parent node
 */
int height(node *root)
{
    // If the root is null, this is the bottom of the tree (height 0)
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        // Get the height from both left and right subtrees to check which is
        // the greatest
        int right_h = height(root->right);
        int left_h = height(root->left);

        // The final height is the height of the greatest subtree(left or right)
        // plus 1(which is the root's level)
        if (right_h > left_h)
        {
            return (right_h + 1);
        }
        else
        {
            return (left_h + 1);
        }
    }
}

/** Utilitary procedure to free all nodes in a tree
 * @param root pointer to parent node
 */
void purge(node *root)
{
    if (root != NULL)
    {
        if (root->left != NULL)
        {
            purge(root->left);
        }
        if (root->right != NULL)
        {
            purge(root->right);
        }
        free(root);
        root = NULL;  // reset pointer
    }
}

/** Traversal procedure to list the current keys in the tree in order of value
 * (from the left to the right)
 * @param root pointer to parent node
 */
void inOrder(node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("\t[ %d ]\t", root->data);
        inOrder(root->right);
    }
}

/** Main funcion */
int main()
{
    // this reference don't change.
    // only the tree changes.
    node *root = NULL;
    int opt = -1;
    int data = 0;

    // event-loop.
    while (opt != 0)
    {
        printf(
            "\n\n[1] Insert Node\n[2] Delete Node\n[3] Find a Node\n[4] Get "
            "current Height\n[5] Print Tree in Crescent Order\n[0] Quit\n");
        scanf("%d", &opt);  // reads the choice of the user

        // processes the choice
        switch (opt)
        {
        case 1:
            printf("Enter the new node's value:\n");
            scanf("%d", &data);
            root = insert(root, data);
            break;

        case 2:
            printf("Enter the value to be removed:\n");
            if (root != NULL)
            {
                scanf("%d", &data);
                root = delete (root, data);
            }
            else
            {
                printf("Tree is already empty!\n");
            }
            break;

        case 3:
            printf("Enter the searched value:\n");
            scanf("%d", &data);
            find(root, data) ? printf("The value is in the tree.\n")
                             : printf("The value is not in the tree.\n");
            break;

        case 4:
            printf("Current height of the tree is: %d\n", height(root));
            break;

        case 5:
            inOrder(root);
            break;
        }
    }

    // deletes the tree from the heap.
    purge(root);

    return 0;
}
