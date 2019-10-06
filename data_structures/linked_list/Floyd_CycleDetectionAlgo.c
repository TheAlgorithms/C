///Floyd Cycle Finding Algorithm

#include<stdio.h>
#include<stdbool.h>

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

bool CheckforCycle(struct Node*head)
{
    struct Node* slow = head, *fast = head;     //Initialised two pointers
    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast)            //if at any instance, the slow and fast pointer point to the same node, it means a loop is present
            return true;
    }
    return false;
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
    head->next->next->next->next = head->next; //Cycle made for testing
    if(CheckforCycle(head))
        printf("Cycle found in Linked List 1\n");
    else
        printf("No cycle found in Linked List 1\n");
    //test case 2
    struct Node*head1= NULL;
    insert(&head1,7);
    insert(&head1,2);
    insert(&head1,3);
    insert(&head1,8);
    insert(&head1,5);
    insert(&head1,9);
if(CheckforCycle(head1))
        printf("Cycle found in Linked List 2\n");
    else
        printf("No cycle found in Linked List 2\n");
    return 0;

}
