#include <stdio.h>
#include <math.h>
/*
Problem 4: 
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible(divisible with no remainder) by all of the numbers from 1 to N?
*/
int isprime(int no) {
	int sq;

	if (no == 2) {
		return 1;
	}
	else if (no%2 == 0) {
		return 0;
	}
	sq = ((int)(sqrt(no))) + 1;
	for (int i = 3; i < sq; i += 2) {
		if (no%i == 0) {
			return 0;
		}
	}
	return 1;
}
int countExp(int number,int power){
	int x=0;
	while (1){
		if (number%power==0){
			number/=power;
			x++;
		}
		else{return x;
		}
		
	}
}
int main(){
	int smallest=1,x,number,last=0;
	scanf("%d",&number);
	
	int primes[100];
	int powerList[100];
	for (int i=0;i<100;i++){
		powerList[i]=0;
	}
	for (int k=2;last<100;k++){
		
		if (isprime(k)==1){
			primes[last]=k;//assign the prime
			/*printf("last:%d , k:%d\n",last,k);*/
			last++;//move 1 in the array
		}
	
	}
	
	for (int ctr=1;ctr<=number;ctr++){
		for(int i=0;i<100;i++){
			
		x=countExp(ctr,primes[i]);
		if (x>powerList[i])powerList[i]=x;
		}
	}

for (int p=0;p<100;p++){
	/*printf("index %d:%d\n",p,powerList[p]);*/
	smallest*=pow(primes[p],powerList[p]);
}

	printf("the smallest number is: %d",smallest);
	return 0;
}
/*1 2 3 4 5 6 7 8 9 10 */
