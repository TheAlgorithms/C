#include<stdio.h>
int main(){
	int n,rows,col,num=1;
	printf("Enter the numer of rows: ");
	scanf("%d",&n);
	for(rows=n;rows>=1;rows--){
		for(col=1;col<=rows;col++){
			printf("%d ",num);
		}
		num++;
		printf("\n");
	}
}
