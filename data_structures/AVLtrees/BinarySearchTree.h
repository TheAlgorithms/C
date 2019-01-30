/************************************************************************
BinarySearchTree.h

Purpose:
    Define constants used in the project.
    Struct definitions for a general Binary Search Tree.
    Define function prototypes used by general Binary Search Trees.
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
} Element;


//Typedef for a node in the doubly linked list (has next and previous pointers).
typedef struct NodeT
{
    Element element;
    struct NodeT *pLeft;
    struct NodeT *pRight;
} NodeT;

//Typedef for a binary search tree implementation.  
//Contains a pointer to the root node of the tree.
typedef struct
{
    NodeT *pRoot;
} BinarySearchTreeImp;

typedef BinarySearchTreeImp *BinarySearchTree;


/*****Prototypes*******/

//Malloc a new BinarySearchTreeImp and return it's address.
BinarySearchTree newBinarySearchTree();


//Free the BinarySearchTree and any nodes that still exist in the tree.
void freeBinarySearchTree(BinarySearchTree tree);

//Recursive function to free every node in a Binary Search Tree.
void postOrderNodeFree(NodeT *p);


//Allocate a new node and store "value" as the Element in the node.  Return the address of the node.
NodeT *allocateNode(Element value);

//Function to search for a node with key value equal to searchValue.  Return a pointer to the node if you find it or return NULL if it does not exist.  Calls the recursiveSearch() function, passing it the root pointer.
NodeT *search(BinarySearchTree tree, long searchValue);

//Recursive algorithm for searching for a node with key value equal to searchValue.  Return a pointer to the node if you find it or return NULL if it does not exist.
NodeT *recursiveSearch(NodeT *p, long searchValue);

//Create a node to store the given Element and add it as a leaf in the BinarySearchTree.  Do not worry about balancing the tree for this project.
//Return true if the insert worked successfully, and return false if the node already existed in the tree.
int recursiveInsert(NodeT **p, Element value);

//Create a node to store the given Element and add it as a leaf in the BinarySearchTree.  Do not worry about balancing the tree for this project.
//Return true if the insert worked successfully, and return false if the node already existed in the tree.
int insert(BinarySearchTree tree, Element value);

//Recursivly print the key values of all nodes in the subtree rooted at p in increasing order.  Calls the recursive function passing it a pointer to the root node.
void printInOrder(BinarySearchTree tree);

//Recursive function to conduct the inorder traversal.
void recursivePrintInOrder(NodeT *p);

//Print the key values of all nodes in the subtree rooted at p according to a preorder traversal.  Calls the recursive function passing it a pointer to the root node.
void printPreOrder(BinarySearchTree tree);

//Recursive function to conduct the preorder traversal.
void recursivePrintPreOrder(NodeT *p);
