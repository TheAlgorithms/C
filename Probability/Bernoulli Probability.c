#include<stdio.h>
#include<math.h>
int main() {
        float a,n,r,ncr,p;
        float x,y,z,fact1,fact2,fact3;
        
        fact1=1;
        for(x=1; x<=n;x++)
        fact1=fact1*x;
         fact2=1;
        for(y=1; y<=r;y++)
        fact2=fact2*y;
        fact3=3;
        for(z=1; z<=n;z++)
        fact3=fact3*z;
printf("Provide the probability of success=");
scanf("%f",&a);
if (a>1)
printf ("Input error");
else{
printf("Provide number of trials held=");
scanf("%f",&n);
printf("Provide your desired number of success=");
scanf("%f",&r);
if (r>n)
printf("Input Error");
else
{
ncr= fact1/((fact2)*(fact3));
p= ncr*pow(a,r)*pow(1-a,n-r);
if (p>1)
printf("Input Error, Check Again");
else
printf("Your asked probability=%f",p);
}
}
}
