//C program to display the Pascal's triangle upto the nth input row
#include <stdio.h>

int main()
{
    int row, c = 1, j, i, k;
    printf("Input number of rows: ");
    scanf("%d", &row);
    for (i = 0; i < row; i++)
    {
        for (j = 1; j <= row - i; j++)
        {
             printf("  ");
        }   
        for (k = 0; k <= i; k++)
        {
            if (k == 0 || i == 0)
                c = 1;
            else
                c = c * (i - k + 1) / k;
            printf("% 4d", c);
        }
        printf("\n");
    }
    return 0;
}
/*
Test case 1:
Input number of rows: 5
            1
          1   1
        1   2   1
      1   3   3   1     
    1   4   6   4   1 
*/