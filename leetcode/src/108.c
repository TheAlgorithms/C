/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *convertBST(int *nums, int left, int right)
{
    if (left > right)
        return NULL;
    else
    {
        int mid = (right + left) / 2;
        struct TreeNode *new_val = malloc(sizeof(struct TreeNode));
        new_val->val = nums[mid];
        new_val->left = convertBST(nums, left, mid - 1);
        new_val->right = convertBST(nums, mid + 1, right);
        return new_val;
    }
}

struct TreeNode *sortedArrayToBST(int *nums, int numsSize)
{
    if (numsSize == 0)
        return NULL;
    else
        return convertBST(nums, 0, numsSize - 1);
}
