#include <stdio.h>
#include <stdlib.h>

struct AVLnode
{
	int key;
	struct AVLnode *left;
	struct AVLnode *right;
	int height;
};
typedef struct AVLnode avlNode;

int max(int a, int b)
{
	return (a > b)? a : b;
}

avlNode *newNode(int key)
{
	avlNode *node = (avlNode*)malloc(sizeof(avlNode));

	if(node == NULL)
		printf("!! Out of Space !!\n");
	else
	{
		node->key = key;
		node->left = NULL;
		node->right = NULL;
		node->height = 0;
	}

	return node;
}

int nodeHeight(avlNode *node)
{
	if(node == NULL)
		return -1;
	else
		return(node->height);
}

int heightDiff(avlNode *node)
{
	if(node == NULL)
		return 0;
	else
		return(nodeHeight(node->left) - nodeHeight(node->right));
}

/* Returns the node with min key in the left subtree*/
avlNode *minNode(avlNode *node)
{
	avlNode *temp = node;

	while(temp->left != NULL)
		temp = temp->left;

	return temp;
}

void printAVL(avlNode *node, int level)
{
	int i;
	if(node!=NULL)
	{
		printAVL(node->right, level+1);
		printf("\n\n");

		for(i=0; i<level; i++)
			printf("\t");

		printf("%d", node->key);

		printAVL(node->left, level+1);
	}
}

avlNode *rightRotate(avlNode *z)
{
	avlNode *y = z->left;
	avlNode *T3 = y->right;

	y->right = z;
	z->left = T3;

	z->height = (max(nodeHeight(z->left), nodeHeight(z->right)) + 1);
	y->height = (max(nodeHeight(y->left), nodeHeight(y->right)) + 1);

	return y;
}

avlNode *leftRotate(avlNode *z)
{
	avlNode *y = z->right;
	avlNode *T3 = y->left;

	y->left = z;
	z->right = T3;

	z->height = (max(nodeHeight(z->left), nodeHeight(z->right)) + 1);
	y->height = (max(nodeHeight(y->left), nodeHeight(y->right)) + 1);

	return y;
}

avlNode *LeftRightRotate(avlNode *z)
{
	z->left = leftRotate(z->left);

	return (rightRotate(z));
}

avlNode *RightLeftRotate(avlNode *z)
{
	z->right = rightRotate(z->right);

	return (leftRotate(z));
}

avlNode *insert(avlNode *node, int key)
{

	if(node == NULL)
		return (newNode(key));

	/*Binary Search Tree insertion*/

	if(key < node->key)
		node->left = insert(node->left, key);		/*Recursive insertion in L subtree*/
	else if(key > node->key)
		node->right = insert(node->right, key); 	/*Recursive insertion in R subtree*/

	/* Node  Height as per the AVL formula*/
	node->height = (max(nodeHeight(node->left), nodeHeight(node->right)) + 1);


	/*Checking for the balance condition*/
	int balance = heightDiff(node);

	/*Left Left */
	if(balance>1 && key < (node->left->key))
		return rightRotate(node);

	/*Right Right */
	if(balance<-1 && key > (node->right->key))
		return leftRotate(node);

	/*Left Right */
	if (balance>1 && key > (node->left->key))
	{
		node = LeftRightRotate(node);
	}

	/*Right Left */
	if (balance<-1 && key < (node->right->key))
	{
		node = RightLeftRotate(node);
	}

	return node;

}

avlNode *delete(avlNode *node, int queryNum)
{
	if(node == NULL)
		return node;

	if(queryNum < node->key)
		node->left = delete(node->left, queryNum);			/*Recursive deletion in L subtree*/
	else if(queryNum > node->key)
		node->right = delete(node->right, queryNum);		/*Recursive deletion in R subtree*/
	else
	{
		/*Single or No Child*/
		if((node->left == NULL) || (node->right==NULL))
		{
			avlNode *temp = node->left ?
										node->left :
										node->right;

			/* No Child*/
			if(temp == NULL)
			{
				temp = node;
				node = NULL;
			}
			else  /*Single Child : copy data to the parent*/
				*node = *temp;

			free(temp);
		}
		else
		{
			/*Two Child*/

			/*Get the smallest key in the R subtree*/
			avlNode *temp = minNode(node->right);
			node->key = temp->key;			/*Copy that to the root*/
			node->right = delete(node->right, temp->key); /*Delete the smallest in the R subtree.*/
		}
	}

	/*single node in tree*/
	if(node == NULL)
		return node;


	/*Update height*/
	node->height = (max(nodeHeight(node->left), nodeHeight(node->right)) + 1);

	int balance = heightDiff(node);

	/*Left Left */
	if((balance>1) && (heightDiff(node->left) >= 0))
		return rightRotate(node);

	/*Left Right */
	if ((balance>1) && (heightDiff(node->left) < 0))
	{
		node = LeftRightRotate(node);
	}

	/*Right Right */
	if((balance<-1) && (heightDiff(node->right) >= 0))
		return leftRotate(node);

	/*Right Left */
	if ((balance<-1) && (heightDiff(node->right) < 0))
	{
		node = RightLeftRotate(node);
	}

	return node;

}

avlNode *findNode(avlNode *node, int queryNum)
{
	if(node!=NULL)
	{
		if(queryNum < node->key)
			node = findNode(node->left, queryNum);
		else if(queryNum > node->key)
			node = findNode(node->right, queryNum);
	}

	return node;
}

void printPreOrder(avlNode *node)
{
	if(node == NULL)
		return;

	printf("  %d  ", (node->key));
	printPreOrder(node->left);
	printPreOrder(node->right);
}

void printInOrder(avlNode *node)
{
	if(node == NULL)
		return;
	printInOrder(node->left);
	printf("  %d  ", (node->key));
	printInOrder(node->right);
}

void printPostOrder(avlNode *node)
{
	if(node == NULL)
		return;
	printPostOrder(node->left);
	printPostOrder(node->right);
	printf("  %d  ", (node->key));
}

int main()
{
	int choice;
	int flag=1;
	int insertNum;
	int queryNum;

	avlNode *root = NULL;
	avlNode *tempNode;

	while(flag == 1)
	{
		printf("\n\nEnter the Step to Run : \n");

		printf("\t1: Insert a node into AVL tree\n");
		printf("\t2: Delete a node in AVL tree\n");
		printf("\t3: Search a node into AVL tree\n");
		printf("\t4: printPreOrder (Ro L R) Tree\n");
		printf("\t5: printInOrder (L Ro R) Tree\n");
		printf("\t6: printPostOrder (L R Ro) Tree\n");
		printf("\t7: printAVL Tree\n");

		printf("\t0: EXIT\n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 0:
				{
					flag=0;
					printf("\n\t\tExiting, Thank You !!\n");
					break;
				}

			case 1:
				{

					printf("\n\tEnter the Number to insert: ");
					scanf("%d", &insertNum);

					tempNode = findNode(root, insertNum);

					if(tempNode!=NULL)
						printf("\n\t %d Already exists in the tree\n", insertNum);
					else
					{
						printf("\n\tPrinting AVL Tree\n");
						printAVL(root, 1);
						printf("\n");

						root = insert(root, insertNum);
						printf("\n\tPrinting AVL Tree\n");
						printAVL(root, 1);
						printf("\n");
					}

					break;
				}

			case 2:
				{
					printf("\n\tEnter the Number to Delete: ");
					scanf("%d", &queryNum);

					tempNode = findNode(root, queryNum);

					if(tempNode==NULL)
						printf("\n\t %d Does not exist in the tree\n", queryNum);
					else
					{
						printf("\n\tPrinting AVL Tree\n");
						printAVL(root, 1);
						printf("\n");
						root = delete(root, queryNum);

						printf("\n\tPrinting AVL Tree\n");
						printAVL(root, 1);
						printf("\n");
					}

					break;
				}

			case 3:
				{
					printf("\n\tEnter the Number to Search: ");
					scanf("%d", &queryNum);

					tempNode = findNode(root, queryNum);


					if(tempNode == NULL)
						printf("\n\t %d : Not Found\n", queryNum);
					else
					{
						printf("\n\t %d : Found at height %d \n", queryNum, tempNode->height);

						printf("\n\tPrinting AVL Tree\n");
						printAVL(root, 1);
						printf("\n");
					}

					break;
				}

			case 4:
				{
					printf("\nPrinting Tree preOrder\n");
					printPreOrder(root);

					break;
				}

			case 5:
				{
					printf("\nPrinting Tree inOrder\n");
					printInOrder(root);

					break;
				}

			case 6:
				{
					printf("\nPrinting Tree PostOrder\n");
					printPostOrder(root);

					break;
				}

			case 7:
				{
					printf("\nPrinting AVL Tree\n");
					printAVL(root, 1);

					break;
				}

			default:
				{
					flag=0;
					printf("\n\t\tExiting, Thank You !!\n");
					break;
				}

		}


	}


	return 0;
}
