#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	struct node* left;
	struct node* right;
	int data;
} node;

node* newNode(int data){
	node* tmp = (node*)malloc(sizeof(node));
	tmp->data = data;
	tmp->left = NULL;
	tmp->right = NULL;

	return tmp;
}

node* insert(node* root, int data){
	if (root == NULL)
		root = newNode(data);

	else if (data > root->data)
		root->right = insert(root->right, data);
	
	else if (data < root->data)
		root->left = insert(root->left, data);

	return root;
}

node* getMax(node* root){
	if (root->right == NULL)
		return root;
	else
		root->right = getMax(root->right);
}

node* delete(node* root, int data){
	if (root == NULL) 
		return root;

	else if (data > root->data)
		root->right = delete(root->right, data);

	else if (data < root->data)
		root->left = delete(root->left, data);
	
	else if (data == root->data){
		if ((root->left == NULL) && (root->right == NULL)){
			free(root);
			return NULL;
		}
		else if (root->left == NULL){
			node* tmp = root->right;
			free(root);
			return tmp;
		}
		else if (root->right == NULL){
			node* tmp = root->left;
			free(root);
			return tmp;
		}
		else {
			node* tmp = getMax(root->left);
			root->data = tmp->data;
			root->left = delete(root->left, tmp->data);
		}
	}
	return root;
}

int find(node* root, int data){
	if (root == NULL)
		return 0;
	else if (data > root->data)
		return find(root->right, data);
	else if (data < root->data)
		return find(root->left, data);
	else if (data == root->data)
		return 1;
}

int height(node* root){
	if (root == NULL)
		return 0;
	else{
		int right_h = height(root->right);
		int left_h = height(root->left);
		
		if (right_h > left_h)
			return (right_h + 1);
		else
			return (left_h + 1);
	}
}

void purge(node* root){
	if (root != NULL){
		if (root->left != NULL)
			purge(root->left);
		if (root->right != NULL)
			purge(root->right);
		free(root);
	}
}

void inOrder(node* root){
	if(root != NULL){
		inOrder(root->left);
		printf("\t[ %d ]\t", root->data);
		inOrder(root->right);
	}
}

void main(){
	node* root = NULL;
	int opt = 1;
	int data;

	while (opt != 0){
		printf("\n\n[1] Insert Node\n[2] Delete Node\n[3] Find a Node\n[4] Get current Height\n[5] Print Tree in Crescent Order\n[0] Quit\n");
		scanf("%d",&opt);

		switch(opt){
			case 1:	printf("Enter the new node's value:\n");
				scanf("%d",&data);
				root = insert(root,data);
				break;

			case 2: printf("Enter the value to be removed:\n");
				if (root != NULL){
					scanf("%d",&data);
					root = delete(root,data);
				}
				else 
					printf("Tree is already empty!\n");
				break;

			case 3: printf("Enter the searched value:\n");
				scanf("%d",&data);
				find(root,data) ? printf("The value is in the tree.\n") : printf("The value is not in the tree.\n");
				break;
				
			case 4: printf("Current height of the tree is: %d\n", height(root));
				break;

			case 5: inOrder(root);
				break;
		}
	}

	purge(root);
}
