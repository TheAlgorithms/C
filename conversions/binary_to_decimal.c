/**
 * Modified May 30, 2018 - Jonaphael
 * 
 */

#include <stdio.h>
#include <string.h>

#define MAX (sizeof(int) * 8)

int check_binary_number(const char *number);
void bitwise_conversion(const char *binary_number);

int main() 
{
	char binary_number[MAX];
	printf("Enter any binary number: ");
	scanf("%s", binary_number);

	if(strlen(binary_number) >= MAX)
		printf("Binary number to long");
	else
		bitwise_conversion(binary_number);
}

/* @check_if_binary() 
 * @brief check if the given number is binary 
 * @param binary number - string with the binary number
 * 
 * @return a negative number if is not
 * 
 * @return a positive number if is true
 */
int check_binary_number(const char *binary_number)
{
	/* https://www.asciitable.com/  '1' == 49 and '0' == 84 */
	int count =0;
	while(count < strlen(binary_number)){

		/* check if each digit is a binary digit */
		if((binary_number[count] != 49) && (binary_number[count]) != 48)
			return -1;

		count++;
	}
	
	return 1;
}

/* conver the number using bit-wise and Shift */
void bitwise_conversion(const char *binary_number)
{
	int count = strlen(binary_number); /* LSB */
	int result = 0;
	if(check_binary_number(binary_number) != -1){
		/* convert the number */
		for(;count >= 0; count--){
			if(binary_number[count] == 49) /* check if the digit is 1 */{
				result |= (1 << (strlen(binary_number) - count) -1 ); /* shift left with a negative number or 0 equals 1 */
			}
		}

		printf("\nThe number in decimal is: %d\n",result);
	}
	else
		printf("Number is not a binary number");
}