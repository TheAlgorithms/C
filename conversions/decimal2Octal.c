/*****Decimal to octal conversion*******************/
#include <stdio.h>
void decimal2Octal(long decimalnum);
 
int main(){

    long decimalnum;

    printf("Enter the decimal number: ");
	scanf("%ld", &decimalnum);
    
    decimal2Octal(decimalnum);

return 0;
}
 
/********function for convert decimal numbers to octal numbers************/ 
void decimal2Octal(long decimalnum){
  long remainder, quotient;

    int octalNumber[100], i = 1, j;
    quotient = decimalnum;

    while (quotient != 0){
		octalNumber[i++] = quotient % 8;

        quotient = quotient / 8;
	}

    for (j = i - 1; j > 0; j--)

        printf("%d", octalNumber[j]);

	printf("\n");
}
