/*
** BogdanAdrian11
** https://github.com/BogdanAdrian11
*/

#include <stdlib.h>
#include <stdio.h>

// Returns the number nb to power power 
int		ft_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_power(nb, power - 1));
}

/* Alocates memory for the converton result and
**  does the convertion from decimal to any base
** It's an extension of convert_to function
*/
char	*fill(char *b_t, int nr, int index, int r_t)
{
	int		rest;
	char	*n_t;
	int		negativ;

	negativ = 0;
	if (nr < 0)
	{
		negativ = 1;
		nr = nr * (-1);
	}
	n_t = (char *)malloc(sizeof(char) * (index + 1));
	n_t[index] = '\0';
	if (nr == 0)
		n_t[0] = b_t[0];
	while (nr != 0)
	{
		index--;
		rest = nr % r_t;
		nr = nr / r_t;
		n_t[index] = b_t[rest];
	}
	if (negativ == 1)
		n_t[0] = '-';
	return (n_t);
}

// Converts from decimal to any base
char	*convert_to(int nr, int r_t, char *b_t)
{
	int		index;
	int		temp;
	int		negativ;
	char	*nr_t;

	negativ = 0;
	if (nr < 0)
	{
		negativ = 1;
		temp = nr * (-1);
	}
	else
		temp = nr;
	index = negativ;
	while (temp != 0)
	{
		temp = temp / r_t;
		index++;
	}
	nr_t = fill(b_t, nr, index, r_t);
	return (nr_t);
}

// Converts from any base to decimal
int		convert_from(char *nbr, char *b_f, int r_f, int l)
{
	int		pos;
	int		nr;
	int		index;
	int		negativ;

	negativ = 0;
	nr = 0;
	if (nbr[0] == '-')
		negativ = 1;
	index = negativ;
	if (nbr[0] == '+')
		index = 1;
	while (nbr[index] != '\0')
	{
		pos = 0;
		while (b_f[pos] != '\0' && b_f[pos] != nbr[index])
			pos++;
		nr += ft_power(r_f, l - 1) * pos;
		index++;
		l--;
	}
	if (negativ == 1)
		nr = nr * (-1);
	return (nr);
}

/* Converts from any base to any base
** @base_from and @base_to is represented by an array of characters
**  containing the characters used in the base in order of their value
** @nbr the number we want to convert, containing only characters from
**  base_from array
** returns the number converted to base_to
*/
char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		radix_from;
	int		radix_to;
	char	*nbr_to;
	int		length;
	int		nr;

	radix_from = 0;
	radix_to = 0;
	length = 0;
	while (base_from[radix_from] != '\0')
		radix_from++;
	while (base_to[radix_to] != '\0')
		radix_to++;
	while (nbr[length] != '\0')
		length++;
	if (nbr[0] == '-' || nbr[0] == '+')
		length--;
	nr = convert_from(nbr, base_from, radix_from, length);
	nbr_to = convert_to(nr, radix_to, base_to);
	return (nbr_to);
}

int	main()
{
	char	nbr[100];
	char	base_from[100];
	char	base_to[100];
	
	printf("base examples: 01 for base 2\n");
	printf("               poneyvif or 01234567 for an octal base\n");
	printf("               0123456789ABCDEF for hexadecimal base\n");
	printf("Type the sequence of characters forming the base from which to convert: ");
	scanf("%s", base_from);
	printf("Type the number to convert using only %s: ", base_from);
	scanf("%s", nbr);	
	printf("Type the sequence of characters forming the base to convert to: ");
	scanf("%s", base_to);
	printf("Number in the new base: %s\n", ft_convert_base(nbr, base_from, base_to));
	return (0);
}
