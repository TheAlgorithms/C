/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct List {
    struct TreeNode* node;
    struct List* next;
};

bool findTargetPath(struct TreeNode* node, struct TreeNode* target, struct List* path){
    if (node == NULL){
        return false;
    }
    
    struct List* pathItem = malloc(sizeof(struct List));
    pathItem->node = node;
    pathItem->next = NULL;
    path->next = pathItem;
    
    if (node->val == target->val){
        return true;
    }

    if (findTargetPath(node->left, target, pathItem)){
        return true;
    }
    
    if (findTargetPath(node->right, target, pathItem)){
        return true;
    }
    
    path->next = NULL;
    free(pathItem);
    return false;
}

void freeList(struct List* target){
    if (target->next != NULL){
        freeList(target->next);
    }
    
    free(target);
}


// Find full path for p and q.
// Find the longest common path in pathes.
// Runtime: O(n)
// Space: O(n)
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct List* pPath = malloc(sizeof(struct List));
    struct List* qPath = malloc(sizeof(struct List));
    
    findTargetPath(root, p, pPath);
    findTargetPath(root, q, qPath);
    
    struct TreeNode* lowestTreeNode = NULL;
    struct List* pPathCursor = pPath->next;
    struct List* qPathCursor = qPath->next;
    while(pPathCursor != NULL && qPathCursor != NULL) {
        if (pPathCursor->node->val == qPathCursor->node->val){
            lowestTreeNode = pPathCursor->node;
            pPathCursor = pPathCursor->next;
            qPathCursor = qPathCursor->next;
            continue;
        }

        break;
    }
    
    freeList(pPath);
    freeList(qPath);
    
    return lowestTreeNode;
}
