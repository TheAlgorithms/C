#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int n;
    scanf("%d\n",&n);
    
    char a[n][100];
    
    for(int i=0;i<n;i++)
    scanf("%s\n",&a[i]);
    
   for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {   
            int k=strcmp(a[i],a[j]);
            if(k>0)
            {
                char temp[100];
                strcpy(temp,a[i]);
                strcpy(a[i],a[j]);
                strcpy(a[j],temp);
            }
        }
    }
    for(int i=0;i<n;i++)
    printf("%s ",a[i]);
    
}
