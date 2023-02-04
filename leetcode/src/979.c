/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct NodeDistributeInfo {
    int distributeMoves;
    int distributeExcess;
};

struct NodeDistributeInfo* getDisturb(struct TreeNode* node) {
    struct NodeDistributeInfo* result = malloc(sizeof(struct NodeDistributeInfo));

    if (node == NULL) {
        result->distributeMoves = 0;
        result->distributeExcess = 1;
        return result;
    }

    struct NodeDistributeInfo* leftDistribute = getDisturb(node->left);
    struct NodeDistributeInfo* rightDistribute = getDisturb(node->right);

    int coinsToLeft = 1 - leftDistribute->distributeExcess;
    int coinsToRight = 1 - rightDistribute->distributeExcess;

    // Calculate moves as excess and depth between left and right subtrees.
    result->distributeMoves = leftDistribute->distributeMoves + rightDistribute->distributeMoves + abs(coinsToLeft) + abs(coinsToRight);
    result->distributeExcess = node->val - coinsToLeft - coinsToRight;

    free(leftDistribute);
    free(rightDistribute);

    return result;
}

// Depth-first search .
// On each node-step we try to recombinate coins between left and right subtree. 
// We know that coins are the same number that nodes, and we can get coins by depth
// Runtime: O(n)
// Space: O(1)
int distributeCoins(struct TreeNode* root) {
    return getDisturb(root)->distributeMoves;
}
