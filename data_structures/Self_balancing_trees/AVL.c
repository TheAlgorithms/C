#include <iostream>
using namespace std;
typedef struct node{
	int data;
	node *right;
	node *left;
	int height;
}node;
int max(int a,int b);
int height(node *a)
{
	if(a == NULL)
		return 0;
	else 
		return a->height;
}
int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
node* newnode(int key)
{
	node *a = new node;
	a->data = key;
	a->left = NULL;
	a->right = NULL;
	a->height = 1;
	return a;
}
node* rightrotate(node *y)
{
	node *x = y->left;
	node *t = x->right;
	x->right = y;
	y->left = t;

	y->height = max(height(y->left),height(y->right))+ 1;
	x->height = max(height(x->left),height(x->right))+ 1;
	return x;
}
node* leftrotate(node *x)
{
	node *y = x->right;
	node *t = y->left;
	y->left = x;
	x->right = t;
	x->height = max(height(x->left),height(x->right))+1;
	y->height = max(height(y->left),height(y->right))+1;
}
int getbalance(node *a)
{
	if(a==NULL)
		return 0;
	return height(a->left) - height(a->right);
}
node* insert(node *node,int data)
{
	if(node == NULL)
		return newnode(data);
	if(data < node->data)
		node->left =  insert(node->left,data);
	else if (data > node->data)
		node ->right = insert(node->right,data);
	else
		return node;
	node ->height = 1 + max(height(node->left),height(node->right));
	int balance = getbalance(node);
	if(balance > 1 && data < node->left->data)
		return rightrotate(node);
	if(balance < -1 && data > node->right->data)
		return leftrotate(node);
	if(balance > 1 && data > node->left->data)
	{
		node->left = leftrotate(node->left);
		return rightrotate(node);
	}
	if(balance < -1 && data < node->right->data)
	{
		node ->right = rightrotate(node->right);
		return leftrotate(node);
	}	
	return node;
}
void preorder(node *root)
{
	if(root!=NULL)
	{
		cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}
void postorder(node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout << root->data << " ";
	}	
}
node* minnode(node *giv)
{
	node* temp =  giv;
	while(temp ->left != NULL)
	{
		temp = temp -> left;
	}
	return temp;
}
node* deletenode(node* root,int data)
{
	if(root == NULL)
		return root;
	if(data < root-> data)
		root->left = deletenode(root->left,data);
	else if(data > root->data)
		root->right = deletenode(root->right,data);
	else
	{
		 if((root->left == NULL) || (root->right == NULL) )
        {  
            node *temp;
            if(root->left == NULL)
            	temp = root->right;
            else
            	temp = root->left;
            if (temp == NULL)  
            {  
                temp = root;  
                root = NULL;  
            }  
            else  
            	*root = *temp; 
            free(temp);  
		}
		 else
        {
        	node* temp = minnode(root->right);
        	root->data = temp->data;
        	root->right = deletenode(root->right,temp->data);
        }        
	}
	if(root == NULL)
		return root;
	root->height = 1+ max(height(root->left),height(root->right));
	int balance = getbalance(root);
    if (balance > 1 && getbalance(root->left) >= 0)  
    	return rightrotate(root);    
    if (balance > 1 && getbalance(root->left) < 0)  
    {  
        root->left = leftrotate(root->left);  
        return rightrotate(root);  
    }    
    if (balance < -1 &&  getbalance(root->right) <= 0)  
        return leftrotate(root);  
    if (balance < -1 &&  getbalance(root->right) > 0)  
    {  
        root->right = rightrotate(root->right);  
        return leftrotate(root);  
    }  
    return root;
}
int main()
{
	node *root = NULL;
	while(1)
	{
		cout << "enter 1 to insert 2 to delete other for traversal"<< endl;
		int a;
		cin >> a;
		if(a == 1)
		{
			cout << "enter the element you want to insert - " << endl;
			int g;
			cin >> g;
			root = insert(root,g);
		}
		if(a == 2)
		{
			cout << "enter the element you want to delete - " << endl;
			int b;
			cin >> b;
			root = deletenode(root,b);
		}
		cout << endl << endl;
			cout << "preorder-> " ;preorder(root) ;cout << endl;
			cout << "inorder-> " ;inorder(root);cout  << endl;
			cout << "postorder-> ";postorder(root);cout  << endl;
		cout << endl << endl;
	}
}