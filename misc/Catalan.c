#include<stdio.h>

long int catalan(int n)
{
    // Base case
    if (n <= 1) return 1;
 
    // catalan(n) is sum of catalan(i)*catalan(n-i-1)
    long int res = 0;
    for (int i=0; i<n; i++)
        res += catalan(i)*catalan(n-i-1);
 
    return res;
}

int main() {
    int n; 
    printf("Enter the number whose Catalan You Want to find");
    scanf("%d", &n);
    
    printf("The answer is :%ld", catalan(n));
    return 0;
}
