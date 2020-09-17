#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    struct Node *left;  
    struct Node *right; 
    int data;           
} Node;

Node *newNode(int data)
{
    // creates a node
    Node *tmp = (Node *)malloc(sizeof(Node));
//inserting in node
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;

    return tmp;
}
//inserting data in nodes
Node *insert(Node *root, int data)
{
    // If the root of the subtree is null, insert key here
    if (root == NULL)
    {
        root = newNode(data);
    }
    else if (data > root->data)
        root->right = insert(root->right, data);
    else if (data < root->data)
        root->left = insert(root->left, data);
    // Returns the modified tree
    return root;
}

Node* getMax(Node* root)
{
	if(root==NULL)
	 {
	 	printf("no element\n");
	 	return NULL;
	 }
	if(root->right!=NULL)
		return (root->right);
	else
		return root; 
}

Node *delete_node (Node *root, int data)
{
    // If the root is null, nothing to be done
    if (root == NULL)
        return root;
    else if (data > root->data)
        root->right = delete_node (root->right, data);
    else if (data < root->data)
        root->left = delete_node (root->left, data);
    else if (data == root->data){
        if ((root->left == NULL) && (root->right == NULL))
        {  // Case 1: the root has no leaves, remove the node
            free(root);
            return NULL;
        }
        else if (root->left == NULL)
        {  // Case 2: the root has one leaf, make the leaf the new root and
            // remove
            // the old root
            Node *tmp = root;
            root = root->right;
            free(tmp);
            return root;
        }
        else if (root->right == NULL)
        {
            Node *tmp = root;
            root = root->left;
            free(tmp);
            return root;
        }
        else
        {  // Case 3: the root has 2 leaves, find the greatest key in the left
            // subtree and switch with the root's

            // finds the biggest node in the left branch.
            Node *tmp = getMax(root->left);
            root->data = tmp->data;
            root->left = delete_node (root->left, tmp->data);
        }
    }
    return root;
}


int find(Node *root, int data)
{
    // If the root is null, the key's not present
    if (root == NULL)
        return 0;
    else if (data > root->data)
        return find(root->right, data);
    else if (data < root->data)
        return find(root->left, data);
    else if (data == root->data)
        return 1;
    else
    {  // unknown result!!
        return 0;
    }
}

int height(Node *root)
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
            return (right_h + 1);
        else
            return (left_h + 1);
    }
}

void deletetree(Node *root)
{
	if(root==NULL)
	return ;
	deletetree(root->left);
	deletetree(root->right);
	free(root);
}

void preOrder(Node *root)
{
    if (root != NULL)
    {
    	printf("\t[ %d ]\t", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

/** Main funcion */
int main()
{
    // this reference don't change.
    // only the tree changes.
    Node *root = NULL;
    int opt = -1;
    int data = 0;

    // event-loop.
    while (opt != 0)
    {
        printf(
            "\n\n[1] Insert Node\n[2] Delete Node\n[3] Find a Node\n[4] Get "
            "current Height\n[5] Print Tree in preOrder traversal(root->left->right)\n[0] Quit\n");
        scanf("%d", &opt);  // reads the choice of the user
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
                root = delete_node (root, data);
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
            preOrder(root);
            break;
        }
    }

    // deletes the tree from the heap.
    deletetree(root);

    return 0;
}
