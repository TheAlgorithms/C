#include<stdio.h>
#include<stdlib.h>

/*Threaded Binary Tree is a binary tree variant in which all left child
pointers that are NULL (in Linked list representation) point to its
in-order predecessor, and all right child pointers that are NULL
(in Linked list representation) point to its in-order successor.

This file is a simple implementation of a Threaded Binary Tree
with the following functionalities:
 - Insertion
 - Search
 - Deletion
 - Listing of node keys inorder,preorder, postorder
*/

// Node, the basic data structure in the tree
typedef struct Node
{
	int data;
	struct Node *llink;
	struct Node *rlink;
}node;

node* create_node(int data)
{
	node *ptr=(node*) malloc(sizeof(node));
	ptr->rlink=ptr->llink=NULL;
	ptr->data=data;
	return ptr;
}

void insert_BT(node **root,int data)
{
	node *new_node=create_node(data);
	node *temp;  //to be deleted
	node *prev;  //keeps track of the parent of the element deleted
	if(*root==NULL)
	{
		*root=new_node;
	}
	else
	{
		temp=*root;
		prev=NULL;
		while(temp!=NULL)
		{
			if(new_node->data>temp->data)
			{
				prev=temp;
				temp=temp->rlink;
			}
			else if(new_node->data<temp->data)
			{
				prev=temp;
				temp=temp->llink;
			}
			else
			{
				return;
			}
		}

		if(new_node->data>prev->data)
		{
			prev->rlink=new_node;
		}
		else
		{
			prev->llink=new_node;
		}
	}
}

// returns "Element found" if the search element is present else returns, "Element not found"
void search(node *root, int ele)
{
	node *temp=root;
	while(temp!=NULL)
	{
		if(temp->data==ele)
		{
			break;
		}
		else if(ele>temp->data)
		{
			temp=temp->rlink;
		}
		else
		{
			temp=temp->llink;
		}
	}

	if(temp==NULL)
	{
		printf("%s\n","Element not found." );
	}
	else 	printf("%s\n","Element found." );
}

void inorder_display(node *curr)
{
	if(curr!=NULL)
	{
		inorder_display(curr->llink);
		printf("%d\t",curr->data );
		inorder_display(curr->rlink);
	}

}

void postorder_BT(node *curr)
{
	if(curr!=NULL)
	{
		postorder_BT(curr->llink);
		postorder_BT(curr->rlink);
		printf("%d\t",curr->data);
	}

}

void preorder_BT(node *curr)
{
	if(curr!=NULL)
	{
		printf("%d\t",curr->data);
		preorder_BT(curr->llink);
		preorder_BT(curr->rlink);
	}
}

// deletes the node if present, else it takes no action.
void delete_BT(node **root,int ele)
{
	node* temp;
	node *prev;
	if(*root==NULL)	return;
	else
	{
		temp=*root;
		prev=NULL;
		// search
		while(temp!=NULL)
		{
			if(temp->data==ele)
			{
				break;
			}
			else if(ele>temp->data)
			{
				prev=temp;
				temp=temp->rlink;
			}
			else
			{
				prev=temp;
				temp=temp->llink;
			}
			}
		}

		if(temp==NULL)
			return;
		else
		{
			node *replacement;   //deleted node's replacement
			node *t;
			if(temp->llink==NULL && temp->rlink==NULL)
			{
				replacement=NULL;
			}
			else if(temp->llink==NULL && temp->rlink!=NULL)
			{
				replacement=temp->rlink;
			}
			else if(temp->llink!=NULL && temp->rlink==NULL)
			{
				replacement=temp->llink;
			}
			else
			{
				replacement=temp->rlink;  //replaced with inorder successor
				t=replacement;
				while(t->llink!=NULL)
				{
					t=t->llink;
				}
				t->llink=temp->llink;  //leftmost node of the replacement is linked to the left child of the deleted node
			}

			if(temp==*root)
			{
				free(*root);
				*root=replacement;
			}
			else if(prev->llink==temp)
			{
				free(prev->llink);
				prev->llink=replacement;
			}
			else if(prev->rlink==temp)
			{
				free(prev->rlink);
				prev->rlink=replacement;
			}
		}
	}


void main()
{
	printf("BINARY TREE: \n");
	node *root=NULL;
	int choice,n;
	do
	{
		printf("%s\n","1. Insert into BT" );
		printf("%s\n","2. Print BT - inorder" );
		printf("%s\n","3. Print BT - preorder" );
		printf("%s\n","4. print BT - postorder" );
		printf("%s\n","5. delete from BT" );
		printf("%s\n","6. search in BT" );
		scanf("%d",&choice);


	switch(choice)
	{
		case 1:
		printf("%s\n","Enter a no:" );
		scanf("%d",&n);
		insert_BT(&root,n);
		break;
		case 2:
		inorder_display(root);
		printf("\n");
		break;
		case 3:
		preorder_BT(root);
		printf("\n");
		break;
		case 4:
		postorder_BT(root);
		printf("\n");
		break;
		case 5:
		printf("%s\n","Enter a no:" );
		scanf("%d",&n);
		delete_BT(&root,n);
		break;
		case 6:
		printf("%s\n","Enter a no:" );
		scanf("%d",&n);
		search(root,n);
		break;
	}

	}while(choice!=0);
}
