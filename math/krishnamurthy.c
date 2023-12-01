#include <stdio.h>

/*

 * A krishnamurthy number is a number where the sum of 
 the factorial of its digits is equal to the number itself

 For example, 145 = 1! + 4! + 5!
 but 13 != 1! + 3!

 * For more information, visit https://www.geeksforgeeks.org/problems/krishnamurthy-number1323/1

*/


int factorial(int n){
    //Simple function returning the factorial of n

    if (n<2){
	return n;
    }
    return n*factorial(n-1);
}

int get_digit(int n, int sum){
    // Function returning the sum of the factorial of the digits

    if (n<10){
	return sum+factorial(n);
    }
    else{
	int div = n/10;
	sum += factorial(n%10);
	return get_digit(div,sum);
    }
}

void krishnamurthy(int n){
    int sum=0;
    if (get_digit(n,sum)==n){
	printf("%d is a krishnamurthy number\n",n);
    }
    else {
	printf("%d is not a krishnamurthy number\n",n);
    }
}

int main(){
    int n = 13, x = 145;
    printf("For example: \n");
    krishnamurthy(n);
    krishnamurthy(x);
    return 0;
}

