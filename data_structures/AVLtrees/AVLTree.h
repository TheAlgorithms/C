/***********************************************************************
AVLTree.h

Purpose:
    Define constants used in the project.
    Struct definitions for a general AVL Tree.
    Define function prototypes used by general AVL Trees.
************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>


//#define constant values
#define TRUE 1
#define FALSE 0


//typedef for the Element struct which constains a c string to store a URL in the BrowserList
typedef struct
{
    long key;
} ElementAVL;


//Typedef for a node in the doubly linked list (has next and previous pointers).
typedef struct NodeAVL
{
    ElementAVL element;
    struct NodeAVL *pLeft;
    struct NodeAVL *pRight;
	struct NodeAVL *pParent;
	int iBalanceFactor;
	
} NodeAVL;

//Typedef for a AVL tree implementation.  
//Contains a pointer to the root node of the tree.
typedef struct
{
    NodeAVL *pRoot;
} AVLTreeImp;

typedef AVLTreeImp *AVLTree;


/*****Prototypes*******/

//Malloc a new AVLTreeImp and return it's address.
AVLTree newAVLTree();


//Free the AVLTree and any nodes that still exist in the tree.
void freeAVLTree(AVLTree tree);

//Recursive function to free every node in a AVL Tree.
void postOrderAVLNodeFree(NodeAVL *p);


//Allocate a new node and store "value" as the Element in the node.  Return the address of the node.
NodeAVL *allocateAVLNode(ElementAVL value);

//Function to search for a node with key value equal to searchValue.  Return a pointer to the node if you find it or return NULL if it does not exist.  Calls the recursiveSearch() function, passing it the root pointer.
NodeAVL *searchAVL(AVLTree tree, int searchValue);

//Recursive algorithm for searching for a node with key value equal to searchValue.  Return a pointer to the node if you find it or return NULL if it does not exist.
NodeAVL *recursiveSearchAVL(NodeAVL *p, int searchValue);


//Create a node to store the given Element and add it as a leaf in the AVLTree.  Calls the recursive insert function.
//Return true if the insert worked successfully, and return false if the node already existed in the tree.
int insertAVL(AVLTree tree, ElementAVL value);


//Create a node to store the given Element and add it as a leaf in the AVLTree.  Rebalances the tree if necessary.
//Return true if the insert worked successfully, and return false if the node already existed in the tree.
int recursiveInsertAVL(NodeAVL *p, ElementAVL value);


//Function that iteratively traces back towards the root, updating balance factors and using rotations to balance the tree if necessary.
void checkForRebalancing(NodeAVL *p);

//Function that "rotates p down and to the left" and pulls p's right child "up and to the left".
void leftRotate(NodeAVL *p);

//Function that "rotates p down and to the right" and pulls p's left child "up and to the right".
void rightRotate(NodeAVL *p);

//Recursivly print the key values of all nodes in the subtree rooted at p in increasing order.  Calls the recursive function passing it a pointer to the root node.
void printInOrderAVL(AVLTree tree);

//Recursive function to conduct the inorder traversal.
void recursivePrintInOrderAVL(NodeAVL *p);

//Print the key values of all nodes in the subtree rooted at p according to a preorder traversal.  Calls the recursive function passing it a pointer to the root node.
void printPreOrderAVL(AVLTree tree);

//Recursive function to conduct the preorder traversal.
void recursivePrintPreOrderAVL(NodeAVL *p);
