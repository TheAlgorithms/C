#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

bool is_binary(intmax_t num);
int num_len(intmax_t num);

int main(void)
{
    intmax_t remainder, number = 0, decimal_number = 0, temp = 1;
    
    int length = num_len(INTMAX_MAX)-1;
    printf("\n Enter any binary number , max %d digits: ",length);
    scanf("%jd", &number);
    assert(num_len(number)<=length);
    assert(is_binary(number));
    
    // Iterate over the number until the end.
    while (number > 0)
    {
        remainder = number % 10;
        number = number / 10;
        decimal_number += remainder * temp;
        temp = temp * 2;  // used as power of 2
    }

    printf("%jd\n", decimal_number);
    return 0;
}

bool is_binary(intmax_t num)
{
	int remainder=0;
	
	while(num>0)
	{
		remainder=num%10;
		if(remainder==0 || remainder==1)
		{
			num /= 10;
			continue;
		}
		else
			return false;
	}
	return true;
}

int num_len(intmax_t num)
{
	int i;
	for(i=0; num>0; i++)
	{
		num /= 10;
	}
	return i;
}
