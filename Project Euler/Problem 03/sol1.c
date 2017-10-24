/*
Problem:
The prime factors of 13195 are 5,7,13 and 29. What is the largest prime factor of a given number N?
e.g. for 10, largest prime factor = 5. For 17, largest prime factor = 17.
*/

#include<stdio.h>
#include<math.h>

int isprime(long long int no)
{
    if(no==2) return 1;
    else if(no%2==0) return 0;
    long int sq=sqrt(no);
    for(long int i=3;i<=sq;i+=2)
        if(no%i==0) return 0;
    return 1;
}

int main()
{
        long long int n,n1,max=0;
        scanf("%lld",&n);
        if(isprime(n)) printf("%lld\n",n);
        else{
            while(n%2==0)
                n=n/2;
            if(isprime(n)) printf("%lld\n",n);
            else
            {
                n1=sqrt(n);
                for(long long int i=3;i<=n1;i+=2)
                    if(n%i==0)
                        if(isprime(n/i))
                        {
                            max=n/i;
                            break;
                        }
                        else if(isprime(i))
                        {
                            max=i;
                        }
                printf("%lld\n",max);
            }
        }
    return 0;
}