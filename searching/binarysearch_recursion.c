#include<stdio.h>
int RBsearch(int a[],int l,int h,int p);
void main()
{
int n,a[100],i,p,value,l,h,mid;
printf("enter number of elements: \n");
scanf("%d",&n);
printf("enter the elements: \n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("enter key element : \n");
scanf("%d",&p);
value=RBsearch(a,0,n-1,p);
if(value !=0)
{
printf("the number %d is at %d position \n",p,value);
}
else
{
printf("the number is not found");
}
}
int RBsearch(int a[],int l,int h,int p)
{
int mid=0;
if(l<=h)
{
mid=(l+h)/2;
if(a[mid]==p)
{
return mid;
}
else if(p<a[mid])
{
return RBsearch(a,l,mid-1,p);
}
else{
return RBsearch(a,mid+1,h,p);
}
}
else
return 0;
}
