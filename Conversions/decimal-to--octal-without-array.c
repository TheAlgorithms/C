#include <stdio.h>
#include <math.h>

void main()
{
  int rem, div, num;
  // Taking large value for i and sum
  long int i = 1, sum = 0;

  // Asking for the number from user
  printf("Enter any number");
  scanf("%d" , &num);

  while(div>0)
  {
    rem = num%8;
    div = num/8;
    num = div;
    // Taking the number as a sum in an integer.
    sum = sum + (rem*i);
     i  = i*10;
  } 

  // Printing the desired value as sum.
  printf("%ld" , sum);
}