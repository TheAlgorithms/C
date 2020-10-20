						/* https://github.com/omarmdh */

/*****integer to another base conversion*******************/
#include "stdio.h"
#include "string.h"

/**** convert and print ****/
void		decimal_to_base(int nb, int base)
{
	char	*basestab = "0123456789ABCDEF";

	if (nb > 0)
		decimal_to_base(nb / base, base);
	printf("%c", basestab[nb % base]);
}

int main(void)
{
	int nb = 0;
	int base = 0;

	printf("enter a integer: ");
	scanf("%d", &nb);
	printf("enter a base (2 - 16): ");
	scanf("%d", &base);
	if (nb < 0)
	{
		nb = nb * -1;
		printf("-");
	}
	if (base < 2 || base > 16)
		printf("Wrong Base !!\n");
	else
		decimal_to_base(nb, base);
	return (0);
}
