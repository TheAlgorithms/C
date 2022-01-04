//C program for printing the rectangular pattern
#include<stdio.h>
void printPattern(int rows);
int main(){
	int rows;
	printf("Enter number of rows:");
	scanf("%d",&rows);
	printPattern(rows);
	return 0;
}
void printPattern(int n){
	int s=2*n-1;
	//Upper half
	for(int i=0;i<(s/2)+1;i++){
		int m=n;
		//Decreasing part
		for(int j=0;j<i;j++){
			printf("%d ",m);
			m--;
		}
		//Constant part
		for(int k=0;k<s-2*i;k++){
			printf("%d ",n-i);
		}
		//Increasing part
		m=n-i+1;
		for(int l=0;l<i;l++){
			printf("%d ",m);
			m++;
		}
		printf("\n");
	}
	//Lower half
	for(int i=s/2-1;i>=0;i--){
		//Decreasing part
		int m=n;
		for(int j=0;j<i;j++){
			printf("%d ",m);
			m--;
		}
		for(int k=0;k<s-2*i;k++){
			printf("%d ",n-i);
		}
		m=n-i+1;
		for(int l=0;l<i;l++){
			printf("%d ",m);
			m++;
		}
		printf("\n");
	}
}

