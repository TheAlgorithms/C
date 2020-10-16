#include<stdio.h>
#include<stdlib.h>

struct rec{
    int data;
    struct rec *left;
    struct rec *right;
};
int digit, count;

struct rec *tree = NULL;
struct rec *insert(struct rec *tree, int digit);
void inorder(struct rec *tree);
void  postorder(struct rec *tree);
void preorder(struct rec *tree);
void traversal();
void main(){
    int choice;
    while(1){
        printf("Enter your Choice:\n1.Insert\n2.Traversal\n3.Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the digit and to stop enter 999: ");
                scanf("%d", &digit);
                while(digit != 999){
                     tree = insert(tree, digit);
                     scanf("%d", &digit);
                }
                break;
            case 2:
                traversal();
                break;
            case 3:
                exit(1);
        }
    }
}

void traversal(){
    int option;
    while(1){
        printf("Enter your choice:\n1.Inorder\n2.Preorder\n3.Preorder\n4.Exit\n");
        scanf("%d", &option);
        switch(option){
            case 1:
                inorder(tree);                                              
                break;
            case 2:
                preorder(tree);
                break;
            case 3:
                postorder(tree);
                break;
            case 4:
                exit(0);
        }
    }
}

void inorder(struct rec *tree){
    if(tree != NULL){
        inorder(tree->left);
        printf("%d\t", tree->data);
        inorder(tree->right);
    }
}

void preorder(struct rec *tree){
    if(tree != NULL){
        preorder(tree->left);
        printf("%d\t", tree->data);
        preorder(tree->right);
    }
}

void postorder(struct rec *tree){
    if(tree != NULL){
        postorder(tree->left);
        printf("%d\t", tree->data);
        postorder(tree->right);
    }
}

struct rec *insert(struct rec *tree, int digit){  
    if(tree == NULL){
        tree = malloc(sizeof(tree));
        tree->left = NULL;
        tree->right = NULL;
        tree->data = digit;
        count++;
    } else {
        if(count % 2 == 0)
            tree->left = insert(tree->left, digit);
        else
            tree->right = insert(tree->right, digit);
    }
    return tree;
}
