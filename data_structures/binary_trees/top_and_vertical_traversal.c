#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

struct tree {
	int data;
	struct tree *left,*right;
};

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

void inorder(struct tree *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}


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


void printlevel(struct tree *root)
{
	int h=height(root);
	for(int i=1;i<=h;i++)
	{printf("\n");
		currentleveltraversal(root,i);
	}
//	printf("%d ->",root->data);
}

/*void verticalordertraversal(struct tree *root,int column)
{
	if(root==NULL)
	return;
	int min=1000,max=0;
	queue<tree*> q;
	struct tree *temp;
	q.push(root);
	while(q.empty())
	{
		temp=q.front();
		printf("%d ",temp->data);
		q.pop();
		hash[column]+=temp->data;
		if(temp->left!=NULL)
		q.push(root->left);
		if(temp->right!=NULL)
		q.push(root->right);
	}
	printf("\ndone....\n");
}*/

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

void printverticalorder(struct tree *root,int level,int hd)
{
	if(root==NULL)
	return ;
	if(hd==level)
	printf("%d ",root->data);
	printverticalorder(root->left,level,hd-1);
	printverticalorder(root->right,level,hd+1);
}

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


void printleft(struct tree *root){
    	if (root == NULL){
        	return;
   	}
    	printleft(root->left);
		printf("%d ",root->data);
}

void printright(struct tree *root){
    	if(root == NULL){
        	return;
    	}
    	printf("%d ",root->data);
    	printright(root->right);
}

void top_view(struct tree *root)
{
	printleft(root);
    printright(root->right);
}

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
