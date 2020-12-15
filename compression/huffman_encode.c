/**
 * @file
 * @brief Huffman encoding of given words. It takes 3 steps to make encoded
 * number array.
 *
 * 1: make linked list of characters given.
 * 2: make tree inside the list with huffman algorithm.
 *    Head node of the list will be the top of the tree when its done.
 * 3: travel the tree and at the same time, make char arrays of encoded numbers.
 */

#include <stdio.h>
#include <stdlib.h>

 /** node for make huffman tree */
typedef struct _node {
    char character;
    int count;

    struct _node* next; /** pointer for make linked list of given characters */

    struct _node* left;  /** pointer for make tree for huffman encode */
    struct _node* right; /** pointer for make tree for huffman encode */
} node;

/** struct to manage linked list of characters */
typedef struct {
    node* head;
    node* tail;

} nodelist;

/** finding character in the list.
 * @param list list that has character you want to find
 * @param charac character you want to find
 * @returns founded node in the list
 */
node* findinlist(nodelist* list, char charac) {
    // node* find ;
    node* temp = list->head;

    while (temp != NULL) {
        if (temp->character == charac) {
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}

/** make new node to make linked list
 * @param character
 * @param count number of character in given input
 * @returns new node
 */
node* makenode(char character, int count) {
    node* temp = (node*)malloc(sizeof(node));

    temp->character = character;
    temp->count = count;
    temp->next = NULL;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

/** count leaf nodes of tree
 * @param nod root node of tree
 * @returns number of leafs
 */
int countleaf(node* nod) {
    if (nod != NULL) {
        if (nod->left == NULL && nod->right == NULL) {
            return 1;
        }
        return countleaf(nod->left) + countleaf(nod->right);
    }
}

/** find node with the smallest quantity among the list
 * @param list list
 * @returns smallest node
 */
node* smallest(nodelist* list) {
    node* small = list->head;
    node* temp = list->head;

    while (temp != NULL) {
        if (small->count > temp->count ||
            small->count == temp->count && countleaf(small) > countleaf(temp)) {
            small = temp;
        }
        temp = temp->next;
    }

    return small;
}

/** when you found smallest node, seperate that node from list
 * @param list list
 * @param nod smallest node
 *
 */
void disconnectnode(nodelist* list, node* nod) {
    node* temp = list->head;

    // if the node is head of list, set link of head to NULL
    if (temp->character == nod->character) {
        node* hd;
        hd = list->head;
        list->head = list->head->next;
        hd->next = NULL;
        return;
    }

    // else
    while (temp->next != NULL) {
        if (temp->next->character == nod->character) {
            // if the node is tail of list, set link of previous node to NULL
            if (temp->next == list->tail) {
                list->tail = temp;
                temp->next = NULL;
            }

            // if the node is middle of list, set link of previous to next node
            else {
                node* right;
                right = temp->next->next;
                temp->next = right;
                nod->next = NULL;
            }

            return;
        }
        temp = temp->next;
    }
}

/** make huffman tree inside the list. At the end, head of list will be the top
 * of huffman tree.
 * @param list list
 */
void maketree(nodelist* list) {
    node* small1;  // smallest node
    node* small2;  // next smallest node

    small1 = smallest(list);
    disconnectnode(list, small1);

    // if only one node left in the list
    if (list->head == list->tail) {
        node* newnode = (node*)malloc(sizeof(node));
        newnode->count = small1->count + list->head->count;
        newnode->left = small1;
        newnode->right = list->head;

        list->head = newnode;
        list->head->next = NULL;

    }
    else {
        small2 = smallest(list);
        disconnectnode(list, small2);

        // make new node that will be root of tree.
        // attatch small1 and small2 to it, then add to tail of the list.
        node* newnode = (node*)malloc(sizeof(node));
        newnode->count = small1->count + small2->count;
        newnode->left = small1;
        newnode->right = small2;

        list->tail->next = newnode;
        list->tail = newnode;
        list->tail->next = NULL;
    }
}

// array of the encoded numbers in order of ascii number.
// ex: results[97] is encoded number of'a'
char* results[126];

// record the length of encoded number
int sizeofresults[126];

// simple stack for contain encoded number that made while travel the tree.
int stack[100];
int top = -1;
void push(int n) {
    top++;
    stack[top] = n;
}
int pop() {
    int result = stack[top];
    top--;
    return result;
}

/** print encoded number in the results[126] array.
 *   print it order of ascii numbers.
 */
void printresult() {
    int i = 0;
    for (i; i < 126; i++) {
        if (results[i] != NULL) {
            printf("%c : ", i);
            int j = 0;
            for (j; j <= sizeofresults[i]; j++) {
                printf("%d", results[i][j]);
            }
            printf("\n");
        }
    }
}

/** travel the huffman tree inorderly.
 *  add 0 when travel down to left, add 1 when travel down to right.
 *
 *  @param root top node of the tree
 */
void inorder(node* root) {
    if (root->left == NULL && root->right == NULL) {
        char* encodednumber = (char*)malloc(sizeof(char) * top + 1);

        int i = 0;
        for (i; i <= top; i++) {
            encodednumber[i] = (char)stack[i];
        }
        sizeofresults[root->character] = top;
        results[root->character] = encodednumber;

        return;
    }

    if (root != NULL) {
        push(0);
        inorder(root->left);
        pop();

        push(1);
        inorder(root->right);
        pop();
    }
}

int main() {
    // 99 characters will be taken in input (except \0)
    char tempstr[100];

    printf("type in words to encode :\n");
    gets(tempstr);

    // init list
    nodelist list;
    list.head = NULL;
    list.tail = NULL;

    // make head node with first letter initially
    list.head = makenode(tempstr[0], 1);
    list.tail = list.head;

    // make list of characters from second letter
    int i = 1;
    node* temp;
    while (i < 100) {
        if (tempstr[i] == '\0') break;

        temp = findinlist(&list, tempstr[i]);
        if (temp == NULL) {  // not found, make node
            list.tail->next = makenode(tempstr[i], 1);
            list.tail = list.tail->next;
        }
        else {  // found
            temp->count++;
        }
        i++;
    }
    /////////////////////////
    // character list has made

    // make tree with list
    while (list.head->next != NULL) {
        maketree(&list);
    }

    // traverse and encode
    inorder(list.head);

    printf("\nresults \n\n");
    printresult();

    return 0;
}
