#include <stdio.h>
#define LIMIT 2000000

static int numberArray[LIMIT] ={0}; 


int main (void)
{
 int i;
 long long result = 2;
 int last_prime = 2; 
 int prime_found = 1;


 for (i = 1; i < LIMIT; i+=2) 
   numberArray[i] =  i;  


 while (prime_found) 
 {
  int j;
  prime_found = 0;


  for (i = last_prime+1; i < LIMIT; i++)
  {
   if (numberArray[i] != 0) 
   {
    last_prime = i; 
    result += i;
    prime_found = 1;
    break;
   }
  }


  if (prime_found) 
  {
   for ( j = 2; j < LIMIT; j++ )
   {
    if ( j*last_prime > LIMIT )
     break;


    numberArray[j*last_prime] = 0;
   }
  }
 }


 printf("The sum of all primes below %d is %lld \n\n", LIMIT, result);
 
 return 1;
}
