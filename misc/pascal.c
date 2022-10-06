//C program to display the Pascal's triangle upto the nth input row
//Author - Ankush Roy - https://github.com/ankushroy25

#include <stdio.h> //inclusion of header file

int main()// main function body
{
    // declaration and initialisation of variables
    int row, c = 1, j, i, k; 
    /* row - the no. of rows of the pascal triangle user wants to display
    i,j,k - iterative variables
    c - the calculate the binomial coefficients    
    */

    printf("Input number of rows: "); 
    scanf("%d", &row); //user input
    
    //loop for each row from top to bottom
    for (i = 0; i < row; i++) 
    {
        // print spaces to align the numbers properly
        for (j = 1; j <= row - i; j++) 
        {
             printf("  ");
        }   
        
        //loop to print the numbers
        for (k = 0; k <= i; k++) 
        {
            //as the first and last number in a row = 1, checking the boundary conditions 
            if (k == 0 || i == 0)
            {   
                c = 1;
            }
            else
            {
              // calculating the numbers by binomial coefficient method(using factorial reduced formula)
                c = c * (i - k + 1) / k; 
            }
            printf("% 4d", c);
        }

        //moving to the next line after all mumbers in a row has been displayed
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