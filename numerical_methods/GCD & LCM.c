#include<stdio.h>
//function for find GCD
int gcd(int a,int b){
	int t,r;
	//swaping of a & b if a<b 
	if(a<b){
		t=a;
		a=b;
		b=t;
	}
	
	for(;r!=0;){
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}
//function for find LCM
int lcm(int c,int d){
	int s,R,e,f;
	//swaping of c & d if c<d
	if(c<d){
		s=c;
		c=d;
		d=s;
	}

	for(e=1,R=1;R!=0;e++){
		f=c*e;
		R=f%d;
	}
	return f;
}
main()
{
	int i,j,k,G,L;
	printf("enter two numbers:");
	scanf("%d %d",&i,&j);
	fflush(stdin);
	printf("Enter\n1 for GCD \n2 for LCM\n3 for both\n");
	scanf("%d",&k);
	G=gcd(i,j);
	L=lcm(i,j);
	
	switch(k){
		case 1:printf("GCD of given numbers is %d",G);break;
		case 2:printf("LCM of given numbers is %d",L);break;
		case 3:printf("GCD & LCM respectively are %d & %d",G,L);break;
	}
}
