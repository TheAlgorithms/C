#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*start1=NULL,*start2=NULL;
struct node* create(int d){
    struct node *n;
    n=(struct node *)malloc(sizeof(struct node));
    n->data=d;
    n->next=NULL;
}
struct node* insertRearMulti(struct node *n,struct node *start){
    struct node *ptr=start;
    if(start==NULL)
        start=n;
    else{
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=n;
    }
    return start;
}
void reverse(struct node *start)
{
	if(start==NULL)
		printf("Underflow");
	else
	{
		
	}
	
}
void showMulti(struct node *start){
    if(start==NULL)
        printf("Underflow\n");
    else{
        struct node *ptr;
        printf("The list is ");
        for(ptr=start;ptr!=NULL;ptr=ptr->next)
            printf("%d ",ptr->data);
        printf("\n");
    }
}
struct node* delMulti(int d, struct node *start){
    if(start==NULL)
        printf("Underflow\n");
    else{
        struct node *ptr, *prev;
        for(ptr=start;ptr!=NULL;prev=ptr,ptr=ptr->next)
            if(ptr->data==d)
        break;
    if(ptr==NULL)
        printf("Not Found\n");
    else{
        printf("%d is deleted\n",d);
        if(ptr==start)
            start=ptr->next;
        else
            prev->next=ptr->next;
        free(ptr);
        }
    }
    return start;
}
int main(void){
    int n,d,pos;
    do{
        printf("Menu:\n1. Insert in list 1\n2. Insert in list 2\n3. Show list 1\n4. Show list 2\n5. Delete from list 1\n6. Delete from list 2\n7. Exit\nEnter the choice: ");
        scanf("%d",&n);
        switch(n){
            case 1:
                printf("enter the data: ");
                scanf("%d",&d);
                start1=insertRearMulti(create(d),start1);
                break;
            case 2:
                printf("enter the data: ");
                scanf("%d",&d);
                start2=insertRearMulti(create(d),start2);
                break;
            case 3:
                showMulti(start1);
                break;
            case 4:
                showMulti(start2);
                break;
            case 5:
                printf("enter the data: ");
                scanf("%d",&d);
                start1=delMulti(d,start1);
                break;
            case 6:
                printf("enter the data: ");
                scanf("%d",&d);
                start2=delMulti(d,start2);
                break;
            case 7:
                printf("Thank you\n");
                break;
            default:
                printf("Wrong choice, Try Again!!\n");
        }
    }while(n!=7);
    return 1;
}
