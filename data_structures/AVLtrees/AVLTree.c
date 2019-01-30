/***************AVLTree.c***************
Purpose:    
    to create and handle AVL trees
****************************************/
#include "AVLTree.h"


/*************newAVLTree*************
Purpose:
    To crate a new NULL AVL tree and return it
Return:
    AVLTree
*************************************/
AVLTree newAVLTree()
{
        //creating the Structure of the AVL Tree
	AVLTree tree = (AVLTree)malloc(sizeof(AVLTreeImp));
	tree->pRoot = NULL; //setting the root to NULL
	return tree; //returning the Tree
}


/**************freeAVLTree******************
Purpose:
    To free the entire AVL Tree
Params:
    tree - AVLTree: a AVLTree Structure
Retrun:
    void
*******************************************/
void freeAVLTree(AVLTree tree)
{
        //free all the nodes in the tree
	postOrderAVLNodeFree(tree->pRoot);
	free(tree); //free the tree structure its self	
}


/************postOrderAVLNodeFree*********
Purpose:
    To free the nodes from a certin node
Params:
    p - *NodeAVL: a AVL node pointer to access the nodes structure
Return:
    void
*****************************************/
void postOrderAVLNodeFree(NodeAVL *p)
{
	if(p != NULL) //if this node is not null
	{
		postOrderAVLNodeFree(p->pLeft); //recurse to the left
		postOrderAVLNodeFree(p->pRight); //recurse to the right
		free(p); //free the node
	}
}

/*************allocateAVLNode**************
Purpose:
    to allocate a new AVLNode and set all its 
    values to default values.
Params:
    value - ElementAVL: an ElementAVL structure holding 
                        values.

*******************************************/
NodeAVL *allocateAVLNode(ElementAVL value)
{
        //create space for the sturcture
	NodeAVL *pNew = (NodeAVL *)malloc(sizeof(NodeAVL));
	pNew->pLeft = NULL; 
	pNew->pRight = NULL;
	pNew->pParent = NULL;
	pNew->element = value; //set the new value
	pNew->iBalanceFactor = 0; //set the default balance factor
	
	return pNew; //return	
}


/*****************searchAVLTree*****************
Purpose:
    to search an AVLTree for a given value.
Params:
    tree - AVLTree: a AVLTree structure
    searchValue - int: a value to search for
***********************************************/
NodeAVL *searchAVL(AVLTree tree, int searchValue)
{
        //call sub routine to find the value
	return recursiveSearchAVL(tree->pRoot,searchValue);
}


/*************recursiveSearchAVL***************
Purpose:
    Recursive algorithm for searching for a node 
    with key value equal to searchValue. Returns a 
    pointer to the node if you find it or it will 
    return NULL if it does not exist.
Param:
    p - *NodeAVL: a AVL node pointer to access the nodes structure
    searchValue - int: a value to search for
*********************************************/
NodeAVL *recursiveSearchAVL(NodeAVL *p, int searchValue)
{
	
	if(p==NULL)//if we have no more values to search
		return NULL; //key does not exist.
	
	if(p->element.key == searchValue) //if we found the key
		return p;//return the key

	else if(p->element.key > searchValue) //if the element's key is > search value
		return recursiveSearchAVL(p->pLeft,searchValue);
	else //the element's key is < search value
		return recursiveSearchAVL(p->pRight,searchValue);
	
}

/*****************insertAVLTree*******************
Purpose:
    To insert a new ElementAVL into an AVLTree.
Param:
    tree - AVLTree: a AVLTree structure
    value - ElementAVL: a new ElementAVL value to insert
                        into the tree
Returns:
    int for error checking.

*************************************************/
int insertAVL(AVLTree tree, ElementAVL value)
{
	
	if(tree->pRoot == NULL)
	{
		//The recursiveInsert() function assumes that the pointer we pass is not NULL, so if pRoot is NULL then we handle this case here.
		tree->pRoot = allocateAVLNode(value);
		return TRUE;
	}
	else
	{
		int result = recursiveInsertAVL(tree->pRoot,value);
		
		//If we rotated the root, the new root would be the parent of the old root.
		if(tree->pRoot->pParent != NULL){
			
			tree->pRoot = tree->pRoot->pParent;
		}				
		
		return result;
	}
	
}


/******************recursiveInsertAVL******************
Purpose:
    Recursive algorithm to insert value into an AVL tree.
    I check to see if the next node would be NULL if we continued.  
    This allows us to update the parent pointer. 
    Given the implementation, p will never be NULL. 
Params:
    p - *NodeAVL: a AVL node pointer to access the nodes structure
    value - ElementAVL: a new ElementAVL value to insert
                        into new tree
Return:
    int for error checking
*******************************************************/
int recursiveInsertAVL(NodeAVL *p, ElementAVL value)
{	
        //if the key is already in the tree
	if( p->element.key == value.key )
	{
		return FALSE;
	}//if the element key is > value
	else if( p->element.key > value.key )
	{
		if(p->pLeft != NULL) //the left side is not null
			return recursiveInsertAVL(p->pLeft, value); //go farther down the tree
		else
		{
			//value.key is less than current node, but current node does not have a left child.
			//The new node should be the left child of the current node.
			//Ater insertion, check to see if we need to rebalance the tree.
			p->pLeft = allocateAVLNode(value);
			p->pLeft->pParent = p;
			checkForRebalancing(p->pLeft);
			return TRUE;
		}
	}
	else//element key is < value
	{
		if(p->pRight != NULL) //the right side is not null
			return recursiveInsertAVL(p->pRight, value); //go farther down the tree
		else
		{
			//value.key is greater than current node, but current node does not have a right child.
			//The new node should be the right child of the current node.
			//Ater insertion, check to see if we need to rebalance the tree.
			p->pRight = allocateAVLNode(value);
			p->pRight->pParent = p;
			checkForRebalancing(p->pRight);
			return TRUE;
		}
		
	}
	
}
/********************checkForRebalancing*********************
Purpose:
    This function is passed p which is a pointer to the newly 
    inserted node into the tree. This fun walks from p towards 
    the root of the tree until we find a node that needs to be 
    rotated or until we determine that the tree is balanced.
    We perform any rotations and update any balance factors 
    that need to be updated.
Params:
    p - *NodeAVL: a AVL node pointer to access the nodes structure
Return:
    void
************************************************************/
void checkForRebalancing(NodeAVL *p)
{
	//some tempory vars
	NodeAVL *z = p;
	NodeAVL *x;
	
        //assign x to the partent of z, check to see if null
                                    // increase x by the parent
                                    //due to us wanting to go
                                    //up in the tree to see if we
                                    //effected other balance nodes.
	for(x=z->pParent; x != NULL; x = x->pParent)
	{
		//x is the parent of z.
		if(z == x->pLeft)
		{
			//z is the left child of x.  Check to see if x was imbalanced to the left prior to insertion.
			if(x->iBalanceFactor < 0)
			{
				//Both are true: (1) z is left child of x, and (2) x was imbalanced to the left.
				//We need to fix with rotations.
				if(z->iBalanceFactor <= 0)
				{
					//z is NOT imbalanced to the right, so a right rotate on x will fix the tree.
					rightRotate(x);
					
					//Update the balance factors of x and z.
					x->iBalanceFactor = 0;
					z->iBalanceFactor = 0;
					
				}
				else 
				{
					//z is imbalanced to the right, so a right rotation on x will cause x to be imbalanced to the left.
					//To fix, we left rotate z and then we right rotate x to fix the tree.
					//We create w to store the right child of z (before insertion), as it's balance factor will affect the ending balance factors.
					//Note w cannot be NULL since z is imbalanced to the right.
					
					NodeAVL *w = z->pRight;
					leftRotate(z);
					rightRotate(x);
					
					//Update the balance factors for each node in the rotate.
					if(w->iBalanceFactor > 0)
					{
						w->iBalanceFactor = 0;
						x->iBalanceFactor = 0;
						z->iBalanceFactor = -1;
					}
					else if(w->iBalanceFactor == 0)
					{
						w->iBalanceFactor = 0;
						x->iBalanceFactor = 0;
						z->iBalanceFactor = 0;
					}
					else
					{
						w->iBalanceFactor = 0;
						x->iBalanceFactor = 1;
						z->iBalanceFactor = 0;
						
					}
					
				}
				
				return;
				
			}
			else
			{
				//x was not imbalanced to the left, so we only need to update x's balance factor.
				
				if(x->iBalanceFactor == 1)
				{
					x->iBalanceFactor = 0;
					return;
				}
				
				//If here then x's balance factor before was 0.
				//Update balance factor, and set z to be it's parent for the next iteration of the for loop.
				x->iBalanceFactor = -1;
				z = x;				
			}			
			
		}
		else
		{
			//z is the right child of x.  Check to see if x was imbalanced to the right prior to insertion.
			if(x->iBalanceFactor > 0)
			{
				//Both are true: (1) z is right child of x, and (2) x was imbalanced to the right.
				//We need to fix with rotations.
				if(z->iBalanceFactor >= 0)
				{
					//z is NOT imbalanced to the left, so a left rotate on x will fix the tree.
					leftRotate(x);
					
					//Update the balance factors of x and z.
					x->iBalanceFactor = 0;
					z->iBalanceFactor = 0;
					
				}
				else
				{
					//z is imbalanced to the left, so a left rotation on x will cause x to be imbalanced to the right.
					//To fix, we right rotate z and then we left rotate x to fix the tree.
					//We create w to store the left child of z (before insertion), as it's balance factor will affect the ending balance factors.
					//Note w cannot be NULL since z is imbalanced to the left.
					
					NodeAVL *w = z->pLeft;
					rightRotate(z);
					leftRotate(x);
					
					//Update the balance factors.
					if(w->iBalanceFactor > 0)
					{
						w->iBalanceFactor = 0;
						x->iBalanceFactor = -1;
						z->iBalanceFactor = 0;
					}
					else if(w->iBalanceFactor == 0)
					{
						w->iBalanceFactor = 0;
						x->iBalanceFactor = 0;
						z->iBalanceFactor = 0;
					}
					else
					{
						w->iBalanceFactor = 0;
						x->iBalanceFactor = 0;
						z->iBalanceFactor = 1;
						
					}
					
				}
				
				return;
				
			}
			else
			{
				//x was not imbalanced to the right, so we only need to update x's balance factor.
				
				if(x->iBalanceFactor == -1)
				{
					x->iBalanceFactor = 0;
					return;
				}
				
				//If here then x's balance factor before was 0.
				//Update balance factor, and set z to be it's parent for the next iteration of the for loop.
				x->iBalanceFactor = 1;
				z = x;				
			}		
			
			
		}		
		
	}
	
	
}


/********************leftRotate*****************************
Purpose:
    This fucntion rotates around a node to bring it down to the left.
Param:
    p - *NodeAVL: a AVL node pointer to access the nodes structure
Return:
    void
*******************************************************/
void leftRotate(NodeAVL *p)
{
    NodeAVL *a, *b, *c, *subTree; //a few node pointers to keep track of pointer switching
    a=p->pParent;
    b=p;
    c=p->pRight;
    subTree = c->pLeft; //assign all the pointers
    if(a != NULL)
    {       //check to see if b was not the root 
        if(b == a->pRight) //check to see which child b is to a, then assign  a a new chile
            a->pRight=c;
        else
            a->pLeft = c;
    }

    c->pParent = a; //make c new parent = a 

    if(subTree != NULL) //check to see if c left child had anything if it did we set the parent to be b
        subTree->pParent = b;

    return; 
}

/************************rightRotate********************************
Purpose:
    This functions rotates around a node to bring it down to the right
Param:
    p - *NodeAVL: a AVL node pointer to access the nodes structure
Return:
    void
*********************************************************/
void rightRotate(NodeAVL *p)
{
    NodeAVL *a, *b, *c, *subTree; //a few node pointers tokeep track of pinter switching
    a=p->pParent;
    b=p;
    c=p->pLeft;
    subTree = c->pRight; //assign all the ponters

    if(a!=NULL)
    {        //check to see if b was not the root
	if(b==a->pLeft) //chech to see which child b is to a, then assign a a new child
	    a->pLeft=c;
	else
	    a->pRight = c;
    }

    c->pParent = a; //make c new parent = a

    if(subTree!=NULL) //check to see if c left child had anything if it did we se the parent to b.
	subTree->pParent = b;

    return;
}


/*******************printInOrderAVL*********************
Purpose:
    Prints an entire AVL tree in order by key.
Params:
    tree- AVLTree: an AVLTree structure
Returns:
    void
*******************************************************/
void printInOrderAVL(AVLTree tree)
{
        //calls recursive sub-routine to do the printing.
	recursivePrintInOrderAVL(tree->pRoot);
}

/***************recursivePrintInOrderAVL****************
Purpose:
    To print in recurisve fashion the sub-tree from a given
    NodeAVL
Param:
     p - *NodeAVL: a AVL node pointer to access the nodes structure
Return:
    void
*******************************************************/
void recursivePrintInOrderAVL(NodeAVL *p)
{
	if(p != NULL) //if the current p is not null
	{
		recursivePrintInOrderAVL(p->pLeft); //go all the way to the left
		printf("%ld\n",p->element.key); //print the key 
		recursivePrintInOrderAVL(p->pRight); //then go all the way to the
                                                    //right to print those keys.
	}	
}

/*************printPreOrderAVL*******************
Purpose:
    To print the pre-order of an AVLTree
Param:
    tree- AVLTree: an AVLTree structure
Returns:
    void
************************************************/
void printPreOrderAVL(AVLTree tree)
{
        //call sub-routine to to the printing
	recursivePrintPreOrderAVL(tree->pRoot);
}

/******************recursivePrintPreOrderAVL***********
Purpose:
    To print in recursive fashion the keys in pre-order
Param:
    p - *NodeAVL: a AVL node pointer to access the nodes structure
Returns:
    void
******************************************************/
void recursivePrintPreOrderAVL(NodeAVL *p)
{
	if(p != NULL) //if the current p is not null
	{
		
		printf("%ld\n",p->element.key); //print the key

		recursivePrintPreOrderAVL(p->pLeft); //go the the left 
                                                     // and print those keys

		recursivePrintPreOrderAVL(p->pRight); //then go the right and
                                                     //print those keys.
	}	
}


