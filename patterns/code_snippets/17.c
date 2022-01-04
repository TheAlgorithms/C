#include<stdio.h>
int main(){
	int rows;
	printf("Enter number of rows:");
	scanf("%d",&rows);
	for(int i=1;i<=rows;i++){
		for(int j=1;j<=rows-i;j++){
			printf(" ");
		}
		for(int k=i;k>=1;k--){
			printf("%d",k);
		}
		for(int k=2;k<=i;k++){
			printf("%d",k);
		}
		printf("\n");
	}
	for(int i=rows-1;i>=0;i--){
		for(int j=1;j<=rows-i;j++){
			printf(" ");
		}
		for(int k=i;k>=1;k--){
			printf("%d",k);
		}
		for(int k=2;k<=i;k++){
			printf("%d",k);
		}
		printf("\n");
	}
	return 0;
}
