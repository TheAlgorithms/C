#include <stdio.h>
#include <stdlib.h>

void mask(int number){

	//create bitmask
	unsigned int mask = 0;
    //crates mask 0b1111..1111
	mask = ~((~(unsigned)0)>>1);
    int oneencountered = 0;
	while (mask != 0){
		//if current bit is 1
		if ((number & mask) != 0){
			printf ("1");
			oneencountered = 1;
		}
		else {
		    if(oneencountered)
			    printf ("0");
		}
	//shift mask 1 position to the right
	mask >>= 1;
	}


}

int main()
{

    // input of the user
    int inputNumber;

    printf("\t\tConverter decimal --> binary\n\n");

    // reads a decimal number from the user.
    printf("\nenter a positive integer number: ");
    scanf("%d",&inputNumber);

    mask(inputNumber);

    return 0;
}
