#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int prime(long number);

int main(){
    long i;
    double sum=0;
    for( i=2 ; i<2000000 ; i++ ){
	if( prime(i) )
	    sum += i;	
    }
    printf("%f\n",sum);
    return 0;
}

int prime(long number){
    long i;
    for( i=2 ; i<sqrt(number) ; i++ )
	if( number%i == 0 )
	    return 0;
    return 1;
}    
