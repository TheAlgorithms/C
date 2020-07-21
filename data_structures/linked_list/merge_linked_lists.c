#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *head1 = NULL;
struct node *head2 = NULL;

///// MAIN ALGORITHMIC FUNCTION to MERGE the two input linked lists ///////

void merge()
{
    struct node *temp1 = head1;
    struct node *temp2 = head2;

    struct node *holder1 = NULL;
    struct node *holder2 = NULL;
    // Temporary pointer variables to store the address of next node of the two
    // input linked list

    while (temp1 != NULL && temp2 != NULL)
    {
        holder1 = temp1->next;
        // Storing the address of next node of first linked list
        temp1->next = temp2;
        // Making the first node of first linked list point to first node of
        // second linked list

        if (holder1 != NULL)
        {
            // Making the first node of second linked list point to second node
            // of first linked list
            holder2 = temp2->next;
            temp2->next = holder1;
        }
        temp1 = holder1;
        temp2 = holder2;
        // Updating the address location of two pointer variables temp1 and
        // temp2
    }
}

void printlist(struct node *temp)
{
    printf("%d", temp->data);
    temp = temp->next;
    while (temp != NULL)
    {
        printf("->%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    // Linked List 1: 1->3->5->7   :   Linked List 2: 2->4->6
    //  making lists
    struct node *one = (struct node *)malloc(sizeof(struct node));
    struct node *two = (struct node *)malloc(sizeof(struct node));
    struct node *three = (struct node *)malloc(sizeof(struct node));
    struct node *four = (struct node *)malloc(sizeof(struct node));
    struct node *five = (struct node *)malloc(sizeof(struct node));
    struct node *six = (struct node *)malloc(sizeof(struct node));
    struct node *seven = (struct node *)malloc(sizeof(struct node));
    // Seven nodes are created

    head1 = one;
    head2 = two;
    // head1 points to first node of first linked list
    // head2 points to first node of second linked list

    one->data = 1;
    one->next = three;

    two->data = 2;
    two->next = four;

    three->data = 3;
    three->next = five;

    four->data = 4;
    four->next = six;

    five->data = 5;
    five->next = seven;

    six->data = 6;
    six->next = NULL;
    // Last node of second input linked list

    seven->data = 7;
    seven->next = NULL;
    // Last node of first input linked list

    printf("Linked List 1: ");
    printlist(head1);
    printf("\nLinked List 2: ");
    printlist(head2);

    // Merging the two linked list into single linked list
    merge();

    printf("\nMerged Linked List: ");
    printlist(head1);  // list one has been modified

    return 0;
}
