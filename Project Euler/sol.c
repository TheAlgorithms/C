#include<stdio.h>
int main()
{
    int n,sum_squares=0,square_sum=0;

    scanf("%d",&n);         //Inputting the input from the user
    sum_squares=n*(n+1)*(2*n+1)/6;      //Calculating the sum of the squares of the first n natural numbers

    square_sum=(n+1)*n*(n+1)*n/4;       //Calculating the square of the sum of the first n natural numbers

    printf("Difference = %d",square_sum-sum_squares);   //Displaying the results
    return 0;
}
