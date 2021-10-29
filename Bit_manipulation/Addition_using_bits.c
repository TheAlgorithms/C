#include<stdio.h>

//this is a function which will execute addition using bits
int add_bits(int value1, int value2)
{
	unsigned int carry = value1 & value2;
	unsigned int sum = value1 ^ value2;
	
	while(carry != 0)
	{
		unsigned int shiftedcarry = carry << 1;
		carry = sum & shiftedcarry;
		sum ^= shiftedcarry;
	}

	return sum;

} 

int main(void)
{
	printf("%d\n",add_bits(55,10));

	return 0;

}
