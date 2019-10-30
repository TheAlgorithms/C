/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <limits.h>

typedef struct {
    int *values;
    int CurrentIndex;
    int NumberOfNodes;
} BSTIterator;

void TraverseAndAssign(struct TreeNode *root, BSTIterator *obj) {
    if(!root)
        return;
    if(root->left) 
        TraverseAndAssign(root->left, obj);
    obj->values[obj->CurrentIndex] = root->val;
    obj->CurrentIndex++;
    if(root->right)
        TraverseAndAssign(root->right, obj);
}

int TotalNodes(struct TreeNode *root) {
    if(!root) 
        return 0;
    int nodes_left = TotalNodes(root->left);
    int nodes_right = TotalNodes(root->right);
    return nodes_left + nodes_right + 1;
}

BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    int n = TotalNodes(root);
    int size = n+1;
    printf("%d", size);
    BSTIterator *obj = (BSTIterator*)malloc(sizeof(BSTIterator));
    obj->values = (int*)calloc(size, sizeof(int));
    obj->CurrentIndex = 0;
    obj->NumberOfNodes = n;
    obj->values[size - 1] = INT_MAX;
    TraverseAndAssign(root, obj);
    obj->CurrentIndex = 0;
    return obj;
}

/** @return the next smallest number */
int bSTIteratorNext(BSTIterator* obj) {
    int NextValue = obj->values[obj->CurrentIndex];
    obj->CurrentIndex++;
    return NextValue;
}

/** @return whether we have a next smallest number */
bool bSTIteratorHasNext(BSTIterator* obj) {
    if(!obj->NumberOfNodes) {
        return false;
    }
    printf(" Here ");
    return (obj->values[obj->CurrentIndex] == INT_MAX) ? false : true;
}

void bSTIteratorFree(BSTIterator* obj) {
    free(obj->values);
    free(obj);
}
