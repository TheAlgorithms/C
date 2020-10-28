// Code for the preorder inorder and post order traversals of a binary tree

#include <stdio.h>
#include <stdlib.h>

// structure of node
struct node
{
    int data;
    struct node *right;
    struct node *left;
};

// Links new node to  a tree
struct node* new_node(int data)
{
    struct node * temp= (struct node*)malloc(sizeof(struct node));
    temp->right=NULL;
    temp->left=NULL;
    temp->data=data;
    return temp;
}

// Traversal functions
void preorder(struct node *head)
{
    if(head!=NULL)
    {
        printf("%d   ", head->data);
        preorder(head->left);
        preorder(head->right);
    }

}

void inorder(struct node *head)
{
    if(head!=NULL)
    {
        inorder(head->left);
        printf("%d   ", head->data);
        inorder(head->right);
    }

}

void postorder(struct node *head)
{
    if(head!=NULL)
    {
        postorder(head->left);
        postorder(head->right);
        printf("%d   ", head->data);
    }
}

int main()
{
    //Creating a tree
    struct node*head=new_node(10);
    head->right=new_node(15);
    head->left=new_node(16);
    head->right->right=new_node(11);
    head->left->right=new_node(12);
    head->left->left=new_node(13);

    /*
         10
        /  \
       16   15
      /  \    \
     13  12    11

    */
    printf("The inorder traversal is: ");
    inorder(head);
    printf("\n");
    printf("The preorder traversal is:  ");
    preorder(head);
    printf("\n");
    printf("The postorder traversal is: ");
    postorder(head);
    printf("\n");
    return 0;
}
