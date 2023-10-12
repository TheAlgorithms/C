//to generate Binomial Coefficient for given degree
#include<stdio.h>
#include<stdlib.h>
void main(){
    int n,i,j,r;
    printf("\nEnter the value of n and r for calculation of nCr: ");
    scanf("%d %d",&n,&r);
    if(r>n){
        printf("Invalid Entry for n and r in nCr. (r>n)");
        exit(0);
    }//end of if block
    int **DP=(int**)malloc((n+1)*sizeof(int*));
    for(i=0;i<n+1;i++)
    DP[i]=(int*)malloc((n+1)*sizeof(int));
    for(i=0;i<=n;i++)
    for(j=0;j<=i;j++)
    if(j==0||j==i)
    DP[i][j]=1;
    else
    DP[i][j]=DP[i-1][j-1]+DP[i-1][j];
    printf("The required binomial expansion for (a+b)^%d would be (a+b)^%d = ",n,n);
    for(i=0;i<n;i++)
    printf("%da^%db^%d + ",DP[n][i],n-i,i);
    printf("%da^%db^%d",DP[n][n],n,n);
    printf("\nThe required value of nCr for n=%d and r=%d i.e. %dC%d or C(%d,%d) = %d",n,r,n,r,n,r,DP[n][r]);
    for(i=0;i<n;i++)
    free(DP[i]);
    free(DP);
}//end of main