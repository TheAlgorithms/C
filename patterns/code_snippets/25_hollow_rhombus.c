//C program to print Hollow rhombus
#include<stdio.h>
int main(){
	int i,j,n;
	scanf("%d",&n);
	//Hollow rhombus
	printf("Hollow Rhombus\n\n");
	for(i=0;i<n;i++){
		for(j=0;j<n-i;j++){
			printf(" ");//Leading spaces
		}
		for(j=0;j<n;j++){
			//upper horizontal, bottom horizontal, left diagonal, right diagonal
			if(i==0||i==n-1||j==0||j==n-1)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}
