//C program to print a right angled binary triangle
#include<stdio.h>
int main(){
	int rows,col,n;
	printf("Enter number of lines: ");
	scanf("%d",&n);
	for(rows=1;rows<=n;rows++){
		for(col=1;col<=rows;col++){
			if((rows+col)%2==0){
				printf("1 ");
			}
			else{
				printf("0 ");
			}
		}
		printf("\n");
	}
}
