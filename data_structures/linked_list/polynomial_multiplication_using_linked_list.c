/* Multiplying two polynomials using linked list*/

#include <stdio.h>
#include <stdlib.h>


## Creates the node. 
## The data part contains an integer coefficient and the exp part contains corresponding exponents.
## Like in x^2. data=1, exp=2.
#@ Idea is take two such polynomials using lists and the output is a third list containig the answer.
struct node
{
    int data;
    int exp;
    struct node * next;
};


## To dynamically allocate memory for a new node in a list
struct node * new_node()
{
    struct node* temp= (struct node*)malloc(sizeof(struct node));
    printf("Enter coefficient: ");
    scanf("%d",&temp->data);
    printf("Enter exponent: ");
    scanf("%d", &temp->exp);
    temp->next=NULL;
    return temp;
}


## Creates a linked list. Takes argument the first node of the list

struct node* list(struct node* head)
{
    int i, n;
    struct node *temp, *change=head;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        temp=new_node();
        if(head==NULL)                 ##Checks if list is empty
        {
            head=temp;
            change=temp;
        }
        else
        {
            change->next=temp;
            change=temp;
        }
    }
    return head;
}

## utility function. To create the nodes for list 3.
## This was required so that the data part can be used properly.

struct node * new_node_3()
{
    struct node* temp= (struct node*)malloc(sizeof(struct node));
    temp->next=NULL;
    return temp;
}

## Takes two linked lists having head pointers as head1, head2 as input.
## Also takes in head3 which is the resultant list that will have the product of two polynomials.

struct node* multiply(struct node* head1, struct node * head2, struct node* head3)
{
    struct node* temp, *change2, *change3,*del;
    while(head1!=NULL)
    {
        change2=head2;
        while(change2!=NULL)
        {
            temp=new_node_3();
            temp->data=(head1->data)*(change2->data);
            temp->exp=head1->exp+ change2->exp;
            if(head3==NULL)
           {
               head3=temp;
               change3=temp;
           }
           else
            {
                change3=head3;
                while(change3->next!=NULL)
                {
                    if(change3->exp== temp->exp)
                    {
                        change3->data= change3->data + temp->data;
                        break;
                    }
                    change3=change3->next;
                }
                if(change3->exp==temp->exp)
                {
                    change3->data= change3->data + temp->data;
                }
                else if(change3->next==NULL)
                {
                    change3->next=temp;
                }
            }
          change2=change2->next;
        }

        del=head1;
        head1=head1->next;
        free(del);
    }
    return head3;
}


## Prints the resultant list.

void print(struct node* head)
{
    struct node*change=head;
    if(head==NULL)
    {
        printf("No list exists.\n");
        return;
    }
    else{
        while(change!=NULL)
        {
            printf("%d x ^(%d) + ",change->data, change->exp);
            change=change->next;
        }
        printf("\n");
    }
}

int main()
{
    struct node * head1=NULL, *head2=NULL;
    head1=list(head1);      /*Creates first list*/
    head2=list(head2);      /*Creates second list*/
    struct node* head3=NULL;
    head3=multiply(head1, head2, head3);
    print(head3);
    free(head1);              /* Frees the dynamically allocated memory */
    free(head2);
    free(head3);
    return 0;
}
