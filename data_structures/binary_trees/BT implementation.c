//Binary Tree implementation---> creation,insertion and deletion , traversal,searching

#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node* left;
	struct node* right;
};
struct node* getnode()
{
	struct node* p;
	p=(struct node*)malloc(sizeof(struct node));
	return p;
}
struct node* maketree(int x)
{
	struct node* p;
	p=getnode();
	p->info=x;
	p->left=NULL;
	p->right=NULL;	
	return p;
}
struct node* setleft(struct node* p, int x)
{

	if(p==NULL)
	printf("Void insrtion");
	else if(p->left!=NULL)
	printf("Invalid insertion");
	else 
	p->left=maketree(x);
}
struct node* setright(struct node* p, int x)
{

	if(p==NULL)
	printf("Void insrtion");
	else if(p->right!=NULL)
	printf("Invalid insertion");
	else 
	p->right=maketree(x);
}
void pretrav(struct node* p)
{int count =0;
		if(p!=NULL)
	{
	pretrav(p->left);
	pretrav(p->right);
	printf("%d",p->info);
		
	
}

}
void posttrav(struct node* p)
{
		if(p!=NULL)
	{
	printf("%d",p->info);
	posttrav(p->left);
	posttrav(p->right);
	
}
}
void intrav(struct node* p)
{
	if(p!=NULL)
	{
	
	intrav(p->left);
	printf("%d",p->info);
	intrav(p->right);
	}
}

int main()
{
	struct node* q;
	q=maketree(23);
	setright(q,2);
	setleft(q,45);
	pretrav(q);
	printf("\n");
		intrav(q);
	printf("\n");
		posttrav(q);
	printf("\n");
	return 0;
}
