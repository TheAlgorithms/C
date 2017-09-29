/*********decimal number to binary number conversion*****************/
#include <stdio.h>
void decimal2Binary(long num);
 
int main(){
	
    long num;
 
    printf("Enter a decimal integer \n");
    scanf("%ld", &num);
    decimal2Binary(num);

return 0;
} 

/***function for convert decimal numbers to binary numbers****************/
void decimal2Binary(long num){

long  decimal_num, remainder, base, binary, no_of_1s;

base = 1; 
binary = 0; 
no_of_1s = 0;

while (num > 0)
    {
        remainder = num % 2;
      
        if (remainder == 1)
        {
            no_of_1s++;
        }
        binary = binary + remainder * base;
        num = num / 2;
        base = base * 10;}
        
    printf("Its binary equivalent is = %ld\n", binary);
}
