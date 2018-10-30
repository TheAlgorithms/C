#include<stdio.h>
#include<stdlib.h>
#include<time.h>

long int decToBin(int num) {
	if(num==0)
		return 0;
	else
		return (num%2 + 10*decToBin(num/2));
}

int main() {
	int num;
	srand(time(NULL));
	num=rand() % 20;
	printf("\n The binary of %d is '%ld'\n\n",num,decToBin(num));
	return 0;
}
