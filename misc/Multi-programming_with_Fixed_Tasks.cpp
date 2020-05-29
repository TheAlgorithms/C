#include<stdio.h>
#include<conio.h>
void main()
{
int m,p,s,p1;
int m1[4],i,f,f1=0,f2=0,fra1,fra2,s1;
clrscr();
printf("Enter the memory size:");
scanf_s("%d",&m);
printf("Enter the no of partitions:");
scanf_s("%d",&p);
s=m/p;
printf("Each partn size is:%d",s);
printf("\nEnter the no of processes:");
scanf_s("%d",&p1);
for(i=0;i<p1;i++)
{
printf("\nEnter the memory req for process%d:",i+1);
scanf_s("%d",&m1[i]);
if(m1[i]<=s)
{

printf("\nProcess is allocated in partition%d",i+1);
fra1=s-m1[i];
printf("\nInternal fragmentation for process is:%d",fra1);
f1=f1+fra1;
}
else
{
printf("\nProcess not allocated in partition%d",i+1);
s1=m1[i]-s;
fra2=s-s1;
f2=f2+fra2;
printf("\nExternal fragmentation for partition is:%d",fra2);
}
}
printf("\nProcess\tmemory\tallocatedmemory");
for(i=0;i<p1;i++)
printf("\n%5d\t%5d\t%5d",i+1,s,m1[i]);
f=f1+f2;
printf("\nThe tot no of fragmentation is:%d",f);
_getch();
}
