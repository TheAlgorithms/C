#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node{
    int val;
    struct node* par;
    struct node* left;
    struct node* right;
    int color;
}Node;

// Create a new node
Node* newNode(int val, Node* par){
    Node* create = (Node*)(malloc(sizeof(Node)));
    create->val = val;
    create->par = par;
    create->left = NULL;
    create->right = NULL;
    create->color = 1;
}

// Check if the node is the leaf
int isLeaf(Node* n){
    if(n->left == NULL && n->right == NULL){
        return 1;
    }
    return 0;
}

// Left Rotate
Node* leftRotate(Node* node){
    Node* parent = node->par;
    Node* grandParent = parent->par;

    parent->right = node->left;
    if(node->left != NULL){
        node->left->par = parent;
    }
    node->par = grandParent;
    parent->par = node;
    node->left = parent;
    if(grandParent != NULL){
        if(grandParent->right == parent){
            grandParent->right = node;
        }
        else{
            grandParent->left = node;
        }
    }
    return node;
}

// Right Rotate
Node* rightRotate(Node* node){
    Node* parent = node->par;
    Node* grandParent = parent->par;

    parent->left = node->right;
    if(node->right != NULL){
        node->right->par = parent;
    }
    node->par = grandParent;
    parent->par = node;
    node->right = parent;
    if(grandParent != NULL){
        if(grandParent->right == parent){
            grandParent->right = node;
        }
        else{
            grandParent->left = node;
        }
    }
    return node;
}


// Check the node after the insertion step
void checkNode(Node* node){

    // If the node is the root
    if(node == NULL || node->par == NULL){
        return;
    }
    Node* child = node;
    //If it is a black node or its parent is a black node
    if(node->color == 0 || (node->par)->color == 0){
        // Dont Do Anything
        return;
    }

    // Both parent and child are red
    // Check For Uncle
    Node* parent = node->par;
    Node* grandParent = parent->par;

    // If grandParent is NULL, then parent is the root.
    // Just make the root black.
    if(grandParent == NULL){
        parent->color = 0;
        return;
    }


    // If both the children of the grandParent are red
    if(grandParent->right != NULL && (grandParent->right)->color == 1 && grandParent->left != NULL && (grandParent->left)->color == 1){
        // Make the grandParent red and both of its children black
        (grandParent->right)->color = 0;
        (grandParent->left)->color = 0;
        grandParent->color = 1;
        return;
    }
    else{
        // The only option left is rotation.
        Node* greatGrandParent = grandParent->par;
        // Right Case
        if(grandParent->right == parent){
            //Right Right Case
            if(parent->right == node){
                grandParent->right = parent->left;
                if(parent->left != NULL){
                    (parent->left)->par = grandParent;
                }
                parent->left = grandParent;
                grandParent->par = parent;

                // Attach to existing Tree;
                parent->par = greatGrandParent;
                if(greatGrandParent != NULL){
                    if(greatGrandParent->left != NULL && greatGrandParent->left == grandParent){
                        greatGrandParent->left = parent;
                    }
                    else{
                        greatGrandParent->right = parent;
                    }
                }

                // Change the colors
                parent->color = 0;
                grandParent->color = 1;
            }
            else{   // Right Left Case
                // First step -> Parent Child Rotation
                parent->left = child->right;
                if(child->right != NULL){
                    (child->right)->par = parent;
                }
                child->right = parent;
                parent->par = child;
                
                // Second step -> Child and GrandParent Rotation
                grandParent->right = child->left;
                if(child->left != NULL){
                    (child->left)->par = grandParent;
                }
                child->left = grandParent;
                grandParent->par = child;

                // Attach to the existing tree
                child->par = greatGrandParent;
                if(greatGrandParent != NULL){
                    if(greatGrandParent->left != NULL && greatGrandParent->left == grandParent){
                        greatGrandParent->left = child;
                    }
                    else{
                        greatGrandParent->right = child;
                    }
                }

                // Change The Colors
                child->color = 0;
                grandParent->color = 1;
            }
        }
        else{   // Left Case
            //Left Left Case
            if(parent->left == node){
                grandParent->left = parent->right;
                if(parent->right != NULL){
                    (parent->right)->par = grandParent;
                }
                parent->right = grandParent;
                grandParent->par = parent;

                // Attach to existing Tree;
                parent->par = greatGrandParent;
                if(greatGrandParent != NULL){
                    if(greatGrandParent->left != NULL && greatGrandParent->left == grandParent){
                        greatGrandParent->left = parent;
                    }
                    else{
                        greatGrandParent->right = parent;
                    }
                }

                // Change the colors
                parent->color = 0;
                grandParent->color = 1;
            }
            else{   //Left Right Case
                
                // First step -> Parent Child Rotation
                parent->right = child->left;
                if(child->left != NULL){
                    (child->left)->par = parent;
                }
                child->left = parent;
                parent->par = child;
                
                // Second step -> Child and GrandParent Rotation
                grandParent->left = child->right;
                if(child->right != NULL){
                    (child->right)->par = grandParent;
                }
                child->right = grandParent;
                grandParent->par = child;

                // Attach to the existing tree
                child->par = greatGrandParent;
                if(greatGrandParent != NULL){
                    if(greatGrandParent->left != NULL && greatGrandParent->left == grandParent){
                        greatGrandParent->left = child;
                    }
                    else{
                        greatGrandParent->right = child;
                    }
                }

                // Change The Colors
                child->color = 0;
                grandParent->color = 1;
            }
        }
    }
}

// To insert a node in the existing tree
void insertNode(int val, Node** root){
    Node* buffRoot = *root;
    while(buffRoot){
        if(buffRoot->val > val){
            // Go left
            if(buffRoot->left != NULL){
                buffRoot = buffRoot->left;
            }
            else{
                //Insert The Node
                Node* toInsert = newNode(val, buffRoot);
                buffRoot->left = toInsert;
                buffRoot = toInsert;

                //Check For Double Red Problems
                break;
            }
        }
        else{

            // Go right
            if(buffRoot->right != NULL){
                buffRoot = buffRoot->right;
            }
            else{
                //Insert The Node
                Node* toInsert = newNode(val, buffRoot);
                buffRoot->right = toInsert;
                buffRoot = toInsert;

                //Check For Double Red Problems
                break;
            }
        }
    }


    while(buffRoot != *root){
        checkNode(buffRoot);
        if(buffRoot->par == NULL){
            *root = buffRoot;
            break;
        }
        buffRoot = buffRoot->par;
        if(buffRoot == *root){
            buffRoot->color = 0;
        }
    }
}

void checkForCase2(Node* toDelete, int delete, int fromDirection, Node** root){

    if(toDelete == (*root)){
        (*root)->color = 0;
        return;
    }

    if(!delete && toDelete->color == 1){
        if(!fromDirection){
            if(toDelete->right != NULL){
                toDelete->right->color = 1;
            }
        }
        else{
            if(toDelete->left != NULL){
                toDelete->left->color = 1;
            }
        }
        toDelete->color = 0;
        return;
    }


    // Get the sibling for further inspection
    Node* sibling;
    Node* parent = toDelete->par;
    int locateChild = 0;    // 0 if toDeleted is left of its parent else 1
    if(parent->right == toDelete){
        sibling = parent->left;
        locateChild = 1;
    }
    else{
        sibling = parent->right;
    }

    //Case 2.1. i.e. if the any children of the sibling is red
    if((sibling->right != NULL && sibling->right->color == 1) || (sibling->left != NULL && sibling->left->color == 1)){
        if(sibling->right != NULL && sibling->right->color == 1){

            // Sibling is left and child is right. i.e. LEFT RIGHT ROTATION
            if(locateChild == 1){
                
                int parColor = parent->color;

                // Step 1: Left rotate sibling
                sibling = leftRotate(sibling->right);

                // Step 2: Right rotate updated sibling
                parent = rightRotate(sibling);

                // Check if the root is rotated
                if(parent->par == NULL){
                    *root = parent;
                }

                // Step 3: Update the colors
                parent->color = parColor;
                parent->left->color = 0;
                parent->right->color = 0;

                // Delete the node (present at parent->right->right)
                if(delete){
                    if(toDelete->left != NULL){
                        toDelete->left->par = parent->right;
                    }
                    parent->right->right = toDelete->left;
                    free(toDelete);
                }

            }
            else{   // Sibling is right and child is also right. i.e. LEFT LEFT ROTATION    

                int parColor = parent->color;

                // Left Rotate the sibling
                parent = leftRotate(sibling);

                // Check if the root is rotated
                if(parent->par == NULL){
                    *root = parent;
                }

                // Update Colors
                parent->color = parColor;
                parent->left->color = 0;
                parent->right->color = 0;

                // Delete the node (present at parent->left->left)
                if(delete){
                    if(toDelete->right != NULL){
                        toDelete->right->par = parent->left;
                    }
                    parent->left->left = toDelete->left;
                    free(toDelete);
                }

            }
        }
        else{

            // Sibling is right and child is left. i.e. RIGHT LEFT ROTATION
            if(locateChild == 0){
                
                int parColor = parent->color;

                // Step 1: Right rotate sibling
                sibling = rightRotate(sibling->left);

                // printf("%d - reached\n", sibling->val);
                // return;

                // Step 2: Left rotate updated sibling
                parent = leftRotate(sibling);

                // Check if the root is rotated
                if(parent->par == NULL){
                    *root = parent;
                }

                // Step 3: Update the colors
                parent->color = parColor;
                parent->left->color = 0;
                parent->right->color = 0;

                // Delete the node (present at parent->left->left)
                if(delete){
                    if(toDelete->right != NULL){
                        toDelete->right->par = parent->left;
                    }
                    parent->left->left = toDelete->right;
                    free(toDelete);
                }


            }
            else{   // Sibling is left and child is also left. i.e. RIGHT RIGHT ROTATION

                int parColor = parent->color;

                // Right Rotate the sibling
                parent = rightRotate(sibling);

                // Check if the root is rotated
                if(parent->par == NULL){
                    *root = parent;
                }

                // Update Colors
                parent->color = parColor;
                parent->left->color = 0;
                parent->right->color = 0;

                // Delete the node (present at parent->right->right)
                if(delete){
                    if(toDelete->left != NULL){
                        toDelete->left->par = parent->right;
                    }
                    parent->right->right = toDelete->left;
                    free(toDelete);
                }

            }
        }
    }
    else if(sibling->color == 0){   //Make the sibling red and recur for its parent

        // Recolor the sibling
        sibling->color = 1;

        // Delete if necessary
        if(delete){
            if(locateChild){
                toDelete->par->right = toDelete->left;
                if(toDelete->left != NULL){
                    toDelete->left->par = toDelete->par;
                }
            }
            else{
                toDelete->par->left = toDelete->right;
                if(toDelete->right != NULL){
                    toDelete->right->par = toDelete->par;
                }
            }
        }

        checkForCase2(parent, 0, locateChild, root);
    }
    else{   // Bring the sibling on top and apply 2.1 or 2.2 accordingly
        if(locateChild){    //Right Rotate

            toDelete->par->right = toDelete->left;
            if(toDelete->left != NULL){
                toDelete->left->par = toDelete->par;
            }

            parent = rightRotate(sibling);

            // Check if the root is rotated
            if(parent->par == NULL){
                *root = parent;
            }

            parent->color = 0;
            parent->right->color = 1;
            checkForCase2(parent->right, 0, 1, root);
        }
        else{   // Left Rotate

            toDelete->par->left = toDelete->right;
            if(toDelete->right != NULL){
                toDelete->right->par = toDelete->par;
            }
            parent = leftRotate(sibling);

            // Check if the root is rotated
            if(parent->par == NULL){
                *root = parent;
            }

            printf("\nroot - %d - %d\n", parent->val, parent->left->val);

            parent->color = 0;
            parent->left->color = 1;
            checkForCase2(parent->left, 0, 0, root);
        }
    }

}

// To delete a node from the tree
void deleteNode(int val, Node** root){
    Node* buffRoot = *root;

    //Search for the element in the tree
    while(1){
        
        if(val == buffRoot->val){
            // Node Found
            break;
        }

        if(val > buffRoot->val){
            if(buffRoot->right != NULL){
                buffRoot = buffRoot->right;
            }
            else{
                printf("Node Not Found!!!");
                return;
            }
        }
        else{
            if(buffRoot->left != NULL){
                buffRoot = buffRoot->left;
            }
            else{
                printf("Node Not Found!!!");
                return;
            }
        }
    }

    Node* toDelete = buffRoot;

    // Look for the leftmost of right node or right most of left node
    if(toDelete->left != NULL){
        toDelete = toDelete->left;
        while(toDelete->right != NULL){
            toDelete = toDelete->right;
        }
    }
    else if(toDelete->right != NULL){
        toDelete = toDelete->right;
        while(toDelete->left != NULL){
            toDelete = toDelete->left;
        }
    }

    if(toDelete == *root){
        *root = NULL;
        return;
    }

    // Swap the values
    buffRoot->val = toDelete->val;
    toDelete->val = val;

    // Checking for case 1
    if(toDelete->color == 1 || (toDelete->left != NULL && toDelete->left->color == 1) || (toDelete->right != NULL  && toDelete->right->color == 1)){
        
        // if it is a leaf
        if(toDelete->left == NULL && toDelete->right == NULL){
            // Delete instantly
            if(toDelete->par->left == toDelete){
                toDelete->par->left = NULL;
            }
            else{
                toDelete->par->right = NULL;
            }
        }
        else{   // else its child should be red

            // Check for the exitstence of left node
            if(toDelete->left != NULL){
                // The node should be right to its parent
                toDelete->par->right = toDelete->left;
                toDelete->left->par = toDelete->par;
                toDelete->left->color = 1;
            }
            else{   // else the right node should be red
                toDelete->par->left = toDelete->right;
                toDelete->right->par = toDelete->par;
                toDelete->right->color = 1;
            }
        }

        // Remove the node from memory
        free(toDelete);
    }
    else{   // Case 2
        checkForCase2(toDelete, 1, ((toDelete->par->right == toDelete)), root);
    }

    

}

void printInorder(Node* root){
    if(root != NULL){
        printInorder(root->left);
        printf("%d c-%d ", root->val, root->color);
        printInorder(root->right);
    }
}

void checkBlack(Node* temp,int c){
    if (temp==NULL){
        printf("%d ",c);
        return ;
    }
    if (temp->color==0){
        c++;
    }
    checkBlack(temp->left,c);
    checkBlack(temp->right,c);
}

int main(){
    Node* root = NULL;
    int scanValue, choice = 1;
    printf("1 - Input\n2 - Delete\n3 - Inorder Traversel\n0 - Quit\n\nPlease Enter the Choice - ");
    scanf("%d", &choice);
    while(choice){
        switch(choice){
            case 1:
                printf("\n\nPlease Enter A Value to insert - ");
                scanf("%d", &scanValue);
                if(root == NULL){
                    root = newNode(scanValue, NULL);
                    root->color = 0;
                }
                else{
                    insertNode(scanValue, &root);
                }
                printf("\nSuccessfully Inserted %d in the tree\n\n", scanValue);
                break;
            case 2:
                printf("\n\nPlease Enter A Value to Delete - ");
                scanf("%d", &scanValue);
                deleteNode(scanValue, &root);
                printf("\nSuccessfully Inserted %d in the tree\n\n", scanValue);
                break;
            case 3:
                printf("\nInorder Traversel - ");
                printInorder(root);
                printf("\n\n");
                // checkBlack(root,0);
                // printf("\n");
                break;
            default:
                if(root != NULL){
                    printf("Root - %d\n", root->val);
                }
        }
        printf("1 - Input\n2 - Delete\n3 - Inorder Traversel\n0 - Quit\n\nPlease Enter the Choice - ");
        scanf("%d", &choice);
    }
}



// 32 12 50 53 1 2 3 4 5 6 7 8 9
