#include <stdio.h>
#include <stdlib.h>

typedef struct Tree
{
    int data;
    struct Tree* left;
    struct Tree* right;
} Tree;

void MorrisTraversal(Tree* root)
{
    Tree *current, *pre;

    if (root == NULL)
        return;

    current = root;
    while (current != NULL)
    {
        if (current->left == NULL)
        {
            printf("%d ", current->data);
            current = current->right;
        }
        else
        {
            pre = current->left;
            while (pre->right != NULL && pre->right != current)
                pre = pre->right;

            if (pre->right == NULL)
            {
                pre->right = current;
                current = current->left;
            }

            else
            {
                pre->right = NULL;
                printf("%d ", current->data);
                current = current->right;
            }
        }
    }
}
Tree* newTree(int data)
{
    Tree* node = (Tree*)malloc(sizeof(Tree));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

int main()
{
    Tree* root = newTree(1);
    root->left = newTree(2);
    root->right = newTree(3);
    root->left->left = newTree(4);
    root->left->right = newTree(5);

    MorrisTraversal(root);

    return 0;
}
