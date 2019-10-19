/*This program calculate the semifatorial number. Input: a non negative number. Some number could provocate int overflow.
output: semifactorial
*/

#include <stdio.h>

int semifactorial(int N){
        if(N==2) return 2;
        else if(N==1 || N==0) return 1;
        else return N * semifactorial(N-2);
}

int main(){
        int N, result;
	do{
        	printf("Please, insert a non-negative number:\n");
        	scanf("%d",&N);
	}while(!(N>=0));
        result = semifactorial(N);
        printf("\n%d\n", result);
        return 0;
}








