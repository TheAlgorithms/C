/**
 * Modified 07/12/2017, Kyler Smith
 * 
 */

#include <stdio.h>

int main() {

	int remainder, number = 0, decimal_number = 0, temp = 1;
	printf("/n Enter any binary number= ");
	scanf("%d", &number);

	// Iterate over the number until the end.	
	while(number > 0) {
	
		remainder = number % 10;
		number = number / 10;
		decimal_number += remainder * temp;
		temp = temp*2;		//used as power of 2
	
	}

	printf("%d\n", decimal_number);
}
