
#include<stdio.h>
int main(){
    int n,rev=0,rem,m;
    printf("Enter a number: ");
    scanf("%d",&n);
    m=n;
    while(n!=0)
    {
        rem=n%10;
        rev=rev*10+rem;
        n=n/10;
    }
    if(m==rev)
        printf("The number is a Palindrome");
    else
        printf("The number is not a Palindrome");
    return 0;
}
