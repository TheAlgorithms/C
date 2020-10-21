/* A menu driven program to create a doubly circular linked list, insert and delete nodes*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
    struct node * prev;
};

struct node* new_node()
{
    int n;
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &n);
    temp->data= n;
    temp->prev=NULL;
    temp->next=NULL;
    return temp;
}

struct node* list_by_user(struct node* head)
{
    struct node *temp, *change=head;
    int n;
    do
    {
        temp=new_node();
        if(head==NULL)
        {
            temp->next=temp;
            temp->prev=temp;
            head=temp;
            change=temp;
        }
        else
        {
            temp->next=head;
            head->prev=temp;
            change->next=temp;
            temp->prev=change;
            change=temp;
        }
        printf("Enter 1 to continue, 0 to exit\n");
        scanf("%d", &n);
    }while(n);
    return head;
}

struct node* list_n_nodes(struct node* head)
{
    int i, n;
    struct node*temp, *change=head;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        temp=new_node();
        if(head==NULL)
        {
            temp->next=temp;
            temp->prev=temp;
            head=temp;
            change=temp;
        }
        else
        {
            temp->next=head;
            head->prev=temp;
            change->next=temp;
            temp->prev=change;
            change=temp;
        }
    }
    return head;
}

struct node* ins_at_beg(struct node* head)
{
    struct node* temp;
    temp=new_node();
    if(head==NULL)
    {
        temp->next=temp;
        temp->prev=temp;
        head=temp;
    }
    else{
        temp->next=head;
        head->prev->next=temp;
        temp->prev=head->prev;
        head->prev=temp;
        head=temp;
    }
    return head;
}

struct node* ins_at_end(struct node* head)
{
    struct node* temp;
    temp=new_node();
    if(head==NULL)
    {
        temp->next=temp;
        temp->prev=temp;
        head=temp;
    }
    else{
        temp->next=head;
        head->prev->next=temp;
        temp->prev=head->prev;
        head->prev=temp;
    }
    return head;
}

struct node * ins_at_n_pos(struct node * head)
{
    int i, n;
    struct node *temp, *change=head;
    printf("Enter position: ");
    scanf("%d",&n);
    if(n==1)
    {
        head=ins_at_beg(head);
        return head;
    }
    change=change->next;
    for(i=1; i<n-2; i++)
    {
        change=change->next;
    }
    if(change->next==head)
    {
        head=ins_at_end(head);
    }
    else{
        temp=new_node();
        temp->next=change->next;
        change->next->prev=temp;
        change->next=temp;
        temp->prev=change;
    }
    return head;

}

struct node * ins_before_n_val(struct node *head)
{
    int n,i;
    struct node* temp, *change=head;
    printf("Enter value: ");
    scanf("%d",&n);
    if(head==NULL)
    {
        printf("List doesn't exist\n");
        return head;
    }
    if(head->data==n)
    {
        head=ins_at_beg(head);
    }
    else
    {
        while(change->next!=head && change->next->data!=n)
        {
            change=change->next;
        }
        if(change->next==head)
        {
            printf("Value not found.\n");
        }
        else
        {
            temp=new_node();
            temp->next=change->next;
            change->next->prev=temp;
            change->next=temp;
            temp->prev=change;
        }
    }
    return head;
}

struct node * ins_after_n_val(struct node *head)
{
    int n,i;
    struct node* temp, *change=head;
    printf("Enter value: ");
    scanf("%d",&n);
    if(head==NULL)
    {
        printf("List doesn't exist\n");
        return head;
    }
    if(head->data==n)
    {
        temp=new_node();
        temp->next=change->next;
        change->next->prev=temp;
        change->next=temp;
        temp->prev=change;
    }
    else
    {
        change=change->next;
        while(change!=head && change->data!=n)
        {
            change=change->next;
        }
        if(change==head)
        {
            printf("Value not found.\n");
        }
        else
        {
            temp=new_node();
            temp->next=change->next;
            change->next->prev=temp;
            change->next=temp;
            temp->prev=change;
        }
    }
    return head;
}

struct node* del_1st_node(struct node*head)
{
    struct node* temp, *change;
    if(head==NULL)
    {
        printf("Create a list first.\n");
        return head;
    }
    temp=head;
    change=head->prev;
    change->next=head->next;
    head->next->prev=change;
    head=head->next;
    free(temp);
    return head;
}

struct node* del_at_end(struct node* head)
{
    struct node* temp, *change;
    if(head==NULL)
    {
        printf("Create a list first.\n");
        return head;
    }
    temp=head->prev;
    change=head->prev->prev;
    change->next=head;
    head->prev=change;
    free(temp);
    return head;
}

struct node* delete_n_val(struct node* head)
{
    struct node* temp, *change=head;
    int n;
    printf("Enter the val: ");
    scanf("%d",&n);
    if(head==NULL)
    {
        printf("Create a list first.\n");
        return head;
    }
    if(head->data==n)
    {
        head=del_1st_node(head);
    }
    else
    {
        change=change->next;
        while(change!=head && change->data!=n)
        {
            change=change->next;
        }
        if(change==head)
        {
            printf("Value doesn't exist\n");
        }
        else
        {
            temp=change;
            change->prev->next=change->next;
            change->next->prev=change->prev;
            free(temp);
        }
    }
    return head;
}

struct node* delete_after_n_val(struct node* head)
{
    struct node* temp, *change=head;
    int n;
    printf("Enter the val: ");
    scanf("%d",&n);
    if(head==NULL)
    {
        printf("Create a list first.\n");
        return head;
    }
    if(head->data==n)
    {
        temp=head->next;
        head->next->next->prev=head;
        head->next=head->next->next;
        free(temp);
    }
    else
    {
        change=change->next;
        while(change!=head && change->data!=n)
        {
            change=change->next;
        }
        if(change==head)
        {
            printf("Value doesn't exist\n");
        }
        else if(change->next==head)
        {
            printf("No node exists after that.\n");
        }
        else
        {
            temp=change->next;
            change->next->next->prev=change;
            change->next=change->next->next;
            free(temp);
        }
    }
    return head;

}

struct node* delete_before_n_val(struct node* head)
{
    struct node* temp, *change=head;
    int n;
    printf("Enter the val: ");
    scanf("%d",&n);
    if(head==NULL)
    {
        printf("Create a list first.\n");
        return head;
    }
    if(head->data==n)
    {
        printf("No node before this.\n");
    }
    else if(head->next->data==n)
    {
        head=del_1st_node(head);
    }
    else
    {
        change=change->next;
        while(change!=head && change->data!=n)
        {
            change=change->next;
        }
        if(change==head)
        {
            printf("Value doesn't exist\n");
        }
        else
        {
            temp=change->prev;
            temp->prev->next=change;
            change->prev=temp->prev;
            free(temp);
        }
    }
    return head;
}


void print(struct node* head)
{
    struct node* change=head;
    while(change->next!=head)
    {
        printf(" %x %d %x      ", change->prev,change->data,&change->data);
        change=change->next;
    }
    printf(" %x %d %x      ", change->prev,change->data,&change->data);
    printf("\n");
}

int main()
{
    struct node* head=NULL;
    int option=0;
    char choice;
    printf(" Press:\n 1 a. To create a list of n nodes\n 1 b. To create a list of your choice.\n");
    printf(" Press:\n 2 a. To insert a node at the begining\n 2 b. To insert a node at the end\n 2 c. To insert a node at the nth position.\n 2 d. To insert a node after the nth val.\n 2 e.To insert a node before the nth val.\n");
    printf(" Press:\n 3 a. To delete a node at the begining\n 3 b. To delete a node at the end\n 3 c. To delete a node at the nth position.\n 3 d. To delete a node after the nth val.\n 3 e.To delete a node before the nth val.\n");
    printf(" Press: 4 to see the list\n.");
    do
    {
        printf("Enter option: ");
        scanf("%d",&option);
        switch(option)
        {
            case 1: printf("Enter choice: ");
                    getchar();
                    scanf("%c",&choice);
                    switch(choice)
                    {
                        case 'a': head=list_n_nodes(head);
                                  break;
                        case 'b': head=list_by_user(head);
                                  break;
                    }
                    break;
            case 2: printf("Enter choice: ");
                    getchar();
                    scanf("%c",&choice);
                    switch(choice)
                    {
                        case 'a': head= ins_at_beg(head);
                                  break;
                        case 'b': head= ins_at_end(head);
                                  break;
                        case 'c': head= ins_at_n_pos(head);
                                  break;
                        case 'd': head= ins_after_n_val(head);
                                  break;
                        case 'e': head= ins_before_n_val(head);
                                  break;
                    }
                    break;
            case 3: printf("Enter choice: ");
                    getchar();
                    scanf("%c",&choice);
                    switch(choice)
                    {
                        case 'a': head=del_1st_node(head);
                                  break;
                        case 'b': head=del_at_end(head);
                                  break;
                        case 'c': head=delete_n_val(head);
                                  break;
                        case 'd': head=delete_after_n_val(head);
                                  break;
                        case 'e': head= delete_before_n_val(head);
                                  break;
                    }
                    break;
            case 4: print(head);
                    break;
        }

        printf("Press 0 to exit, 1 to continue\n");
        scanf("%d",&option);
    }while(option);
    return 0;
}

