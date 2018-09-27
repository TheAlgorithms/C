/*
*covert from decimal to other base
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int stop=0;

    while (stop!=1)
    {
        int inputNumber=0;

        while(inputNumber<=0)
        {
            printf("enter a positive integer number: ");
            scanf("%d",&inputNumber);
        }

        int base=0;

        while (base!=2 && base!=8 && base!=16)
        {
            printf("\nenter the base that you want the number to be converted: ");
            scanf("%d",&base);
        }

        if (base==2)
        {
            to_binary(inputNumber);
        }
        else if (base==8)
        {
            to_octal(inputNumber);
        }
        else if (base==16)
        {
            to_hexa(inputNumber);
        }

        printf ("\npress 0 to convert again");
        printf ("\npress 1 to exit\n");
        scanf("%d",&stop);
        printf("\n");
    }
}

void to_binary(int num)
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

void to_octal(int num)
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

void to_hexa(int num)
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

    printf("\nthe number in hexa is: ");

    for (i = j; i >= 0; i--)
    {
        printf("%c", hexa[i]);
    }

    printf("\n");
}
