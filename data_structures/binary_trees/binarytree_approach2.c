/*
this file have compelete implementation of a binary search tree and has all function defined 
including insert,find,findMax,delet_tree,delete(to delete a node),preOrder and height.
which is required for compelete implementation of a tree
*/

#include <stdio.h>				/*This header files are required to take user input and it has some predefined function which enable us to use them in our code (*if required)*/
#include <stdlib.h>

/*this is a struct method in c/c++ through which we create our own datatype and this datatype would create a memory block or lets name it by NODE
with three portion in it two part of a node will store address of any other node of same datatype (*Node) 
=> left= stores address of left part of each subtree in a tree
=> right= stores address of right part of each subtree in a tree
=> data= contains value of each node of datatype int.
and remaining one part of each node will store data of type integer.*/

typedef struct Node			
{
    struct Node *left;  
    struct Node *right; 
    int data;           
} Node;			// here we assign a name (making it easier for the user to use in code)to our explicitly defined datatype;)

/*the function newNode defining below will create a node of of datatype Node and 
put *left=NULL and *right=NULL at the time of creating a new node and returns the address of that newly created node as its return type is Node*
*/
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
/*function insert would put a value in data part of each node and has return type Node* (address of the node) 
according to the defination of a binary tree this function will work in a same way i.e if value to be kept in a node is less than the value stored at root or head node then that
node will be the part of left subtree,
similerly,
if value to be kept in a node is greater than the value of root or head node then that node will be the part of right subtree
*/
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
/* getMax function will work only on the right part of the tree and will return the address of the right most node in a tree
as right most node has the maximum value stored in it data part (according to the defination of BST)
*/
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
/*
function delete_node returns address of root node after deleting that required node 
first it seach for that node if it is there then it delete 

*/
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
/*
function Find search the node with value data which we provide as parameter in this function which returns 0 if node with value "data" is not present in the tree
or 1 if such node is there is present
*/

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
/* 
function Height return the height of the tree which is the highest number of node lieing in any path from root/head node to a leaf node(having no child)
return type oviously would be integer.
*/
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
/*
this function removes the whole tree (which was created dynamically using malloc) using free method
*/
void deletetree(Node *root)
{
	if(root==NULL)
	return ;
	deletetree(root->left);
	deletetree(root->right);
	free(root);
}
/*
this preOrder function would print value (stored at data part of the node) and this prints the value in following manner
head/root  ->  left-subtree  ->  right-subtree
*/
void preOrder(Node *root)
{
    if (root != NULL)
    {
    	printf("\t[ %d ]\t", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

/** Main funcion 
it has a menu (switch-cases) containg the list of function (defined above) to perform any particuler action*/
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
