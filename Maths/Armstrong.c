#include<stdio.h>
int main(){
    int n,rev=0,rem;
    printf("Enter a number:");
    scanf("%d",&n);
    int m = n;
    while (m != 0)
    {
        rem=m%10;
        rev=rev+rem*rem*rem;
        m=m/10;
    }
   if(rev==n)
        printf("The number is an Armstrong Number");
    else
        printf("The number is not an Armstrong Number");
    return 0;

}
