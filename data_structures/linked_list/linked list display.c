#include<stdio.h>
#include<stdlib.h>


    struct node{      //structure declared
    int data;
    struct node *ptr;
};

    int main()
{
    struct node *first=NULL;//Assings null initially

    struct node *second=NULL;//Assings null initially

    struct node *third=NULL;//Assings null initially

    first=malloc(sizeof(struct node));

    second=malloc(sizeof(struct node));

    third=malloc(sizeof(struct node));

    first->data=22;//filling 22 into data

    first->ptr=second;

    second->data=23;//filling 23 into data

    second->ptr=third;

    third->data=24;//filling 24 into data

    third->ptr=NULL;

    printlist(first);

return 0;
}
    int printlist(struct node *n)

{
    while(n!=NULL)
{
    printf("\t%d",n->data);//printing of data
n=n->ptr;
}
return 0;
}
