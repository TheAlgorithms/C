#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int gcd(int a, int b) {
	if(b==0)
		return a;
	else if(a==0)
		return b;
	else
		return gcd(b,a%b);
}

int main() {
	int a,b;
	srand(time(NULL));
	a=rand() % 100;	
	b=rand() % 100;	
	printf("\nGCD of %d and %d is '%d'\n\n",a,b,gcd(a,b));
	return 0;
}
