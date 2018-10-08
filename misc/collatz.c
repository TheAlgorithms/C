/*
collatz conjecture: a series for a number n in which if n even then the next number is n/2 ,but if n is odd then the next number is 3n+1.
this series continues till it reaches 1*/

#include<stdio.h>
int main()
{
    int n,curr_no;   
    scanf("%d",&n);     //input number 
    curr_no=n;        //curr_no stores input number n   
    while(curr_no!=1)     //loop till series reaches 1
    {
        if(curr_no%2==0)      //condition   for even number
        {
            curr_no=curr_no/2;
            printf("%d->",curr_no);
        }    
        else 
        {
            curr_no=(curr_no*3)+1;      //condition for odd number
            printf("%d->",curr_no);
        }
    }
    printf("1");
    return 0;
}
