#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
//Returns newNode
struct Node* newNode(int val)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node*));
    ptr->data = val;
    ptr->next = NULL;
    return ptr;
}
struct Node* insert(struct Node* top, int val)
{
    if(top==NULL)
        top = newNode(val);
    else
    {
        struct Node *ptr = newNode(val);
        ptr->next =top;
        top =ptr;
    }
    return top;
}

struct Node* reverse_LL(struct Node* top)
{
    struct Node* cur = top, *prev = NULL, *next = NULL;
    while(cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}
//Function to print the LinkList
void display(struct Node *top)
{
    struct Node *ptr = top;
    while(ptr)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    struct Node *top = NULL;
    //Insertion of elements is done at the beginning
    top = insert(top,1);
    top = insert(top,3);
    top = insert(top,6);
    top = insert(top,7);
    top = insert(top,9);

    printf("Linklist Print before reverse operation:\n");
    display(top);

    //After reversing the linklist
    top = reverse_LL(top);

    printf("\nLinklist Print after reverse operation:\n");
    display(top);

    return 0;
}
