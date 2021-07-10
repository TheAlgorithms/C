/** 
*factorial_recursive.c 
*calculates the factorial of whole numbers using recursion
* @Hardik-hi (https://github.com/hardik-hi)
**/


#include <stdio.h>
#include<assert.h>

int factorial_rec(int n);
void test();
int main(void) {
	
	int n;
	printf("Enter the number whose factorial is to be found:\n");
	scanf("%d",&n);
	
	//checks whether the number entered is not negative
	if(n>=0)
	    printf("Factorial is: %d",factorial_rec(n));
	else
	    printf("Cannot find factorial of negative numbers.");
	test();
	
	return 0;
}

//finds the factorial recursively
int factorial_rec(int n){
        
    //if n is 0 or 1 in recursion tree, returns 1
    if(n==0 || n==1)    
        return 1;
        
    //recursively multiplies with lower number's factorial
    if(n>1)
        return n*factorial_rec(n-1);
}

//tests the factorial function
void test(){
    
    assert(factorial_rec(1)==1);
    assert(factorial_rec(5)==120);
    
    printf("\n--------------------------");
    printf("\nThe factorial of: \n");
    printf("0 is %d\n",factorial_rec(0));
    printf("1 is %d\n",factorial_rec(1));
    printf("5 is %d\n",factorial_rec(5));
    printf("10 is %d\n",factorial_rec(10));
    printf("--------------------------\n");
}
