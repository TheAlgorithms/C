/*
 * convert from any base to any base
 */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int base1=0;

    while(base1!=2 && base1!=8 && base1!=10 && base1!=16)
    {
        printf("Enter the current base: ");
        scanf("%d", &base1);
    }

    if (base1==10)
    {
        int number;
        printf("Enter the number: ");
        scanf("%d", &number);

        int base2=0;

        while(base2!=2 && base2!=8  && base2!=16){
        printf("\nenter the base that you want the number to be converted: ");
        scanf("%d",&base2);
        }

            if (base2==2)
        {
            decimal_to_binary(number);
        }
        else if (base2==8)
        {
            decimal_to_octal(number);
        }
        else if (base2==16)
        {
            decimal_to_hexa(number);
        }

    }
    else
    {
        int base2, i, j;
        char number[100];
        printf("Enter the number: ");
        scanf("%s", &number[0]);
        int decimal=0;

        printf("\nenter the base that you want the number to be converted: ");
        scanf("%d",&base2);

	for (i = 0; number[i] != '\0'; i++) {
		if (isdigit(number[i]))
			number[i] -= '0';
		else if (isupper(number[i]))
			number[i] -= 'A' - 10;
		else if (islower(number[i]))
			number[i] -= 'a' - 10;
		else
			number[i] = base1 + 1;

		if (number[i] > base1)
			printf("invalid number\n");
	}

	for (j = 0; j < i; j++) {
		decimal *= base1;
		decimal += number[j];
	}

        if (base2==10)
        {
            printf("%d", decimal);
        }
        else if (base2==2)
            {
                decimal_to_binary(decimal);
            }
            else if (base2==8)
            {
                decimal_to_octal(decimal);
            }
            else if (base2==16)
            {
                decimal_to_hexa(decimal);
            }

    }
}


void decimal_to_binary(int num)
{
    int bits[100];
    int re,j;
    int i=0;

    while(num>0)
    {
        re = num % 2;
        num = num / 2;
        bits[i] = re;
        i++;
    }

    printf("\nthe number in binary is: ");

    for(j=i-1; j>=0; j--)
    {
        printf("%d",bits[j]);
    }
    printf("\n");
}

void decimal_to_octal(int num)
{
    int octal[100];
    int re,j;
    int i=0;

    while(num>0)
    {
        re = num % 8;
        num = num / 8;
        octal[i] = re;
        i++;
    }

    printf("\nthe number in octal is: ");

    for(j=i-1; j>=0; j--)
    {
        printf("%d",octal[j]);
    }
    printf("\n");
}

void decimal_to_hexa(int num)
{
    int re;
    int i, j = 0;
    char hexa[100];

    while (num > 0)
    {
        re= num % 16;
        if (re < 10)
            hexa[j++] = 48 + re;

        else
            hexa[j++] = 55 + re;

        num = num/ 16;
    }

    j--;
    printf("\nthe number in hexa is: ");

    for (i = j; i >= 0; i--)
    {
        printf("%c", hexa[i]);
    }

    printf("\n");
}
