#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode *p, struct TreeNode *q) {
    if (p == NULL && q == NULL)
        return true;
    else if (p && q) {
        if (p->val == q->val
                && isSameTree(p->left, q->left)
                && isSameTree(p->right, q->right))
            return true;
        else return false;
    }
    else return false;
}

void printTreePreOrder(struct TreeNode *p) {
    if (p != NULL) {
        printf("%d", p->val);
        printTreePreOrder(p->left);
        printTreePreOrder(p->right);
    }
    else printf("#");
}

int main() {
    struct TreeNode *t = (struct TreeNode *)calloc(3, sizeof(struct TreeNode));
    struct TreeNode *p = t;
    p->val = 1;
    p->left = ++t;
    t->val = 2;
    t->left = t->right = NULL;
    p->right = ++t;
    t->val = 3;
    t->left = t->right = NULL;
    printTreePreOrder(p); printf("\n");

    t = (struct TreeNode *)calloc(3, sizeof(struct TreeNode));
    struct TreeNode *q = t;
    q->val = 1;
    q->left = ++t;
    t->val = 2;
    t->left = t->right = NULL;
    q->right = ++t;
    t->val = 4;
    t->left = t->right = NULL;
    printTreePreOrder(q); printf("\n");

    printf("%d\n", isSameTree(p, q));

    return 0;
}
