/**
 * \file
 * \brief [Problem 59](https://projecteuler.net/problem=59) solution -
 * optimization using look-up array
 * \author [Yashasvi Goel](https://github.com/yashasvi-goel/)
 *
 */
#include<stdio.h>
int check(int a)
{
    if(a>=65&&a<=90)
        return 1;
    else if(a>=97&&a<=122)
        return 1;
    else if(a>=48&&a<=59)
        return 1;
    else if(a=='('||a==')'||a=='.'||a==','||a=='\''||a=='?'||a=='-'||a=='!'||a==' ')
        return 1;
    return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    int *a=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int x=0;
    int h=0;
    for(int i=97;i<123;i++)
    {
        x=0;
        h=0;
        for(int j=0;j<n;j=j+3)
        {
            x=i^a[j];
            if(!check(x))
            {
                h=1;
                break;
            }
        }
        if(h==0)
        {
            printf("%c",i);
            break;
        }
    }
    for(int i='a';i<='z';i++)
    {
        x=0;
        h=0;
        for(int j=1;j<n;j=j+3)
        {                
            x=i^a[j];
            if(!check(x))
            {
                h=1;
        //        printf(":%c:%c\n",x,i);
                break;
            }
        }
        if(h==0)
        {
            printf("%c",i);
            break;
        }
    }
    for(int i=97;i<123;i++)
    {
        x=0;
        h=0;
        for(int j=2;j<n;j=j+3)
        {                
            x=i^a[j];
            if(!check(x))
            {
                h=1;
                break;
            }
        }
        if(h==0)
        {
            printf("%c",i);
            break;
        }
    }
    return 0;
}
/*
Input
82
32 66 50 20 11 0 42 66 33 19 13 20 47 66 37 14 58 67 43 23 14 17 49 67 46 20 6 51 66 55 9 39 67 45 3 25 56 66 39 14 37 34 65 51 22 8 1 40 65 32 17 14 21 45 65 36 12 57 66 41 20 15 19 50 66 44 23 7 49 65 54 11 36 66 47 0 24 58 65 38 12 38
Output
abc
*/
