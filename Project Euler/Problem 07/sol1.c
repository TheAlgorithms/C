/*
By listing the first six prime numbers:
2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
What is the Nth prime number?
*/

#include <math.h>
#include <stdio.h>
int isprime(int n)
    {
    if (n==2) return 1;
    if(n%2==0) return 0;
    else
        {
        int sq = sqrt(n);
        for(int i=3;i<=sq;i+=2)
            if (n%i==0) return 0;
    }
    return 1;
}

int main(){
    int n;
    scanf("%d",&n);
    int i=0,j=1;
    while(i!=n && j<3)
        {
        j++;
        if(isprime(j)) i++;
    }
    while (i!=n)
    {
        j+=2;
        if(isprime(j)) i++;
    }
    printf("%d\n",j);
    return 0;
}
