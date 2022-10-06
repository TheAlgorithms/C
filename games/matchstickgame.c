//Wap for a matchstick game
#include <stdio.h>
int main()
{
    int opt, cmt = 0, i,mst=0;
    printf("\tMATCHSTICK GAME\t\n");
    for (i = 1; i < 5; i++)
    {
        
        printf("\nEnter to choose 1,2,3 or 4: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:

            printf("\nYou chose 1 matchsticks\n");
            cmt = 4;
            printf("Computer chose 4 matchsticks");
            mst+=5;
            break;
        case 2:

            printf("\nYou chose 2 matchsticks\n");
            cmt = 3;
            printf("Computer chose 3 matchsticks");
            mst+=5;
            break;
        case 3:

            printf("\nYou chose 3 matchsticks\n");
            cmt = 2;
            printf("Computer chose 2 matchsticks");
            mst+=5;
            break;
        case 4:

            printf("\nYou chose 4 matchsticks\n");
            cmt = 1;
            printf("Computer chose 1 matchsticks");
            mst+=5;
            
    
            break;

        default:
            break;
        }
        printf("\nMatchsticks picked: %d",mst);

    }
    
    printf("\nYou are left with last matchstick");
    printf("\nYou lost the game");
    
    return 0;
}