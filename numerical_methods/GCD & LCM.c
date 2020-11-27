#include<stdio.h>
//function for finding GCD(Greatest Common Divisor)
int gcd(int i,int j){
	int t,r;
	//swaping i & j if i<j
	if(i<j){
		t=i;
		i=j;
		j=t;
	}
	//Using euclid's theorem for finding GCD of two numbers
	//According to theorem GCD(i,j)= GCD(j,i%j) ;where i>j.So that last reminder will be our GCD
	for(;r!=0;){
		r=i%j;
		i=j;
		j=r;
	}
	return i; //here i is last reminder so it is GCD
}
//function for finding LCM(Least Common Multiple)
int lcm(int i,int j){
	int t,r,e,f;
	// Swaping i & j if i<j
	if(i<j){
		t=i;
		i=j;
		j=t;
	}
	
	/*
		*Following example will show which logic is used in for loop
		->let i==8,j==6
		->8*1==8 , 8%6!=0
		->8*2==16 , 16%6!=0
		->8*3==24 , 24%6==0 so lcm(8,6)==24
	*/
	for(e=1,r=1;r!=0;e++){
		f=i*e;
		r=f%j;
	}
	return f;
}
int main()
{
	int num1,num2,choice,G,L;// G means GCD & L means LCM
	printf("enter two numbers:");
	scanf("%d %d",&num1,&num2);
	fflush(stdin); //flushing standard input so that below scanf() function will not consider stdin as input
	printf("Enter\n1 for GCD \n2 for LCM\n3 for both\n");
	scanf("%d",&choice); //Gives user multiple choice
	G=gcd(num1,num2);
	L=lcm(num1,num2);
	
	switch(choice){
		case 1:printf("GCD of given numbers is %d",G);break;
		case 2:printf("LCM of given numbers is %d",L);break;
		case 3:printf("GCD & LCM respectively are %d & %d",G,L);break;
	}
	return 0;
}
