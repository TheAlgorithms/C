#include <stdio.h>
int fat(int n){
  int f[n+1],int i;
  /* 0th and 1st number of the series are 0 and 1*/
  f[0] = 0;
  f[1] = 1;
  for (i = 2; i <= n; i++)
  {
      /* Add the previous 2 numbers in the series
         and store it */
      f[i] = f[i-1] + f[i-2];
  }
  return f[n];
}
int main(){
	int number;
	//Asks the factorial of the number n 
	printf("Number: ");
	scanf("%d", &number);
	printf("%d\n", fat(number));
	return 0;
}
