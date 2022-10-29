#include<stdio.h>
#include<stdlib.h>
typedef struct node{
 int exp;
 int coeff;
 struct node *link;
}node;//self referentrial structure for polynomial


struct node *pheader,*qheader,*rheader,*pptr,*qptr,*rptr,*head,*temp,*ptr;
void check(node *head)
{
    if(head==NULL)
    {
        printf("memory not available");
        exit(-1);
    }
}
/*--------------to create a polynomial------------*/
struct node* createPoly()  
{
    head=(node*)malloc(sizeof(node));
    head->exp=0;
    head->coeff=0;
    head->link=NULL;
    check(head);
    ptr=(node*)malloc(sizeof(node));
    ptr=head;
    int n,i=0;
    printf("enter no of terms :");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        temp=(node*)malloc(sizeof(node));
         check(temp);
         printf("enter coefficien and exponent :");
         scanf("%d%d",&temp->coeff,&temp->exp);
         temp->link=NULL;
         ptr->link=temp;
         ptr=ptr->link;
    }

  return head;
}
/*------------to print a polynomial---------*/
void printpoly(node *head)
{
    ptr=(node*)malloc(sizeof(node));
    ptr=head->link;
    if(head->link==NULL)
    {
        printf("list empty");
    }
    else
    {
        while(ptr!=NULL)
    {
        printf(" %dx^%d ",ptr->coeff,ptr->exp);
        if(ptr->link!=NULL)
        {
            printf("+");
        }
        ptr=ptr->link;
        
    }
    }
    
}
/*------function to add polynomial----*/
node *addPoly( node *phead, node *qhead)
{
    pptr=phead->link;
    qptr=qhead->link;
    rheader=(node*)malloc(sizeof(node));
    rheader->coeff=0;
    rheader->exp=0;
    rheader->link=NULL;
    rptr=rheader;
    while(pptr!=NULL && qptr!=NULL)
    {
        if(pptr->exp==qptr->exp)//checking for same exponential condition if same add the coeffs
        {
            temp=(node*)malloc(sizeof(node));
            check(temp);
            temp->coeff=pptr->coeff+qptr->coeff;
            temp->exp=pptr->exp;
            temp->link=NULL;
            rptr->link=temp;
            rptr=rptr->link;
            pptr=pptr->link;
            qptr=qptr->link;
        }
        else if(pptr->exp>qptr->exp)//different exponents then copy as it is
        {
            temp=(node*)malloc(sizeof(node));
            check(temp);
            temp->coeff=pptr->coeff;
            temp->exp=pptr->exp;
            temp->link=NULL;
            rptr->link=temp;
            rptr=rptr->link;
            pptr=pptr->link;
        }
        else if(pptr->exp<qptr->exp)
        {
            temp=(node*)malloc(sizeof(node));
            check(temp);
            temp->coeff=qptr->coeff;
            temp->exp=qptr->exp;
            temp->link=NULL;
            rptr->link=temp;
            rptr=rptr->link;
            qptr=qptr->link;
        }
    }
    while(pptr!=NULL)//copy for the remaining terms in p
    {
        temp=(node*)malloc(sizeof(node));
            check(temp);
            temp->coeff=pptr->coeff;
            temp->exp=pptr->exp;
            temp->link=NULL;
            rptr->link=temp;
            rptr=rptr->link;
            pptr=pptr->link;
        
    }
    while(qptr!=NULL)//copy remaining terms in q
    {
        temp=(node*)malloc(sizeof(node));
            check(temp);
            temp->coeff=qptr->coeff;
            temp->exp=qptr->exp;
            temp->link=NULL;
            rptr->link=temp;
            rptr=rptr->link;
            qptr=qptr->link;
    }
    return rheader;
    
}
int main()
{
    pheader=createPoly();//creating polynomial p
    qheader=createPoly();//creating polynomial q
    rheader=addPoly(pheader,qheader);//adding the polynomials
    printpoly(rheader);

    return 0;
}


