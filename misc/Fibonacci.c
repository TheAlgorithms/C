#include <stdio.h>

//Fibonnacci function 
int fib(int number){
	if(number==1||number==2) return 1;
	else return fib(number-1)+fib(number-2);
}

int main(){
	int number;

	//Asks for the number that is in n position in Fibonnacci sequence
	printf("Number: ");
	scanf("%d", &number);
	
	printf("%d \n", fib(number));
	
	return 0;
}