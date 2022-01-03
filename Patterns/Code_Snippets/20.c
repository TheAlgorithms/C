#include<stdio.h>
int main(){
	int rows;
	printf("Enter number of rows:");
	scanf("%d",&rows);
	for(int i=1;i<=rows;i++){
		for(int j=1;j<=rows-1;j++){
			if(i==1||i==rows)
				printf("*");
			else{
				if(j==1||j==rows-1)
					printf("*");
				else
					printf(" ");
				}
			}
			printf("\n");
		}
		return 0;
	}
