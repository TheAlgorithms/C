///Floyd Cycle Finding Algorithm

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void insert(struct Node**head,int value)
{
    // Create a new node and inserts it in beginning of the list
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = (*head);
    (*head) = temp;
}

struct Node* ReverseList(struct Node*head)
{
    struct Node* temp = NULL, *nextNode = NULL;
    while(head)
    {
        nextNode = head->next;
        head->next = temp;
        temp = head;
        head = nextNode;
    }
    return temp;
}

void PrintLinkedList(struct Node*head)
{
    struct Node*temp = head;
    while(temp!=NULL)
    {
        printf(" %d ", temp->data);
        temp=temp->next;
    }
}

int main()
{
    //test case1
    struct Node*head = NULL;
    insert(&head,1);
    insert(&head,2);
    insert(&head,3);
    insert(&head,4);
    insert(&head,5);
    insert(&head,6);
    printf("\n Displaying Original Linked List: ");
    PrintLinkedList(head);
    head = ReverseList(head);
    printf("\n Displaying Linked List after Reversing : ");
    PrintLinkedList(head);
    return 0;

}
