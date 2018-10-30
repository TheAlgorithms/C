#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define MAX 100
typedef struct{
 int col;
 int row;
 int value;
 }sparse;
sparse a[MAX],b[MAX];

void transpose();
int main()
{
  int r,c,i,j,k=1,**b;
  printf("Enter the no of rows and columns:\n");
  scanf("%d%d",&r,&c);
  a[0].row=r;
  a[0].col=c;
  b=(int **)malloc(r*sizeof(int *));
  for(i=0;i<r;i++)
    b[i]=(int *)malloc(c*sizeof(int));
 
  srand(time(NULL));
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    {
 	int num = rand() % 100;
	b[i][j] = (num < 70) ? 0 : num;
 	
      if(b[i][j]!=0)
      {
        a[k].row=i;
        a[k].col=j;
        a[k].value=b[i][j];
        k++;
      }
    }
  }
  a[0].value=k-1;
  printf("The required sparse matrix is:\n");
  for(i=0;i<k;i++)
    printf("%d\t%d\t%d\n",a[i].row,a[i].col,a[i].value);

  printf("\nTranspose of the matrix is:\n");
  transpose();
}

void transpose()
{
  int n,i,j,cb;
  n=a[0].value;
  b[0].row=a[0].col;
  b[0].col=a[0].row;
  b[0].value=n;
  if(n>0)
    cb=1;
  for(i=0;i<a[0].col;i++)
  {
     for(j=1;j<=n;j++)
     {
        if(a[j].col==i)
	{
	   b[cb].row=a[j].col;
	   b[cb].col=a[j].row;
	   b[cb].value=a[j].value;
	   cb++;
	}
     }
  }
  for(i=0;i<cb;i++)
     printf("%d\t%d\t%d\n",b[i].row,b[i].col,b[i].value);
}






