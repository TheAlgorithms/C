/*
this file have compelete implementation of a binary search tree and has all function defined 
including insert,find,findMax,delet_tree,delete(to delete a node),inOrder,height,level-order-traversal and top-view .
which is required for compelete implementation of a tree
*/
/*This header files are required to take user input and it has some predefined function which enable us to use them in our code (*if required)*/
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;
/*this is a struct method in c/c++ through which we create our own datatype and this datatype would create a memory block or lets name it by NODE
with three portion in it two part of a node will store address of any other node of same datatype (*Node) 
=> left= stores address of left part of each subtree in a tree
=> right= stores address of right part of each subtree in a tree
=> data= contains value of each node of datatype int.
and remaining one part of each node will store data of type integer.*/

struct tree {
	int data;
	struct tree *left,*right;
};

/*the function createtree defining below will create a node of of datatype struct tree and 
put *left=NULL and *right=NULL at the time of creating a new node and returns the address of that newly created node as its return type is Node*
*/

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

/*
this inOrder function would print value (stored at data part of the node) and this prints the value in following manner
left-subtree  ->  head/root ->  right-subtree
*/

void inorder(struct tree *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

/* 
function Height return the height of the tree which is the highest number of node lieing in any path from root/head node to a leaf node(having no child)
return type oviously would be integer.
*/

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

/*
function defined below would returns nothing it just recursively call itself and print the data lieing in particuler level in a binary search tree
*/

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
/*
function printlevel have void return type but it call currentleveltraversal() function to print values of each level it just provide the level number(which has maximum value 
to the height of the tree) to this function 
*/

void printlevel(struct tree *root)
{
	int h=height(root);
	for(int i=1;i<=h;i++)
	{printf("\n");
		currentleveltraversal(root,i);
	}
//	printf("%d ->",root->data);
}


void findminnmax(struct tree *root,int *min,int *max,int hd)
{
	if(root==NULL)
	return ;
	if(hd<*min)
	*min=hd;
	else if(hd>*max)
	*max=hd;
	findminnmax(root->left,min,max,hd-1);
	findminnmax(root->right,min,max,hd+1);
}

/*
function printverticalorder() call itself recursively and print value when until it reaches a leaf node in each vertical traversal
*/
void printverticalorder(struct tree *root,int level,int hd)
{
	if(root==NULL)
	return ;
	if(hd==level)
	printf("%d ",root->data);
	printverticalorder(root->left,level,hd-1);
	printverticalorder(root->right,level,hd+1);
}
/*
function verticalorder prints the vertical view of a tree by taking help of a printverticalorder
*/
void verticalorder(struct tree *root)
{
	if(root==NULL)
	return ;
	int level,min=0,max=0,i=1;
	findminnmax(root,&min,&max,0);
	for(level=min;level<=max;level++)
	{
		printf("level %d:\n",i);
		printverticalorder(root,level,0);
		printf("\n");
		i++;
	}
}

/*printleft prints left part of each subtree calling itself recursively until it reaches a leaf node so it has void return data type*/
void printleft(struct tree *root){
    	if (root == NULL){
        	return;
   	}
    	printleft(root->left);
		printf("%d ",root->data);
}
/*printright prints right part of each subtree calling itself recursively until it reaches a leaf node so it has void return data type*/
void printright(struct tree *root){
    	if(root == NULL){
        	return;
    	}
    	printf("%d ",root->data);
    	printright(root->right);
}
/*function top_view() prints top view of a tree using printleft and printright function which works seperatly i.e. print left subtree and right subtree respectively*/
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
	printf("[1] To get the vertical order traversal of tree you created\n[2] To get the top view of the tree\n[3] To get the inorder traversal of the tree\n[4] To get level order traversal of the tree\n");
	scanf("%d",&opt);
	switch(opt){
	
		case 1:
			printf("Vertical order traversal:- \n");
			verticalorder(root);
			printf("\n");
			break;
		case 2:
			printf("Top veiw:- \n");
			top_view(root);
			printf("\n");
			break;
		case 3:
			printf("Inorder traversal:-\n");
			inorder(root);
			printf("\n");
			break;
		case 4:
			printf("Level order traversal:- ");
			printlevel(root);
			break;
		
	}}
	printf("done:)");
	return 0;
}
