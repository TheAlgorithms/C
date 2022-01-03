//C program to print inverted hollow pyramid triangle star pattern
#include<stdio.h>
int main(){
	int i,j,rows;
	//Input rows to print from user
	printf("Enter number of rows: ");
	scanf("%d",&rows);
	for(i=rows;i>=1;i--){
		//Print trailing spaces
		for(j=i;j<rows;j++){
			printf(" ");
		}
		//Print hollow pyramid
		for(j=1;j<=(2*i-1);j++){
			if(i==rows||j==1||j==(2*i-1)){
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

