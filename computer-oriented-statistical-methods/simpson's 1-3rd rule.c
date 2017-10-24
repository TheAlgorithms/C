#include<conio.h>
#include<stdio.h>
#include<math.h> 
float f(float x)
{
	return 1.0+x*x*x;
}
void main()
{
	int i,n;
	float a,b,h,x,s2,s3,sum,integral;
	printf("enter the lower limit of the integration");
	sacnf("%f",&a);
	printf("enter the upper limit of the integration");
	sacnf("%f",&b);
	printf("enter the number of intervals");
	sacnf("%d",&n);
	h=(b-a)/n;
	sum=f(a)+f(b);
	s2=s3=0.0;
	for(i=1;i<n;i+=3)
	{
		x=a+i*h;
		s3=s3+f(x)+f(x+h);
	}
	for(i=3;i<n;i+=3)
	{
		x=a+i*h;
		s2=s2+f(x);
	}
	intgral=(h/3.0)*(sum+2*s2+4*s3);
	printf("\nvalue of the integral =%9.4f\n",integral);
	getch();
}