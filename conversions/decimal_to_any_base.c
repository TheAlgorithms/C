/*
 *	 C program to convert positive decimal integer to any positive base with base's alphabet given in input (recursive way)
 */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int 	isbad_alphabet(char alphabet[85])
{
	for (int i = 0; i < 85; i++)
	{
		if (strchr(alphabet + i + 1, alphabet[i]))
			return (1);
	}
	return (0);
}

void	display_convertion(unsigned long long nb, char alphabet[86], unsigned short base)
{
	/* Recursive convertion */
	if (nb > base - 1)
		display_convertion(nb/base, alphabet, base);
	/* Displaying converted number in order */
	write(1, alphabet + nb%base, 1);
}

int	main()
{
	unsigned long long	nb = 0;
	char			alphabet[86] = {0};

	/* Decimal number input */
	write(1, "Enter the positive number to convert (-1 < number < 18446744073709551615): ", 75);
	scanf("%llu", &nb);
	/* Base alphabet input */
	write(1, "Enter the base alphabet (limit = 85 characters): ", 48);
	scanf("%85s", alphabet);
	/* Verify that every characters of alphabet is unique */
	if (isbad_alphabet(alphabet))
	{
		write(2, "The base alphabet is not valid, Every character should be unique !\n", 68);
		return (1);
	}
	/* Convertion */
	display_convertion(nb, alphabet, strlen(alphabet));
	write(1, "\n", 1);
	return (0);
}
