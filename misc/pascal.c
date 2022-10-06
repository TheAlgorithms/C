//C program to display the Pascal's triangle upto the nth input row
#include <stdio.h> //inclusion of header file

int main()// main function body
{
    int row, c = 1, j, i, k; // declaration and initialisation of variables
    
    printf("Input number of rows: "); 
    scanf("%d", &row); //user input
    
    for (i = 0; i < row; i++) //loop for each row from top to bottom
    {
        // print spaces to align the numbers properly
        for (j = 1; j <= row - i; j++) 
        {
             printf("  ");
        }   
        
        //loop to print the numbers
        for (k = 0; k <= i; k++) 
        {
            if (k == 0 || i == 0)
                c = 1;
            else
                c = c * (i - k + 1) / k; // calculating the numbers by binomial coefficient method
            printf("% 4d", c);
        }
        printf("\n");
    }
    return 0; //exit by returning 0
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