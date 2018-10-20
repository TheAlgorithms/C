#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numb,i,x;
    printf("Enter the array value:");
    scanf("%d",&x);
    int arr[x];
    printf("Enter the Integer numbers to the array..\n");
    for(i=0;i<=(x-1);i++)
    {
        printf("Enter the %d number:",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Enter a Integer Value to search:");
    scanf("%d",&numb);
    for(i=0;i<=(x-1);i++)
    {
        if (arr[i]==numb)
        {
            printf("%d is at the %d point of the array.",numb,i+1);
            break;
        }
        if (i==(x-1))
            printf("The Value you entered is not at the array..");
    }

    return 0;
}
