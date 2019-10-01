#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct bstNode{
    char element[10];
    int key;
    struct bstNode *left;
    struct bstNode *right;
} BSTNode;

typedef struct{
    BSTNode *root;
    int nodecount;
} BST;

BST *create_bst(){
    BST *tree;
    tree = (BST*) malloc(sizeof(BST));
    tree->root = NULL;
    tree->nodecount = 0;
    return tree;
}

BSTNode *create_bstNode(char *e, int key){
	BSTNode *node = (BSTNode *) malloc(1*sizeof(BSTNode));
	node->left = NULL;
	node->right = NULL; 
	node->key = key;
	strcpy(node->element, e);
	return node;
}

int size(BST *bst){
    return bst->nodecount;
}

char *findhelp(BSTNode *rt, int key, char x[]){
    if(rt == NULL){
        return NULL;
    }
    if(rt->key > key){
        return findhelp(rt->left, key, x);
    }else if(rt->key == key){
        return rt->element;
    }else{
        return findhelp(rt->right, key, x);
    }
}

char *find(BST *bst, int key, char x[]){
    return findhelp(bst->root, key, x);
}

BSTNode *inserthelp(BSTNode *rt, int key, char x[]){
    if(rt == NULL){
        return create_bstNode(x, key);
    }else if(rt->key > key){
        rt->left = inserthelp(rt->left, key, x);
    }else{
        rt->right = inserthelp(rt->right, key, x);
    }
    return rt;
}

void insert(BST *bst, int key, char x[]){
    bst->root = inserthelp(bst->root, key, x);
    bst->nodecount++;
}

BSTNode *getmin(BSTNode *rt){
    if(rt->left == NULL){
        return rt;
    }
    return getmin(rt->left);
}

BSTNode *deletemin(BSTNode *rt){
    if(rt->left == NULL){
        return rt->right;
    }
    rt->left = deletemin(rt->left);
    return rt;
}

BSTNode *removehelp(BSTNode *rt, int key, char x[]){
    if(rt == NULL){
        return NULL;
    }
    if(rt->key > key){
        rt->left = removehelp(rt->left, key, x);
    }else if(rt->key < key){
        rt->right = removehelp(rt->right, key, x);
    }else{
        if(rt->left == NULL){
            BSTNode *aux = rt->right;
            free(rt);
            return aux;
        }else if(rt->right == NULL){
            BSTNode *aux = rt->left;
            free(rt);
            return aux;
        }else{
            BSTNode *temp;
            //temp = (BSTNode*) malloc(sizeof(BSTNode));
            temp = getmin(rt->right);
            strcpy(rt->element, temp->element);
            rt->key = temp->key;
            rt->right = deletemin(rt->right);
        }
    }
}

char *remover(BST *bst, int key, char x[]){
    char *temp;
    temp = findhelp(bst->root, key, x);
    if(temp != NULL){
        bst->root = removehelp(bst->root, key, x);
        bst->nodecount--;
    }
    return temp;
}

void visit_pos(BSTNode *rt){
    if(rt != NULL){
		visit_pos(rt->left);
		visit_pos(rt->right);
		free(rt);
    }
}

int main(){

    return 0;
}
