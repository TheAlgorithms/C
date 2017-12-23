#include <stdio.h>

/* 
https://en.wikipedia.org/wiki/Euclidean_algorithm 
*/

int euclidean_gcd(int a, int b){
    int t;
	while (b){
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main(){
	int a, b;

	printf("Number a: ");
	scanf("%d", &a);
	printf("Number b: ");
	scanf("%d", &b);

	printf("GCD(%d, %d) = %d\n", a, b, euclidean_gcd(a, b));
	
	return 0;
}
