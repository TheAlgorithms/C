#include <stdio.h>
#include <stdlib.h>

 float Taylor_exponential(int n, float x) 
    { 
        float exp_sum = 1;     
        for (int i = n - 1; i > 0; --i ) 
            exp_sum = 1 + x * exp_sum / i;    
        return exp_sum; 
    } 
  int main(void)
    {  
       int n = 25;
       float x = 5.0;    
       
       if (n>0 && x>0)
		{	
		 printf("value of n = %d and x = %d ", n, x );
		 printf("\ne^x = %f",Taylor_exponential(n,x)); 
		}         
   }
