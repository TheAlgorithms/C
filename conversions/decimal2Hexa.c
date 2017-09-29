/*****Decimal to Hexadecimal conversion*******************/
#include <stdio.h>
void decimal2Hexadecimal(long num);

 
int main(){
	
  long decimalnum;
 
  printf("Enter decimal number: ");
  scanf("%ld", &decimalnum);
 
  decimal2Hexadecimal(decimalnum);

return 0;
}

/********function for convert decimal number to hexadecimal number****************/
void decimal2Hexadecimal(long num){

long decimalnum=num;
long quotient, remainder;
int i, j = 0;
char hexadecimalnum[100];

    quotient = decimalnum;

	while (quotient != 0){

        remainder = quotient % 16;
			if (remainder < 10)
            hexadecimalnum[j++] = 48 + remainder;

			else
			hexadecimalnum[j++] = 55 + remainder;

			quotient = quotient / 16;}

    // print the hexadecimal number

    for (i = j; i >= 0; i--){
            printf("%c", hexadecimalnum[i]);}

	printf("\n");
}

