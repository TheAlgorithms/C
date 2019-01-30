/*********************************************************
BinarySearchTree.c

Purpose:
    This will contain a regular BinarySearchTree Implementation
    that does not care about balancing the tree, so there could 
    be the unbalanced trees using this structure, which in the 
    worst case, as I used in the compar.c simulation, it will
    create a link list style structure.


**********************************************************/
#include "BinarySearchTree.h"

/**********************newBinarySearchTree**************
Purpose:
    To creat a new NULL BinarySearchTree
Params:
    N/A
Returns:
    BinarySearchTree
*******************************************************/
BinarySearchTree newBinarySearchTree()
{
        //create space for the binary Search Tree
	BinarySearchTree tree = (BinarySearchTree)malloc(sizeof(BinarySearchTreeImp));
	tree->pRoot = NULL; //set the root to null
	return tree; //reutrn the tree
}


/*****************freeBinarySearchTree***************
Purpose:
    To free an entire Binary Search Tree structure
Params:
    tree - BinarySearchTree: an BinarySearchTree Structue
***************************************************/
void freeBinarySearchTree(BinarySearchTree tree)
{
        //sub-routine to free all the nodes, if any
	postOrderNodeFree(tree->pRoot);
	free(tree); //free the tree structure 	
}


/*************postOrderNodeFree*************
Purpose:
    To free all the sub-tree's nodes from a given
    node.
Param:
    p - *NodeT the points to a NodeT structure
*******************************************/
void postOrderNodeFree(NodeT *p)
{
	if(p != NULL) //if the current node != null
	{
                //go all the way to the left
		postOrderNodeFree(p->pLeft);

                //go all the way to the right
		postOrderNodeFree(p->pRight);

                //then free the node
		free(p);
	}
}


/******************allocateNode****************
Purpose:
    To creat a new NodeT Structure
Param:
    value - Element: an Element Structure
Returns:
    *NodeT - a new pointer to the new NodeT structure that 
             contains the new element
**********************************************/
NodeT *allocateNode(Element value)
{
        //create the space for the structure
	NodeT *pNew = (NodeT *)malloc(sizeof(NodeT));
        //assign default values. and value
	pNew->pLeft = NULL;
	pNew->pRight = NULL;
	pNew->element = value;
	
	return pNew; //return the new NodeT	
}


/*******************search**************************
Purpose:
    To search a BinarySearchTree for a specific value.
Params:
    tree - BinarySearchTree: an BinarySearchTree Structue
    searchValue - long: a key to search in the BinarySearchTree
Returns;
   *NodeT - a pointer to the node if found or NULL
            if not found.
***************************************************/
NodeT *search(BinarySearchTree tree, long searchValue)
{
        //call a recursive sub-routine to search
	return recursiveSearch(tree->pRoot,searchValue);
}

/********************recursiveSearch********************
Purpose:
    Recursive algorithm for searching for a node with key 
    value equal to searchValue.  Return a pointer to the node 
    if you find it or return NULL if it does not exist.
Params:
   p - *NodeT: the points to a NodeT structure
   searchValue - long: a key to search in the BinarySearchTree
Returns:
    *NodeT - that points to the NodeT that contains the key
             or NULL if the key was not found.

*******************************************************/
NodeT *recursiveSearch(NodeT *p, long searchValue)
{
	
	if(p==NULL) //if not found
		return NULL; //return null
	
	if(p->element.key == searchValue) //we found the key
		return p;
	else if(p->element.key > searchValue) //need to recurse to the left
		return recursiveSearch(p->pLeft,searchValue);
	else //we need to recurse to the right
		return recursiveSearch(p->pRight,searchValue);
	
}

/***********************insert********************
Purpose:
    To insert into a BinarySearchTree
Params:
    tree - BinarySearchTree: an BinarySearchTree Structue
    value - Element: an Element Structure
Returns:
    int - for error checking
*************************************************/
int insert(BinarySearchTree tree, Element value)
{	
        //call a recursive sub-routine to insert
	return recursiveInsert(&(tree->pRoot),value);
	
}

/******************recursiveInsert*******************
Purpose:
    to insert a newNodeT into the given sub-Tree
Param:
    p - **NodeT: a double pointer to edit the values
                inside the NodeT single pointer 
    value - Element: an Element Structure
Return:
    int - for error checking
****************************************************/
int recursiveInsert(NodeT **p, Element value)
{
	if(*p == NULL) //if the current node is empty
	{
                //create the new node
		*p = allocateNode(value);
		return TRUE;		
	}
	
        //if the key already exist
	if( (*p)->element.key == value.key )
		return FALSE;// bail

                //if the value is bigger than the key
	else if( (*p)->element.key > value.key ) 
                //go to the smaller side
		return recursiveInsert( &((*p)->pLeft), value);
	else
                //go to the bigger side
		return recursiveInsert( &((*p)->pRight), value);
	
}


/****************printInOrder********************
Purpose:
    Print a BinarySearchTree from least to greatest
    by value of the key.
Param:
    tree - BinarySearchTree: an BinarySearchTree Structue
Returns:
    void
************************************************/
void printInOrder(BinarySearchTree tree)
{
        //sub routin for printing in order
	recursivePrintInOrder(tree->pRoot);
}

/*************recursivePrintInOrder************
Purpose:
    To recursively print the values in order form
    small to large.
Param:
    p - *NodeT: the points to a NodeT structure
Returns:
    void
**********************************************/
void recursivePrintInOrder(NodeT *p)
{
	if(p != NULL) //if there is a current node
	{
                //go all the way to the left
		recursivePrintInOrder(p->pLeft);
                
                //then print the current node once smaller nodes
                //are done printing
		printf("%ld\n",p->element.key);

                //go all the way to the right to 
                //print the larger nodes.
		recursivePrintInOrder(p->pRight);
	}	
}


/****************printPreOrder*****************
Purpose:
    to print a tree in pre order fasion.
Param:
    tree - BinarySearchTree: an BinarySearchTree Structue
Returns:
    void
**********************************************/
void printPreOrder(BinarySearchTree tree)
{
        //sub routine for printing in pre order
	recursivePrintPreOrder(tree->pRoot);
}

/*************recursivePrintPreOrder***********
Purpose:
    to recursively print the sub-tree starting 
    with a given node in pre-order fashion
Param:
    p - *NodeT: the points to a NodeT structure
Returns:
    void
**********************************************/
void recursivePrintPreOrder(NodeT *p)
{
	if(p != NULL) //if the current node is not null
	{
		//print the key
		printf("%ld\n",p->element.key);
                //recurse left to print those nodes
		recursivePrintPreOrder(p->pLeft);
                //recurse right to print those nodes
		recursivePrintPreOrder(p->pRight);
	}	
}


