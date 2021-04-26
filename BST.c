 /* @file    BST.c
 * @brief   Add one line description here
 * @author  [Sakshi Gupta](https://github.com/sg5915076)
 */
 
 #include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct bst
{
int data;
struct bst*left;
struct bst*right;

}node;
node*create();
void insert(node* , node*);
void inorder(node*);
int main()
{
char ch;
node*root=NULL,*N;
do
{
N=create();
if(root==NULL)
root=N;
else
insert(root,N);
printf("want to insert more");
getchar();
scanf("%c",&ch);
}while(ch=='y'|| ch=='Y');

printf("inorder traversal");
inorder(root);
return(0);


}
node*create()
{
node*N;
printf("enter data");

N=(node*)malloc(sizeof(node));
scanf("%d",&N->data);
N->left=NULL;
N->right=NULL;
return N;
}
void insert(node*root,node*N)
{
if(N->data < root->data)
{
if(root->left!=NULL)
insert(root->left,N);
else
root->left=N;
}
if(N->data>root->data)
{
if(root->right!=NULL)
insert(root->right,N);
else
root->right=N;

}
}
void  inorder(node*root)
{
if(root!=NULL)
{inorder(root->left);
printf("%d\n",root->data);
inorder(root->right);
}
}
