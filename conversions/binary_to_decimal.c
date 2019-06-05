/**
 * Modified 07/12/2017, Kyler Smith
 * Modified 06/05/2019, Pocholo Arangote
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
int main() {

    int remainder, number = 0, decimal_number = 0, temp = 1;
    
    char binary_number[100] = {};
    char* binary_number_ptr;
    printf("/n Enter any binary number= ");

    //changes: changed scanf to fgets, preventing an error if input is not a number
    fgets(binary_number, 100, stdin);

    //this assigns the variable number to the converted integer
    number = strtol(binary_number, &binary_number_ptr, 0);

    // Iterate over the number until the end.
    while(number > 0) {

        remainder = number % 10;
        number = number / 10;
        decimal_number += remainder * temp;
        temp = temp*2;		//used as power of 2

    }

    printf("%d\n", decimal_number);
}
