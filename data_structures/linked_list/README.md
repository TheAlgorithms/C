Singly Linked Lists

A linked list is a linear data structure, in which the elements are not stored at contiguous memory locations.
The elements in a linked list are linked using pointers.
 
 In C language, a linked list can be implemented using structure and pointers 
 
 struct node{
    int data;
    struct node *next;
};
struct node *head,*START;//head and START are used interchangably

where next is a Pointer (Or Reference) to the next node

Here follow few basic functions in a linked list

1. Creating a linked list

void CreateList(int n)
{
    struct node *NewNode, *temp;
    int info;
    head=( struct node*)malloc(sizeof(struct node));
    /*Enter the data for first node*/
    scanf("%d",&info);
    head->data=info;
    head->next=NULL;
    temp=head;
    int i;
    for(i=2;i<=n;i++)
    {
        NewNode=(struct node*)malloc(sizeof(struct node));
        if(NewNode==NULL)
        {
            break;
        }
        else
        {
            scanf("%d",&info);
            NewNode->data=info;
            NewNode->next =NULL;
            temp->next=NewNode;
            temp=temp->next;
        }
    }
}

2. Displaying the entire list

void displayList()
{
    struct node* temp;
    temp=head;
    
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

3. Insertion at the end

void insend(int r)
{
    struct node *t,*temp;
    t=(struct node*)malloc(sizeof(struct node));
    
    
    if(head==NULL)
    {
        head=t;
        head->data=r;
        head->next=NULL;
        return ;
    }
    temp=head;
    while(temp->next!=NULL)
    
        temp=temp->next;
        temp->next=t;
        t->data=r;
        t->next=NULL;
 }
 
 4. Insertion at the beginning
 
 void insbeg(int o)
{
    struct node *t;
    t=(struct node*)malloc(sizeof (struct node));
    if(START==NULL)
    {
       START=t;
        START->data=o;
        START->next=NULL;
       return 0;
    }
    t->data=o;
    t->next=START;
    START=t;
}

5. Deleting the entire list

void deleteList2()
{
    struct node *temp;

    while(START!=NULL)
    {
        temp= START;
        START = START->next;

        free(temp);
    }
}

6. Deleting the first element

void pop()
{
    
    struct node*t;
    int n;

    if(START==NULL)
    {
        printf("stack underflow\n");
        return;
    }
    n=START->data;
    printf("%d\n",n);
    t=START->next;
    free(START);
    START=t;
    
    
}