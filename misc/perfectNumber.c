#include <stdio.h>

int isPerfectNumber(int n)
{
  int sum = 0;
  for( int i = 1; (i <= n) && (n%i == 0); i++)
    sum += i;
  return (n > 1) && ( sum == n);
}

int main(void)
{
  int n = 0;
  printf("Number : ");
  scanf("%d", &n);
	
	if(isPerfect(n))
		printf("%d is a Perfect Number\n", n);
	else
		printf("%d is not a Perfect Number\n", n);
}
