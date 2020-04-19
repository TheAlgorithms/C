// C Program to convert hexadecimal to binary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hexadecimal_to_binary(char hex[]);

int main()
{
  int decimal;
  char hex[10];

  printf("Enter the hexadecimal number you want to convert: ");
  scanf("%s", hex);
  printf("The value of %s in binary is ", hex);
  hexadecimal_to_binary(hex);
  printf("\n");
  return 0;
}

void hexadecimal_to_binary(char hex[])
{
  int i, len = strlen(hex);

  for (i=0; i<len; i++)
  {
    switch(hex[i])
    {
      case '0': printf("0000"); break;
      case '1': printf("0001"); break;
      case '2': printf("0010"); break;
      case '3': printf("0011"); break;
      case '4': printf("0100"); break;
      case '5': printf("0101"); break;
      case '6': printf("0110"); break;
      case '7': printf("0111"); break;
      case '8': printf("1000"); break;
      case '9': printf("1001"); break;
      case 'A': case 'a': printf("1010"); break;
      case 'B': case 'b': printf("1011"); break;
      case 'C': case 'c': printf("1100"); break;
      case 'D': case 'd': printf("1101"); break;
      case 'E': case 'e': printf("1110"); break;
      case 'F': case 'f': printf("1111"); break;
      default: fprintf(stderr, "\n\nError!\n\n"); exit(-1);
    }
  }
}