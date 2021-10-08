/*
 * @file
 * @author [jucollet972](https://github.com/jucollet972)
 * @brief decimal_to_anybase is a tiny C program wich convert positive decimal
 * integer to any positive base with the base's alphabet given in input (recursive way) 
 * ######http://codeofthedamned.com/index.php/number-base-conversion
 */

#include <stdio.h>   /// for IO operations
#include <unistd.h>  /// for write
#include <string.h>  /// for strchr and strlen

/*
 * @brief Checking if alphabet is valid
 * @details lenght and duplicates tests on alphabet
 * @param base alphabet inputed by user
 * @return int as success or not
 */
int 	isbad_alphabet(char alphabet[85])
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

/*
 * @brief Convert positive decimal integer into anybase recursively
 * @param nb to convert
 * @param alphabet inputed by user used for base convertion
 * @param base calculated from alphabet
 * @return void
 */
void	display_convertion(unsigned long long nb, char alphabet[86], unsigned short base)
{
	/* Recursive convertion */
	if (nb > base - 1)
		display_convertion(nb/base, alphabet, base);
	/* Displaying converted number in order */
	write(1, alphabet + nb%base, 1);
}

/*
 * @brief Main function
 * @return int on exit
 */
int	main()
{
	unsigned long long	nb = 0;
	char			alphabet[86] = {0};

	/* Decimal number input */
	write(1, "Enter the positive number to convert (-1 < number < 18446744073709551615): ", 75);
	scanf("%llu", &nb);
	/* Base alphabet input */
	write(1, "Enter the base alphabet (1 < alphabet length < 85): ", 52);
	scanf("%85s", alphabet);
	/* Verify that every characters of alphabet is unique */
	if (isbad_alphabet(alphabet))
	{
		write(2, "The base alphabet is not valid, Every character should be unique and the length of the alphabet should be greater than 2 and lower than 86 !\n", 141);
		return (1);
	}
	/* Convertion */
	display_convertion(nb, alphabet, strlen(alphabet));
	write(1, "\n", 1);
	return (0);
}
