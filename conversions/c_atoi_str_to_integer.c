#include <stdio.h>

// recoding the original atoi function in stdlib.h
int	c_atoi(char *str)
{
	int				i;
	int				sign;
	long			value;
	long			prev;

	i = 0;
	sign = 1;
	value = 0;
	// skip wait spaces
	while (((str[i] <= 13 && str[i] >= 9) || str[i] == 32) && str[i] != '\0')
		i++;
	// store the sign
	if (str[i] == '-' || str[i] == '+')
		(str[i++] == '-') ? sign = -1 : 1;
	// convert char by char to an int value
	while (str[i] >= 48 && str[i] <= 57 && str[i] != '\0')
	{
		prev = value;
		value = value * 10 + sign * (str[i] - '0');
		// manage the overflow
		if (sign == 1 && prev > value)
			return (-1);
		else if (sign == -1 && prev < value)
			return (0);
		i++;
	}
	return (value);	
}


int	main()
{
	// Test
	printf("%d\n", c_atoi("-234"));
}
