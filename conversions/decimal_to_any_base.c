/**
 * @file
 * @author [jucollet972](https://github.com/jucollet972)
 * @brief [Decimal to any-base](http://codeofthedamned.com/index.php/number-base-conversion) is a tiny C program wich convert positive decimal
 * integer to any positive base with the base's alphabet given in input (recursive way)
 */

#include <stdio.h>   /// for IO operations
#include <string.h>  /// for strchr and strlen
#include <stdint.h> /// for CPU arch's optimized int types

/**
 * @brief Checking if alphabet is valid
 * @details lenght and duplicates tests on alphabet
 * @param base alphabet inputed by user
 * @return int as success or not
 */
int isbad_alphabet(char alphabet[85])
{
	/* Browse the alphabet */
	unsigned int len = strlen(alphabet);
	
	/* Checking th lenght */	
	if (len < 2)
		return (1);
	for (int i = 0; i < len ; i++)
	{
		/* Searching for duplicates */ 
		if (strchr(alphabet + i + 1, alphabet[i]))
			return (1);
	}
	return (0);
}

/**
 * @brief Convert positive decimal integer into anybase recursively
 * @param nb to convert
 * @param alphabet inputed by user used for base convertion
 * @param base calculated from alphabet
 * @return void
 */
void display_convertion(uint64_t nb, char alphabet[86], unsigned short base)
{
	/* Recursive convertion */
	if (nb > base - 1)
		display_convertion(nb/base, alphabet, base);
	/* Displaying converted number in order */
	printf("%c", alphabet[nb%base]);
}

/**
 * @brief Main function
 * @return 0 on exit or 1 on error
 */
int main()
{
	uint64_t		nb = 0;
	char			alphabet[86] = {0};

	/* Decimal number input */
	printf("Enter the positive number to convert (-1 < number < 18446744073709551615): "); 
	scanf("%lu", &nb);
	/* Base alphabet input */
	printf("Enter the base alphabet (1 < alphabet length < 85): ");
	scanf("%85s", alphabet);  
	/* Verify that every characters of alphabet is unique */
	if (isbad_alphabet(alphabet))
	{
		printf("The base alphabet is not valid, Every character should be unique and the length of the alphabet should be greater than 2 and lower than 86 !\n");
		return (1);
	}
	/* Convertion */
	display_convertion(nb, alphabet, strlen(alphabet));
	printf("\n");
	return (0);
}
