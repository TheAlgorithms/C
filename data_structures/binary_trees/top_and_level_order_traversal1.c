/**
*@file
*@brief has complete implementation of bst with diffrent traversal approach
**/
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

/**
*@brief this is a struct method in c/c++ through which we create our own datatype 
*@note with three portion in it two part of a node will store address of any other node of same datatype (*Node) 
*=> left stores address of left part of each subtree in a tree
*=> right stores address of right part of each subtree in a tree
*=> data contains value of each node of datatype int.
*@note data should of type integer only in this case
**/

struct tree {
	int data;
	struct tree *left,*right;
};

/**
*@brief the function 'createtree' defining below will create a node of datatype 'struct tree' 
put *left=NULL and *right=NULL at the time of creating a new node 
*@param root address of head/root node of the tree
*@param data has tha value which is to be kept in new node
*@returns address of that newly created node 
**/

struct tree* createtree(struct tree *root,int data)
{
	if(root==NULL)
	{
		struct tree *node;
		node =(struct tree*)malloc(sizeof(struct tree));
		root=node;
		node->data=data;
		node->left=node->right=NULL;
		return node;
	}
	else if(data<root->data)
	root->left=createtree(root->left,data);
	else if(data>root->data)
	root->right=createtree(root->right,data);
	return root;
}
/**
*@brief inOrder function would print value (stored at data part of the node) and this prints the value in following manner
*@note left-subtree  ->  head/root ->  right-subtree

*@param address of root node
*@returns 'void'
**/

void inorder(struct tree *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

/**
*@brief function Height return the height of the tree which is the highest number of node lieing in any path from root/head node to a leaf node(having no child)
*@param root address of the tree
*@returns 'int'
**/

int height(struct tree *root)
{
	int x,rhgt,lhgt;
	if(root==NULL)
	{
	//	printf("no elements\n");
		return 0;
	}
	else{
	lhgt=height(root->left);
	rhgt=height(root->right);
	}
	if(lhgt>rhgt)
	x=lhgt;
	else
	x=rhgt;
	return x+1;
}
/**
*@brief function defined below would returns nothing it just recursively call itself and print the data present in particuler level in a binary search tree
*@param root address of tree
*@param level provides which level need to traverse leading from 1 to height of the tree
*@returns 'void'
**/

void currentleveltraversal(struct tree *root,int level)
{
	if(root==NULL)
	return;
	if(level==1)
		printf("%d ",root->data);
	else if(level>1)
	{
		currentleveltraversal(root->left,level-1);	
		
		currentleveltraversal(root->right,level-1);
	}
}

/**
*@brief function 'printlevel' provide level number to 'currentleveltraversal' function 
*@param root address of the tree
*@returns 'void'
**/

void printlevel(struct tree *root)
{
	int h=height(root);
	for(int i=1;i<=h;i++)
	{printf("\n");
		currentleveltraversal(root,i);
	}
//	printf("%d ->",root->data);
}

/**
*@brief 'printleft' prints left part of each subtree calling itself recursively until it reaches a leaf node 
*@param root address of the tree
*@returns 'void'
**/

void printleft(struct tree *root){
    	if (root == NULL){
        	return;
   	}
    	printleft(root->left);
		printf("%d ",root->data);
}

/**
*@brief 'printright' prints right part of each subtree calling itself recursively until it reaches a leaf node 
*@param root address of the tree
*@returns 'void'
**/

void printright(struct tree *root){
    	if(root == NULL){
        	return;
    	}
    	printf("%d ",root->data);
    	printright(root->right);
}

/**
*@brief 'top_view' gives the top image of the tree
*@param root address of the tree
*@returns 'void'
**/

void top_view(struct tree *root)
{
	printleft(root);
    printright(root->right);
}

/*
Here is the main function which has a menu driven (switch-vases)  list of each type of traversal
*/

int main()
{
	int i,n,data;
	struct tree *root=NULL;
	printf("Enter number of value you want to insert in tree: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&data);
		root=createtree(root,data);
	}
	int opt=-1;
	while(opt!=0)
	{
	printf("Select any option from given list:-\n");
	printf("[1] To get the top view of the tree\n[2] To get the inorder traversal of the tree\n[3] To get level order traversal of the tree\n");
	scanf("%d",&opt);
	switch(opt){
		case 1:
			printf("Top veiw:- \n");
			top_view(root);
			printf("\n");
			break;
		case 2:
			printf("Inorder traversal:-\n");
			inorder(root);
			printf("\n");
			break;
		case 3:
			printf("Level order traversal:- ");
			printlevel(root);
			break;
	}}
	printf("done:)");
	return 0;
}
