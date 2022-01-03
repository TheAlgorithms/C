#include<stdio.h>
int main(){
	int n=5;
	for(int i=n;i>=1;i--){
		for(int j=1;j<=n-i;j++){
			printf(" ");
		}
		for(int j=i;j>=1;j--){
			printf("*");
		}
		printf("\n");
	}
}
