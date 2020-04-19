// C Program to convert hexadecimal to binary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int power(int base, int power);
int hexadecimal_to_decimal(char hex[]);

int main(void)
{
  int decimal;
  char hex[10];

  printf("Enter the hexadecimal number you want to convert: ");
  scanf("%s", hex);
  printf("The value of %s in decimal is %d\n", hex, hexadecimal_to_decimal(hex));
  return 0;
}

int power(int base, int power)
{
  int i, result = 1;

  for (i=0; i<power; i++)
  {
    result *= base;
  }

  return result;
}

int hexadecimal_to_decimal(char hex[])
{
  int i, len = strlen(hex), result = 0;

  for (i=0; i<len; i++)
  {
    switch(hex[i])
    {
      case '0': break;
      case '1': result += power(16, len-i-1); break;
      case '2': result += power(16, len-i-1)*2; break;
      case '3': result += power(16, len-i-1)*3; break;
      case '4': result += power(16, len-i-1)*4; break;
      case '5': result += power(16, len-i-1)*5; break;
      case '6': result += power(16, len-i-1)*6; break;
      case '7': result += power(16, len-i-1)*7; break;
      case '8': result += power(16, len-i-1)*8; break;
      case '9': result += power(16, len-i-1)*9; break;
      case 'A': case 'a': result += power(16, len-i-1)*10; break;
      case 'B': case 'b': result += power(16, len-i-1)*11; break;
      case 'C': case 'c': result += power(16, len-i-1)*12; break;
      case 'D': case 'd': result += power(16, len-i-1)*13; break;
      case 'E': case 'e': result += power(16, len-i-1)*14; break;
      case 'F': case 'f': result += power(16, len-i-1)*15; break;
      default: fprintf(stderr, "\n\nError!\n\n"); exit(-1);
    }
  }
  return result;
}