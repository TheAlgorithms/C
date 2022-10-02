#include<stdio.h>
#include<math.h>
int main()
{
float u,r,h,t,pi,angle,theta,s,c;

printf("Provide the initial velocity of the projectile in meters=");
scanf("%f", &u);
printf("Provide the throwing angle of the projectile in degrees=");
scanf("%f", &angle);
theta= 22*angle/(180*7);
s= sin(theta);
c=cos(theta);

r=(u*u*2*s*c)/9.8;
h=u*u*s*s/19.6;
t=(u*s)/9.8;
printf("Greatest vertical height=%f\n",h);
printf("Horizontal Range=%f\n",r);
printf("Total time elapsed=%f\n",t);
}
