#include <stdio.h>
#include <stdlib.h>

void main()
{
    int queue[100], front=0, rear=0;
    int choice = 1,n;

    while (choice)
    {
        printf("Press \n1 for append to the end, \n2 for display, \n3 for deletion at the end, \n0 for exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter a number\n");
                scanf("%d", &n);
                queue[rear]=n;
                rear=rear+1;
                break;

            case 2:
                for(int i=front; i<rear; i++)
                    printf("%d=>", queue[i]);
                printf("End\n");
                break;
            case 3:
                rear=rear-1;

        }

    }
}
