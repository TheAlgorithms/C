#include <stdio.h>

int fat(int number){
    int fac=1;
	if (number == 1 || number == 0) 
		return fac;
	while(number>1){
        fac=fac*number;
        number--;
    }
    return fac;
}

int main(){
	int number;

	//Asks the factorial of the number n 
	printf("Number: ");
	scanf("%d", &number);
	
	printf("%d\n", fat(number));
	
	return 0;
}
