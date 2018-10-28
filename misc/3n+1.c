#include<stdio.h>

int main()
{
  int theNumber = 0;
  int counter = 0;
  printf("Your number ->");
  scanf("%d", &theNumber);

  while(1)
  {
    counter++;
    if((theNumber%2) == 0)
    {
      theNumber = theNumber / 2;
    }
    if((theNumber%2) == 1)
    {
      theNumber = (theNumber * 3) + 1;
    }
    printf("%d\n",theNumber);

    if(theNumber == 2)
    break;
  }
  printf("1");
  printf("\nIt took %d steps.", counter+1);
  return 0;
}
