/* Includes structure for a node and a newNode() function which
   can be used to create a new node in the tree. 
   It is assumed that the data in nodes will be an integer, though
   function can be modified according to the data type, easily.
 */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *leftNode;
    int data;
    struct node *rightNode;
};

struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));

    node->leftNode = NULL;
    node->data = data;
    node->rightNode = NULL;

    return node;
}

int main(void)
{
    /* new node can be created here as :-

       struct node *nameOfNode = newNode(data);

       and tree can be formed by creating further nodes at
       nameOfNode->leftNode and so on.
    */

	return 0;
}