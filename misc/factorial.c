#include <stdio.h>

int fat(int number){
	if (number == 1 || number == 0) 
		return 1;
	else 
		return number*fat(number-1);
}

int main(){
	int number;

	//Asks the factorial of the number n 
	printf("Number: ");
	scanf("%d", &number);
	
	printf("%d\n", fat(number));
	
	return 0;
}
