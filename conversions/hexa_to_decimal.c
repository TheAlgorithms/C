#include <stdio.h>

int ConverterG1(int octal)//converter for greater than or equal to one
{
	int temp = 1;int deci = 0;
	while(octal)
	    {
		deci = deci + (octal % 10)*temp;//Takes each digit
		octal = octal / 10;
		temp = temp * 8;//Raises the power of 8
	    }
	return deci;
}



int main()
{
   int octal,frac,digit;

     printf("Enter the number in Octal to get the decimal form \n");
     scanf("%d",&octal);

     printf("%d",ConverterG1(octal));

    return 0;
  }
