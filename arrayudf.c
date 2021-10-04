#include<stdio.h>

int i;
main()
{

int a[20],n,search,m;

void arrsum(int a[20],int n);

printf("enter the no of elements\n");

scanf("%d",&n);
if(n<=20)
{
printf("enter %d elements\n",n);
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
arrsum(a,n);
}
else
{
printf("invalid input\n");
}

}

void arrsum(int a[20], int n)

{

 max=marks[20];
  for(i=1;i<n;i++)

  {
     if(marks[i]>max)
        max=marks[i];
  }
  printf("maximum SGPA scored by student=%d\n",max);
 }

  else
  {
    printf("cant exeed 20\n");
  }
}

}

