//C program to print hollow pyramid triangle star pattern
#include<stdio.h>
int main(){
	int i,j,rows;
	//Imput rows to print from user
	printf("Enter number of rows: ");
	scanf("%d",&rows);
	for(i=1;i<=rows;i++){
		//Print trailing spaces
		for(j=i;j<rows;j++){
			printf(" ");
		}
		//Print hollow pyramid
		for(j=1;j<=(2*i-1);j++){
			if(j==1||j==(2*i-1)){
				printf("*");
			}
			else{
				printf(" ");
			}
		}
		printf("\n");
	}
	for(i=rows-1;i>=1;i--){
		//Print trailing spaces
		for(j=i;j<rows;j++){
			printf(" ");
		}
		//Print hollow pyramid
		for(j=1;j<=(2*i-1);j++){
			if(j==1||j==(2*i-1)){
				printf("*");
			}
			else{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}

