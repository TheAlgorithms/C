#include<stdio.h>
#define row 10
#define col 10
#include <time.h>
#include <stdlib.h>
void printpath(int m[row][col]);
int main()
{
	/*int m[row][col]={
		{1,0,0,0,1,0},
		{1,1,0,1,1,1},
		{0,1,1,0,0,1},
		{1,0,1,1,0,1},
		{1,0,0,1,0,0},
		{1,0,0,1,1,1}
	};*/
	srand(time(NULL));
	int n,i,j,m[row][col];
        for(i=0;i<row;i++)
	{
	   for(j=0;j<col;j++)
	   {
	     n=rand() % 100;
	     m[i][j]=n>50?1:0;
	   }
	}
	
	for(i=0;i<row;i++)
	{
	  for(j=0;j<col;j++)
	  {
	    printf("%d\t",m[i][j]);
	  }
	  printf("\n");
	}
	printpath(m);
	return 0;
}
void printpath(int m[row][col])
{
	int i=0,j=0;
	printf("Path is:\n(row,column)\n");
	while(i<row)
	{
		if((m[i][j]==1)&&(j<col))
		{
			printf("(%d,%d)\n",i,j);
			j++;
		}
		else
		{
			j=j-1;
			i++;
		}
	}
	printf("\n");
}
