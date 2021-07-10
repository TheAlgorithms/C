#include <stdio.h>
#include <stdlib.h>
#define MAX 20

//FUNCTION PROTOTYPES
int QUEUE[MAX],REAR,FRONT;
void DISPLAY(int []);
void INSERT(int [],int);
void DELETE(int []);
void PEEK(int []);
 
int main()
{
    int ITEM=0;
    int choice=0;
    int FRONT=REAR=-1; 
    while(choice != 5)
    {
        //clrscr();
        printf("\nMENU :");
        printf("\n1. To INSERT element in the QUEUE");
        printf("\n2. To Delete element from QUEUE");
        printf("\n3. To PEEK topmost element in the QUEUE");
        printf("\n4. To DISPLAY the QUEUE");
        printf("\n5. To EXIT");
        printf("\nYour Choice : ");
        scanf("%d",&choice);
 
        switch(choice)
        {
            case 1 :	printf("\nEnter Item to be insert : ");
                		scanf("%d",&ITEM);
                		INSERT(QUEUE,ITEM);
            			break;
   
            case 2 :	POP(QUEUE);
            			break;
   
            case 3	:	PEEK(QUEUE);
            			break;
   
            case 4 :	DISPLAY(QUEUE);
            			break;
            			
            case 5 :	printf("\nProgram Terminated!!!\n");
            			break;
           
		    default:	printf("\nInvalid Choice!!!\n");
            			break;
        }
        getch();
    }
    
    return 0;
}


void DISPLAY(int QUEUE[])
{
    int i=0;
    if(FRONT=-1||FRONT>REAR)
    {
        printf("\nQUEUE Underflow\n");
        return;
    }

    //printf("%d <-- TOP ",QUEUE[TOP]);
    for(i=FRONT;i<=REAR;i++)
    {
        printf("\n%d",QUEUE[i]);
    }
    printf("\n\n");
}

void INSERT(int QUEUE[],int item)
{
    if(REAR==MAX-1)
    {
        printf("\nQUEUE Overflow\n");
        return;
    }
    
    else if(FRONT=REAR=-1)
    {
        FRONT=REAR=0;
    }
    else
    {
        REAR++;
        QUEUE[REAR]=item;
    }
}

void DELETE(int QUEUE[])
{
    int deletedItem;
    if(FRONT=-1||FRONT>REAR)
    {
        printf("\nQUEUE Underflow\n");
        return;
    }
 
    deletedItem=QUEUE[FRONT];
    FRONT++;
    printf("\n%d Deleted Successfully\n",deletedItem);
}

void PEEK(int QUEUE[])
{
    if(FRONT=-1||FRONT>REAR)
    {
        printf("\nQUEUE Underflow\n");
        return;
    }
 
    printf("\nREAR --> %d\n",QUEUE[REAR]);
}

