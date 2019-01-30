/********************************************
Compare.c

Purpose:
    Driver File for comparing how an unbalanced
    binary Search tree is exponetially slower than
    an AVLTree.
*********************************************/
#include <time.h>
#include "BinarySearchTree.h"
#include "AVLTree.h"


void compareTreeRunningTimes(long n);

/************************main*******************************
Purpose:
    To compare the different times it takes to build, search
    and free an unbalance binary search tree vs an AVLTree
Param:
    N/A
Returns:
    int for error checking
Special Nodes:
    The code in this file is not the main
    take away, so it will not be as heavily 
    commented.
***********************************************************/
int main()
{
	srand(time(NULL));
	
	long i;
	
	//Call function for inputs of size 10, 100, 1000, 10000, and 100000.
	for(i=10; i<1000; i*=10)
	{
		compareTreeRunningTimes(i);
		
		printf("\n---------------------------------------------------\n\n");
		
	}
	
	//Call function for inputs of size 200000, 300000, 400000, and 500000.
	for(i=200000; i<=500000; i+=100000)
	{
		compareTreeRunningTimes(i);
		
		printf("\n---------------------------------------------------\n\n");
		
	}

	return 0;
}

/***************compareTreeRunningTimes***********
Purpose:
    Insert the values from 1 to n into a regular binary 
    search tree and into an AVL Tree, and then search for 
    each of the n values. Report the amount of time each 
    takes in milliseconds.
Param:
    n - long: the number of keys in the trees.
Returns:
    void
**************************************************/
void compareTreeRunningTimes(long n)
{
	printf("Time for n = %ld",n);
	
	printf("\n\nBuilding regular Binary Search Tree.\n");
	clock_t startTime = clock();
	
	BinarySearchTree tree = newBinarySearchTree();
	long i;
	for(i=0; i<n; i++)
	{
		Element element;
		element.key = i;
		
		insert(tree,element);
	}
	
	clock_t endOfInsertTime = clock();
	
	double timeToInsert = ((double) endOfInsertTime - startTime)/CLOCKS_PER_SEC;
	printf("Inserts completed in %.6f seconds.  Now searching...\n",timeToInsert);
	
	for(i=0; i<n; i++)
	{
		search(tree, i);
	}
	
	clock_t endOfSearchTime = clock();
	
	double timeToSearch = ((double) endOfSearchTime - endOfInsertTime)/CLOCKS_PER_SEC;
	printf("Searches completed in %.6f seconds.  Now freeing...\n",timeToSearch);
	
	freeBinarySearchTree(tree);
	
	clock_t endOfBST = clock();
	
	double timeToFree = ((double) endOfBST - endOfSearchTime)/CLOCKS_PER_SEC;	
	double totalTime = ((double) endOfBST - startTime)/CLOCKS_PER_SEC;
	
	printf("Freeing completed in %.6f seconds.\n%.6f seconds to overall.\n",timeToFree,totalTime);
	
	
	//Now repeat the same thing for AVL Trees.
	
	printf("\n\nBuilding AVL Tree.\n");
	clock_t startTimeAVL = clock();
	
	AVLTree avlTree = newAVLTree();
	for(i=0; i<n; i++)
	{
		ElementAVL element;
		element.key = i;
		
		insertAVL(avlTree,element);
	}
	
	clock_t endOfInsertTimeAVL = clock();
	
	double timeToInsertAVL = ((double) endOfInsertTimeAVL - startTimeAVL)/CLOCKS_PER_SEC;
	printf("Inserts completed in %.6f seconds.  Now searching...\n",timeToInsertAVL);
	
	for(i=0; i<n; i++)
	{
		searchAVL(avlTree, i);
	}
	
	clock_t endOfSearchTimeAVL = clock();
	
	double timeToSearchAVL = ((double) endOfSearchTimeAVL - endOfInsertTimeAVL)/CLOCKS_PER_SEC;
	printf("Searches completed in %.6f seconds.  Now freeing...\n",timeToSearchAVL);
	
	freeAVLTree(avlTree);
	
	clock_t endOfAVL = clock();
	
	double timeToFreeAVL = ((double) endOfAVL - endOfSearchTimeAVL)/CLOCKS_PER_SEC;	
	double totalTimeAVL = ((double) endOfAVL - startTimeAVL)/CLOCKS_PER_SEC;
	
	printf("Freeing completed in %.6f seconds.\n%.6f seconds to overall.\n",timeToFreeAVL,totalTimeAVL);
	
	printf("\nThe AVL tree beat the regular Binary Search Tree by %.6f seconds.\n",totalTime-totalTimeAVL);
	
	
}
