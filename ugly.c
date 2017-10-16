// Ugly numbers are numbers whose only prime factors are 2, 3 or 5
 #include <stdio.h>
int main()
{
    int x,i,n,temp; 
    printf("Enter a number: ");
   scanf("%d", &n);     // Reads a number till which ugly numbers are to be printed 
   for(i=1;i<=n;i++)
   {
   	   temp =i;
       x=i;
       while (x%2==0)    // Checking if completely divisible by 2
        x = x/2;
        while (x%3==0)   // Checking if completely divisible by 3
         x = x/3;
        while (x%5==0)// Checking if completely divisible by 5
         x = x/5;
//After repeatedly dividing with the numbers 2,3,5  if the part left is 1 then it is ugly
       printf("ugly numbers are :");      
       if(x == 1)
       {
        printf("%d \n",temp);
       }
   }
 }

