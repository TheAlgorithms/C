/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2){
    int sequence1[100] ={0}, sequence2[100]={0}, num_of_node1 =0,num_of_node2 =0;
    
    num_of_node1 = sequence(root1,sequence1,num_of_node1);
    num_of_node2 = sequence(root2,sequence2,num_of_node2);

    if (num_of_node1 != num_of_node2)
        return false;
       
    for (int i = 0;i<num_of_node1; i++){
        if (sequence1[i] != sequence2[i])
            return false;
    }
    return true;
}


int sequence(struct TreeNode* root ,int *list , int num_of_node){

    if (!root)
        return num_of_node;
    
    if (!root->left &&  !root->right){
        list[num_of_node] = root->val;
        num_of_node ++;
        return num_of_node;
    }
    
    num_of_node = sequence(root->left ,list , num_of_node);
    num_of_node = sequence(root->right ,list , num_of_node);
    
    return num_of_node; 
}
