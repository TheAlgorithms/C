/*
 * decimal_to_binary.c
 * 
 * Modified on May 30, 2018 - Jonaphael
 */
#include <stdio.h>

/* convert a number */
void binary_conversion(int number);

int main(void)
{
    // input of the user
    int inputNumber = 0;
    printf("\t\tConverter decimal --> binary\n\n");

    while(inputNumber >= 0)
    {
        // reads a decimal number from the user.
        printf("Enter any negative number to exit");
        printf("\nEnter a positive integer number: ");
        scanf("%d",&inputNumber);
        binary_conversion(inputNumber);
    }
    
    return 0;
}

/* convert a decimal number to binary */
void binary_conversion(int number)
{
    /* a temporary number */
    int temp = number;

    /* how many bits contains in number */
    int bits = -1;

    if(number == 0)
        printf("0");
    else
    {
        if(number > 0)
        {
            /* get the number of bits */
            while(temp)
            {
                temp >>= 1;
                bits++;
            }

            /* MSB in number */
            temp = 1 << bits;

            /* print the result */
            printf("\nThe number %d in binary is :", number);
            while(temp)
            {
                if(number & temp)
                    printf("1");
                else
                    printf("0");

                temp >>= 1;
            }
        }    
    }
    printf("\n\n");
}