#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode *binTree;
typedef struct TreeNode
{
	char data;
	binTree left;
	binTree right;
}treeNode;

typedef struct Stack *ptrstack;
typedef struct Stack
{
	binTree data[100];
	int front;
}stack;

ptrstack creat_stack()
{
	ptrstack s = (ptrstack)malloc(sizeof(stack));
	s->front = 0;
	return s;
}

void push(ptrstack s, binTree bt)
{
	s->data[s->front] = bt;
	s->front += 1;
}

binTree pop(ptrstack s)
{
	s->front -= 1;
	return s->data[s->front];
}

int is_empty(ptrstack s)
{
	if(s->front == 0)
		return 1;
	else
		return 0;
}

binTree creat_bin_tree()
{
	binTree bt;
	char ch;
	scanf("%c", &ch);
	if(ch == '#')
		bt = NULL;
	else{
		bt = (binTree)malloc(sizeof(treeNode));
		if(!bt)
			exit(0);
		bt->data = ch;
		bt->left = creat_bin_tree();
		bt->right = creat_bin_tree();
	}
	return bt;
}

void in_order_traversal1(binTree bt)
{
	if(bt){
		in_order_traversal1(bt->left);
		printf("%c\n", bt->data);
		in_order_traversal1(bt->right);
	}
}

void in_order_traversal(binTree bt)
{
	binTree t = bt;
	ptrstack s = creat_stack();
	while(t || !is_empty(s)){
		while(t){
			push(s, t);
			t = t->left;
		}
		if(!is_empty(s)){
			t = pop(s);
			printf("%c\n", t->data);
			t = t->right;
		}
	}
}

int main(int argc, char const *argv[])
{
	binTree tree;
	tree = creat_bin_tree();
	in_order_traversal1(tree);
	// in_order_traversal(tree);
	return 0;
}
