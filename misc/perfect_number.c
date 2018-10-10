// C program to check if a number is perfect or not.
// A perfect number is a positive integer that is equal to the sum of its proper positive divisors.
#include<stdio.h>

int main() {
    int i, number, sum;

    printf("Enter a number: ");
    scanf("%d", &number);

    sum = 0;
    
    for(i=1 ; i<=number/2 ; i++) {
        
        if( number % i == 0 ) {
            sum = sum + i;
        }

    }

    if(sum == number) {
        printf("\nIt is a perfect number.");
    }
    else {
        printf("\nIt is not a perfect number.");
    }

    return 0;
}
